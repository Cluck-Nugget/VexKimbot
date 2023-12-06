// Filename:    drivetrain.cpp
// Authors:     Dax DiLallo, Matthew Pak
// Created:     Dec 05 2023
// Description: The file that holds all drivetrain related functions


#include "vex.h"
#include "drivetrain.h"

// Function to stop all drivetrain motors.
void stopDrivetrain()
{
  // Individually stops every drivetrain motor.
  leftFront.stop();
  rightFront.stop();
  leftBack.stop();
  rightBack.stop();
  leftMiddle.stop();
  rightMiddle.stop();
}

// Function to control the drivetrain.

// Documentation:
// First value: Should be inbetween 0 and 1 to represent drive speed.
// Second value: Should be inbetween 0 and 1 to represent turn speed.
// Third value: Should be inbetween 0 and 100 to represent the deadzone in percent.
void motorControl(float driveSpeed, float turnSpeed, int deadzone)
{
  // Sets the x and y intagers to the position of axis1*turnSpeed and axis3*turnSpeed respectively.
  int x = controller1.Axis1.position(percent)*turnSpeed;
  int y = controller1.Axis3.position(percent)*driveSpeed;

  // Uses motion and turning logic based on joystick positions to allow driving while not in the deadzone.
  if (abs(x) > deadzone || abs(y) > deadzone) {
    leftFront.spin(forward, x - y, percent);
    rightFront.spin(reverse, -x - y, percent);
    leftBack.spin(forward, x - y, percent);
    rightBack.spin(reverse, -x - y, percent);
    leftMiddle.spin(forward, x - y, percent);
    rightMiddle.spin(reverse, -x - y, percent);
  }
  // If the joysticks are in the deadzone, stop all drivetrain motors.
  else
  {
    stopDrivetrain();
  }
}