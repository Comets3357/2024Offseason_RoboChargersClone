// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Commands/AmpCommands.h"
#include <frc2/command/Commands.h>

void RobotContainer::ConfigureBindings() {
    DriverController.X().OnTrue(AmpEject(&Amp));
  DriverController.X().OnFalse(AmpStop(&Amp));
}

RobotContainer::RobotContainer() {
ConfigureBindings();
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}


