#define CDS 0
#define LED 3

unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    Serial.print("1초에 한 번 밝기 측정 : ");
    int value = analogRead(CDS);
    Serial.println(255 - value/4);
    analogWrite(LED, 255 - value/4);
  }
}