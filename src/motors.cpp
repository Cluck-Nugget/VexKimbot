#include <string>
#include "vex.h"
#include "motors.h"

void displayMotorStats(vex::motor m, std::string label) {
  printf("%s: temp:%f  torque:%f power:%f volt:%f curr:%f efficiency:%f\n",
      label.c_str(), m.temperature(celsius), m.torque(InLb), m.power(watt), m.voltage(volt), m.current(amp), m.efficiency(percent));
}

void displayAllMotorStats() {
  displayMotorStats(RightFront, "Right Front");
  displayMotorStats(RightMiddle, "Right Middle");
  displayMotorStats(RightBack, "Right Back");
  displayMotorStats(LeftFront, "Left Front");
  displayMotorStats(LeftMiddle, "Left Middle");
  displayMotorStats(LeftBack, "Left Back");
  displayMotorStats(Intake, "Intake");
//  displayMotorStats(Shooter, "Shooter");
}

void setDrivingBrakeType(vex::brakeType mode) {
  RightFront.setStopping(mode);
  RightMiddle.setStopping(mode);
  RightBack.setStopping(mode);
  LeftFront.setStopping(mode);
  LeftMiddle.setStopping(mode);
  LeftBack.setStopping(mode);
}

void initMotors() {
  setDrivingBrakeType(brake);
  Intake.setStopping(brake);
  Shooter.setStopping(brake);

  RightFront.setPosition(0, degrees);
  RightMiddle.setPosition(0, degrees);
  RightBack.setPosition(0, degrees);
  LeftFront.setPosition(0, degrees);
  LeftMiddle.setPosition(0, degrees);
  LeftBack.setPosition(0, degrees);
  Intake.setPosition(0, degrees);
  Shooter.setPosition(0, degrees);
}

double motorPosition() {
  return LeftMiddle.position(degrees);
}

double motorSpeed() {
  return LeftMiddle.velocity(dps);
}

void rawDriveVoltage(double x, double y, bool isReverse) {
  if (isReverse) {
    double left = -x + y;
    double right = x + y;
    rawTankDriveVoltage(left, right);
  } else {
    double left = x + y;
    double right = -x + y;
    rawTankDriveVoltage(left, right);
  }
}

void rawTankDriveVoltage(double lhs, double rhs) {
  LeftFront.spin(reverse, lhs, volt);
  LeftBack.spin(reverse, lhs, volt);
  LeftMiddle.spin(reverse, lhs, volt);
  RightFront.spin(forward, rhs, volt);
  RightBack.spin(forward, rhs, volt);
  RightMiddle.spin(forward, rhs, volt);
}

void normalizedDrive(double x, double y) {
  x = x < 0 ? (x * -x / 100) : (x * x / 100);
  y = y < 0 ? (y * -y / 100) : (y * y / 100);
  double left = x + y;
  double right = -x + y;
  LeftFront.spin(reverse, left, percent);
  LeftBack.spin(reverse, left, percent);
  LeftMiddle.spin(reverse, left, percent);
  RightFront.spin(forward, right, percent);
  RightBack.spin(forward, right, percent);
  RightMiddle.spin(forward, right, percent);
}

void stopDriving(){
  LeftFront.stop();
  LeftMiddle.stop();
  LeftBack.stop();
  RightFront.stop();
  RightMiddle.stop();
  RightBack.stop();
}


// Find highest voltage through testing
const double intakeVoltage = 10;
const double intakeReverseVoltage = 10;
int intakeState = 0;
double lastIntakePosition = 0;
double intakeStallCount = 0;

void intakeOn() {
  Intake.spin(forward, intakeVoltage, volt);
  intakeState = 1;
  lastIntakePosition = Intake.position(degrees);
}

void intakeOff() {
  Intake.stop(brake);
  intakeState = 0;
}

void intakeReverse() {
  Intake.spin(reverse, intakeReverseVoltage, volt);
  intakeState = -1;
  lastIntakePosition = Intake.position(degrees);
}

bool isIntakeOn() {
  return intakeState == 1;
}

bool isIntakeOff() {
  return intakeState == 0;
}

bool isIntakeReverse() {
  return intakeState == -1;
}
