// motors.h

#ifndef _MOTORS_h
#define _MOTORS_h

#include <string.h>
#include <SoftwareSerial.h>
#include "Control.h"
#include "Counters.h"
#include "display.h"
#include <Stepper.h>

typedef struct Motor {
	char mLet;
	Stepper* mPtr;
//	int steps_per_rotation, 
//		steps_per_mm;
	uint8_t units, steps_per_unit;
	long limLowLoc,	// Lowest location the motor can move to
		limHiLoc,	// Highest location the motor can move to
		homeLoc,	// Origin the motor should start from
		fastSpeed, //Speed for G0 moves
		slowSpeed,	//Speed for G1 moves
		location,	// Location from origin
	oldLocation;	// Used for move calculations / completion
} ;

extern Stepper StepperX, StepperY, StepperZ, StepperE, StepperF;
// extern inSw swS1, swS2, swS3, swS4 /*swSquare, swTriangle=S4,  */;
extern uint8_t stpr1, stpr2;
extern Counter1 RunStop;
extern Counter2 cFlag;
extern uint8_t s1Press, s2Press, s3Press, s4Press, verbose, units;
extern long lKillTime;
extern String cmdStr[7];
extern  Led led1, led2, led3, led4;
extern struct Motor mX, mY, mZ, mE, mF;


int mInit(char mL, Stepper* mS, Motor* m, long mFastSpeed, long mSlowSpeed, int mStepsRot, int mStepsMM, int mUnits);
double mMove(char motor, double cnt);
#endif

