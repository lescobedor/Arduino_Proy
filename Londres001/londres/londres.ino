#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;
int Led = 13;
int Pecera = 2;
int Cochera = 4;
int Minutes = 0;
DateTime Now;

// Convierte las horas y minutos a segundo y le sumas los segundo sg
int getSecondsHour(int hr, int min = 0, int sg = 0) {
  return (hr * 60 + min) * 60 + sg;
}

// Convierte las horas y minutos a segundo y le sumas los segundo sg
int getSecondsDate(DateTime date){
  int Hour = date.hour();
  int Minutes = date.minute();
  int Seconds = date.second();
  return getSecondsHour(Hour,Minutes,Seconds);
}

int getMinutesHour(int hr, int min = 0) {
  return hr * 60 + min;
}

int getMinutesDate(DateTime date){
  int Hour = date.hour();
  int Minutes = date.minute();  
  return getMinutesHour(Hour,Minutes);
}

void setup () {
  pinMode(Led, OUTPUT);
  pinMode(Pecera, OUTPUT);
  pinMode(Cochera, OUTPUT);
  
  Wire.begin(); // Inicia el puerto I2C
  RTC.begin(); // Inicia la comunicación con el RTC
  Serial.begin(9600); // Establece la velocidad de datos del puerto serie
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");   
    RTC.adjust(DateTime(__DATE__, __TIME__));  // Establece la fecha y hora (Comentar una vez establecida la hora)
    Serial.println(String(__DATE__) + " " + String(__TIME__));
  }  
}

void loop() {
  Now = RTC.now();
  if (Minutes != getMinutesDate(Now)) {
    Minutes = getMinutesDate(Now);
    outDate(Now);
    runPecera(Now);
    runCochera(Now);  
  }
  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led, LOW);
  delay(500);
}

void runCochera(DateTime date){  
  if((getMinutesDate(date) >= getMinutesHour(19) && getMinutesDate(date) < getMinutesHour(23)) || ( getMinutesDate(date) >= getMinutesHour(6) && getMinutesDate(date) <= getMinutesHour(8))) {
    digitalWrite(Cochera,true);
    Serial.println("Cochera On " + String(getSecondsDate(date)));
  } else {
    digitalWrite(Cochera,false);
    Serial.println("Cochera Off" + String(getSecondsDate(date)));
  }  
}

void runPecera(DateTime date) {  
  if(getMinutesDate(date) >= getMinutesHour(7) && getMinutesDate(date) < getMinutesHour(22)) {
    digitalWrite(Pecera,LOW);
    Serial.println("Pecera On " + String(getSecondsDate(date)));
  } else {
    digitalWrite(Pecera,HIGH);
    Serial.println("Pecera Off" + String(getSecondsDate(date)));
  }
}

void outDate(DateTime date) {
  //DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  Serial.print(date.year(), DEC); // Año
  Serial.print('/');
  Serial.print(date.month(), DEC); // Mes
  Serial.print('/');
  Serial.print(date.day(), DEC); // Dia
  Serial.print(' ');
  Serial.print(date.hour(), DEC); // Horas
  Serial.print(':');
  Serial.print(date.minute(), DEC); // Minutos
  Serial.print(':');
  Serial.print(date.second(), DEC); // Segundos
  Serial.println();
}

