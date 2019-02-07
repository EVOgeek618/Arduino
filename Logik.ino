#define LP 13
#define BP 7

boolean tr = false;
boolean pr = false;

void setup() {
  pinMode(LP,OUTPUT);
  pinMode(BP,INPUT);

}

void loop() {
  int cur = digitalRead(BP);
  if (cur && !pr)
  {
    tr=!tr;
  }
  pr=cur;
  digitalWrite(LP,tr);
  }
