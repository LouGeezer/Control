//
//
//

#include "display.h"
#include "Settings.h"

void pUnits(Motor* motor, int x, int y) {
	String tempStr;
	u8g.setPrintPos(x, y);
	switch (motor->units) {
	case UNITS_DEGREES:
		u8g.print("deg");
		break;
	case UNITS_INCHES:
		u8g.print("in");
		break;
	case UNITS_MM:
		u8g.print("mm");
		break;
	case UNITS_STEPS:
		u8g.print("stp");
		break;
	}
}

void beep(uint8_t mSec) {
#ifndef BEEPER_OFF
	digitalWrite(BEEPER_PIN, HIGH);
	delay(mSec);
	digitalWrite(BEEPER_PIN, LOW);
#endif // BEEPER_OFF
}

void drawSettingsMenu(void) {
	String tempStr;
	uint8_t temp = u8g.getMode();
	u8g_uint_t tempX, tempY;
	u8g_uint_t x1 = 64, y1 = 0, x2 = 64, y2 = 0;
	// graphic commands to redraw the complete screen should be placed here
	//	u8g.setFont(u8g_font_lucasfont_alternate);
	/*	u8g.setColorIndex(1);
	u8g.drawBox(10, 12, 20, 30);
	u8g.setColorIndex(0);
	u8g.drawPixel(28, 14);

	u8g.setColorIndex(1);
	u8g.drawLine(0,30, 128,30);
	u8g.drawLine(65,0, 65,64); */

	u8g.setFont(u8g_font_5x8);
	u8g.setFontLineSpacingFactor(30);
	u8g.setFontPosBaseline();

	u8g.drawStr(0, 10, "X Motor:");
/*	tempStr = String(mX.location, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 10);
	//	u8g.setDefaultForegroundColor(); //*************
	if (menuItem == 1) {
		u8g.drawBox(32, 2, 29, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.setPrintPos(61 - tempX, 10);
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************
	pUnits(&mX, 62, 10);

	u8g.drawStr(80, 10, "Spd:");
	tempStr = String(mX.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 10);
	if (menuItem == 2) {
		u8g.drawBox(100, 2, 28, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************/

	u8g.drawStr(0, 20, "Y Motor:");
/*	tempStr = String(mY.location, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 20);
	if (menuItem == 3) {
		u8g.drawBox(32, 12, 29, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************
	pUnits(&mY, 62, 20);

	u8g.drawStr(80, 20, "Spd:");
	tempStr = String(mY.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 20);
	if (menuItem == 4) {
		u8g.drawBox(100, 12, 28, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************/

	u8g.drawStr(0, 30, "Z Motor:");
/*	tempStr = String(disp.z.loc, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 30);
	if (menuItem == 5) {
		u8g.drawBox(32, 22, 29, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************
	pUnits(&mZ, 62, 30);

	u8g.drawStr(80, 30, "Spd:");
	tempStr = String(mZ.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 30);
	if (menuItem == 6) {
		u8g.drawBox(100, 22, 28, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************/

	u8g.drawStr(0, 40, "E loc:");
	tempStr = String(disp.e.loc, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 40);
	u8g.print(tempStr);
	pUnits(&mE, 62, 40);

	u8g.drawStr(80, 40, "Spd:");
	tempStr = String(mE.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 40);
	u8g.print(tempStr);

	u8g.drawStr(0, 50, "F loc:");
	tempStr = String(disp.f.loc, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 50);
	u8g.print(tempStr);
	pUnits(&mF, 62, 50);

	u8g.drawStr(80, 50, "Spd:");
	tempStr = String(mF.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 50);
	u8g.print(tempStr);

	u8g.drawStr(0, 60, "Last Cmd:");
	tempStr = getValue(disp.lCmd, '\n', 0);
	u8g.setPrintPos(55, 60);
	u8g.print(tempStr);
}

