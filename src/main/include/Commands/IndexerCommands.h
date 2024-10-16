#pragma once

#include <frc2/command/CommandPtr.h>
#include "Subsystems/IndexerSubsystem.h"

frc2::CommandPtr IndexerIntake(IndexerSubsystem* indexer);
frc2::CommandPtr IndexerToLauncher(IndexerSubsystem* indexer);
frc2::CommandPtr IndexerStop(IndexerSubsystem* indexer);
frc2::CommandPtr IndexerEject(IndexerSubsystem* indexer);