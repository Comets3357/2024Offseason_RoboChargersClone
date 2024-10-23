#pragma once
#include <frc2/command/SubsystemBase.h>
#include <frc/AddressableLED.h>

#include "subsystems/IndexerSubsystem.h"

class LEDSubsystem : public frc2::SubsystemBase {
   public:
   LEDSubsystem(IndexerSubsystem* indexer);
   void Periodic() override;
   void SimulationPeriodic() override;

   bool enabled = false;
   bool comms = false;
   private:
   IndexerSubsystem* indexerSubsystem;
   frc::AddressableLED led{9};
   std::array<frc::AddressableLED::LEDData, 90> ledBuffer;

};