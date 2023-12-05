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

bool IsShooterOn;
bool IsIntakeOn;

void init() {
  vexcodeInit();
  Brain.Screen.print("6636A");
  Brain.Screen.newLine();
  Brain.Screen.print("Misto kim!!!");
}

void stopMotors() {
  LeftFront.stop();
  RightFront.stop();
  LeftBack.stop();
  RightBack.stop();
  LeftMiddle.stop();
  RightMiddle.stop();
}

void motorControl() {
  int y = Controller1.Axis3.position(percent);
  int x = Controller1.Axis1.position(percent);

  if (x > 5 || y > 5 || x < -5 || y < -5) {
    LeftFront.spin(forward, x - y, percent);
    RightFront.spin(reverse, -x - y, percent);
    LeftBack.spin(forward, x - y, percent);
    RightBack.spin(reverse, -x - y, percent);
    LeftMiddle.spin(forward, x - y, percent);
    RightMiddle.spin(reverse, -x - y, percent);
  }
  else {
    stopMotors();
  }
}

void intakeControl() {
  if (Controller1.ButtonL1.pressing()) {
    if (!IsIntakeOn == true) {
      Intake.spin(reverse, 90, percent);  
      IsIntakeOn = true;
    }
    else {
      Intake.stop();
      IsIntakeOn = false;
    }
  }
  if (Controller1.ButtonL2.pressing()) {
    if (!IsIntakeOn == true) {
      Intake.spin(forward, 90, percent);  
      IsIntakeOn = true;
    }
    else {
      Intake.stop();
      IsIntakeOn = false;
    }
  }
}

void ShooterControl() {
  if (Controller1.ButtonR1.pressing()) {
    if (!IsShooterOn == true) {
      Shooter.spin(reverse, 90, percent);  
      IsShooterOn = true;
    } 
    else {
      Shooter.stop();
      IsShooterOn = false;
    }
  }
}

int main() {
  init();
  while (true) {
    motorControl();
    intakeControl();
    ShooterControl();
    vex::task::sleep(10);
  }
}
