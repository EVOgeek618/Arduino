#define RS 13
#define YS 12
#define GS 11

int red_on=20000;
int red_yellow_on=3000;
int yellow_on=2000;
int green_on=15000;
int green_blink=500;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RS, OUTPUT);
  pinMode(YS, OUTPUT);
  pinMode(GS, OUTPUT);
}
void loop() {
  digitalWrite(GS, HIGH); //Работа зеленого светодиода
  delay(green_on);                          
  for (int i=0; i<3; i++){  //цикл мигания ЗС
    digitalWrite(GS, LOW);
    delay(green_blink);
    digitalWrite(GS, HIGH); 
    delay(green_blink);
    };
  digitalWrite(GS, LOW);
  digitalWrite(YS, HIGH);
  delay(yellow_on);
  digitalWrite(YS, LOW);
  digitalWrite(RS, HIGH); //Смена ЗС на КС
  delay(red_on);
  digitalWrite(YS, HIGH); //Включение ЖС
  delay(red_yellow_on);
  digitalWrite(RS, LOW);
  digitalWrite(YS, LOW);                     
}
