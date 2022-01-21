#define maxTurnSpeed 1.0f //The maximum speed the robot can turn
#define maxMoveSpeed 1.0f //The maximum speed the robot can move
#define approachSpeedPercent 0.1f //The percentage to increment robot speed by

#define distanceType 1 //The way distance is calculated. Use 0 for centimeters and 1 for inches
#define distanceRefreshRate 0 //Time in seconds in between each distance calculation. Set to 0 for none.

#define INTAKE_SPEED -0.45

// Joystick Controls:

//Gyro Controls
#define CalibrateGyro 8 //Button to calibrate the gyro
#define ResetGyro 1

//Micellaneous
#define ResetTeleopTimer 7
#define FieldCentricControl 2 //changes between field-centric and robot-centric mode while in tele-op mode
#define FieldCentricToggle false //whether or not FieldCentricControl toggles the centric mode

#define MoveFast 1
#define ShowOff 10

//Intake Controls
#define IntakePushControl 3
#define IntakePullControl 1