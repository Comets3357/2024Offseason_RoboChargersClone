#include "Subsystems/LEDSubsystem.h"
#include "rev/CANSparkMax.h"
#include <frc/DriverStation.h>

LEDSubsystem::LEDSubsystem(IndexerSubsystem* indexer) {
  indexerSubsystem = indexer;
  led.SetLength(90);
  for (size_t i = 0; i < 90; i++)
  {
    ledBuffer[i].SetRGB(0, 0, 0);
  }
  led.SetData(ledBuffer);
}

void LEDSubsystem::Periodic() {
  enabled = frc::DriverStation::IsEnabled();
  comms = frc::DriverStation::IsDSAttached();

  if (!enabled)
  {
    if (comms)
    {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(0, 255, 0);
      }
      led.SetData(ledBuffer);
    } else {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(255, 0, 0);
      }
      led.SetData(ledBuffer);
    }
  } else {
    if (indexerSubsystem->GamePieceDetected()) {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(0, 255, 0);
      }
      led.SetData(ledBuffer);
    } else {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(255, 165, 0);
      }
      led.SetData(ledBuffer);
    }
  }
}

void LEDSubsystem::SimulationPeriodic() {
   
}