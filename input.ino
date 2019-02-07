#define LED_PIN 13 //светодиод
#define DIGITAL_IN 7 //кнопка
void setup() {
  
pinMode(LED_PIN,OUTPUT);
pinMode(DIGITAL_IN,INPUT_PULLUP);
}

void loop() {
 digitalWrite(LED_PIN,!digitalRead(DIGITAL_IN));

}
