#include <TM1637Display.h>
#include "OneWire.h"
#include <TimerOne.h>

#define LED 2
#define TOUCH 6
#define DIO 10
#define CLK 9

OneWire ds(11); // 온도센서
byte ds_addr[8];
uint8_t found;
uint8_t scratchpad[10];
int16_t raw;
float celcius;
volatile uint8_t long delayCount = 0;
volatile uint8_t temperature = 2;

TM1637Display FND(CLK, DIO); // FND
volatile uint8_t long count = 0; // 시간 측정

volatile int touched = 0, countReady = 0; // 터치

volatile uint8_t ledState = 0; // led 상태

void setup(){
  Serial.begin(115200);
  pinMode(TOUCH, INPUT); // 터치 센서를 입력
  pinMode(LED, OUTPUT); // LED를 출력으로
  
  found = ds.search(ds_addr);
  
  FND.setBrightness(0x04);
  Timer1.initialize(100000);
  Timer1.attachInterrupt(timer);
}

void timer(){
  touched = digitalRead(TOUCH);
  if(touched){
    count++;
  }
  else if(!touched && count){
    countReady = count;
    count = 0;
  }

  if(temperature == 0){
    delayCount++;
    if(delayCount >= 10){
      delayCount = 0;
      temperature = 1;
    }
  }
}

void loop(){
  digitalWrite(LED, ledState);

  if(countReady){
    if(countReady <= 10){
      ledState ^= 1;
      digitalWrite(LED, ledState);
    }
    
    else if(countReady > 10){
      temperature = 0;
    }
    countReady = 0;
  }
  if(found && temperature == 0){
    ds.reset();
    ds.select(ds_addr);
    ds.write(0x44, 1);
  }

  if(found && temperature == 1){
    ds.reset();
    ds.select(ds_addr);
    ds.write(0xBE);
    ds.read_bytes(scratchpad, 9);

    raw = ((int16_t)scratchpad[1] << 8) + (int16_t)scratchpad[0];
    celcius = (float)raw/16.0;
    int digit = celcius;
    int celciusFloat = (celcius - digit) * 100;
    FND.showNumberDecEx(digit * 100 + celciusFloat, 0x40, true);
    temperature = 2;
  }
}