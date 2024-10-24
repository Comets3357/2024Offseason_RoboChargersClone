#pragma once
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <rev/CANSparkMax.h>
#include <rev/CANSparkFlex.h>
 
class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();
 
 
  //void Periodic() override;
  void IntakeRun(double IntakeRunPower);
  void IntakeStop();
 
 private:
   rev::CANSparkFlex IntakeLMotor{11, rev::CANSparkFlex::MotorType::kBrushless};
   rev::CANSparkFlex IntakeFMotor{12, rev::CANSparkFlex::MotorType::kBrushless};
};