// Filename:    intake.cpp
// Authors:     Dax DiLallo, Melia Tsai
// Created:     Dec 05 2023
// Description: The file that holds all intake related functions

#include "vex.h"
#include "intake.h"

// Function to be able to control the intake.

// Documentation:
// First value: Should be inbetween 0 and 1 to represent intake speed.
// Second value: Should be inbetween 0 and 1 to represent outtake speed.
void intakeControl(float intakeSpeed, float outtakeSpeed)
{
  // If L1 is pressing, then spin the intake so it sucks in triballs. Make sure to not spin if it is already.
  if (controller1.ButtonL1.pressing() && !intake.isSpinning())
  {
    intake.spin(reverse, intakeSpeed*100, percent);
  }
  // If L2 is pressing, then spin the intake so it spits out the triballs. Make sure to not spin if it is already.
  else if (controller1.ButtonL2.pressing() && !intake.isSpinning())
  {
    intake.spin(forward, outtakeSpeed*100, percent);
  }
  // Stop the intake if the driver is not holding any buttons.
  else
  {
    intake.stop();
  }
}