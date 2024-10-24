#pragma once
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/PivotSubsystem.h"

class DefaultPivotCommand
    : public frc2::CommandHelper<frc2::Command, DefaultPivotCommand> {
 public:
    std::function<double()> POVSupplier;
    std::function<double()> POV;

    /**
    * Creates a new PivotCommand (yippee!).
    *
    * @param pivotSubsystem The subsystem used by this command.
    * @param supplier POV
    */
    explicit DefaultPivotCommand(PivotSubsystem* pivotSubsystem, std::function<double()> POV);

    void Execute() override;

 private:
  PivotSubsystem* pivotSubsystem;
};