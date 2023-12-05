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

bool isShooterOn;
bool isIntakeOn;

void init() {
  vexcodeInit();
  brain1.Screen.print("6636A");
  brain1.Screen.newLine();
  brain1.Screen.print("Misto kim!!!");
}

void stopMotors() {
  leftFront.stop();
  rightFront.stop();
  leftBack.stop();
  rightBack.stop();
  leftMiddle.stop();
  rightMiddle.stop();
}

void motorControl() {
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
  else {
    stopMotors();
  }
}

void intakeControl() {
  if (controller1.ButtonL1.pressing()) {
    if (!isIntakeOn == true) {
      intake.spin(reverse, 90, percent);  
      isIntakeOn = true;
    }
    else {
      intake.stop();
      isIntakeOn = false;
    }
  }
  if (controller1.ButtonL2.pressing()) {
    if (!isIntakeOn == true) {
      intake.spin(forward, 90, percent);  
      isIntakeOn = true;
    }
    else {
      intake.stop();
      isIntakeOn = false;
    }
  }
}

void shooterControl() {
  if (controller1.ButtonR1.pressing()) {
    if (!isShooterOn == true) {
      shooter.spin(reverse, 90, percent);  
      isShooterOn = true;
    } 
    else {
      shooter.stop();
      isShooterOn = false;
    }
  }
}

int main() {
  init();
  while (true) {
    motorControl();
    intakeControl();
    shooterControl();
    vex::task::sleep(10);
  }
}
