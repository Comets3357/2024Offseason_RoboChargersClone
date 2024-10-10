// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>

RobotContainer::RobotContainer() {
  ConfigureBindings();
}

frc2::CommandPtr RobotContainer::IndexerIntake() {
  return frc2::cmd::Run([this] {
    if (indexer.GamePieceDetected()){
      indexer.StopMotor();
    } else {
      indexer.RunMotor(0.2);
    }
  });
}

frc2::CommandPtr RobotContainer::IndexerToLauncher() {
  return frc2::cmd::Run([this] {indexer.RunMotor(0.5);});
}

frc2::CommandPtr RobotContainer::IndexerStop() {
  return frc2::cmd::RunOnce([this] {indexer.StopMotor();});
}

frc2::CommandPtr RobotContainer::IndexerEject() {
  return frc2::cmd::Run([this] {indexer.RunMotor(-0.4);});
}

void RobotContainer::ConfigureBindings() {
  driverController.A().WhileTrue(IndexerIntake());
  driverController.A().OnFalse(IndexerStop());
  driverController.B().WhileTrue(IndexerEject());
  driverController.B().OnFalse(IndexerStop());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
