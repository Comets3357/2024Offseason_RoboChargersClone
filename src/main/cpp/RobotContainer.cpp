// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Commands/AmpCommands.h"
#include "Commands/DefaultPivotCommand.h"
#include "Commands/IndexerCommands.h"
#include <frc2/command/Commands.h>

RobotContainer::RobotContainer() {
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  driverController.A().WhileTrue(IndexerIntake(&indexer));
  driverController.A().OnFalse(IndexerStop(&indexer));
  driverController.B().WhileTrue(IndexerEject(&indexer));
  driverController.B().OnFalse(IndexerStop(&indexer));
  driverController.X().OnTrue(AmpEject(&Amp));
  driverController.X().OnFalse(AmpStop(&Amp));

  //pivot subsystem
  pivotSubsystem.SetDefaultCommand(DefaultPivotCommand(&pivotSubsystem, [this] { return m_driverController.GetPOV(); }).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}


