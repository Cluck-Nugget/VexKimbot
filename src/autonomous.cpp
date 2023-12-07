#include "vex.h"
#include "autonomous.h"

// Function to calculate distance based on wheel angle.

// DOCUMENTATION:
// First value: Should be a number that is the angle of the wheel.
// Second value: The diameter of the wheel.
float calculateDistance(double angle, float diameter)
{
    // Calculate the radius from the diameter.
    float radius = diameter/2;
    // Return the distance.
    return (((radius*radius)*M_PI)/360)*angle;
}



