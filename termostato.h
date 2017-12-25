#ifndef termostato_h
#define termostato_h

#include "Arduino.h"
#include "math.h"



class termostato

{

  public:
  
  int setPinact(int pin);
  int setTempend(int temp); 
  void actionHot();
  void actionCold();
  int Thermistor(int pin);
  double getTemp();
  double setRes(double r);
  
  private:

  int tempEnd= 32;
  int pinAct = 2;
  int pinT=0;
  double temperature;
  double res = 10000;
};

#endif

