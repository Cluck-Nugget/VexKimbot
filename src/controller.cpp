#include "controller.h"
#include "vex.h"
#include "motors.h"


void drivecontrol(void) {
  printf("Enabling usercontrol\n");
  setDrivingBrakeType(brake);

  while (true) {
    int x = Controller1.Axis1.position(percent);
    int y = Controller1.Axis3.position(percent);
    if (x > 5 || x < -5 || y > 5 || y < -5) {
      normalizedDrive(x, y);
    } else {
      stopDriving();
    }

    long time = vex::timer::system();

    // Intake: R1 & R2
    if (Controller1.ButtonR1.pressing()) {
      intakeOn();
    } else if (Controller1.ButtonR2.pressing()) {
      intakeReverse();
    } else {
      intakeOff();
    }
    vex::task::sleep(10);
  }
}

void auton() {
}
