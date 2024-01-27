// Filename:    autonomous.cpp
// Authors:     Dax DiLallo
// Created:     Dec 07 2023
// Description: The file that holds all autonomous related functions

#include "vex.h"
#include "autonomous.h"
#include "global.h"

// Initializes auton.
void autonInit()
{
    // Calibrate the inertial sensor.
    sensor.startCalibration(3000);
    while (sensor.isCalibrating())
    {
        vex::task::sleep(100);
    }

    // Reset the sensor rotation and heading.
    sensor.resetHeading();
    sensor.resetRotation();

    // Print the sensor error.
    printf("Init Sensor Heading:%f \n", sensor.heading(degrees));
    vex::task::sleep(1000);
    printf("After Sensor Heading:%f \n", sensor.heading(degrees));
}

// The function to move the drivetrain a specific amount of inches.

/*
Documentation:

First value: The amount of inches to move. Use negative to go reverse.
Second value: The speed in percent to move at.
*/
void move(double inches, double speed)
{
    double futurePosition = calculateFuturePosition(inches);
    while (true)
    {
        // Move forward until a wheel is at the right angle.
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

// Function to turn a specific amount of degrees.

/*
Documentation:

First value: The amount of degrees to turn. Use negative to go left.
Second value: The speed to turn at.
*/
void turnDegrees(double angle, double speed)
{
    double target = sensor.rotation(degrees) + angle;
    // Turn the robot until at the right angle.
    if (angle > 0)
    {
        while (sensor.rotation(degrees) < target)
        {
            turn(true, speed, percent);
            vex::task::sleep(10);
        }
        printf("Stopped \n");
        stopDrivetrain();
    }
    else if (angle < 0)
    {
        while (sensor.rotation(degrees) > target)
        {
            turn(false, speed, percent);
            vex::task::sleep(10);
        }
        printf("Stopped \n");
        stopDrivetrain();
    }
}

// Skills auton function.
void skillsAuton()
{
    printf("Running Skills\n");
    move(4, 15);
    turnDegrees(-100, 10);
    move(-2, 30);
    shooter.spin(forward, 95, percent);
}

// Normal auton function.
void auton()
{
    printf("Running Auton\n");
    move(-15, 100);
}

// Function to test turn error at differen speeds.
void testTurn(double angle, double speed)
{
    double currentRotation = sensor.rotation(degrees);
    turnDegrees(angle, speed);
    vex::task::sleep(1000);
    double afterRotation = sensor.rotation(degrees);
    double error = (currentRotation + angle) - sensor.rotation(degrees);
    printf("Speed:%f Before:%f After:%f Turn Error:%f \n", speed, currentRotation, afterRotation, error);
}


// Function to find the best speed with the least error.
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