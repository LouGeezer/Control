#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#endif // CONTROL_H #define CONTROL_H
#define RAMPS_H

#include "display.h"
#ifdef ARD_MOTOR_SHIELD_H
// Declare the used pins
int dirA = 12;
int dirB = 13;
int pwmA = 3;
int pwmB = 11;

#endif // ARD_MOTOR_SHIELD_H

#ifdef RAMPS_H
// For RAMPS 1.4
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
#define I2C_SOA			   20
#define I2C_SCL            21

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN				9

#define PS_ON_PIN			12

//STOP / KILL button
#define KILL_PIN				41 //[RAMPS14-SMART-ADAPTER]

#define BTN_EN1				31 //[RAMPS14-SMART-ADAPTER]
#define BTN_EN2				33 //[RAMPS14-SMART-ADAPTER]
#define BTN_ENC				35 //[RAMPS14-SMART-ADAPTER]
#define ENC_PORT PINC			// bitmapped port of ATMEGA 2560

//beeper
#define BEEPER_PIN			37 //[RAMPS14-SMART-ADAPTER] / 37 = enabled; -1 = disabled / (if you don't like the beep sound ;-)

//SD card detect pin
#define SDCARDDETECT		49 //[RAMPS14-SMART-ADAPTER]


#define HEATER_0_PIN		10
#define HEATER_1_PIN		8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING

#define SERVO_1_PIN			11	// Servo pin closest to the Reset button
#define SERVO_2_PIN			6	// Servo pin second closest to the Reset button
#define SERVO_3_PIN			5	// Servo pin third closest to the Reset button
#define SERVO_4_PIN			4	// Servo pin fourth closest to the Reset button




#endif // RAMPS_H

#define LJ_LFT_MASK 0x80
#define LJ_RT_MASK 0x40
#define LJ_UP_MASK 0x20
#define LJ_DOWN_MASK 0x10
#define LJ_SWITCH_MASK 0x08
#define SELECT_MASK 0x04
#define HOME_MASK 0x02
#define START_MASK 0x01
#define NONE_MASK 0xFC

// LED's
#define PLAYER1 SERVO_1_PIN
#define PLAYER2 SERVO_2_PIN
#define PLAYER3 SERVO_3_PIN
#define PLAYER4 SERVO_4_PIN

// Mapping to PS3 Controller
// Switches
#define SQUARE_SW X_MIN_PIN
#define X_SW X_MAX_PIN
#define CIRCLE_SW Y_MAX_PIN
#define TRIANGLE_SW Z_MIN_PIN

// G20: Set Units to Millimeters
// G21: Set Units to Inches
// C60: Set Units to Degrees (Non-std G-Code)
#define UNITS_STEPS		3
#define UNITS_DEGREES	2
#define UNITS_INCHES	1
#define UNITS_MM		0

// RunStop settings, used for emergency stop
#define RS_RUN 1
#define RS_STOP 0
