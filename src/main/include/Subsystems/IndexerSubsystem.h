#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>

class IndexerSubsystem : public frc2::SubsystemBase {
   public:
   IndexerSubsystem();

   /**
   * Runs the motor using the power of Somali Bidirectional Acceleration Flicker Gooning
   * 
   * @param power How much power to put into the motor from [-1,1]
   */
   void RunMotor(double power);

   /**
   * Stops the motor using the power of Russian Multidimensional Elementary Still Water + Adrenaline + Noradrenaline
   * 
   * Those who know💀
   */
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