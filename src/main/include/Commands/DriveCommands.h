#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/FunctionalCommand.h>
#include "Subsystems/DriveSubsystem.h"


namespace DriveCommands {
   /*
   * Drives to a certain position from the current position(Opponent starts Jamaican Smiling(those who know(only balkans understand(from the screen to the ring to the pen to the king))))
   * 
   * @param xPosition X Position to drive to
   * @param yPosition Y Position to drive to
   */
   frc2::CommandPtr DriveTo(DriveSubsystem* drive, double xPosition, double yPosition);
}
