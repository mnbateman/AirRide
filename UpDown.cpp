

                /*            HIGH = no power @ relay !!!             */

#include "UpDown.h"

  int _RRIPin;
  int _RROPin;
  int _LRIPin;
  int _LROPin;
  //int _RRHeightPin;
 // int _LRHeightPin;

UpDown::UpDown(const int RRIPin, const int RROPin, const int LRIPin, const int LROPin){
   _RRIPin = RRIPin;
   _RROPin = RROPin;
   _LRIPin = LRIPin;
   _LROPin = LROPin;
  pinMode(RRIPin, OUTPUT);    //Right Rear (air) In Pin
  pinMode(RROPin, OUTPUT);    //Right Rear (air) Out Pin
  pinMode(LRIPin, OUTPUT);    //Left Rear (air) In Pin
  pinMode(LROPin, OUTPUT);    //Left Rear (air) Out Pin
  digitalWrite(RRIPin, HIGH);      //No Power @ AirIN relay
  digitalWrite(RROPin, HIGH);      //No Power @ AirOUT relay
  digitalWrite(LRIPin, HIGH);      //No Power @ AirIN relay
  digitalWrite(LROPin, HIGH);      //No Power @ AirOUT relay
}

UpDown::~UpDown(){/* nothing to destruct*/}

/*void UpDown::Equalize(const int RRHeightPin, const int LRHeightPin){
  _RRHeightPin = RRHeightPin;
  _LRHeightPin = LRHeightPin;
pinMode(_RRHeightPin, INPUT);
pinMode(_LRHeightPin, INPUT);
}
*/

void UpDown::increaseRR(){    //RIGHT
  digitalWrite(_RRIPin, LOW);       //Power @ AirIN relay
  digitalWrite(_RROPin, HIGH);      //No Power @ AirOUT relay
  Serial.println(_RRIPin);
  delay(500);
}

void UpDown::increaseLR(){    //LEFT
  digitalWrite(_LRIPin, LOW);       //Power @ AirIN relay
  digitalWrite(_LROPin, HIGH);      //No Power @ AirOUT relay
  Serial.println(_LRIPin);
  delay(500);
}

void UpDown::decreaseRR(){    //RIGHT
  digitalWrite(_RROPin, LOW);       //Power @ AirOUT relay
  digitalWrite(_RRIPin, HIGH);      //No Power @ AirIN relay
  Serial.println(_RROPin);
  delay(500);
}

void UpDown::decreaseLR(){    //LEFT
  digitalWrite(_LROPin, LOW);       //Power @ AirOUT relay
  digitalWrite(_LRIPin, HIGH);      //No Power @ AirIN relay
  Serial.println(_LROPin);
  delay(500);
}

void UpDown::equalRR(){       //RIGHT
  digitalWrite(_RRIPin, HIGH);      //No Power @ AirIN relay
  digitalWrite(_RROPin, HIGH);      //No Power @ AirOUT relay
}

void UpDown::equalLR(){       //LEFT
  digitalWrite(_LRIPin, HIGH);      //No Power @ AirIN relay
  digitalWrite(_LROPin, HIGH);      //No Power @ AirOUT relay
}


