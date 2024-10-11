#pragma once

#include <frc2/command/CommandPtr.h>
#include "Subsystems/AmpSubsystem.h"
#include "frc2/command/Commands.h"

  frc2::CommandPtr AmpEject(AmpSubsystem *Amp);
  frc2::CommandPtr AmpStop(AmpSubsystem *Amp);