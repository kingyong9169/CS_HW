#include <TimerOne.h>
#include <TM1637Display.h>

#define CLK 10
#define DIO 11
#define TOUCH 3

TM1637Display fnd(CLK, DIO);
volatile uint16_t tSec = 0;
volatile uint16_t tMsec = 0;
volatile uint16_t tFlag = 0;
volatile int Touched = 0;
volatile long tPeriod;

void setup() {
  pinMode(TOUCH, INPUT_PULLUP);
  tPeriod = 50000;
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT1, RISING);
  Timer1.initialize(tPeriod);
  Timer1.attachInterrupt(blinked);
  fnd.setBrightness(1);
  fnd.showNumberDecEx(0, 0x40, true);
}

void blinked(){
  if(Touched == 1){
    tMsec = tMsec + 5;
    if(tMsec == 100){
      tSec += 1;
      tMsec = 0;
    }
    tFlag = 1;
  }
  else{
    tFlag = 0;
    tMsec = 0;
    tSec = 0;
  }
}

void ISR_INT1(){
  Touched ^= 1;
}

void loop() {
  uint16_t num = 0;
  uint16_t dot = 0x40;
  if(tFlag == 1 && Touched == 1){
    num = tSec * 100 + tMsec;
    dot = ((tMsec % 50) == 0) ? 0 : 0x40; // 0.5초 마다 깜빡
    fnd.showNumberDecEx(num, dot, true);
    tFlag = 0;
  }
}