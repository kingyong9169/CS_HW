#include <TM1637Display.h>

#define DIO 11
#define CLK 10
#define TOUCH 3
#define VOLUME 0
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

TM1637Display FND(CLK, DIO);
volatile int Touched = 0;
int adValue;
int degree;
char buf[80];

void setup(){
  pinMode(TOUCH, INPUT_PULLUP);
  degree = 0;
  Serial.begin(9600);
  // touch sensor int1
  attachInterrupt(digitalPinToInterrupt(TOUCH), touch_isr, RISING);
  // FND 초기화
  FND.setBrightness(0x04);
  FND.showNumberDec(degree);
}

void touch_isr(){
  Touched = 1;
}

void loop(){
  unsigned long pt, ct;
  if(Touched == 1){
    pt = micros();
    adValue = analogRead(VOLUME);
    ct = micros();
    Serial.print("analogRead() 실행시간 : "); Serial.println(ct - pt);
    
    degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
    pt = micros();
    FND.showNumberDec(degree);
    ct = micros();
    Serial.print("FND.showNumberDec() 실행시간 : "); Serial.println(ct - pt);
    
    sprintf(buf, "degree: %d", degree);
    Serial.println(buf);
    Touched = 0;
  }
}