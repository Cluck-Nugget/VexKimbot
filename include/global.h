#include "vex.h"

void init();
void stopDrivetrain();
void resetDrivetrain();
double averageAngle();
float calculateDistance(double angle, float diameter);
bool isInRange(float number, float min, float max);
void spinDrivetrain(directionType direction, int speed, percentUnits speedUnit);