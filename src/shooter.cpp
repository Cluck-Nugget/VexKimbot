// Filename:    shooter.cpp
// Authors:     Dax DiLallo, Melia Tsai
// Created:     Dec 05 2023
// Description: The file that holds all shooter related functions

#include "vex.h"
#include "shooter.h"
#include "global.h"

int R1State = 0;

// Function to initialize the shooter motor.
void shooterInit()
{
  // Reset the shooter motor position.
  shooter.resetPosition();
  // Set the shooter stopping method to coast.
  shooter.setStopping(coast);
}

// Function to be able to control the shooter.

// Documentation:

// First value: Should be in-between 0 and 1 to represent shooter drawback speed.
void shooterControl(float shooterSpeed)
{
  if ((controller1.ButtonR1.pressing()) && (R1State == 0))
  {
    R1State = 1;
    shooter.spin(reverse, shooterSpeed, percent);
  }
  if ((!controller1.ButtonR1.pressing()) && (R1State == 1))
  {
    R1State = 0;
    shooter.stop();
  }
}