#define PVALUE 0.75

#define START 10
#define STOP  11
#define MOVE  12
#define SWITCH 14
#define ADJUST 13

#define NUMAUTOLINES 30


#define IDXX 7 /* x offset from 0,0 for index wheel FL=7, FR=17, RL=7, RR=17 */
#define IDXY -17 /*y offset from 0,0 for index wheel FL=-7, FR=-7, RL=-17, RR=-17 */ 

#define BRPW 70
#define SLPW 65
#define BNPW 75
#define GSPW 45


//Motor controller defines
#define TIMEOUT 10
#define NOTIMEOUT 0
//Joystick defines
#define DIR 0
#define ROT 1
#define ARM 2

//-------------------CAN BUS DEFINES---------------
//Swerve CAN bus defines for steering motors
#define FLS 3
#define FRS 4
#define RLS 2
#define RRS 11
//Swerve CAN bus defines for drive motors
#define FLD 7
#define FRD 8
#define RLD 6
#define RRD 9
//Swerve CAN Bus defines for intake motor
#define INTAKE 10


//For swerve code, define motor data locations in the arrays
#define RR 0
#define FR 1
#define FL 2
#define RL 3
#define ALL -1 /* all drive channels */
#define IDX  3 /* use Rear Left Wheel as index */
#define PI 3.141592654
#define SW_L 10.875   //Distance between wheels from front to back
#define SW_W 10.875   //Distance between wheels from side to side




#define RED1  (frc::DriverStation::kRed*10+1)
#define RED2  (frc::DriverStation::kRed*10+2)
#define RED3  (frc::DriverStation::kRed*10+3)
#define BLUE1 (frc::DriverStation::kBlue*10+1)
#define BLUE2 (frc::DriverStation::kBlue*10+2) //hopefully not including the libs doesn't cause these to break
#define BLUE3 (frc::DriverStation::kBlue*10+3)
#define UNKNOWN 0


#define hasIntake true