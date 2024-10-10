#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>

class IndexerSubsystem : public frc2::SubsystemBase {
   public:
   IndexerSubsystem();

   /**
   * @param power How much power to put into the motor from [-1,1]
   */
   void RunMotor(double power);
   void StopMotor();

   /*
   *Checks if the indexer has a game piece
   */

   bool GamePieceDetected();
   void Periodic() override;
   void SimulationPeriodic() override;
   private:
   rev::CANSparkMax indexer{21, rev::CANSparkBase::MotorType::kBrushless};
   rev::SparkLimitSwitch beamBreak = indexer.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);
};