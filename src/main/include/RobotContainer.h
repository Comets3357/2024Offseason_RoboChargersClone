// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/RunCommand.h>
#include <frc/MathUtil.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "Subsystems/IndexerSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  IndexerSubsystem indexer;

  frc2::CommandXboxController driverController{0};

  frc2::CommandPtr IndexerIntake();
  frc2::CommandPtr IndexerToLauncher();
  frc2::CommandPtr IndexerStop();
  frc2::CommandPtr IndexerEject();
  void ConfigureBindings();
};
