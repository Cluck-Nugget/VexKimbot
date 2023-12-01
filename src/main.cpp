/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pmp                                                       */
/*    Created:      Wed Nov 02 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         10              
// FrontRight           motor         1               
// RearLeft             motor         8               
// RearRight            motor         3               
// Controller1          controller                    
// MidLeft              motor         9               
// MidRight             motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Print Messages on the Robot Brain
  Brain.Screen.print("6636A");
  Brain.Screen.newLine();
  Brain.Screen.print("Misto kim!!!");
  
  while (true) {
    int y = Controller1.Axis3.position(percent);
    int x = Controller1.Axis1.position(percent);

    if (x > 5 || y > 5 || x < -5 || y < -5) {
      LeftFront.spin(reverse, x + -y, percent);
      RightFront.spin(forward, -x + -y, percent);
      LeftBack.spin(reverse, x + -y, percent);
      RightBack.spin(forward, -x + -y, percent);
      LeftMiddle.spin(reverse, x + -y, percent);
      RightMiddle.spin(forward, -x + -y, percent);
    } else {
      LeftFront.stop();
      RightFront.stop();
      LeftBack.stop();
      RightBack.stop();
      LeftMiddle.stop();
      RightMiddle.stop();
    }
  }
}
