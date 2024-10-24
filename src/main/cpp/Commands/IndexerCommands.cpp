#include "Commands/IndexerCommands.h"
#include "frc2/command/Commands.h"

frc2::CommandPtr IndexerIntake(IndexerSubsystem* indexer) {
  return frc2::cmd::Run([indexer] {
    if (indexer->GamePieceDetected()){
      indexer->StopMotor();
    } else {
      indexer->RunMotor(0.4);
    }
  });
}

frc2::CommandPtr IndexerToLauncher(IndexerSubsystem* indexer) {
  return frc2::cmd::Run([indexer] {indexer->RunMotor(0.5);});
}

frc2::CommandPtr IndexerStop(IndexerSubsystem* indexer) {
  return frc2::cmd::RunOnce([indexer] {indexer->StopMotor();});
}

frc2::CommandPtr IndexerEject(IndexerSubsystem* indexer) {
  return frc2::cmd::Run([indexer] {indexer->RunMotor(-0.4);});
}