#include"vex.h"
#include "util.h"

// Initialization Functions

void initArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = 0;
  }
}

void initArray(double arr[], int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = 0;
  }
}

// Conversion Functions
// Functions allow us to more easily make conversions in other functions accurately 
// by organizing the conversion values to their units

double inchesToDegrees(double inches) {
  return inches / INCHES_PER_DEGREE;
}

double degreesToInches(double degrees) {
  return degrees * INCHES_PER_DEGREE;
}

double mmToDegrees(double mm) {
  return mm / MM_PER_DEGREE;
}

double degreesToMm(double degrees) {
  return degrees * MM_PER_DEGREE;
}

double inchesToMm(double inches) {
  return inches * MM_PER_INCH;
}

double mmToInches(double mm) {
  return mm / MM_PER_INCH;
}

double degreesToRadians(double deg) {
  return deg * RADIANS_PER_DEGREE;
}

double radiansToDegrees(double rad) {
  return rad * DEGREES_PER_RADIAN;
}

// Range Functions

bool inRange(double value, double min, double max) {
  return value >= min && value <= max;
}

double clip(double value, double min, double max) {
  if (value > max) {
    return max;
  }
  if (value < min) {
    return min;
  }
  return value;
}

double smartClip(double value, double min, double max) {
  // Assume that all 3 numbers should be positive or all 3 should be negative.
  if (value < 0 && min >= 0 && max >= 0) {
    if (min < max) {
      double temp = min;
      min = -max;
      max = -temp;
    } else {
      min = -min;
      max = -max;
    }
  }
  return clip(value, min, max);
}

double subPos(double number, int cutoff, int increment) {
  while (number >= cutoff) {
    number -= increment;
  }
  return number;
}

double subNeg(double number, int cutoff, int increment) {
  while (number <= cutoff) {
    number += increment;
  }
  return number;
}

double clipAngle(double angle) {
  if (angle > 0) {
    angle = subPos(angle, 3600000, 3600000);
    angle = subPos(angle, 360000, 360000);
    angle = subPos(angle, 36000, 36000);
    angle = subPos(angle, 3600, 3600);
    return subPos(angle, 360, 360);
  }
  angle = subNeg(angle, -3600000, 3600000);
  angle = subNeg(angle, -360000, 360000);
  angle = subNeg(angle, -36000, 36000);
  angle = subNeg(angle, -3600, 3600);
  return subNeg(angle, -1, 360);
}

double clipAngle180(double angle) {
  angle = clipAngle(angle);
  if (angle > 180) {
    angle -= 360;
  } else if (angle <= -180) {
    angle += 360;
  }
  return angle;
}

// Settings

Team team;
void setTeam(Team t) {
  team = t;
  printf("TEAM CHANGED TO: %s\n", team == TEAM_RED ? "RED" : "BLUE");
}
bool isTeamRed() {
  return team == TEAM_RED;
}

bool skillsSetting;
void setSkills(bool isSkills) {
  skillsSetting = isSkills;
  printf("SKILLS CHANGED TO: %s\n", skillsSetting ? "TRUE" : "FALSE");
}
bool isSkills() {
  return skillsSetting;
}

double getShootingSpeedForVoltage(double v) {
  return (111.802 * v) - 7.35025;
  //return (86.0754 * v) + 95.7337;

//return (-4.99523 * v * v) + (178.597 * v) - 253.3;
//  return (117.812 * v) - 83.9139;
//  return (109.3 * v) - 147.016;
}

double getVoltageForShootingSpeed(double s) {
  return (0.0095522 * s) - 0.32462;
//  return (0.0113564 * s) - 0.920724;
//  return (0.0000041653 * s * s) + (0.00312555 * s) + 2.29198;
//  return (0.00848434 * s) + 0.715019;
//  return (0.00914696 * s) + 1.34659;
}

double getLhsDrivingSpeedForVoltage(double v) {
  return (349.973 * v) - 242.16;
//  return (349.384 * v) - 260.452;
}
double getRhsDrivingSpeedForVoltage(double v) {
  return (349.973 * v) - 242.16;
//  return (349.384 * v) - 260.452;
}

double getLhsVoltageForDrivingSpeed(double s) {
  return (0.0028561 * s) + 0.693624;
//  return (0.00286069 * s) + 0.747936;
}
double getRhsVoltageForDrivingSpeed(double s) {
  return (0.0028561 * s) + 0.693624;
//  return (0.00286069 * s) + 0.747936;
}

double getLhsRightTurnSpeedForVoltage(double v) {
  return (49.9969 * v) - 38.7549;
}
double getRhsRightTurnSpeedForVoltage(double v) {
  return (49.9969 * v) - 38.7549;
}
double getLhsLeftTurnSpeedForVoltage(double v) {
  return (49.1885 * v) - 48.2597;
}
double getRhsLeftTurnSpeedForVoltage(double v) {
  return (49.1885 * v) - 48.2597;
}

double getLhsVoltageForRightTurnSpeed(double s) {
  return (0.0199614 * s) + 0.787557;
}
double getRhsVoltageForRightTurnSpeed(double s) {
  return (0.0199614 * s) + 0.787557;
}
double getLhsVoltageForLeftTurnSpeed(double s) {
  return (0.0202583 * s) + 1.00233;
}
double getRhsVoltageForLeftTurnSpeed(double s) {
  return (0.0202583 * s) + 1.00233;
}


const int seriesMax = 272;
const int seriesLen = 480;
int seriesIdx = 0;
double series1[seriesLen];
double series2[seriesLen];
double series3[seriesLen];
double series4[seriesLen];
double series5[seriesLen];

// vex v5 brain screen size: 480 x 272

void resetDraw() {
  seriesIdx = 0;
}

void redraw(double series[], int startIdx, vex::color c) {
  Brain.Screen.setPenColor(c);
  int endIdx = (seriesIdx < seriesLen) ? (startIdx + seriesIdx - 2) : (startIdx + seriesLen - 2);
  int column = 0;
  for (int i = startIdx; i < endIdx; i++) {
    Brain.Screen.drawLine(
      column, seriesMax - (int) (seriesMax * series[i % seriesLen]),
      column + 1, seriesMax - (int) (seriesMax * series[(i + 1) % seriesLen]));
    column++;
  }
}

void redraw() {
  Brain.Screen.clearScreen();
  int startIdx = (seriesIdx < seriesLen) ? 0 : seriesIdx;
  redraw(series1, startIdx, vex::color::yellow);
  redraw(series2, startIdx, vex::color::red);
  redraw(series3, startIdx, vex::color::green);
  redraw(series4, startIdx, vex::color::white);
  redraw(series5, startIdx, vex::color::cyan);
}

void redraw(double s1, double s2, double s3, double s4, double s5) {
  series1[seriesIdx % seriesLen] = s1;
  series2[seriesIdx % seriesLen] = s2;
  series3[seriesIdx % seriesLen] = s3;
  series4[seriesIdx % seriesLen] = s4;
  series5[seriesIdx % seriesLen] = s5;
  seriesIdx++;
  //redraw();
}
