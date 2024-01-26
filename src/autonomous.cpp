// Filename:    autonomous.cpp
// Authors:     Dax DiLallo
// Created:     Dec 07 2023
// Description: The file that holds all autonomous related functions

#include "vex.h"
#include "autonomous.h"
#include "global.h"

void autonInit()
{
    sensor.startCalibration(3000);
    while (sensor.isCalibrating())
    {
        vex::task::sleep(100);
    }
    sensor.resetHeading();
    sensor.resetRotation();

    printf("Init Sensor Heading:%f \n", sensor.heading(degrees));
    vex::task::sleep(1000);
    printf("After Sensor Heading:%f \n", sensor.heading(degrees));
}

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
        vex::task::sleep(10);
    }
}

int debugCount = 0;
void turnDegrees(double angle, double speed)
{
    debugCount = 0;
    // right is positive, left is negative
    double target = sensor.rotation(degrees) + angle;
    if (angle > 0) {
        while (sensor.rotation(degrees) < target) {
            // if (debugCount++ % 20 == 0) {
            //     printf("Right Turn:%f \n", sensor.rotation(degrees));
            // }
            turn(true, speed, percent);
            vex::task::sleep(10);
        }
        printf("Stopped \n");
        stopDrivetrain();
    } else if (angle < 0) {
        while (sensor.rotation(degrees) > target)
        {
            // if (debugCount++ % 20 == 0) {
            //     printf("Left Turn:%f \n", sensor.rotation(degrees));
            // }
            turn(false, speed, percent);
            vex::task::sleep(10);
        }
        printf("Stopped \n");
        stopDrivetrain();
    }
}

void skillsAuton()
{
    move(4, 15);
    turnDegrees(-100, 10);
    move(-2, 30);
    shooter.spin(forward, 95, percent);
}

void auton()
{
    move(-15, 100);
}

void testTurn(double angle, double speed)
{
    double currentRotation = sensor.rotation(degrees);
    turnDegrees(angle, speed);
    vex::task::sleep(1000);
    double afterRotation = sensor.rotation(degrees);
    double error = (currentRotation + angle) - sensor.rotation(degrees);
    printf("Speed:%f Before:%f After:%f Turn Error:%f \n", speed, currentRotation, afterRotation, error);
}

void testAuton()
{
    testTurn(180, 10);
    testTurn(180, 15);
    testTurn(180, 20);
    testTurn(180, 25);
    testTurn(180, 30);
    testTurn(180, 35);
    testTurn(180, 40);
}