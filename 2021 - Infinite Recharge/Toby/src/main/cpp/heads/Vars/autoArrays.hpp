
int (*AutoArray)[8];


// autonomous barrel race  RED 1

int BR_AutoArray[NUMAUTOLINES][8]={
	//CMD,   Acc mSec,Dec Inches, MaxPwr,TargetX, TargetY, Orientation Deg,IntakeState
	{START,      0,         0,      0,      0,       0,        0,            0}, //Start at midfield location
	{MOVE,    750,         5,   BRPW,     -10,      50,        0,            0},	//up to speed
	{MOVE,       5,         5,   BRPW,     5,     101,        0,            0},	//cone 1
	{MOVE,       5,         5,   BRPW,     30,     121,        0,            0},	//
	{MOVE,       5,         5,   BRPW,     30,      75,        0,            0},	//
	{MOVE,       5,         5,   BRPW,     5,      75,        0,            0},	//
	{MOVE,       5,         5,   BRPW,     -15,     185,        0,            0},	//cone 2
	{MOVE,       5,         5,   BRPW,      -45,     185,        0,            0}, 	//
	{MOVE,       5,         5,   BRPW,      -45,     130,        0,            0}, 	//
	{MOVE,       5,         5,   BRPW,     40,     196,        0,            0}, 	//cone 3
	{MOVE,       5,         5,   BRPW,     40,     240,        0,            0},	//
	{MOVE,       5,         5,   BRPW,     -5,     240,        0,            0},
	{MOVE,       5,         5,    100,     -25,     120,        0,            0},	//
	{MOVE,       5,        60,    100,     0,       0,        0,            0},	//return to base
	{MOVE,       5,        60,     30,     0,      20,        0,            0},	//descelerate
	{STOP,       0,         0,      0,      0,       0,        0,            0},	//STOP
};

// slalom  RED 2

int	SL_AutoArray[NUMAUTOLINES][8]={
	//CMD,   Acc mSec,Dec Inches, MaxPwr,TargetX, TargetY, Orientation Deg,IntakeState
	{START,      0,         0,      0,     160,      40,        0,            0},	//Start at right location
	{MOVE,    500,         5,   SLPW,     110,     90,        0,            0},	//
	{MOVE,       5,         5,   100,     90,     260,        0,            0},	//pass 1
	{MOVE,     5,         5,     65,     125,     285,        0,            0},	//500
	{MOVE,		 5,			5,	   65,	   105,		320,		0,			  0},	//pass 3
	{MOVE,       5,         5,     65,      75,     290,        0,            0},	//
	{MOVE,       5,         5,     65,     120,     250,        0,            0},	//pass 4
	{MOVE,       5,         5,   100,     120,      80,        0,            0},	//
	{MOVE,       5,         5,     65,      95,      30,        0,            0},	//pass 5
	{STOP,       0,         0,      0,       0,       0,        0,            0},	//STOP
};

// Bounce Path   RED 3 line up to right of zone with left front corner at middle

int	BN_AutoArray[NUMAUTOLINES][8]={
	//CMD,   Acc mSec,Dec Inches, MaxPwr,TargetX, TargetY, Orientation Deg,IntakeState
	{START,      0,         0,      0,    IDXX,   IDXY,        0,            0},	//Start at midfield location
	{MOVE,    500,         5,   BNPW,     -23,     22,        0,            0},	//
	{MOVE,       5,        10,     50,     -50,     25,        0,            0},	//pin 1
	{ADJUST,     0,         0,      0,     -10,      0,        0,            0},	//spin 10"@45 15"@50
	{MOVE,    500,         5,   BNPW,      15,     70,        0,            0},	//
	{MOVE,       5,         5,   BNPW,      40,     94,        0,            0},	//turn 1
	{MOVE,       5,         5,   BNPW,      35,    100,        0,            0},	//
	{MOVE,       5,         5,  55,     -20,    130,        0,            0},	//
	{MOVE,       5,         5,   40,     -50,    125,        0,            0},	//
	{ADJUST,     0,         0,      0,     0,      0,        0,            0},	//spin 10"@45 15"@50
	{MOVE,    500,        5,   BNPW,      20,    120,        0,            0},	//pin 2
	{MOVE,       5,         5,   BNPW,      35,    195,        0,            0},	//
	{MOVE,       5,        5,   BNPW,     -30,    200,        0,            0},	//pin 3
	{MOVE,       5,        5,   40,     -60,    200,        0,            0},	//pin 3
	//{ADJUST,     0,         0,      0,     -10,      0,        0,            0},	//spin 10"@45 15"@50
	{MOVE,    500,         5,   BNPW,     -20,    190,        0,            0},	//
	{MOVE,       5,         5,   BNPW,     -20,    220,        0,            0},	//finish
	{STOP,       0,         0,      0,       0,      0,        0,            0},	//STOP
};

// Galactic Search Path(s)   BLUE 1

int	GS_AutoArray_Initial[NUMAUTOLINES][8]={	
	//CMD,   Acc mSec,Dec Inches, MaxPwr,TargetX, TargetY, Orientation Deg,IntakeState
	{START,      0,         0,      0,    20,      10,        0,            -1},	//Start at midfield location
	{MOVE,    1500,         5,   GSPW,     20,     40,        45,            -1},	//
	{MOVE,       5,         5,   GSPW,     30,     80,        85,           1},	//
	{SWITCH,     6,         0,      0,     0,      0,        0,            0},	//Detect path A or B and switch AutoArray
	//-----------------------------Ball 1 Red B--------------------------
	{MOVE,    5,         5,   GSPW,     100,     140,        45,            1},
	{MOVE,    5,         5,   GSPW,     35,     220,        -45,            1}, 
	{MOVE,    5,         5,   GSPW,     40,     295,        -90,            1},
	{MOVE,    5,         5,   GSPW,     50,     285,        -90,            0}, 
	{STOP,       0,         0,      0,       0,      0,        0,            0}, //STOP
	//----------------------------Ball 1 Red A--------------------------
	{MOVE,    5,         5,   GSPW,     70,     75,        90,            1}, 
	{SWITCH,     6,         0,      0,     0,      0,        0,            0},
	{MOVE,    500,         5,   GSPW,     125,    175,        45,            1},
	{MOVE,    500,         5,   GSPW,     20,     160,       -30,            1}, 
	{MOVE,    5,         5,   GSPW,     30,     250,        -45,            1},
	{MOVE,    5,         5,   GSPW,     50,     330,        -90,            0}, 
	{STOP,       0,         0,      0,       0,      0,        0,            0},	//STOP
	//--------------------------Blue A + B------------------------------
	{MOVE,    1500,         5,   GSPW,     130,     130,        0,            1},
	{MOVE,    1500,         5,   GSPW,     138,     165,        -30,            1},
	{MOVE,    1500,         5,   GSPW,     110,     175,        -90,            1},
	{MOVE,    5,         5,   GSPW,     49,     170,        -30,            1},
	{MOVE,    5,         5,   GSPW,     45,     225,        0,            1},
	{MOVE,    5,         5,   GSPW,     94,     300,        45,            1},
	{MOVE,    5,         5,   GSPW,     125,     345,        90,            1},
	{STOP,       0,         0,      0,       0,      0,        0,            0},
};