//
//
//

#include "motors.h"
#include "commands.h"

int mInit(char mL, Stepper* mS, Motor* m, long mFastSpeed, long mSlowSpeed, int mStepsRot, int mStepsMM, int mUnits) {
	if (verbose == VERBOSE_DEBUG) {
		Serial.print(mL);
		Serial.print(" Motor ");
		Serial.print("Fastspeed="); // verbose info
		Serial.println(mFastSpeed);
		mS->setSpeed(mFastSpeed);
	}
	m->mLet = mL;
	m->mPtr = mS;
	m->slowSpeed = 10;
	m->fastSpeed = 400;
	m->steps_per_unit = 25;
	m->units = mUnits;
	m->location = 0;

	m->mPtr->setSpeed(mFastSpeed);
}

double mMove(char motor, double cnt) {
	double stepsToDo = 0, stepsDone = 0;
	int success = 1;
	Motor* m; Stepper* s;
	switch (motor) {
	case 'X':
	case 'x':
		m = &mX;
		break;
	case 'Y':
	case 'y':
		m = &mY;
		break;
	case 'Z':
	case 'z':
		m = &mZ;
		break;
	case 'E':
	case 'e':
		m = &mE;
		break;
	case 'F':
	case 'f':
		m = &mF;
		break;
	}
	if (m->units == UNITS_STEPS) {
		stepsToDo = cnt * 2;
	}
	else if (m->units == UNITS_DEGREES) {
//		stepsToDo = cnt / 360;		May want to spin more than 360 degrees
		stepsToDo = cnt * 35.5;
	}
	else if (m->units == UNITS_INCHES) {
		stepsToDo = cnt * 254;
		stepsToDo = stepsToDo * 12;
	}
	else if (m->units == UNITS_MM) {
		stepsToDo = cnt * 10;
		stepsToDo = stepsToDo * 12;
	}
	if (verbose == VERBOSE_DEBUG) {
		Serial.print(motor);
		Serial.print(" Motor; ");
		Serial.print(cnt);
		Serial.print(" count;");
		Serial.print(m->units);
		Serial.print(" units; ");
		Serial.print(stepsToDo);
		Serial.print(" steps to do; "); // verbose info
		Serial.print("RunStop="); // verbose info
		Serial.println(RunStop.val);
	}
	led2.set();
	if ((cnt != 1) && (cnt != -1)) delay(1000);	// cmd may have come from menu & KILL PB still bouncing
	digitalWrite(X_ENABLE_PIN, LOW);
	digitalWrite(Y_ENABLE_PIN, LOW);

	stepsDone = stepsToDo;
#define KILL_ACTIVE (digitalRead(KILL_PIN) == 0)
#define KILL_COUNTS ((menuItem == 0) && ((millis() - lKillTime) > 800))
	while ((RunStop.val == RS_RUN) && (stepsToDo >= 1) && (KILL_COUNTS && !KILL_ACTIVE)) { // KILL_PIN used for Menus currently
		if (stepsToDo > 0) {
			m->mPtr->step(-1);
			stepsToDo--;
		}
	}
	while ((RunStop.val == RS_RUN) && (stepsToDo <= -1) && (KILL_COUNTS && !KILL_ACTIVE)) {
		if (stepsToDo < 0) {
			m->mPtr->step(1);
			stepsToDo++;
		}
	}
	if (stepsToDo != 0) {	// Didn't finish the move, need to recalc steps actually taken
		stepsDone = stepsDone - stepsToDo;
		if (m->units == UNITS_DEGREES) {
			stepsDone = stepsDone / (12800 * 360);
		}
		else if (m->units == UNITS_INCHES) {
			stepsDone = stepsDone / (12 * 254);
		}
		else if (m->units == UNITS_MM) {
			stepsDone = stepsDone / (12 * 10);
		}
	}
	else {
//		stepsDone = stepsDone; // we did all the steps required in cnt
	}
	led2.clear();
	if (m->location == m->oldLocation) m->location += (long)cnt;	// if the same, must have been a command move, increment
																	// if different, must have been a menu move. Increment already done.
	m->oldLocation = m->location;
/*	if (m->units == UNITS_DEGREES)							// May want to move more than 360 degrees
		if (m->location >= 360) m->location -= 360;
		else if (m->location <= -360) m->location += 360;
*/
		// picture loop -- refresh screen after long moves
		u8g.firstPage();
		do {
			drawMain();
		} while (u8g.nextPage());

		return success;
}