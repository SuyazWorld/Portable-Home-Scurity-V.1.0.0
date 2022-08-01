#include<SoftwareSerial.h>
int relay = 7; //pin relay
int sensorPin = 8; //pin ldr
int led = 9; // pin led
int led2 = 5;
int buzzer = 10; // pin buzzer
int sensorPir = 6; // pin pir

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(sensorPir,INPUT);
  }

void loop(){
  int sensorValue = digitalRead(sensorPin);
  int pirval = digitalRead(sensorPir); 
  Serial.println(pirval);
  if (sensorValue==0)//disini 0 itu bisa kita sebut HIGH ato 1 entah kenapa gatau juga
    {
    digitalWrite(relay, LOW); //disini juga LOW artinya di relay HIDUP entah kenapa gatau juga
    tone(buzzer, 2000);
    digitalWrite(led,HIGH);
    digitalWrite(buzzer, HIGH);
    delay(80);
    digitalWrite(led,LOW);
    delay(80);
    }
  else if(pirval== HIGH){
    digitalWrite(led2, HIGH);
    delay(150);
    digitalWrite(led2, LOW);
    delay(150);
  }
  noTone(buzzer);
  digitalWrite(led,LOW);
  digitalWrite(relay,HIGH); //disini HIGH artinya di relay MATI entah kenapa gatau juga
  digitalWrite(buzzer, LOW);
  }
