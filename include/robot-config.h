using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontLeft;
extern motor FrontRight;
extern motor RearLeft;
extern motor RearRight;
extern controller Controller1;
extern motor MidLeft;
extern motor MidRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );