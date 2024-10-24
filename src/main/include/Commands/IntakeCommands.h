#pragma once

#include <frc2/command/CommandPtr.h>
#include "Subsystems/IntakeSubsystem.h"

  frc2::CommandPtr IntakeRun(IntakeSubsystem *Intake);
  frc2::CommandPtr IntakeStop(IntakeSubsystem *Intake);