#include "Commands/DriveCommands.h"
#include <frc2/command/FunctionalCommand.h>

frc2::CommandPtr StopDrive(DriveSubsystem* driveSubsystem) {
   return frc2::cmd::RunOnce([driveSubsystem] {driveSubsystem->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);});
}