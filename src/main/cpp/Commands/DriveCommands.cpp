#include "Commands/DriveCommands.h"
#include <frc2/command/FunctionalCommand.h>

frc2::CommandPtr StopDrive(DriveSubsystem* driveSubsystem) {
   return frc2::cmd::RunOnce([driveSubsystem] {driveSubsystem->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);});
}


frc2::CommandPtr DriveTo(DriveSubsystem* driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::radian_t rotationRadians = 0_rad, units::meters_per_second_t maxSpeedMetersPerSecond = 3_mps) {
   return frc2::FunctionalCommand(
      [driveSubsystem] {driveSubsystem->ResetEncoders();},
      [driveSubsystem, xPositionMeters, yPositionMeters, rotationRadians, maxSpeedMetersPerSecond] {
         double xPosition = xPositionMeters.value();
         double yPosition = yPositionMeters.value();
         double rotation = rotationRadians.value();
         double maxSpeed = maxSpeedMetersPerSecond.value();

         double MaxAbsValue = std::max(std::abs(xPosition), std::abs(yPosition));
         //The greater of the two will be -1 or 1, the lesser will be a number [-1, 1]
         double xRelativeRatio = xPosition/MaxAbsValue;
         //The greater of the two will be -1 or 1, the lesser will be a number [-1, 1]
         double yRelativeRatio = yPosition/MaxAbsValue;
         units::meters_per_second_t xSpeed{maxSpeed*xRelativeRatio};
         units::meters_per_second_t ySpeed{maxSpeed*yRelativeRatio};
         double magnitude = std::sqrt(std::pow(xPosition, 2) + std::pow(yPosition, 2));
         double speed = std::sqrt(std::pow(xSpeed.value(), 2) + std::pow(ySpeed.value(), 2));
         double time = magnitude / speed;
         units::radians_per_second_t rps{rotation/time};
         driveSubsystem->Drive(xSpeed, ySpeed, rps, true, true);
      },
      [driveSubsystem] (bool interrupted) {StopDrive(driveSubsystem);},
      [driveSubsystem, xPositionMeters, yPositionMeters] {
         double xPosition = xPositionMeters.value();
         double yPosition = yPositionMeters.value();

         double xCurPos = driveSubsystem->GetPose().X().value();
         double yCurPos = driveSubsystem->GetPose().Y().value();
         return std::floor(xCurPos) == xPosition && std::floor(yCurPos) == yPosition;
      },
      {driveSubsystem}
   ).ToPtr();
}

frc2::CommandPtr DriveTo(DriveSubsystem* driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::radian_t rotationRadians) {
   return DriveTo(driveSubsystem, xPositionMeters, yPositionMeters, rotationRadians, 3_mps);
}

frc2::CommandPtr DriveTo(DriveSubsystem *driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::meters_per_second_t maxSpeedMetersPerSecond) {
   return DriveTo(driveSubsystem, xPositionMeters, yPositionMeters, 0_rad, maxSpeedMetersPerSecond);
}

frc2::CommandPtr DriveTo(DriveSubsystem *driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters) {
   return DriveTo(driveSubsystem, xPositionMeters, yPositionMeters, 0_rad, 0_mps);
}