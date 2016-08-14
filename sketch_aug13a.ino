
#include "Equalize.h"
#include "UpDown.h"
#include "DoSwitch.h"
int rideHeight = 65;
boolean party = true;
boolean tits = true;
Equalize eq(A0,A1);
DoSwitch action;
UpDown upDown(22,23,24,25) ;     // upDown(Right Rear 'airIN' relay, Right Rear 'airOUT' relay)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(41, OUTPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
  party = action.switchIt();
  //Serial.println("party");
  //Serial.println(party);
 
  if(party == false){                   //equalize here
      Serial.println("Blink");
      eq.makeMoves(rideHeight);
    }
    else{                               //defer to here once setup is proper
      digitalWrite(41, HIGH); 
     }
     //delay(500);
}






