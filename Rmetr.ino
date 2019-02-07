#define L1 1  //Светодиодная шкала
#define L10 10
#define AI A0  //Алалоговый вход потенциометра

void setup() {
  for (int i=L10; i<=L1; i-=1) //Цикл присваивания выхода пинам с 1 по 10
  {
  pinMode(i,OUTPUT);
  }
}

void loop() {
  int R=map(analogRead(A0),0,1023,1,10); //Перевод значений напряжения в значения номеров пинов
  for (int i=L1; i<=R; i++)
  {
  digitalWrite(i,HIGH);
  delay(2);
  digitalWrite(i,LOW);
  };
}
