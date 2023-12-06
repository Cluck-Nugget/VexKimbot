/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       6366A                                                     */
/*    Created:      Wed Nov 02 2022                                           */
/*    Description:  Misto kim!!!                                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// Function to initialize the bot
void init()
{
  vexcodeInit();
  brain1.Screen.print("6636A");
  brain1.Screen.newLine();
  brain1.Screen.print("Misto kim!!!");
}

// Function to stop all motors
void stopMotors()
{
  leftFront.stop();
  rightFront.stop();
  leftBack.stop();
  rightBack.stop();
  leftMiddle.stop();
  rightMiddle.stop();
}

// Function to be able to control the drivetrain
void motorControl()
{
  int y = controller1.Axis3.position(percent);
  int x = controller1.Axis1.position(percent);

  if (x > 5 || y > 5 || x < -5 || y < -5) {
    leftFront.spin(forward, x - y, percent);
    rightFront.spin(reverse, -x - y, percent);
    leftBack.spin(forward, x - y, percent);
    rightBack.spin(reverse, -x - y, percent);
    leftMiddle.spin(forward, x - y, percent);
    rightMiddle.spin(reverse, -x - y, percent);
  }
  else
  {
    stopMotors();
  }
}

// Function to be able to control the intake
void intakeControl()
{
  if (controller1.ButtonL1.pressing() && !intake.isSpinning())
  {
    intake.spin(reverse, 90, percent);
  }
  else if (controller1.ButtonL2.pressing() && !intake.isSpinning())
  {
    intake.spin(forward, 90, percent);
  }
  else
  {
    intake.stop();
  }
}

// Function to be able to control the shooter
void shooterControl()
{
  if (controller1.ButtonR1.pressing() && !shooter.isSpinning())
  {
    shooter.spin(forward, 90, percent);  
  }
  else
  {
    shooter.stop();
  }
}

// Main function that is run when the program starts
int main()
{
  init();
  while (true)
  {
    motorControl();
    intakeControl();
    shooterControl();
    task::sleep(10);
  }
}
