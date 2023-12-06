/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       6366A                                                     */
/*    Created:      Wed Nov 30 2023                                           */
/*    Description:  Misto kim!!!                                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// Function to initialize the bot.
void init()
{
  vexcodeInit();
  // Misto kim!!!!
  brain1.Screen.print("6636A");
  brain1.Screen.newLine();
  brain1.Screen.print("Misto kim!!!");
}

// Function to stop all drivetrain motors.
void stopMotors()
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
    stopMotors();
  }
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
  // Stop the intake if the driver is not holding any buttons.
  else
  {
    intake.stop();
  }
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
  else
  {
    shooter.stop();
  }
}

// Main function that runs when the program starts.
int main()
{
  // Initialize the robot.
  init();
  // Go into main loop that allows you to control all functions of the robot.
  while (true)
  {
    motorControl(1, 1, 5);
    intakeControl(0.9, 0.9);
    shooterControl(0.7);
    task::sleep(10);
  }
  return 0;
}
