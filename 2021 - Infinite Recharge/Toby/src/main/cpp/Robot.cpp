/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Required Variables & Methods
#include "heads/Vars/Libs.hpp"
#include "heads/Vars/Defines.hpp"
#include "heads/Vars/Settings.hpp"
#include "heads/Vars/varsPub.hpp"
#include "heads/SmallFuncts.hpp"
#include "heads/Vars/autoArrays.hpp"

using namespace std;



class Robot : public frc::TimedRobot {
	public:

	void RobotInit() override {// Called when code is first loaded
		wpi::outs() << "\n Robot Initializing \n";

		//will set TargetDir to current position of the wheels
		TargetDir[FL]=(FLSteer.GetSensorCollection().GetPulseWidthPosition()/4096.0)*360.0;
		TargetDir[FR]=(FRSteer.GetSensorCollection().GetPulseWidthPosition()/4096.0)*360.0;
		TargetDir[RR]=(RRSteer.GetSensorCollection().GetPulseWidthPosition()/4096.0)*360.0;
		TargetDir[RL]=(RLSteer.GetSensorCollection().GetPulseWidthPosition()/4096.0)*360.0;

		//Camera1= frc::CameraServer::GetInstance()->StartAutomaticCapture(0);

		//FLSteer.GetSensorCollection().SetPulseWidthPosition(0,TIMEOUT);
		FLSteer.ConfigSelectedFeedbackSensor(FeedbackDevice::PulseWidthEncodedPosition, 0, NOTIMEOUT);
		FLSteer.SetSensorPhase(false);
		FLSteer.ConfigNominalOutputForward(0.0f, TIMEOUT);
		FLSteer.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		FLSteer.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		FLSteer.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		FLSteer.SelectProfileSlot(0, 0);
		FLSteer.Config_kP(0, PVALUE, TIMEOUT);
		FLSteer.Config_kI(0, 0.0, TIMEOUT);
		FLSteer.Config_kD(0, 0.0, TIMEOUT);
		FLSteer.Set(ControlMode::Position, TargetDir[FL]);

		//FRSteer.GetSensorCollection().SetPulseWidthPosition(0,TIMEOUT);
		FRSteer.ConfigSelectedFeedbackSensor(FeedbackDevice::PulseWidthEncodedPosition, 0, NOTIMEOUT);	 
		FRSteer.SetSensorPhase(false);
		FRSteer.ConfigNominalOutputForward(0.0f, TIMEOUT);
		FRSteer.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		FRSteer.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		FRSteer.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		FRSteer.SelectProfileSlot(0, 0);
		FRSteer.Config_kP(0, PVALUE, TIMEOUT);
		FRSteer.Config_kI(0, 0.0, TIMEOUT);
		FRSteer.Config_kD(0, 0.0, TIMEOUT);
		FRSteer.Set(ControlMode::Position, TargetDir[FR]);

		//RLSteer.GetSensorCollection().SetPulseWidthPosition(0,TIMEOUT);
		RLSteer.ConfigSelectedFeedbackSensor(FeedbackDevice::PulseWidthEncodedPosition, 0, NOTIMEOUT);	
		RLSteer.SetSensorPhase(false);
		RLSteer.ConfigNominalOutputForward(0.0f, TIMEOUT);
		RLSteer.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		RLSteer.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		RLSteer.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		RLSteer.SelectProfileSlot(0, 0);
		RLSteer.Config_kP(0, PVALUE, TIMEOUT);
		RLSteer.Config_kI(0, 0.0, TIMEOUT);
		RLSteer.Config_kD(0, 0.0, TIMEOUT);
		RLSteer.Set(ControlMode::Position, TargetDir[RL]);

		//RRSteer.GetSensorCollection().SetPulseWidthPosition(0,TIMEOUT);
		RRSteer.ConfigSelectedFeedbackSensor(FeedbackDevice::PulseWidthEncodedPosition, 0, NOTIMEOUT);	 
		RRSteer.SetSensorPhase(false);
		RRSteer.ConfigNominalOutputForward(0.0f, TIMEOUT);
		RRSteer.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		RRSteer.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		RRSteer.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		RRSteer.SelectProfileSlot(0, 0);
		RRSteer.Config_kP(0, PVALUE, TIMEOUT);
		RRSteer.Config_kI(0, 0.0, TIMEOUT);
		RRSteer.Config_kD(0, 0.0, TIMEOUT);
		RRSteer.Set(ControlMode::Position, TargetDir[RR]);
			
		RLDrive.GetSensorCollection().SetIntegratedSensorPosition(0);
		RLDrive.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, NOTIMEOUT);	 // PIDLoop=0 
		RLDrive.SetSensorPhase(false);
		RLDrive.ConfigNominalOutputForward(0.0f, TIMEOUT);
		RLDrive.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		RLDrive.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		RLDrive.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		RLDrive.SelectProfileSlot(0, 0);
		RLDrive.Config_kP(0, 0.5, TIMEOUT);
		RLDrive.Config_kI(0, 0.0, TIMEOUT);
		RLDrive.Config_kD(0, 0.0, TIMEOUT);
		RLDrive.Set(ControlMode::Position, 0.0);
		
