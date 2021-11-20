#include <TM1637Display.h>

#define LED 3
#define DIO 11
#define CLK 10

TM1637Display FND(CLK, DIO);
String input = "";
String num = "";
bool stringComplete = false;

void fndEvent();

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("직렬통신 명령 처리기");
  FND.setBrightness(0x04);
}

void loop() {
  if(stringComplete){
    Serial.println(input);
    if(input == "LED ON" || input == "led on") digitalWrite(LED, HIGH);
    else if(input == "LED OFF" || input == "led off") digitalWrite(LED, LOW);
    else if(input.startsWith("FND ") || input.startsWith("fnd ")) fndEvent();
    else Serial.println("Command error");
    
    input = "";
    stringComplete = false;
  }
}

void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read();
    if(inChar !='\n') input += inChar;
    else if(inChar =='\n') stringComplete = true;    
  }
}

void fndEvent(){
  int len = input.length();
  num = "";
  for(int n = 4 ; n < len ; n++){
    char ch = input.charAt(n);
    if(ch >= '0' && ch <= '9') num += ch;
    else{
      Serial.println("Command error");
      return;
    }
  }
  if(num.length() <= 4) FND.showNumberDec(num.toInt());
  else Serial.println("Command error");
}