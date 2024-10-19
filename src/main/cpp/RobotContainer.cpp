// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Commands/DriveCommands.h"


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
  driverController.LeftTrigger().OnTrue(DriveTo(&drive, 2_m, 2_m));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
