

//removing the extern for the vars apparently fixed it

frc::ADIS16448_IMU Gyro{}; //expansion port gyro

//Updates RobotAngle to current gyro angle
void ReadGyro() {
	RobotAngle = Gyro.GetAngle();
}

/*
Returns the time passed (in seconds) since the last iteration
@param iterationsPerSecond multiplier for the amount of iterations a second
@return the time since the last iteration adjusted for the amount of iterations a second
*/
double GetIterationTime(const int iterationsPerSecond = 1) {
	double currentTime = IterationTimer.GetFPGATimestamp();
	double periodPassed = (currentTime-lastTime);
	
	lastTime = currentTime;

	return periodPassed*iterationsPerSecond;
}

//Get the current values for autonomous mode variables
std::tuple<int, int, int, int, int, int, int, int, double, double, double, double, double> GetAutonomousValues(int *Array, double time) {// Variables returned: Command, Speed, Orientation, AccSec, AutoX, AutoY, RemainingInches, MaxPower, DeltaA, X, Y, Z
	int MaxFromDcel, MaxFromAcel, DecInches, AccSec, RemainingInches;
	int Command, Speed, AutoX, AutoY, Orientation;
	double MaxPower, X, Y, Z, DeltaA, IntakeDIR;

	//Point data to current autonomous command line
	Command = *Array;
	Orientation = *(Array+6);
	Speed = *(Array+3);
	AccSec = *(Array+1);
	DecInches = *(Array+2);
	AutoX = *(Array+4);
	AutoY = *(Array+5);
	IntakeDIR = *(Array+7);

	RemainingInches = sqrt(pow((RobotX[IDX]-AutoX),2)+pow((RobotY[IDX]-AutoY),2)); //distance to target
	MaxFromDcel = (pow(RemainingInches,2)*10000)/pow(DecInches,2); //Max speed percentage based on deceleration value given 
	MaxFromAcel = (int)(time*100000)/AccSec; //Get msec since we started and divide by msec to full power for power limit from acceleration

	if(MaxFromDcel<MaxFromAcel) {
		MaxPower=(MaxFromDcel*Speed)/100;
    } else {
		MaxPower=(MaxFromAcel*Speed)/100;
	}
	if (MaxPower > Speed) {MaxPower = Speed;}
	if (MaxPower < 0) {MaxPower = 0;}

	//Calculate the X,Y direction to target
	X = (AutoX-(int)RobotX[IDX]);
	Y = (AutoY-(int)RobotY[IDX]);

	//Calculate the delta in the robot orientation target
	DeltaA = (RobotAngle-Orientation);
	Z = (DeltaA*-1.0)/90.0;
	if (Z > 1.0) {Z = 1.0;}
	if (Z < -1.0) {Z = -1.0;}

	//Return
	return std::make_tuple(Command, Speed, Orientation, AccSec, AutoX, AutoY, RemainingInches, MaxPower, DeltaA, X, Y, Z, IntakeDIR);
}

//Get the unajusted robot speed
double GetSpeed() {
	double A,B;
	A = SWRVX+SWRVZ;
	B = SWRVY+SWRVZ;

	return std::clamp(sqrt(pow(A,2)+pow(B,2)),-1.0,1.0);
}

/*
Returns the proper multiplier for the value of approachSpeedPercent
@return negative or positive percent
*/
float GetSpeedIncrement() {
	float increment = 1.0f;

	if (currentSpeed > previousSpeed) {
		increment += approachSpeedPercent;
	} else if (currentSpeed < previousSpeed) {
		increment -= approachSpeedPercent;
	} else {
		increment += approachSpeedPercent;
	}

	return increment;
}

//Do the math on each wheel to find the new angle and speed required
void  Calc4WheelTurn() {
	double A,B,C,D,R,temp;
	R = SW_L+SW_W;

	A = SWRVX-SWRVZ*(SW_L/R);
	B = SWRVX+SWRVZ*(SW_L/R);
	C = SWRVY-SWRVZ*(SW_W/R);
	D = SWRVY+SWRVZ*(SW_W/R);

	ModDir[FR] = atan2(B,C)*180/PI;
	ModSpd[FR]=  sqrt(pow(B,2)+pow(C,2));

	ModDir[FL] = atan2(B,D)*180/PI;
	ModSpd[FL]=  sqrt(pow(B,2)+pow(D,2));

	ModDir[RL] = atan2(A,D)*180/PI;
	ModSpd[RL]=  sqrt(pow(A,2)+pow(D,2));

	ModDir[RR] = atan2(A,C)*180/PI;
	ModSpd[RR]=  sqrt(pow(A,2)+pow(C,2));

	//Evenly reduces ModSpd members so that the highest value will always be 1
	temp = 0;
	for (int i=0;i<4;i++) {
		if(ModSpd[i]>temp) {
			temp=ModSpd[i];
		}
	}
	if (temp>1.0) {
		for(int i=0;i<4;i++) {
			ModSpd[i]/=temp;
		}
	}
}