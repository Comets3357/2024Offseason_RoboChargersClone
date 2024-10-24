#include "Subsystems/IntakeSubsystem.h"
 
IntakeSubsystem::IntakeSubsystem()
{
    IntakeLMotor.SetSmartCurrentLimit(40);
}
void IntakeSubsystem::IntakeRun(double IntakeRunPower)
{
    IntakeLMotor.Set(IntakeRunPower);
    IntakeFMotor.Set(IntakeRunPower);
}
void IntakeSubsystem::IntakeStop()
{
    IntakeLMotor.Set(0);
}