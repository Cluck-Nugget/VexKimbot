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

competition comp;

// Main function that runs when the program starts.
int main()
{
  // Initialize the robot.
  init();
  // Go into main loop that allows you to control all functions of the robot.
  comp.autonomous(skillsAuton);
  comp.drivercontrol(driveControl);
  // auton();
  // return 0;
}