#define ECHO_PIN 8
#define TRIG_PIN 7

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(measure());
}

int measure()
{
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);
  int distance = pulseIn(ECHO_PIN, HIGH, 15000) / 50;

  return constrain(distance, 1, 300);
}
  
