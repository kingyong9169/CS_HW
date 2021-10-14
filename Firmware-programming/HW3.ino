#include <TM1637Display.h>

#define DIO 11
#define CLK 10
#define TOUCH 2
#define TOGGLE 3

TM1637Display FND(CLK, DIO);
volatile int  Touched = 0, Toggled = 0;
uint16_t  TouchCount = 0;

void setup() {
  // TM1637Display
  FND.setBrightness(0x04);
  FND.showNumberDec(TouchCount);

  // Touch sensor
  pinMode(TOUCH, INPUT_PULLUP);
  pinMode(TOGGLE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT0, RISING);
  attachInterrupt(digitalPinToInterrupt(TOGGLE), ISR_INT1, CHANGE);
  FND.showNumberDec(TouchCount);
}

void ISR_INT0()
{
  Touched = 1;
}

void ISR_INT1()
{
  Toggled = 1;
}

void loop() {
  if (Touched == 1) {
    TouchCount += 1;
    FND.showNumberDec(TouchCount);
    Touched = 0;
  }
  else if (Toggled == 1){
    if(TouchCount > 0){
      TouchCount -= 1;
    }
    FND.showNumberDec(TouchCount);
    Toggled = 0;
  }
}