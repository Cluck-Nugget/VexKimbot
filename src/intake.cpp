// Filename:    intake.cpp
// Authors:     Dax DiLallo, Melia Tsai
// Created:     Dec 05 2023
// Description: The file that holds all intake related functions

#include "vex.h"
#include "intake.h"
#include "global.h"

// Function to initialize the intake motor.
void intakeInit()
{
  // Reset the intake position.
  intake.resetPosition();
  // Set the stopping method of the intake motor to coast.
  intake.setStopping(coast);
}

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
  // Stop the intake if L1 or L2 is not being pressed.
  else
  {
    intake.stop();
  }
}