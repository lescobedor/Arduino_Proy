/*
||
|| @file NLed.h
|| @version 1.0
|| @author Luis Escobedo
|| @contact vbeno76@gmail.com
||
|| @description
|| 
||
|| @license
|| | Copyright (c) 2016 Luis Escobedo. All rights reserved.
||
*/
#ifndef NLed_H
#define NLed_H
#include "Arduino.h"

class NLed {
	public:
		NLed();
		void init(uint8_t sw, uint8_t led);
		bool getStateLed();
		void onLed();
		void offLed();
		void toggleLed();
		void writeLed();
		
		bool getStateSw();
		void checkSw();
		
	private:
		bool _statusLed = false;
		bool _statusSw = false;
		uint8_t _sw = 0;
		uint8_t _led = 0;
};

#endif
