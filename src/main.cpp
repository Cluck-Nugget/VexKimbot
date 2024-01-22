// Filename:    main.cpp
// Authors:     Dax DiLallo
// Created:     Nov 30 2023
// Description: The main file that connects all other files in this codebase.

#include "vex.h"

#include "drivetrain.h"
#include "intake.h"
#include "shooter.h"
#include "autonomous.h"
#include "global.h"

using namespace vex;

// Main function that runs when the program starts.
int main()
{
  // Initialize the robot.
  init();
  // Go into main loop that allows you to control all functions of the robot.
  //auton();
  while (true)
  {
    motorControl(1, 1, 5);
    intakeControl(0.9, 0.9);
    shooterControl(0.7);
    task::sleep(10);
  }
  return 0;
}