#define LED_PIN 13
#define DIGITAL_IN 7
void setup() {
  // put your setup code here, to run once:
pinMode(LED_PIN,OUTPUT);
pinMode(DIGITAL_IN,INPUT_PULLUP);
}

void loop() {
 digitalWrite(LED_PIN,!digitalRead(DIGITAL_IN));

}
