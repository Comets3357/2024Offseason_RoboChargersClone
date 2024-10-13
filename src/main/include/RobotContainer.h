// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/button/CommandXboxController.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "Constants.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/Auto.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:

  frc2::CommandXboxController driverController{OIConstants::kDriverControllerPort};

  frc2::CommandPtr emptyAuto = autos::EmptyAuto();
  
  frc::SendableChooser<frc2::Command*> sendableChooser;

  
  DriveSubsystem drive;

  void ConfigureBindings();
};
