#ifndef Equalize_H
#define Equalize_H

#include <Arduino.h>
//#include <UpDown.h>

    void increaseRR();
    void decreaseRR();
    void equalRR();
    void increaseLR();
    void decreaseLR();
    void equalLR();

class Equalize{
  public:
    //int _RRHeightPin;
    //int _LRHeightPin;
    Equalize(const int, const int);
    ~Equalize();
    void makeMoves(int);
  private:
    int rr_height;
    int num;

};

#endif
