#define TOUCH 9
#define LED 3
#define BAUDRATE 9600

uint8_t prevTouch = 0;
uint8_t currTouch = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  pinMode(TOUCH, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currTouch = digitalRead(TOUCH);
  if( (prevTouch == HIGH) && (currTouch == LOW)){
    digitalWrite(LED,LOW);
    Serial.println("Not Touched!");
  }
  else if((prevTouch == LOW) && (currTouch == HIGH)){
    digitalWrite(LED,HIGH);
    Serial.println("Touched!");
  }
  prevTouch = currTouch;
}