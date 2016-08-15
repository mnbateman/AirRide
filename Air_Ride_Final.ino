#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float heightval [] = {0,0,0,0};
int sensorlcd[] = {0,5,10,15};               // {FL,FR,RL,RR}
int heightSensor[] = {A0,A1,A2,A3};        // {FL,FR,RL,RR} ---ANALOG
int pressureSensor[] = {A4,A5,A6,A7,A8};        // {FL,FR,RL,RR,(Tank)} ---ANALOG
int upvalves[] = {28,26,24,22};              // {FL,FR,RL,RR}
int downvalves[] = {29,27,25,23};            // {FL,FR,RL,RR}
int setheight = 500;
int waitCounter[][4] = {{0,0,0,0},{1,1,1,1},{2,2,2,2}};
int toggle [] = {40,42,44,46};          // toggle is a button or switch to trigger actions
boolean switchStatus = false;
int counter;

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  int i = 0;
  while(i < 4){
    Serial.println(heightSensor[i]);
    pinMode(toggle[i], INPUT_PULLUP);
    pinMode(heightSensor[i], INPUT);
    pinMode(pressureSensor[i], INPUT);
    pinMode(upvalves[i], OUTPUT);
    pinMode(downvalves[i], OUTPUT);
  i++;
  }
  
      lcd.begin(20,4);
      lcd.setCursor(sensorlcd[0],0);
      lcd.print("FL");
      lcd.setCursor(sensorlcd[1],0);
      lcd.print("FR");
      lcd.setCursor(sensorlcd[2],0);
      lcd.print("RL");
      lcd.setCursor(sensorlcd[3],0);
      lcd.print("RR");
      lcd.setCursor(sensorlcd[0],1);
      lcd.print("00");
      lcd.setCursor(sensorlcd[1],1);
      lcd.print("00");
      lcd.setCursor(sensorlcd[2],1);
      lcd.print("00");
      lcd.setCursor(sensorlcd[3],1);
      lcd.print("00");
      delay(1000);
  
  
  
      
}
// ------------------- adjust bags ------------------------
void adjustBags() {
int i = 0;
int where[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
while(i < 4){
  heightval[i] = analogRead(heightSensor[i]);
  Serial.print(heightSensor[i]);Serial.print("_");Serial.println(heightval[i]);
  lcd.setCursor(sensorlcd[i],1);
  lcd.print(heightval[i]);
  i++;
}







  
}

// ------------------- adjust bags -------------------------
boolean switcher() {
  int i = 0;
  int p[4] = {0,0,0,0};
  while(i < 4){
      if(digitalRead(toggle[i]) == LOW){
        //Serial.print("button on-");Serial.println(i);
        p[i] = 1;  
       }
       else{
        p[i] = 0;
       }
    i++;
    }
    if ((p[0] + p[1] + p[2] + p[3]) > 0) {switchStatus = true;}
    else if ((p[0] + p[1] + p[2] + p[3]) == 0){switchStatus = false;}
    //Serial.println(switchStatus);Serial.println("");
    return switchStatus;
  }

void loop() {
    int buttonState1;
    int previousbuttonState1;
    buttonState1 = switcher();
  if (buttonState1 == true) {
    //Serial.println(counter);
    if (buttonState1 == true && counter == 0) {
      Serial.println("ONCE-----");          // RUN ONLY ONCE
      counter++;
    }
    else{
      adjustBags();
    Serial.println("HIGH");                 // LOOP WHILE BUTTON IS HIGH
  }
  }
  else {
    Serial.println("LOW");            //LOOP WHEN SWITCHES OFF
    counter = 0;
  }
}
