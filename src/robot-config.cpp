#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  brain1;

// VEXcode device constructors
motor leftFront = motor(PORT1, ratio6_1, false);
motor leftMiddle = motor(PORT9, ratio6_1, false);
motor leftBack = motor(PORT10, ratio6_1, false);
motor rightFront = motor(PORT8, ratio6_1, false);
motor rightMiddle = motor(PORT2, ratio6_1, false);
motor rightBack = motor(PORT3, ratio6_1, false);
motor intake = motor(PORT20, ratio18_1, false);
controller controller1 = controller(primary);
motor shooter = motor(PORT5, ratio36_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}