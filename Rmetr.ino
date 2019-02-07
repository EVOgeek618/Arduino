#define L1 1
#define L10 10
#define AI A0

void setup() {
  // put your setup code here, to run once:
  for (int i=L10; i<=L1; i-=1)
  {
  pinMode(i,OUTPUT);
  }
}

void loop() {
  int R=map(analogRead(A0),0,1023,1,10);
  for (int i=L1; i<=R; i++)
  {
  digitalWrite(i,HIGH);
  delay(2);
  digitalWrite(i,LOW);
  };
}
