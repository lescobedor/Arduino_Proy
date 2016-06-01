#include "leOS2.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>


int V1 = 0;
int V2 = 0;

//global variables
const uint8_t MAX_JOBS = 999; //max allowed jobs -1 (i.e.: 9 = 10-1)

//jobs variables
struct looper_core {
  void (*jobPointer)(void); //store the pointers to user's jobs
  unsigned long userJobInterval; //the interval between each job execution
  unsigned long plannedJob; //keep the next instant of each job execution
  uint8_t jobIsActive;
};

looper_core _jobs[MAX_JOBS];
unsigned long minu = 0;
unsigned long milis = 0;
unsigned long micro = 0;
unsigned long mm = 0;
unsigned long Intervalo = 300000;
unsigned long IntTmp = 0;
unsigned long SegMin = 0;


void setup() {  
  pinMode(4,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  SegMin = (long)1000 * 60u;
}


int Bandera = 0;
void loop() { 
  //delay(2000); 
  /*    
  digitalWrite(13,LOW);
  delay(2000);
  digitalWrite(13,HIGH);
  delay(2000);
  */
  if(milis == 0 || (milis + SegMin) < millis()){    
    if (milis != 0) {
      minu ++;
      Serial.print("Minutos: ");
      Serial.print(minu);
      Serial.print(" - " );
      Serial.print(millis());
      Serial.print(" - " );
      Serial.print(milis + SegMin);
      Serial.print(" - " );
      Serial.println(micros());
    }
    milis = millis();
  }
  /*
  Serial.print(millis());
  Serial.print(" - " );
  Serial.print(milis);
  Serial.print(" - " );
  Serial.println(SegMin);
*/        
  micro = micros();
  IntTmp = Intervalo;
  /*Serial.print(millis());
  Serial.print(" - ");
  Serial.print(micro);
  Serial.print(" - ");
  V1 = analogRead(A1);
  Serial.print(V1);
  Serial.print(" - ");
  V2 = analogRead(A3);
  Serial.print(V2);
  Serial.print(" - ");
  Serial.println((V1 + V2) / 2);*/
  while(micro + IntTmp > micros()) {
    mm = micros();
    if(micro > mm){
      Bandera = 1;
      Serial.println("Se reseteo el contador");
      Serial.print("Micros: ");
      Serial.println(mm);
      Serial.print("Anterio: ");
      Serial.println(micro);
      IntTmp = 4294967295 - micro;
      Serial.print("Dif1: ");
      Serial.println(IntTmp);
      IntTmp = Intervalo - IntTmp;
      Serial.print("Dif2: ");
      Serial.println(IntTmp);
      micro = mm;
    }
  }
  if (Bandera > 0) {
    Bandera = 0;
    Serial.print("Micros Nuevos: ");
    Serial.println(micros());    
  }
}
