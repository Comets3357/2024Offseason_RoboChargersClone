#include "subsystems/PivotSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>


PivotSubsystem::PivotSubsystem() {

    pivotEncoder.SetVelocityConversionFactor(360 /*degrees*/);
    pivotMotor.SetSoftLimit(rev::CANSparkBase::SoftLimitDirection::kForward, 80);
    pivotMotor.SetSoftLimit(rev::CANSparkBase::SoftLimitDirection::kReverse, 30);
    PivotPID.SetFeedbackDevice(pivotEncoder);
}

void PivotSubsystem::setAngularAngle(int angle) {
    targetAngle = angle;
}

void PivotSubsystem::setAngularSpeed(int speed) {
    pivotMotor.Set(speed);
}

double PivotSubsystem::getAngularAngle() {
    return pivotEncoder.GetPosition();
}

double PivotSubsystem::getTargetAngle() {
    return targetAngle;
}

void PivotSubsystem::calculatePID() {
    pivotMotor.Set(pid.Calculate(getAngularAngle(), getTargetAngle()));
}

void PivotSubsystem::Periodic() {

    if (targetAngle > 80) {
        targetAngle = 80;
    }
    if (targetAngle < 30) {
        targetAngle = 30;
    }

    frc::SmartDashboard::PutNumber("Target Angle", PivotSubsystem::getTargetAngle());
    frc::SmartDashboard::PutNumber("Angular Angle", PivotSubsystem::getAngularAngle());
    frc::SmartDashboard::PutNumber("PID Calculaton", pid.Calculate(getAngularAngle(), getTargetAngle()));
}