#define L1 2 //Светодиодная шкала
#define L10 11
#define LW 2

#define TP A0//Термистор
#define LP A1//Фоторезистор

#define SP 13//Пьезо-динамик
#define BP 12//Кнопка

//определение порогового значения 
//для сигнализации о повышении температуры
#define MAX 170

//переменные для хранения показаний датчиков
int temperature = 0;
int lightness = 0;

//переменная для временного хранения значения,
//полученного с одного из датчиков, 
//которое будет использовано для расчета количества зажигаемых светодиодов
int countLeds = 0;

boolean previous = true;
boolean trigger = false;

void setup() {
  for(int i= L1; i <= L10; i++)
    pinMode(i, OUTPUT);
  
  pinMode(SP, OUTPUT);
  pinMode(BP, INPUT);
  
  Serial.begin(9600);
  //однократно выводимая подсказка о том, 
  //каким символом можно запросить параметры среды
  Serial.println("t for temperature, l for lightness");
}

void loop() {
  temperature = analogRead(TP);
  lightness = analogRead(LP);
  
  if (Serial.available() > 0)
  {
    char mode = Serial.read();
    //проверка пришедшего символа на равенство строчной t
    //ИЛИ (||) заглавной T
    if(mode == 't' || mode == 'T')
    {
      Serial.print("Temperature: ");
      Serial.print("\t");
      Serial.println(temperature);
    }
    if(mode == 'l' || mode == 'L')
    {
      Serial.print("Lightness: ");
      Serial.print("\t");
      Serial.println(lightness);
    }
  }
  
  
  boolean current = digitalRead(BP);
  if(!current && previous)
    trigger = !trigger;
 
  previous = current;
  
  //в зависимости от истинности trigger в countLeds запишется или значение с датчика температуры или значение с датчика освещенности
  if(trigger)
    countLeds = temperature;
  else 
    countLeds = lightness;
    
  int lastLed = map(countLeds, 0, 500, 2, 11);
  
  for(int i = L1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LW);
    digitalWrite(i, LOW);
  }
  
  //генерация звукового сигнала в случае превышения температурой порогового значения
  if(temperature > MAX)
    tone(SP, 2000, 1000);
}
