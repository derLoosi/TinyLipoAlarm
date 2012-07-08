#include <SoftwareSerial.h>

#include "config.h"
#include "def.h"

SoftwareSerial mySerial(0, 1);

void setup()  
{
  analogReference(INTERNAL);
  mySerial.begin(9600);
  pinMode(buzzer, OUTPUT);
 
}

void loop() // run over and over
{
    vbatraw = analogRead(analogPin);
    vbat=vbatraw*16/VBATSCALE;
    mySerial.println(vbat);
    
    if(vbat > VBATLEVEL1){
      vbatalarm=0;
    }
    if(vbat < VBATLEVEL1){
      vbatalarm=1;
    }
    if(vbat < VBATLEVEL2){
      vbatalarm=2;
    }
    if(vbat < VBATLEVEL3){
      vbatalarm=3;
    }
    
    if(vbatalarm==0){
      delay(500);
    }
    
    if(vbatalarm==1){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(800);
    }
    
    if(vbatalarm==2){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(400);
    }
    
    
    if(vbatalarm==3){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(400);
    digitalWrite(buzzer, LOW);
    delay(100);
    }
}
