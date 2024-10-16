
#include "RobotContainer.h"
#include "Commands/DefaultPivotCommand.h"

#include <frc2/command/Commands.h>

RobotContainer::RobotContainer() {
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {

 pivotSubsystem.SetDefaultCommand(DefaultPivotCommand(&pivotSubsystem,
  [this] { return m_operatorController.GetPOV(); }          //D-Pad
  ).ToPtr());
  
}
