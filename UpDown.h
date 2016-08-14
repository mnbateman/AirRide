#ifndef UpDown_H
#define UpDown_H

#include <Arduino.h>
//#include <Equalize.h>

class UpDown{
  public:
    UpDown(const int, const int, const int, const int);
    ~UpDown();
    //void Equalize(const int, const int);
    void increaseRR();
    void decreaseRR();
    void equalRR();
    void increaseLR();
    void decreaseLR();
    void equalLR();
    private:
    int RRIPin;
    int RROPin;
    

};

#endif

