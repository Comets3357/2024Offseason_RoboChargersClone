// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once

#include "Subsystems/AmpSubsystem.h"
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/RunCommand.h>



class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();
   
  frc2::CommandXboxController DriverController{1};
  

 private:
  AmpSubsystem Amp;

  void ConfigureBindings(); 
};
