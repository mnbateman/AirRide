#include "DoSwitch.h"

int switchPin = 40;
  int switchState;    //On = 0, Off = 1
  int oldSwitchState = HIGH; //On = 0, Off = 1
  boolean doit;
  

DoSwitch::DoSwitch(){
  pinMode(switchPin, INPUT_PULLUP);
  //switchState = LOW;
}

DoSwitch::~DoSwitch(){/* nothing to destruct*/}


boolean DoSwitch::switchIt(){
 
  switchState = digitalRead(switchPin);
      
  if (switchState != oldSwitchState){
      doit = false;
      oldSwitchState = switchState;
    }
  else {
      doit = true;
      
    }
    return doit;
    
  
 

    }
  


