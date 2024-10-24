#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

class AmpSubsystem : public frc2::SubsystemBase
{
    public:
        AmpSubsystem();
        void AmpEject(double AmpEjectPower);
        void AmpStop();
    private:
        rev::CANSparkMax AmpMotor {51, rev::CANSparkMax::MotorType::kBrushless};
};