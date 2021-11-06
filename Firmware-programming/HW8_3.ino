#include <TimerOne.h>

#define LED 9

volatile long tPeriod = 1000000;

void setup(){
  pinMode(LED, OUTPUT);
  Timer1.initialize(tPeriod); // 1초
  Timer1.pwm(LED, 307);
}

void loop(){
  // nothing
}
