// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Commands/AmpCommands.h"
#include "Commands/IndexerCommands.h"
#include "Commands/DriveCommands.h"
#include "Commands/DriveTo.h"


RobotContainer::RobotContainer() {
  drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        drive.Drive(
            -units::meters_per_second_t{frc::ApplyDeadband(
                driverController.GetLeftY(), OIConstants::kDriveDeadband)},
            -units::meters_per_second_t{frc::ApplyDeadband(
                driverController.GetLeftX(), OIConstants::kDriveDeadband)},
            -units::radians_per_second_t{frc::ApplyDeadband(
                driverController.GetRightX(), OIConstants::kDriveDeadband)},
            true, true);
      },
      {&drive}));

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  driverController.LeftTrigger().OnTrue(DriveTo(&drive, 2_m, 2_m).ToPtr());

  driverController.A().WhileTrue(IndexerIntake(&indexer));
  driverController.A().OnFalse(IndexerStop(&indexer));
  driverController.B().WhileTrue(IndexerEject(&indexer));
  driverController.B().OnFalse(IndexerStop(&indexer));
  driverController.X().OnTrue(AmpEject(&Amp));
  driverController.X().OnFalse(AmpStop(&Amp));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}


