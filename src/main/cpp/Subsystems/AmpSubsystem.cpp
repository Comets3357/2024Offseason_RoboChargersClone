#include "Subsystems/AmpSubsystem.h"

AmpSubsystem::AmpSubsystem()
{
    AmpMotor.SetSmartCurrentLimit(40);
}
void AmpSubsystem::AmpEject(double AmpEjectPower)
{
    AmpMotor.Set(AmpEjectPower);
}
void AmpSubsystem::AmpStop()
{
    AmpMotor.Set(0);
}