// Filename:    autonomous.cpp
// Authors:     Dax DiLallo
// Created:     Dec 07 2023
// Description: The file that holds all autonomous related functions

#include "vex.h"
#include "autonomous.h"
#include "global.h"

void move(double inches, double speed)
{
    double futurePosition = calculateFuturePosition(inches);
    while (true)
    {
        if (inches > 0)
        {
            driveForward(forward, speed, percent);
            if (rightFront.position(degrees) >= futurePosition)
            {
                stopDrivetrain();
                break;
            }
        }
        else
        {
            driveForward(reverse, speed, percent);
            if (rightFront.position(degrees) <= futurePosition)
            {
                stopDrivetrain();
                break;
            } 
        }
    }
}

void turnDegrees(double angle, double speed) {
    // right is positive, left is negative
    double target = sensor.rotation(degrees) + angle;
    if (angle > 0) {
        while (sensor.rotation(degrees) < target) {
            turn(true, speed, percent);
        }
        stopDrivetrain();
    } else if (angle < 0) {
        while (sensor.rotation(degrees) > target)
        {
            turn(false, speed, percent);
        }
        stopDrivetrain;
    }
}

void turnTo(double angle, double speed)
{
    while (true)
    {
        if (sensor.rotation(degrees) < angle)
        {
            turn(true, speed, percent);
            if (sensor.rotation(degrees) <= angle)
            {
                stopDrivetrain();
                break;
            }
        }
        else
        {
            turn(false, speed, percent);
            if (sensor.rotation(degrees) >= angle)
            {
                stopDrivetrain();
                break;
            }
        }
    }
}

void auton()
{
    move(20, 50);
    move(-20, 50);
    turnDegrees(90, 50);
    turnDegrees(-90, 50);
}