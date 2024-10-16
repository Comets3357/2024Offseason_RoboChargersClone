// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
#include "RobotContainer.h"
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

  //pivot subsystem
 pivotSubsystem.SetDefaultCommand(DefaultPivotCommand(&pivotSubsystem,
  [this] { return m_driverController.GetPOV(); }          //D-Pad
  ).ToPtr());
  
}
