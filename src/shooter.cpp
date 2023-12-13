// Filename:    shooter.cpp
// Authors:     Dax DiLallo, Melia Tsai
// Created:     Dec 05 2023
// Description: The file that holds all shooter related functions

#include "vex.h"
#include "shooter.h"
#include "global.h"

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
// First value: Should be inbetween 0 and 1 to represent shooter drawback speed.
void shooterControl(float shooterSpeed)
{
  // If R1 is pressing, then spin the shooter to add force to the rubber bands. Make sure to not spin if it is already.
  if (controller1.ButtonR1.pressing() && !shooter.isSpinning())
  {
    shooter.spin(reverse, shooterSpeed*100, percent);  
  }
  // If R1 is not pressing, then stop the shooter.
  else
  {
    shooter.stop();
  }
}