#include "Commands/DriveCommands.h"

frc2::CommandPtr DriveCommands::StopDrive(DriveSubsystem* drive) {
   return frc2::cmd::RunOnce([drive] {drive->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);});
}


frc2::CommandPtr DriveCommands::DriveTo(DriveSubsystem* drive, double xPosition, double yPosition, double rotation = 0) {
   return frc2::FunctionalCommand(
      [drive] {drive->ResetEncoders();},
      [drive, xPosition, yPosition, rotation] {
         double MaxAbsValue = std::max(std::abs(xPosition), std::abs(yPosition));
         units::meters_per_second_t xSpeed{3*(xPosition/MaxAbsValue)};
         units::meters_per_second_t ySpeed{3*(yPosition/MaxAbsValue)};
         double magnitude = std::sqrt(std::pow(xPosition, 2) + std::pow(yPosition, 2));
         double speed = std::sqrt(std::pow(xSpeed.value(), 2) + std::pow(ySpeed.value(), 2));
         double time = magnitude / speed;
         units::radians_per_second_t rps{rotation/time};
         drive->Drive(xSpeed, ySpeed, rps, true, true);
      },
      [drive] (bool interrupted) {DriveCommands::StopDrive(drive);},
      [drive, xPosition, yPosition] {
         double xCurPos = drive->GetPose().X().value();
         double yCurPos = drive->GetPose().Y().value();
         return std::floor(xCurPos) == xPosition && std::floor(yCurPos) == yPosition;
      },
      {drive}
   ).ToPtr();
}