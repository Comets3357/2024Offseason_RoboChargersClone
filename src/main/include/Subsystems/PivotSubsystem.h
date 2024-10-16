#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/controller/PIDController.h>
#include <rev/CANSparkMax.h>


class PivotSubsystem : public frc2::SubsystemBase {
 public:

    PivotSubsystem();

    const double pivotP = 0.04;
    const double pivotI = 0;
    const double pivotD = 0;
    frc::PIDController pid{pivotP, pivotI, pivotD};

    int targetAngle = 60;

    void setAngularAngle(int degree);
    void setAngularSpeed(int speed);
    double getAngularAngle();
    double getTargetAngle();

    void calculatePID();

    void Periodic() override;
 private:

    rev::CANSparkMax pivotMotor{31, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
    rev::SparkAbsoluteEncoder pivotEncoder = pivotMotor.GetAbsoluteEncoder(rev::SparkAbsoluteEncoder::Type::kDutyCycle);
};