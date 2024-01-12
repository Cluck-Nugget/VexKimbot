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

// Gearing is 60:36 200 RMP motors

// Documentation:

// First value: The amount of inches.
float calculateFuturePosition(double inches)
{
  // Calculate the position.
  return rightFront.position(degrees) + (inches*58);
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

void turn(bool isRight, double speed, percentUnits speedUnit)
{
  if (isRight)
  {
    rightFront.spin(reverse, speed, speedUnit);
    rightMiddle.spin(reverse, speed, speedUnit);
    rightBack.spin(reverse, speed, speedUnit);
    leftFront.spin(forward, speed, speedUnit);
    leftMiddle.spin(forward, speed, speedUnit);
    leftBack.spin(forward, speed, speedUnit);
  }
  else
  {
    rightFront.spin(forward, speed, speedUnit);
    rightMiddle.spin(forward, speed, speedUnit);
    rightBack.spin(forward, speed, speedUnit);
    leftFront.spin(reverse, speed, speedUnit);
    leftMiddle.spin(reverse, speed, speedUnit);
    leftBack.spin(reverse, speed, speedUnit);
  }
}