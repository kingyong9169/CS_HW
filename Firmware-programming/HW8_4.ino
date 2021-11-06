#include <TimerOne.h>

#define LED 2

volatile uint8_t tSec = 0;
volatile long tPeriod = 100000;
volatile int led = 1;

void setup(){
  pinMode(LED, OUTPUT);
  Timer1.initialize(tPeriod); // 0.1초
  Timer1.attachInterrupt(bright);
}

void bright()
{
  tSec = tSec + 1;
  if(tSec == 3){
    led = 0;
  }
  else if(tSec == 10){
    led = 1;
    tSec = 0;
  }
}

void loop(){
  if(led == 1){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}