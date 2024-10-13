#pragma once

#include <frc2/command/Commands.h>
#include "Subsystems/DriveSubsystem.h"

frc2::CommandPtr DriveTo(DriveSubsystem *driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::radian_t rotationRadians, units::meters_per_second_t maxSpeedMetersPerSecond);
frc2::CommandPtr DriveTo(DriveSubsystem *driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::radian_t rotationRadians);
frc2::CommandPtr DriveTo(DriveSubsystem *driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters, units::meters_per_second_t maxSpeedMetersPerSecond);
frc2::CommandPtr DriveTo(DriveSubsystem *driveSubsystem, units::meter_t xPositionMeters, units::meter_t yPositionMeters);

frc2::CommandPtr StopDrive(DriveSubsystem *DriveSubsystem);