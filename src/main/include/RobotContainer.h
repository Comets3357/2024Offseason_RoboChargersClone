// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"

#include "subsystems/PivotSubsystem.h"
#include "commands/DefaultPivotCommand.h"
#include "Subsystems/IndexerSubsystem.h"]

class RobotContainer {
 public:
  RobotContainer();

frc2::CommandPtr GetAutonomousCommand();



 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  frc2::CommandXboxController m_operatorController{
      OperatorConstants::kOperatorControllerPort};

  // The robot's subsystems are defined here...
  PivotSubsystem pivotSubsystem;
  
  IndexerSubsystem indexer;

  frc2::CommandXboxController driverController{0};

  void ConfigureBindings();
};
