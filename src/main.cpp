/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\brian                                            */
/*    Created:      Thu Jan 26 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftFront            motor         1               
// LeftMiddle           motor         2               
// LeftBack             motor         3               
// RightFront           motor         11              
// RightMiddle          motor         12              
// RightBack            motor         13              
// Intake               motor         10              
// Controller1          controller                    
// Shooter              motor         19              
// InertialSensor       inertial      21              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "motors.h"
#include "controller.h"
// Testing
#include "motors.h"

using namespace vex;

competition Competition;


void init() {
  initMotors();
  displayAllMotorStats();
  printf("Robot Initialized\n");
}


int main() {
  vexcodeInit();
  init();

  Competition.autonomous(auton);

  Competition.drivercontrol(drivecontrol);
}