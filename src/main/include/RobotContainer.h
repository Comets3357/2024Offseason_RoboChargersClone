// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once

#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/CommandPtr.h>

#include "Subsystems/IndexerSubsystem.h"
#include "Subsystems/AmpSubsystem.h"
#include "Subsystems/LEDSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();
 private:
  AmpSubsystem Amp;
  IndexerSubsystem indexer;
  LEDSubsystem led{&indexer}; 

  frc2::CommandXboxController driverController{0};

  void ConfigureBindings();
};
