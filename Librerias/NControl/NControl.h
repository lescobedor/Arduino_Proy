/*
||
|| @file NControl.h
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

#ifndef NControl_H
#define NControl_H
#include "Arduino.h"

class NControl {
public:
	NControl(uint8_t pinIni);
	void offAll();
	void onAll();
	void resetAll();
	void toggleAll();
	void addTask(uint8_t type,unsigned long interval);
private:
	uint8_t num_task = 0;
};

#endif
