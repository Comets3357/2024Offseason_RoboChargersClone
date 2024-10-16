#include "commands/DefaultPivotCommand.h"
#include "subsystems/PivotSubsystem.h"
#include <RobotContainer.h>
#include <frc/smartdashboard/SmartDashboard.h>

DefaultPivotCommand::DefaultPivotCommand(PivotSubsystem *pivotSubsystem, std::function<double()> POVSupplier)
    : pivotSubsystem{pivotSubsystem} {
    // Register that this command requires the subsystem.
    AddRequirements(pivotSubsystem);
    this->POV = POVSupplier;
}

void DefaultPivotCommand::Execute() {

    //this stuff is kinda self-explainatory lmao
    if (POV() == 0) {
        pivotSubsystem->setAngularAngle(pivotSubsystem->getTargetAngle() + 2);
    }
    else if (POV() == 180) {
        pivotSubsystem->setAngularAngle(pivotSubsystem->getTargetAngle() - 2);
    }    


    pivotSubsystem->calculatePID();

    //smartdashboard
    frc::SmartDashboard::PutNumber("Pov", POV());
}