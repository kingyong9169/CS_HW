#include <TM1637Display.h>

#define DIO 11
#define CLK 10
#define TOUCH 3
#define analogPin 5
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

TM1637Display FND(CLK, DIO);
volatile int Touched = 0;
int adValue;
int degree;

void setup() {
  pinMode(TOUCH, INPUT_PULLUP);
  degree = 0;
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT1, RISING);
  FND.setBrightness(0x04);
  FND.showNumberDec(degree);
}

void ISR_INT1(){
  Touched = 1;
}

void loop() {
  if(Touched == 1){
    adValue = analogRead(analogPin);  // 12 bit 0 ~ 1023
    degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
    FND.showNumberDec(degree);
    Touched = 0;
  }
}