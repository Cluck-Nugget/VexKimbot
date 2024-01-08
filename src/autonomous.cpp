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
void move(float distance, int speed)
{
    // Set variables.
    float range = 1;
    // Reset the drivetrain motor positions.
    resetDrivetrain();
    // Spin the drivetrain in the correct direction.
    driveForward(forward, speed, percent);
    while (true)
    {
        // Stop the drivetrain if it's distance moved the correct distance.
        if (isInRange(calculateDistance(averageAngle(), 4), distance - range/2, distance + range/2))
        {
            stopDrivetrain();
            break;
        }
    }
}