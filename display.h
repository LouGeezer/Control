// display.h

#if defined(ARDUINO) && ARDUINO >= 100
#include <U8glib.h>
#include "arduino.h"
#include <EEPROM.h>
#include <String.h>
#include <Stepper.h>
#include <SoftwareSerial.h>
#else
#include "WProgram.h"
#endif
#include "motors.h"
#include "Control.h"

// display options
#define DRAW_INFO	0;	// Draw the Info screen
#define DRAW_MENU	1;	// Draw the Menu screen

extern uint8_t menuItem, temp1, temp2, temp3, temp4;

#define LED_OFF 0;
#define LED_ON 1;

#ifndef _DISPLAY_h
#define _DISPLAY_h

typedef struct mLine {
	long loc;
	long spd;
};

typedef struct dScreen {
	mLine x;
	mLine y;
	mLine z;
	mLine e;
	mLine f;
	String lCmd;
};

extern U8GLIB_ST7920_128X64_4X u8g;
extern dScreen disp;
extern String getValue(String data, char separator, int index);
extern struct Motor mX, mY, mZ, mE, mF;

void displayInit(void);
void beep(uint8_t mSec);
int8_t readEncoder(void);
void pUnits(Motor* motor, int x, int y);
void drawMain(void);
void drawMotorMenu(void);
void drawSettingsMenu(void);

class Led
{
private:
	uint8_t  pinNumber;
	boolean	state;

public:
	void init(uint8_t led);
	uint8_t pin(void);
	void set(void);
	void clear(void);

	Led(void);
	//	Led(uint8_t pin);
	~Led() {};
};

#endif
