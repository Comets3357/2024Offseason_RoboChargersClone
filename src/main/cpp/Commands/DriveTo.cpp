#include <Commands/DriveTo.h>
#include <Commands/DriveCommands.h>

DriveTo::DriveTo(DriveSubsystem* driveSubsystem, units::meter_t xDisplacementMeters, units::meter_t yDisplacementMeters, units::radian_t rotationRadians, units::meters_per_second_t maxSpeedMetersPerSecond) 
: driveSubsystem{driveSubsystem} {
   AddRequirements(driveSubsystem);
   this->driveSubsystem = driveSubsystem;
   xDisplacement = xDisplacementMeters.value();
   yDisplacement = yDisplacementMeters.value();
   rotation = rotationRadians.value();
   maxSpeed = maxSpeedMetersPerSecond.value();
}

void DriveTo::Initialize() {
   xTarget = driveSubsystem->GetPose().X().value() + xDisplacement;
   yTarget = driveSubsystem->GetPose().Y().value() + yDisplacement;
}

void DriveTo::Execute() {
   double xAway = xTarget - driveSubsystem->GetPose().X().value();
   double yAway = yTarget - driveSubsystem->GetPose().Y().value();

   units::meters_per_second_t xSpeed{xAway > 0 ? std::min(xAway, maxSpeed) : std::max(xAway, -maxSpeed)};
   units::meters_per_second_t ySpeed{yAway > 0 ? std::min(yAway, maxSpeed) : std::max(yAway, -maxSpeed)};
         
   units::radians_per_second_t rps{rotation};
   driveSubsystem->Drive(xSpeed, ySpeed, rps, true, true);
}

void DriveTo::End(bool interrupted) {
   StopDrive(driveSubsystem);
}

bool DriveTo::IsFinished() {
   return std::sqrt(std::pow(xTarget - driveSubsystem->GetPose().X().value(), 2) + std::pow(yTarget - driveSubsystem->GetPose().Y().value(), 2)) < 1;
}