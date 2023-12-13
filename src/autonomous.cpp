// Filename:    autonomous.cpp
// Authors:     Dax DiLallo
// Created:     Dec 07 2023
// Description: The file that holds all autonomous related functions

#include "vex.h"
#include "autonomous.h"
#include "global.h"

// Documentation:

// First value: Should be inbetween -100 and 100.
// Second value: The distance that the drivetrain should move in inches.
void move(int speed, float distance)
{
    // Set variables.
    float range = 1;
    directionType isReverse;

    // Reset the drivetrain motor positions.
    resetDrivetrain();
    // Set the isReverse property appropriately.
    if (distance > 0)
    {
        isReverse = forward;
    }
    else
    {
        isReverse = reverse;
    }
    spinDrivetrain(isReverse, speed, percent);
    while (true)
    {
        if (isInRange(calculateDistance(averageAngle(), 4), distance - range/2, distance + range/2))
        {
            stopDrivetrain();
            break;
        }
    }
}
