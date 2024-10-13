// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/MathUtil.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/Commands.h>

#include <utility>

#include "Constants.h"
#include "Subsystems/DriveSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  frc2::CommandXboxController driverController{OIConstants::kDriverControllerPort};

  
  DriveSubsystem drive;

  void ConfigureBindings();
};
