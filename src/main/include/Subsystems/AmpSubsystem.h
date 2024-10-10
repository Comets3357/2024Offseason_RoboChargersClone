#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
//#include "Subsystems/PivotSubsystem.h"

class AmpSubsystem : public frc2::SubsystemBase
{
    public:
        AmpSubsystem();
        //void Periodic() override;
        void AmpExtend(double AmpExtendPower);
        void AmpEject(double AmpEjectPower);
        void AmpStop();
    private:
        rev::CANSparkMax AmpMotor {21, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
          
};