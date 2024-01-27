// Filename:    drivetrain.cpp
// Authors:     Dax DiLallo, Matthew Pak
// Created:     Dec 05 2023
// Description: The file that holds all drivetrain related functions


#include "vex.h"
#include "drivetrain.h"
#include "global.h"

// Function to set all drivetrain motor stopping methods.
void drivetrainInit()
{
  // Individually reset each motor position.
  resetDrivetrain();
  // Individually change each stopping method.
  leftFront.setStopping(brake);
  leftMiddle.setStopping(brake);
  leftBack.setStopping(brake);
  rightFront.setStopping(brake);
  rightMiddle.setStopping(brake);
  rightBack.setStopping(brake);
}

// Function to control the drivetrain.

/*
Documentation:

First value: Should be inbetween 0 and 1 to represent drive speed.
Second value: Should be inbetween 0 and 1 to represent turn speed.
Third value: Should be inbetween 0 and 100 to represent the deadzone in percent.
*/
void motorControl(float driveSpeed, float turnSpeed, float deadzone)
{
  // Set the x and y intagers to the position of axis1*turnSpeed and axis3*turnSpeed respectively.
  int axisX = controller1.Axis1.position(percent)*turnSpeed;
  int axisY = controller1.Axis3.position(percent)*driveSpeed;

  // Use motion and turning logic based on joystick positions to allow driving while not in the deadzone.
  if (axisX > deadzone || axisY > deadzone || axisX < -deadzone || axisY < -deadzone)
  {
    leftFront.spin(forward, axisX + axisY, percent);
    rightFront.spin(forward, -axisX + axisY, percent);
    leftBack.spin(forward, axisX + axisY, percent);
    rightBack.spin(forward, -axisX + axisY, percent);
    leftMiddle.spin(forward, axisX + axisY, percent);
    rightMiddle.spin(forward, -axisX + axisY, percent);
  }
  // If the joysticks are in the deadzone, then stop all drivetrain motors.
  else
  {
    stopDrivetrain();
  }
}