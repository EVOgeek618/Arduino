#define LED_PIN 3
#define IR_DIST_SENS A0
#define MA 10

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int distance = measure(IR_DIST_SENS);
  Serial.println(distance);
  analogWrite(LED_PIN, map(distance, 0, 1023, 0, 255));
}
int measure(int pin)
{
  static int measurements[MA];

  for (int i = 0; i < MA - 1; i++)
  {
    measurements[i] = measurements[i + 1];
  }
  measurements[MA - 1] = analogRead(pin);

  
  long mean = 0;
  //на этот раз цикл идет до последнего элемента массива
  for (int i = 0; i < MA; i++)
  {
    mean += measurements[i];
  }
  return mean /= MA;
}
