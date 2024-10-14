// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Subsystems/IndexerSubsystem.h"

#include "rev/CANSparkMax.h"

IndexerSubsystem::IndexerSubsystem() {
   indexer.SetSmartCurrentLimit(45);
}

void IndexerSubsystem::RunMotor(double power) {
   indexer.Set(power);
}

void IndexerSubsystem::StopMotor() {
   indexer.Set(0);
}

bool IndexerSubsystem::GamePieceDetected() {
   return beamBreak.Get();
}

void IndexerSubsystem::Periodic() {
   
}

void IndexerSubsystem::SimulationPeriodic() {
   
} 