#include "vex.h"

void init();
void stopDrivetrain();
void resetDrivetrain();
double averageAngle();
float calculateFuturePosition(double inches);
bool isInRange(float number, float min, float max);
void driveForward(directionType direction, int speed, percentUnits speedUnit);