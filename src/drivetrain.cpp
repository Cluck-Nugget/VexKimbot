// Filename:    drivetrain.cpp
// Authors:     Dax DiLallo, Matthew Pak
// Created:     Dec 05 2023
// Description: The file that holds all drivetrain related functions


#include "vex.h"
#include "drivetrain.h"

// Function to set all drivetrain motor stopping methods.
void drivetrainInit() {
  // Individually reset each motor position.
  leftFront.resetPosition();
  leftMiddle.resetPosition();
  leftBack.resetPosition();
  rightFront.resetPosition();
  rightMiddle.resetPosition();
  rightBack.resetPosition();
  // Individually change each stopping method.
  leftFront.setStopping(brake);
  leftMiddle.setStopping(brake);
  leftBack.setStopping(brake);
  rightFront.setStopping(brake);
  rightMiddle.setStopping(brake);
  rightBack.setStopping(brake);
}

// Function to stop all drivetrain motors.
void stopDrivetrain()
{
  // Individually stop every drivetrain motor.
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
void motorControl(float driveSpeed, float turnSpeed, float deadzone)
{
  // Set the x and y intagers to the position of axis1*turnSpeed and axis3*turnSpeed respectively.
  int x = controller1.Axis1.position(percent)*turnSpeed;
  int y = controller1.Axis3.position(percent)*driveSpeed;

  // Use motion and turning logic based on joystick positions to allow driving while not in the deadzone.
  if (x > deadzone || y > deadzone || x < -deadzone || y < -deadzone) {
    leftFront.spin(reverse, x + y, percent);
    rightFront.spin(forward, -x + y, percent);
    leftBack.spin(reverse, x + y, percent);
    rightBack.spin(forward, -x + y, percent);
    leftMiddle.spin(reverse, x + y, percent);
    rightMiddle.spin(forward, -x + y, percent);
  }
  // If the joysticks are in the deadzone, then stop all drivetrain motors.
  else
  {
    stopDrivetrain();
  }
}