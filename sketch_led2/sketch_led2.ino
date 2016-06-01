#include "NControl.h"
#include "NLed.h"



void Salida(String texto) {
  Serial.println(texto);
}



void setup() {
  Serial.begin(9600);
  Salida("Iniciando");
  delay(500);
  pinMode(13,OUTPUT);
  pinMode(A1,INPUT);
//  Ctr.onAll();
}

NControl Ctr = NControl(22);
void loop() {
  delay(500);
  Ctr.toggleAll();
  //Serial.println(analogRead(A1));
}
