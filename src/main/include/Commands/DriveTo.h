#pragma once

#include <frc2/command/CommandHelper.h>
#include "Subsystems/DriveSubsystem.h"

class DriveTo
    : public frc2::CommandHelper<frc2::Command, DriveTo> {
public:
   explicit DriveTo(DriveSubsystem* driveSubsystem, units::meter_t xDisplacementMeters, units::meter_t yDisplacementMeters, units::radian_t rotationRadians = 0_rad, units::meters_per_second_t maxSpeedMetersPerSecond = 0_mps);
   void Initialize() override;
   void Execute() override;
   void End(bool interrupted) override;
   bool IsFinished() override;
private:
   DriveSubsystem* driveSubsystem;
   double xDisplacement;
   double yDisplacement;
   double rotation;
   double maxSpeed;
   double xTarget;
   double yTarget;
};

