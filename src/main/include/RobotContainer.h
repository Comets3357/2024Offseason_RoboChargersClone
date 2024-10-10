// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include "Subsystems/AmpSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

  

 private:
  AmpSubsystem Amp;
  frc2::CommandPtr AmpEject();
  frc2::CommandPtr AmpExtend();

  void ConfigureBindings(); 
};
