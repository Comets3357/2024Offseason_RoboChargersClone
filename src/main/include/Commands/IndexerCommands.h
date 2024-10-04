#pragma once

#include <frc2/command/CommandHelper.h>

#include "Subsystems/IndexerSubsystem.h"

namespace IndexerCommands {
   frc2::CommandPtr IndexerIntake(IndexerSubsystem* indexer);
   frc2::CommandPtr IndexerToLauncher(IndexerSubsystem* indexer);
   frc2::CommandPtr StopIndexer(IndexerSubsystem* indexer);
   frc2::CommandPtr EjectIndexer(IndexerSubsystem* indexer);
}