#include "Commands/IntakeCommands.h"
#include <frc2/command/Commands.h>

frc2::CommandPtr IntakeRun(IntakeSubsystem* Intake)
{
  return frc2::cmd::RunOnce([Intake]{Intake->IntakeRun(0.3);});
}
frc2::CommandPtr IntakeStop(IntakeSubsystem* Intake)
{
  return frc2::cmd::RunOnce([Intake] {Intake->IntakeStop();});
}