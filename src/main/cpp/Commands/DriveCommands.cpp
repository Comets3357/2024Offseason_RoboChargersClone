#include "Commands/DriveCommands.h"
#include <frc2/command/FunctionalCommand.h>

frc2::CommandPtr StopDrive(DriveSubsystem* driveSubsystem) {
   return frc2::cmd::RunOnce([driveSubsystem] {driveSubsystem->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);});
}


frc2::CommandPtr DriveTo(DriveSubsystem* driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::radian_t rotationRadians = 0_rad, units::meters_per_second_t maxSpeedMetersPerSecond = 3_mps) {
         double xPosition = xPositionMeters.value();
         double yPosition = yPositionMeters.value();
         double rotation = rotationRadians.value();
         double maxSpeed = maxSpeedMetersPerSecond.value();
         double xTarget;
         double yTarget;
   return frc2::FunctionalCommand(
      [driveSubsystem] {driveSubsystem->ResetEncoders();},
      [driveSubsystem, xPosition, yPosition, rotation, maxSpeed] {
         double xCurrentPosition = driveSubsystem->GetPose().X().value();
         double yCurrentPosition = driveSubsystem->GetPose().Y().value();
         double xAway = xPosition - xCurrentPosition;
         double yAway = yPosition - yCurrentPosition;

         units::meters_per_second_t xSpeed{xAway > 0 ? std::min(xAway, maxSpeed) : std::max(xAway, -maxSpeed)};
         units::meters_per_second_t ySpeed{yAway > 0 ? std::min(yAway, maxSpeed) : std::max(yAway, -maxSpeed)};
         
         units::radians_per_second_t rps{rotation};
         driveSubsystem->Drive(xSpeed, ySpeed, rps, true, true);
      },
      [driveSubsystem] (bool interrupted) {StopDrive(driveSubsystem);},
      [driveSubsystem, xPosition, yPosition] {
         double xCurPos = driveSubsystem->GetPose().X().value();
         double yCurPos = driveSubsystem->GetPose().Y().value();
         return std::sqrt(std::pow(xPosition - xCurPos, 2) + std::pow(yPosition - yCurPos, 2)) < 1;
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
   return DriveTo(driveSubsystem, xPositionMeters, yPositionMeters, 0_rad, 3_mps);
}