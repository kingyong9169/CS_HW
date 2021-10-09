#define LED 7
#define TOUCH 3

uint8_t ledValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledValue);
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT1, CHANGE);
  ledValue = 0;
}

void ISR_INT1() {
  ledValue ^= 1;
  digitalWrite(LED, ledValue);
}

void loop() {
  // do nothing
}
