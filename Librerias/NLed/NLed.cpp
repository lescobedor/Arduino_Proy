/*
||
|| @file NLed.cpp
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
/*
 * Líbreria para el manejo Dígital
 * 
 * El proposito es controlar por medio de pin dígital swith que 
 * puede cambiar su estatus de apagado a encendido y ver reflejado
 * ese cambio en el dispositivo de salida
 * */

#include "NLed.h"

NLed::NLed() {

}

void NLed::init(uint8_t sw, uint8_t led){
	this->_sw = sw;
	this->_led = led;
	pinMode(this->_led,OUTPUT);
    pinMode(this->_sw,INPUT);
    this->_statusSw = getStateSw();
    this->_statusSw ? onLed() : offLed();
}
bool NLed::getStateLed() { 
	return this->_statusLed; 
}

bool NLed::getStateSw() { 
	return digitalRead(this->_sw); 
}

void NLed::writeLed() {
	digitalWrite(this->_led,this->_statusLed);
}

void NLed::onLed(){
	this->_statusLed = true;
	writeLed();
}

void NLed::offLed(){
	this->_statusLed = false;
	writeLed();
}

void NLed::toggleLed(){
	Serial.print("Led: ");
	Serial.println(this->_led);
	this->_statusLed ? offLed() : onLed();
}

void NLed::checkSw(){
	bool sw = getStateSw();
	if (sw != this->_statusSw){
		this->_statusSw = sw;
		toggleLed();
	}
}
