// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once

#include <frc/MathUtil.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/Commands.h>

#include "Constants.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/IndexerSubsystem.h"
#include "Subsystems/AmpSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();
 private:
  AmpSubsystem Amp;
  IndexerSubsystem indexer;
  DriveSubsystem drive;

  frc2::CommandXboxController driverController{OIConstants::kDriverControllerPort};

  void ConfigureBindings();
};
