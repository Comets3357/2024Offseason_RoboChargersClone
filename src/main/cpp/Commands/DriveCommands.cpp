#include "Commands/DriveCommands.h"

using namespace DriveCommands;

frc2::CommandPtr DriveTo(DriveSubsystem* drive, double xPosition, double yPosition) {
   return frc2::FunctionalCommand(
      [drive] {},
      [drive] {},
      [drive] (bool interrupted) {},
      [drive] {return true;},
      {drive}
   ).ToPtr();
}