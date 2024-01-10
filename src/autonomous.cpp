// Filename:    autonomous.cpp
// Authors:     Dax DiLallo
// Created:     Dec 07 2023
// Description: The file that holds all autonomous related functions

#include "vex.h"
#include "autonomous.h"
#include "global.h"

void move(double inches, double speed)
{
    driveForward(forward, speed, percent);
    while (rightFront.position(degrees) < calculateFuturePosition(inches))
    {
        if (rightFront.isSpinning())
        {
            driveForward(forward, speed, percent);
        }
    }
}