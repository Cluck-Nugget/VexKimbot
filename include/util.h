#include <math.h>

// Initialization Functions

void initArray(int arr[], int length);
void initArray(double arr[], int length);

// Dignostics

void resetDraw();
void redraw();
void redraw(double s1, double s2, double s3, double s4, double s5);

// Conversion Functions
//Const ints are set to the values we later use in conversion functions
const double MM_PER_INCH = 25.4;
const double WHEEL_DIAMETER_INCHES = 3.25;
const double WHEEL_DIAMETER_MM = WHEEL_DIAMETER_INCHES * MM_PER_INCH;
const double INCHES_PER_DEGREE = (M_PI * WHEEL_DIAMETER_INCHES) / 360;
const double MM_PER_DEGREE = (M_PI * WHEEL_DIAMETER_MM) / 360;
const double DEGREES_PER_RADIAN = 180 / M_PI;
const double RADIANS_PER_DEGREE = M_PI / 180;

double inchesToDegrees(double inches);
double degreesToInches(double degrees);
double mmToDegrees(double mm);
double degreesToMm(double degrees);
double inchesToMm(double inches);
double mmToInches(double mm);
double degreesToRadians(double deg);
double radiansToDegrees(double rad);

// Settings

enum Team {
  TEAM_RED = 0,
  TEAM_BLUE = 1
};

void setTeam(Team t);
bool isTeamRed();

void setSkills(bool isSkills);
bool isSkills();

// Range Functions

bool inRange(double value, double min, double max);
double clip(double value, double min, double max);
double smartClip(double value, double min, double max);
double clipAngle(double angle);
double clipAngle180(double angle);

// Sensors

bool isBallLoading();
bool isBallLoaded();
void updateInertialRotation();
double getInertialRotation();
double getInertialHeading();
double getInertialGyroRate();

// Emipirical Formulas

double getShootingSpeedForVoltage(double v);
double getVoltageForShootingSpeed(double s);

double getLhsDrivingSpeedForVoltage(double v);
double getRhsDrivingSpeedForVoltage(double v);

double getLhsVoltageForDrivingSpeed(double s);
double getRhsVoltageForDrivingSpeed(double s);

double getLhsRightTurnSpeedForVoltage(double v);
double getLhsLeftTurnSpeedForVoltage(double v);
double getRhsRightTurnSpeedForVoltage(double v);
double getRhsLeftTurnSpeedForVoltage(double v);

double getLhsVoltageForRightTurnSpeed(double s);
double getLhsVoltageForLeftTurnSpeed(double s);
double getRhsVoltageForRightTurnSpeed(double s);
double getRhsVoltageForLeftTurnSpeed(double s);
