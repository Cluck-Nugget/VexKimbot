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

  Brain.Screen.print("3363A");
  Brain.Screen.newLine();
  Brain.Screen.print("men");
  
   

  while (true) {
    int y = Controller1.Axis3.position(percent);
    int x = Controller1.Axis1.position(percent);

    if (x > 5 || y > 5 || x < -5 || y < -5) {
      FrontLeft.spin(reverse, x + -y, percent);
      FrontRight.spin(forward, -x + -y, percent);
      RearLeft.spin(reverse, x + -y, percent);
      RearRight.spin(forward, -x + -y, percent);
      MidLeft.spin(reverse, x + -y, percent);
      MidRight.spin(forward, -x + -y, percent);
    } else {
      FrontLeft.stop();
      FrontRight.stop();
      RearLeft.stop();
      RearRight.stop();
      MidLeft.stop();
      MidRight.stop();
    }
  }
}
