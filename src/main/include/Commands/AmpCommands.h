#pragma once

#include <frc2/command/CommandPtr.h>

#include "Subsystems/AmpSubsystem.h"

  frc2::CommandPtr AmpEject(AmpSubsystem *Amp);
  frc2::CommandPtr AmpStop(AmpSubsystem *Amp);