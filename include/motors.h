#include <string>
#include "vex.h"

void displayMotorStats(vex::motor m, std::string label);
void displayAllMotorStats();
void setDrivingBrakeType(vex::brakeType mode);

void initMotors();
double motorPosition();
double motorSpeed();

void intakeOn();
void intakeOff();
void intakeReverse();
bool isIntakeStuck();

bool isIntakeOn();
bool isIntakeOff();
bool isIntakeReverse();

void raiseBlocker();
void lowerBlocker();
void stopBlocker();
void moveBlocker(double position);
void updateBlocker();

void rawDriveVoltage(double x, double y, bool isReverse);
void rawTankDriveVoltage(double lhs, double rhs);
void normalizedDrive(double x, double y);
void stopDriving();
