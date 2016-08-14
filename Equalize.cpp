#include "Equalize.h"
#include "UpDown.h"

int _RRHeightPin;
int _LRHeightPin;
int _setHeight;

Equalize::Equalize(const int RRHeightPin, const int LRHeightPin){
  _RRHeightPin = RRHeightPin;
  _LRHeightPin = LRHeightPin;
pinMode(_RRHeightPin, INPUT);
pinMode(_LRHeightPin, INPUT);
}
Equalize::~Equalize(){}

void Equalize::makeMoves(int setHeight){
    _setHeight = setHeight;
    rr_height = analogRead(_RRHeightPin);
  num = rr_height / 10;
  
    if (num == _setHeight){          // if sensor = set height
      Serial.println("equal");
      Serial.println(num);
      Serial.println(_setHeight);
      UpDown equalRR();
    }
    else if (num > _setHeight){        //if sensor > set height
      Serial.println("Low");
      Serial.println(num);
      Serial.println(_setHeight);
      UpDown decreaseRR();
    }
    else if (num < _setHeight){
      //lcd.clear();
      Serial.println("High");
      Serial.println(num);
      Serial.println(_setHeight);
      UpDown increaseRR();
      }
}