		RRDrive.GetSensorCollection().SetIntegratedSensorPosition(0);
		RRDrive.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, NOTIMEOUT);	 
		RRDrive.SetSensorPhase(false);
		RRDrive.ConfigNominalOutputForward(0.0f, TIMEOUT);
		RRDrive.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		RRDrive.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		RRDrive.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		RRDrive.SelectProfileSlot(0, 0);
		RRDrive.Config_kP(0, 0.5, TIMEOUT);
		RRDrive.Config_kI(0, 0.0, TIMEOUT);
		RRDrive.Config_kD(0, 0.0, TIMEOUT);
		RRDrive.Set(ControlMode::Position, 0.0);

		FRDrive.GetSensorCollection().SetIntegratedSensorPosition(0);
		FRDrive.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, NOTIMEOUT);	 
		FRDrive.SetSensorPhase(false);
		FRDrive.ConfigNominalOutputForward(0.0f, TIMEOUT);
		FRDrive.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		FRDrive.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		FRDrive.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		FRDrive.SelectProfileSlot(0, 0);
		FRDrive.Config_kP(0, 0.5, TIMEOUT);
		FRDrive.Config_kI(0, 0.0, TIMEOUT);
		FRDrive.Config_kD(0, 0.0, TIMEOUT);
		FRDrive.Set(ControlMode::Position, 0.0);

		FLDrive.GetSensorCollection().SetIntegratedSensorPosition(0);
		FLDrive.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, NOTIMEOUT);	
		FLDrive.SetSensorPhase(false);
		FLDrive.ConfigNominalOutputForward(0.0f, TIMEOUT);
		FLDrive.ConfigNominalOutputReverse(0.0f, TIMEOUT);
		FLDrive.ConfigPeakOutputForward(+12.0f, TIMEOUT);
		FLDrive.ConfigPeakOutputReverse(-12.0f, TIMEOUT);
		FLDrive.SelectProfileSlot(0, 0);
		FLDrive.Config_kP(0, 0.5, TIMEOUT);
		FLDrive.Config_kI(0, 0.0, TIMEOUT);
		FLDrive.Config_kD(0, 0.0, TIMEOUT);
		FLDrive.Set(ControlMode::Position, 0.0);

		wpi::outs() << "\n Robot Initialized \n";
	}
	void RobotPeriodic() override {//Called each time a new packet is received from the driver station.
		double periodPassed = GetIterationTime();
		float speedIncrement = GetSpeedIncrement();

		currentSpeed = GetSpeed();

		switch (MoveMode) {
			case -1:
				speedPercent = 0;
				break;
			case 0:
				speedPercent = 0;
				break;
			case 1:
				speedPercent = moveSpeedPercent;
				break;
			case 2:
				speedPercent = turnSpeedPercent;
				break;
			case 3:
				speedPercent = moveSpeedPercent;
				break;
		}
		
		/*distanceTime += periodPassed;
		if ((distanceTime>=distanceRefreshRate)||(distanceRefreshRate==0)) {
			distanceTime -= distanceRefreshRate;

			double adjustedValue = Ultrasonic.GetValue()*(5/frc::RobotController::GetVoltage5V());

			switch(distanceType) {
				case 0: //Centimeters
					distanceValue = adjustedValue*0.125;
					break;
				case 1: //Inches
					distanceValue = adjustedValue*0.0492;
					break;
				default://Centimeters
					distanceValue = adjustedValue*0.125;
					break;
			}
		}*/

		if (speedIncrement > 1.0f) {
			speedIncrement += speedIncrement*periodPassed*speedIncrement;
		} else if (speedIncrement < 1.0f) {
			speedIncrement -= speedIncrement*periodPassed*speedIncrement;
		}
		speedIncrement = clamp(speedIncrement, 0.1f, 1.0f);

		UpdateTelemetricData();
	}

	void DisabledInit() override {//Called when the robot first enters disabled mode
		MoveMode = -1;
	}
	
	void AutonomousInit() override {// Called when the robot first enters autonomous mode
		AutoLine = 0;
		MoveMode = 0;
		FieldCentric = true; //Auto operates in field centric mode
		for (int i=0;i<4;i++) {
			OldPosition[i] = GetLocation(i);
		}

		switch (frc::DriverStation::GetInstance().GetAlliance()*10 + frc::DriverStation::GetInstance().GetLocation()) { 
			case RED1:
				AutoArray=BR_AutoArray;			//Red 1 = Barrel Race game
				break;
			case RED2:
				AutoArray=SL_AutoArray;			//Red 2 = Slalom game
				break;
			case RED3:
				AutoArray=BN_AutoArray;			//Red 3 = Bounce game
				break;
			default:
				AutoArray=GS_AutoArray_Initial;	//Blue 1 = Galactic Search game--need logic to determine path A or B
				break;
		}

		return;
	}
    void AutonomousPeriodic() override {// Called each iteration when robot is in autonomous mode
		AutoTime.Start();
	
		ReadGyro();              //get the angle of the robot in to variable "RobotAngle"
		TrackRobot();			//Track the Robot's FL wheel X,Y position around the field
		AutoStateMachine();      //Get updated directional commands from autopilot
		if(!FirstPass) {		// don't try to control anything when state changes
			SwerveControl();         //convert auto pilot commands to joystick motions
			SwerveDrive();           //Update the speed and direction of the swerve drive motors
		}
  	}
  
	void TeleopInit() override {// Called when robot first enters tele-op mode
		for(int i=0;i<4;i++) {
			OldPosition[i]=GetLocation(i);
		}

		MoveMode = 0;
	}
	void TeleopPeriodic() override {// Called each iteration when robot is in tele-op mode
		ReadGyro();
		TrackRobot();			//Track the Robot's FL wheel X,Y position around the field
		SwerveControl();
		SwerveDrive();
		//BallWatch();
	}

	/*void BallWatch(void){
		float V;
		V=BallSensor.GetVoltage();
		if (V<2 && !VoltageLow){
			VoltageLow = 1;
			VoltageHigh=0;
			Ballcount++;
			
		}
		if (V>4 && !VoltageHigh){
			VoltageHigh = 1;
			VoltageLow=0;
			
		}
	}*/
    //This is were the SWRVX,SWRVY,SWRVZ values are set to direct the swerve drives where to go

	//Updates smartscreen with current robot telemetric data
	void UpdateTelemetricData() {
		if (!UpdateCount) {
			char str[40];
			UpdateCount = 25;
			
			if (IsAutonomous()) {
				//Get current autonomous variables
				int Command, AccSec, Speed, Orientation, AutoX, AutoY, RemainingInches;
				double MaxPower,X,Y,Z ,DeltaA;

				tie(Command, ignore, Speed, Orientation, AccSec, AutoX, AutoY, RemainingInches, MaxPower, DeltaA, X, Y, Z) = GetAutonomousValues(AutoArray[AutoLine], AutoTime.Get());
				
				Command=*AutoArray[AutoLine];
				

				//Update smart dashboard
				sprintf(str, "LINE:%d,CMD:%d",AutoLine,Command);
				frc::SmartDashboard::PutString("DB/String 0", str);
				sprintf(str, "TX%d TY%d",(int)AutoX,(int)AutoY);
				frc::SmartDashboard::PutString("DB/String 1", str);
				sprintf(str, "xFL%d,FR%d,RL%d,RR%d",(int)RobotX[FL],(int)RobotX[FR],(int)RobotX[RL],(int)RobotX[RR]);
				frc::SmartDashboard::PutString("DB/String 2", str);
				sprintf(str, "yFL%d,FR%d,RL%d,RR%d",(int)RobotY[FL],(int)RobotY[FR],(int)RobotY[RL],(int)RobotY[RR]);
				frc::SmartDashboard::PutString("DB/String 3", str);
				sprintf(str, "Pwr:%4.2f",MaxPower);
				frc::SmartDashboard::PutString("DB/String 4", str);
				sprintf(str, "Ang T%d,A%3.0f",Orientation,fmod(RobotAngle,360.0));
				frc::SmartDashboard::PutString("DB/String 5", str);
				sprintf(str, "A: %d,%d,%d,%d",(int)ActDir[FL],(int)ActDir[FR],(int)ActDir[RL],(int)ActDir[RR]);
				frc::SmartDashboard::PutString("DB/String 6", str);
				sprintf(str, "T:%d,%d,%d,%d",(int)TargetDir[FL],(int)TargetDir[FR],(int)TargetDir[RL],(int)TargetDir[RR]);
				frc::SmartDashboard::PutString("DB/String 7", str);
				sprintf(str, "TMR: %f", TeleTime.Get());
				frc::SmartDashboard::PutString("DB/String 8", str);
			} else if (IsOperatorControl()) {
				sprintf(str, "RL:%d %d",RLSteer.GetSensorCollection().GetPulseWidthPosition(),RLSteer.GetSensorCollection().GetAnalogInRaw());
				frc::SmartDashboard::PutString("DB/String 0", str);
				sprintf(str, "xFL%d,FR%d,RL%d,RR%d",(int)RobotX[FL],(int)RobotX[FR],(int)RobotX[RL],(int)RobotX[RR]);
				frc::SmartDashboard::PutString("DB/String 1", str);
				//sprintf(str, "yFL%d,FR%d,RL%d,RR%d",(int)RobotY[FL],(int)RobotY[FR],(int)RobotY[RL],(int)RobotY[RR]);
				sprintf(str, "FL: %4.2f, RL: %4.2f", fmod(ActDir[FL],360.0), fmod(ActDir[RL],360.0));
				frc::SmartDashboard::PutString("DB/String 2", str);
				sprintf(str, "Mod: %4.2f,%4.2f",ModDir[RR],ModDir[FL]);
				frc::SmartDashboard::PutString("DB/String 3", str);
				//sprintf(str, "Tgt: %4.2f,%4.2f",TargetDir[RR],TargetDir[FL]);
				sprintf(str, "Pressure: %f",Gyro.GetBarometricPressure());
				frc::SmartDashboard::PutString("DB/String 4", str);
				sprintf(str, "Gyro: %f",fmod(RobotAngle,360.0));
				frc::SmartDashboard::PutString("DB/String 5", str);
				

				//Temp display for encoder values
				sprintf(str, "Distance: %f",distanceValue);
				frc::SmartDashboard::PutString("DB/String 6", str);
				sprintf(str, "Speed: %f", currentSpeed);
				frc::SmartDashboard::PutString("DB/String 7", str);
				sprintf(str, "Move Throttle: %d%%", (int)(moveSpeedPercent*100));
				frc::SmartDashboard::PutString("DB/String 8", str);
				sprintf(str, "Turn Throttle: %d%%", (int)(turnSpeedPercent*100));
				frc::SmartDashboard::PutString("DB/String 9", str);
				//Temp End
			}
		} else {
			UpdateCount--;
		}
	}
	
	void SwerveControl(void) {
		//AutoPilot?
		if (IsAutonomous()) {
			SWRVY = AutoDriveY;
			SWRVX = AutoDriveX;
			SWRVZ = AutoDriveZ;

			if(SWRVZ>1.0)SWRVZ=1.0;
			if(SWRVZ<-1.0) SWRVZ=-1.0;
			if(SWRVY>1.0)SWRVY=1.0;
			if(SWRVY<-1.0) SWRVY=-1.0;
			if(SWRVX>1.0)SWRVX=1.0;
			if(SWRVX<-1.0) SWRVX=-1.0;
		} else if (IsOperatorControl()) { //Teleop Mode
			// Set joystick values
			SWRVX = dir_stick.GetX();
			SWRVY = -dir_stick.GetY();
			SWRVZ = rot_stick.GetX();

			// Set speed values
			moveSpeedPercent = (((dir_stick.GetTwist()*-1)+1)/2) * maxMoveSpeed; // Sets moveSpeedPercent to throttle value
			turnSpeedPercent = (((rot_stick.GetTwist()*-1)+1)/2) * maxTurnSpeed; // Sets turnSpeedPercent to throttle value
			
			// Resets joystick values to 0 if they aren't being adjusted
			if (fabs(SWRVY) < 0.1) SWRVY = 0.0;
			if (fabs(SWRVX) < 0.1) SWRVX = 0.0;
			if (fabs(SWRVZ) < 0.1) SWRVZ = 0.0;

			// Sets the robot move mode
			double move = max(fabs(SWRVX), fabs(SWRVY));
			double rotate = fabs(SWRVZ);
			if (move>0.0 && rotate>0.0) {
				MoveMode = 3; // move & rotate
			} else if (rotate>0.0) {
				MoveMode = 2; // rotate
			} else if (move>0.0) {
				MoveMode = 1; // move
			} else {
				MoveMode = 0; // idle
			}

			// Button events on rotate joystick
			if (rot_stick.GetRawButton(ShowOff)) {//Show-off//Spins the robot really fast
				turnSpeedPercent = 1;
				specialSpeed = 3;
			} else {
				specialSpeed = 1;
			}
			if (rot_stick.GetRawButtonPressed(CalibrateGyro)) Gyro.Calibrate(); //recalibrates the gyro
			if (rot_stick.GetRawButtonPressed(ResetGyro)) Gyro.Reset(); //resets the gyro
			if (rot_stick.GetRawButtonPressed(ResetTeleopTimer)) {//resets the timer
				TeleTime.Stop();
				TeleTime.Reset();
				TeleStarted=0;
				for(int i=0;i<4;i++){
					RobotX[i]=0.0;
					RobotY[i]=0.0;
				}
			}

			// Button events on drive joystick
			if (FieldCentricToggle) {//Controls field-centric vs robot-centric
				if (dir_stick.GetRawButtonPressed(FieldCentricControl)) {
					FieldCentric = !FieldCentric;
				}
			} else {
				FieldCentric = !dir_stick.GetRawButton(FieldCentricControl);
			}

			// Events for Intake Control
			if (hasIntake) {
				if (dir_stick.GetRawButton(IntakePushControl)) {
					Intake.Set(ControlMode::PercentOutput, -(INTAKE_SPEED)*13.0/frc::DriverStation::GetInstance().GetBatteryVoltage());
				}
				else if (dir_stick.GetRawButton(IntakePullControl)) {
					Intake.Set(ControlMode::PercentOutput, INTAKE_SPEED*13.0/frc::DriverStation::GetInstance().GetBatteryVoltage());
				} else {
					Intake.Set(ControlMode::PercentOutput, 0);
				}
			} else if (dir_stick.GetRawButton(MoveFast)) {//doubles the speed
				speedPercent *= 2;
			}
		}
	}



  //Modify the Target direction given the new the direction from Calc4WheelTurn() using shortest distance calculations
  void SetDirection(int channel) {
		int curdir;
 
		if(SpeedPolarity[channel] < 0.0){
			curdir=fmod((TargetDir[channel]+180.0),360.0);
		} else {
			curdir=fmod(TargetDir[channel],360.0);
		}
		
		delta=ModDir[channel]-curdir+ZeroDir[channel]; //What is the distance to move?  How best to get there...

		delta=fmod(delta,360.0);
		//Is Fastest way across 0 boundary?
		if(delta<-180.0) {  //Don't turn more than 180 degrees
			delta+=360.0;
		}
		if(delta>180.0) {
			delta-=360.0;
		}
		if(delta<=90.0 && delta>=-90.0) { //direct move without direction change
			TargetDir[channel]+=delta;
		} else {
			if(delta>90.0) delta-=180.0;
			if(delta<-90.0) delta+=180.0;
			TargetDir[channel]-=delta;
			if(SpeedPolarity[channel]>0.0 ) SpeedPolarity[channel]=-1.0; //switch directions so we steer less
			else SpeedPolarity[channel]=1.0;
		}
	}	// End SetDirection



	//controlling the direction and speed of the swerve drives
    void SwerveDrive() {
    	int i;
    	float Gyro,temp;
      
    	//Read encoder counts and then divide to get degrees of rotation
    	ActDir[FL]=fmod((FLSteer.GetSensorCollection().GetPulseWidthPosition()/11.38) - ZeroDir[FL],360.0); //GetPulseWidthPosition()
		ActDir[FR]=fmod((FRSteer.GetSensorCollection().GetPulseWidthPosition()/11.38) - ZeroDir[FR],360.0);
    	ActDir[RL]=fmod((RLSteer.GetSensorCollection().GetPulseWidthPosition()/11.38) - ZeroDir[RL],360.0);
    	ActDir[RR]=fmod((RRSteer.GetSensorCollection().GetPulseWidthPosition()/11.38) - ZeroDir[RR],360.0);

		//determine if we are field or robot centric and make the adjustment here if necessary    
	    if (FieldCentric) {
			Gyro = (RobotAngle*PI)/180;
		} else {
			Gyro = 0;
		}

		//Restart the Tele-op timer
		if (IsOperatorControl() && TeleStarted==0 && fabs(ModSpd[IDX])>0.1) {
		    TeleTime.Start();
			TeleTime.Reset();
			TeleStarted=1;
		}

		//modify the target robot direction from field centric to robot centric for wheel positions and then set them in calc4wheel
	    temp=SWRVY*cos(Gyro)+SWRVX*sin(Gyro);
	    SWRVX=-SWRVY*sin(Gyro)+SWRVX*cos(Gyro);
	    SWRVY=temp;

		//set rotate direction value
		SWRVZ = pow(turnSpeedPercent*SWRVZ,3);

		Calc4WheelTurn();

		for(i=0;i<4;i++) SetDirection(i);

        //send the drive motor speeds to the motor controllers
		FLDrive.PIDWrite(-clamp(SpeedPolarity[FL]*(-ModSpd[FL])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		FRDrive.PIDWrite(-clamp(SpeedPolarity[FR]*(-ModSpd[FR])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		RLDrive.PIDWrite(-clamp(SpeedPolarity[RL]*(-ModSpd[RL])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		RRDrive.PIDWrite(-clamp(SpeedPolarity[RR]*(-ModSpd[RR])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		/*FLDrive.Set(ControlMode::PercentOutput, -clamp(SpeedPolarity[FL]*(-ModSpd[FL])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		FRDrive.Set(ControlMode::PercentOutput, -clamp(SpeedPolarity[FR]*(-ModSpd[FR])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		RLDrive.Set(ControlMode::PercentOutput, -clamp(SpeedPolarity[RL]*(-ModSpd[RL])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);
		RRDrive.Set(ControlMode::PercentOutput, -clamp(SpeedPolarity[RR]*(-ModSpd[RR])*speedPercent*currentSpeed, -1.0f, 1.0f) * specialSpeed);*/

		//send the swerve motor rotations to the motor controllers
		FLSteer.Set(ControlMode::Position, (TargetDir[FL]/360.0)*4096);
	    FRSteer.Set(ControlMode::Position, (TargetDir[FR]/360.0)*4096);
	    RRSteer.Set(ControlMode::Position, (TargetDir[RR]/360.0)*4096);
		RLSteer.Set(ControlMode::Position, (TargetDir[RL]/360.0)*4096);
    }	// End SwerveDrive

    double GetLocation(int i){
		double result;
		switch (i){ 
			case FL:
				result=FLDrive.GetSelectedSensorPosition();
				break;
			case FR:
				result=FRDrive.GetSelectedSensorPosition();
				break;
			case RL:
				result=RLDrive.GetSelectedSensorPosition();
				break;
			case RR:
				result=RRDrive.GetSelectedSensorPosition();
				break;
			default:
				result=0.0;
		}
		return(result/772.5); //678.44);
	}

    double NewPosition[4],OldPosition[4];
	//Track robot FL wheel X,Y position in inches Y is long side of field X is width
    void TrackRobot(void){
        double Dist,Dir;
		for(int i=0;i<4;i++) {
	     	//Determine distance moved since last time in this routine
			NewPosition[i]=GetLocation(i);
			Dist=NewPosition[i]-OldPosition[i];
			OldPosition[i]=NewPosition[i];
			Dir=ActDir[i]+RobotAngle;
			Dir=fmod(Dir,360.0);
			RobotX[i]+=Dist*sin((Dir*PI)/180.0);
			RobotY[i]+=Dist*cos((Dir*PI)/180.0);
		}
	}	// End TrackRobot

  	//AUTONOMOUS DRIVING STATE MACHINE
    void AutoStateMachine(void){
		int Command, AccSec, Speed, AutoX, AutoY, RemainingInches, IntakeDIR;
		double MaxPower, X, Y, Z, DeltaA;

        //Get values for current autonomous command line
		tie(Command, IntakeDIR, Speed, ignore, AccSec, AutoX, AutoY, RemainingInches, MaxPower, DeltaA, X, Y, Z) = GetAutonomousValues(AutoArray[AutoLine], AutoTime.Get());
        
		//Intake
		if(IntakeDIR>0){
			Intake.Set(ControlMode::PercentOutput, INTAKE_SPEED);
		} else if(IntakeDIR<0){
			Intake.Set(ControlMode::PercentOutput, -(INTAKE_SPEED));
		} else {
			Intake.Set(ControlMode::PercentOutput, 0);
		}

		//Command Execution:
		switch (Command) { //command mode
		case START: 
			RobotX[IDX]=(double)AutoX;
			RobotY[IDX]=(double)AutoY;

			Gyro.Reset();

			AutoLine++;
			FirstPass = true;
			TeleStarted=0; //Trigger Timer to reset and run on power to wheels
			break;
		case MOVE:  //Determine direction and rotation values from autonomous command
			{
				double fctr = fabs(X)+fabs(Y);
				if(fctr == 0.0) {fctr = 1.0;}
				
				if(RemainingInches>0){
					AutoDriveX=(double)((X/(fctr))*MaxPower)/100.0;
					AutoDriveY=(double)((Y/(fctr))*MaxPower)/100.0;
				} else {
					AutoDriveX=0.0;
					AutoDriveY=0.0;
				}
			}
	
			//if(fabs(DeltaA)>0){
				AutoDriveZ=Z; //(double)(pow(Z,3)/15);
			//}else{
			//	AutoDriveZ=0.0;
			//}
			if(FirstPass){
				if(fabs(Y)>fabs(X)){
					Travel=Y;
					UseYTravel=1;
				}else{
					Travel=X;
					UseYTravel=0;
				} 
				FirstPass = false;
			}
			if((UseYTravel&&(Y*Travel<0))||((!UseYTravel)&&(X*Travel<0))){
				RemainingInches=0;
			} 
			if(RemainingInches<(Speed/5)){//&&!FirstPass){ //} && fabs(DeltaA)<5){
				AutoLine++;
				AutoTime.Reset();
				FirstPass=1;
			}
			break;
		case ADJUST: 
			RobotX[IDX]+=(double)AutoX;
			RobotY[IDX]+=(double)AutoY;
			AutoLine++;
			FirstPass = true;
			break;
		case SWITCH:
			if(FirstPass){
				SwitchTimer.Start();
				SwitchTimer.Reset();
				FirstPass = false;
			}
			AutoDriveX=0.0;
			AutoDriveY=0.0;
			AutoDriveZ=0.0;
			if(SwitchTimer.Get()>0.25||BallSensor.Get()){
				if(!BallSensor.Get()) {
					AutoLine+=AccSec;
				} else {
					AutoLine++;
				}
				FirstPass=1;
			}
			break;
		case STOP:
			AutoDriveX=0.0;
			AutoDriveY=0.0;
			AutoDriveZ=0.0;
			Intake.Set(ControlMode::PercentOutput, 0);
			TeleTime.Stop();
			FirstPass = false;
			break;
		default:
			break;
		}
    }
	
	protected:
	frc::Joystick dir_stick{DIR};  //swerve direction
	frc::Joystick rot_stick{ROT};  //swerve rotation
	//frc::Joystick arm_stick{ARM};  //arm functions

	WPI_TalonFX FLDrive = {FLD};
	WPI_TalonFX FRDrive = {FRD};
	WPI_TalonFX RLDrive = {RLD};
	WPI_TalonFX RRDrive = {RRD};
	TalonSRX FLSteer = {FLS};
	TalonSRX FRSteer = {FRS};
	TalonSRX RLSteer = {RLS};
	TalonSRX RRSteer = {RRS};
	TalonSRX Intake = {INTAKE};

	//frc::AnalogInput Ultrasonic{0};

	frc::DigitalInput BallSensor{0};
	//frc::ADXRS450_Gyro Gyro; //small gyro
	//frc::ADIS16448_IMU Gyro; //expansion port gyro
	//cs::UsbCamera Camera1;

	frc::Timer AutoTime; //seconds timer for auto states
	frc::Timer TeleTime; //seconds timer for tele-op mode
	frc::Timer SwitchTimer;
};

//Start Robot
#ifndef RUNNING_FRC_TESTS
int main() {return frc::StartRobot<Robot>();}
#endif