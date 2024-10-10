#include "Subsystems/AmpSubsystem.h"

AmpSubsystem::AmpSubsystem()
{
    AmpMotor.SetSmartCurrentLimit(40);
}

void AmpSubsystem::AmpExtend(double AmpExtendPower)
{
    AmpMotor.Set(AmpExtendPower);
}

void AmpSubsystem::AmpEject(double AmpEjectPower)
{
    AmpMotor.Set(AmpEjectPower);
}

