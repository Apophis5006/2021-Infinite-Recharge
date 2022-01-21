int TeleStarted=1;
double Travel;
int UseYTravel;
//Realtime values of robot status
bool FieldCentric = true;   //determines if robot drives in field-centric mode
float RobotAngle = 0.0f; //angle from Gyro
int UpdateCount = 0;    //counter to slow screen update so it does not take too many CPU cycles

//Robot Speed
float turnSpeedPercent; //Percentage of total turn speed
float moveSpeedPercent; //Percentage of total move speed
float speedPercent = 0.0f; //Percentage of robot speed

float speedIncrement = 0.1f; //Variable used for incrementing the robot speed each iteration

// Robot Distance Calculate
double distanceValue;
double distanceTime;

//Robot MoveMode
int MoveMode = -1; //The way the robot is moving. -1 = disabled, 0 = idle, 1 = direction, 2 = rotation, 3 = direction & rotation
float currentSpeed = 0;
float previousSpeed = 0;

/*Multiplier for pushing the robot past it's max speed limit.
Should not be set above 1 for long durations of time.

Default Value: 1*/
float specialSpeed = 1;

//Iteration Time
frc::Timer IterationTimer; //seconds timer for each iteration
double lastTime = IterationTimer.GetFPGATimestamp(); //what the iteration time was last

/*int VoltageHigh =0;
int VoltageLow =0;
int Ballcount =0;*/

//Swerve Control variables  RR, FR, FL, RL
float SpeedPolarity[4] = {1.0,1.0,1.0,1.0}; //which way is forward on wheels (switches to speed up swerve rotations)
float ActDir[4] = {0.0,0.0,0.0,0.0};        //storage for actual angles of wheel from motor controller encoder feedback
float ZeroDir[4] = {141,-137,-117,91};  //{141,-137,-117,25} //change when changing swerve drive    //storage for adjustment of actual angles of wheel from motor controller encoder feedback
float TargetDir[4] = {0.0,0.0,0.0,0.0};     //target degrees of each wheel
float ModDir[4] = {0.0,0.0,0.0,0.0};        //rotational modification degrees of each wheel to adjust target
float ModSpd[4] = {0.0,0.0,0.0,0.0};        //speed modification degrees of each wheel to adjust target
double SWRVY;							  //Swerve Control Variable--Represents Y coordinate of drive joystick
double SWRVX;                             //Swerve Control Variable--Represents X coordinate of drive joystick
double SWRVZ;                             //Swerve Control Variable--Represents X coordinate of rotate joystick
float delta = 0.0f;                         //local variable for determining best way(least delta degrees) to meet rotatioanl target

//Auto Pilot variables
float TargetAngle;
float CurrentAngle;
float RotPwr;
int AutoLine = 0;
double RobotX[4] = {0.0,0.0,0.0,0.0};
double RobotY[4] = {0.0,0.0,0.0,0.0};
double AutoDriveX, AutoDriveY, AutoDriveZ;
bool FirstPass = true;