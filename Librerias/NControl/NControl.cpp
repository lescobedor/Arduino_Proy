/*
||
|| @file NControl.cpp
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
#include "NControl.h"
#include "NLed.h"

const uint8_t MAX_LEDs = 9;
/*const uint8_t MAX_EVENTS = 9;
struct NEvent{
	uint8_t TipeEvent = 0;
	unsigned long Interval = 0;
	bool Enable = false;
	
};
NEvent Eventos[MAX_EVENTS];
*/
NLed Leds[MAX_LEDs];

NControl::NControl(uint8_t pinIni) {
	for(int e = 0;e < MAX_LEDs;e++){
		Leds[e].init(pinIni + e * 2,pinIni + e * 2 + 1);
	}
}

void NControl::addTask(uint8_t type,unsigned long interval) {
	
}

void NControl::onAll() {
	for(int e = 0;e < MAX_LEDs;e++){
		Leds[e].onLed();
	}
}

void NControl::offAll() {
	for(int e = 0;e < MAX_LEDs;e++){
		Leds[e].offLed();
	}	
}

void NControl::resetAll() {
	for(int e = 0;e < MAX_LEDs;e++){
		Leds[e].writeLed();
	}		
}
void NControl::toggleAll() {
	for(int e = 0;e < MAX_LEDs;e++){
		Leds[e].toggleLed();
	}
}
