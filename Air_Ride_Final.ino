#include <LiquidCrystal.h>
//#define HIGH 0x1
LiquidCrystal lcd(12,11,5,4,3,2);
int sensorval [] = {0,0,0,0};
int sensor[] = {0,1,2,3};                  // {FL,FR,RL,RR}
int pressureSensor[] = {A4,A5,A6,A7,(A8)};   // {FL,FR,RL,RR,(Tank)}
int upvalves[] = {28,26,24,22};            // {FL,FR,RL,RR}
int downvalves[] = {29,27,25,23};          // {FL,FR,RL,RR}
int setHeight = 50;
int waitCounter[][4] = {{0,0,0,0},{1,1,1,1},{2,2,2,2}};
int toggle [] = {40,42,44,46};          // toggle is a button or switch to trigger actions
boolean switchStatus = false;
int counter;

void setup() {
  lcd.begin(20,4);
  Serial.begin(9600);
  int i = 0;
  while(i < 3){
    pinMode(toggle[i], INPUT_PULLUP);
  i++;
  }
}

boolean switcher() {
  int i = 0;
  int p[4] = {0,0,0,0};
  while(i < 2){
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
    Serial.println("HIGH");                 // LOOP WHILE BUTTON IS HIGH
  }
  }
  else {
    Serial.println("LOW");            //LOOP WHEN SWITCHES OFF
    counter = 0;
  }
}
