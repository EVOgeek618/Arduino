#define LED_PIN 3
#define IR_DIST_SENS A0

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int distance = analogRead(IR_DIST_SENS);
   
  Serial.println(distance);
  analogWrite(LED_PIN, map(distance,0,1023,0,255));
}

