#include "vex.h"
#include "global.h"
#include "autonomous.h"
#include "drivetrain.h"
#include "intake.h"
#include "shooter.h"

// Function to initialize the bot.
void init()
{
  vexcodeInit();
  drivetrainInit();
  intakeInit();
  shooterInit();
}

// Function to stop all drivetrain motors.
void stopDrivetrain()
{
  leftFront.stop();
  rightFront.stop();
  leftBack.stop();
  rightBack.stop();
  leftMiddle.stop();
  rightMiddle.stop();
}

// Function to reset the position of the wheels.
void resetDrivetrain()
{
  leftFront.resetPosition();
  leftMiddle.resetPosition();
  leftBack.resetPosition();
  rightFront.resetPosition();
  rightMiddle.resetPosition();
  rightBack.resetPosition();
}

// Function to find the average angle of all of the wheels.
double averageAngle()
{
    double rf = rightFront.position(degrees);
    double rm = rightMiddle.position(degrees);
    double rb = rightBack.position(degrees);
    double lf = leftFront.position(degrees);
    double lm = leftMiddle.position(degrees);
    double lb = leftBack.position(degrees);

    // Return average angle.
    return (rf + rm + rb + lf + lm +lb)/6;
}

// Documentation:

// First value: Should be a number that is the angle of the wheel.
// Second value: The diameter of the wheel.
float calculateDistance(double angle, float diameter)
{
    // Calculate the radius from the diameter.
    float radius = diameter/2;
    double circumfrance = (2*M_PI)*radius;
    // Return the distance in inches.
    return (circumfrance/360)*angle;
}

// Function to check if a value is in a range.

// Documentation:

// First value: The number.
// Second value: Minimum.
// Third value: Maximum.
bool isInRange(float number, float min, float max)
{
  if (number < max && number > min)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Function to spin all drivetrain wheels.

// Documentation:

// First value: The direction (forward or reverse).
// Second value: The speed (depends of value 3).
// Third value: The unit of speed.
void driveForward(directionType direction, int speed, percentUnits speedUnit)
{
  rightFront.spin(direction, speed, speedUnit);
  rightMiddle.spin(direction, speed, speedUnit);
  rightBack.spin(direction, speed, speedUnit);
  leftFront.spin(direction, speed, speedUnit);
  leftMiddle.spin(direction, speed, speedUnit);
  leftBack.spin(direction, speed, speedUnit);
}