void drawMain(void) {
	String tempStr;
	uint8_t temp = u8g.getMode();
	u8g_uint_t tempX, tempY;
	u8g_uint_t x1 = 64, y1 = 0, x2 = 64, y2 = 0;

	u8g.setFont(u8g_font_5x8);
	u8g.setFontLineSpacingFactor(30);
	u8g.setFontPosBaseline();
	u8g.drawStr(0, 10, "X loc:");
	tempStr = String(mX.location, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 10);
	if (menuItem == 1) {
		u8g.drawBox(32, 2, 29, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.setPrintPos(61 - tempX, 10);
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor();
	pUnits(&mX, 62, 10);
	u8g.drawStr(80, 10, "Spd:");
	tempStr = String(mX.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 10);
	if (menuItem == 2) {
		u8g.drawBox(100, 2, 28, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor();
	u8g.drawStr(0, 20, "Y loc:");
	tempStr = String(mY.location, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 20);
	if (menuItem == 3) {
		u8g.drawBox(32, 12, 29, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor();
	pUnits(&mY, 62, 20);
	u8g.drawStr(80, 20, "Spd:");
	tempStr = String(mY.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 20);
	if (menuItem == 4) {
		u8g.drawBox(100, 12, 28, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************
	u8g.drawStr(0, 30, "Z loc:");
	tempStr = String(disp.z.loc, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 30);
	if (menuItem == 5) {
		u8g.drawBox(32, 22, 29, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************
	pUnits(&mZ, 62, 30);

	u8g.drawStr(80, 30, "Spd:");
	tempStr = String(mZ.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 30);
	if (menuItem == 6) {
		u8g.drawBox(100, 22, 28, 9);
		u8g.setDefaultBackgroundColor();
	}
	u8g.print(tempStr);
	u8g.setDefaultForegroundColor(); //*************

	u8g.drawStr(0, 40, "E loc:");
	tempStr = String(disp.e.loc, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 40);
	u8g.print(tempStr);
	pUnits(&mE, 62, 40);

	u8g.drawStr(80, 40, "Spd:");
	tempStr = String(mE.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 40);
	u8g.print(tempStr);

	u8g.drawStr(0, 50, "F loc:");
	tempStr = String(disp.f.loc, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(61 - tempX, 50);
	u8g.print(tempStr);
	pUnits(&mF, 62, 50);

	u8g.drawStr(80, 50, "Spd:");
	tempStr = String(mF.fastSpeed, DEC);
	tempX = tempStr.length() * 5;
	u8g.setPrintPos(128 - tempX, 50);
	u8g.print(tempStr);

	u8g.drawStr(0, 60, "Last Cmd:");
	tempStr = getValue(disp.lCmd, '\n', 0);
	u8g.setPrintPos(55, 60);
	u8g.print(tempStr);
}

void displayInit(void) {
	// flip screen, if required
	// u8g.setRot180();

	// set SPI backup if required
	//u8g.setHardwareBackup(u8g_backup_avr_spi);

	// assign default color value
	if (u8g.getMode() == U8G_MODE_R3G3B2) {
		u8g.setColorIndex(255);     // white
	}
	else if (u8g.getMode() == U8G_MODE_GRAY2BIT) {
		u8g.setColorIndex(3);         // max intensity
	}
	else if (u8g.getMode() == U8G_MODE_BW) {
		u8g.setColorIndex(1);         // pixel on
	}
	else if (u8g.getMode() == U8G_MODE_HICOLOR) {
		u8g.setHiColorByRGB(255, 255, 255);
	}
	disp.x.loc = 0;
	disp.x.spd = 0;
	disp.y.loc = 0;
	disp.y.spd = 0;
	disp.z.loc = 0;
	disp.z.spd = 0;
	disp.e.loc = 0;
	disp.e.spd = 0;
	disp.f.loc = 0;
	disp.f.spd = 0;
	drawMain();
}

Led::Led() {
};

void Led::init(uint8_t led) {
	pinNumber = led;
	pinMode(led, OUTPUT);
	clear();
};

uint8_t Led::pin(void)
{
	return(pinNumber);
};

void Led::set(void)
{
	digitalWrite(pinNumber, LOW);
	state = LED_ON;
	/*		Serial.print((int)pinNumber);
			Serial.print(" ");
			Serial.println((int)state);
			*/
};

void Led::clear(void)
{
	digitalWrite(pinNumber, HIGH);
	state = LED_OFF;
	/*		Serial.print((int)pinNumber);
			Serial.print(" ");
			Serial.println((int)state);
			*/
};