#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// Gearing is 60:36 200 RMP motors

// A global instance of brain used for printing to the V5 Brain screen
brain  brain1;

// VEXcode device constructors
motor leftFront = motor(PORT15, ratio18_1, true);
motor leftMiddle = motor(PORT14, ratio18_1, true);
motor leftBack = motor(PORT18, ratio18_1, true);
motor rightFront = motor(PORT16, ratio18_1, false);
motor rightMiddle = motor(PORT17, ratio18_1, false);
motor rightBack = motor(PORT19, ratio18_1, false);
motor intake = motor(PORT20, ratio18_1, false);
controller controller1 = controller(primary);
motor shooter = motor(PORT6, ratio18_1, false);
inertial sensor = inertial(PORT3);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = false;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}