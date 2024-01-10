// Filename:    autonomous.cpp
// Authors:     Dax DiLallo
// Created:     Dec 07 2023
// Description: The file that holds all autonomous related functions

#include "vex.h"
#include "autonomous.h"
#include "global.h"

void move(double inches, double speed)
{
    while (true)
    {
        if (inches > 0)
        {
            driveForward(forward, speed, percent);
            if (rightFront.position(degrees) > calculateFuturePosition(inches))
            {
                stopDrivetrain();
                break;
            }
        }
        else
        {
            driveForward(reverse, speed, percent);
            if (rightFront.position(degrees) < calculateFuturePosition(inches))
            {
                stopDrivetrain();
                break;
            } 
        }
        
    }
}