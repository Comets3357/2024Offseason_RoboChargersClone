#include "Commands/AmpCommands.h"
#include "frc2/command/Commands.h"

frc2::CommandPtr AmpEject(AmpSubsystem* Amp)
{
  return frc2::cmd::RunOnce([Amp]{Amp->AmpEject(-0.3);});
}

frc2::CommandPtr AmpStop(AmpSubsystem* Amp)
{
  return frc2::cmd::RunOnce([Amp] {Amp->AmpStop();});
}