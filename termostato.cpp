#include "Arduino.h"

#include "termostato.h"
int termostato::setTempend(int temp)
{
	tempEnd=temp;
}

int termostato::setPinact(int pin)
{
 pinAct = pin;
}

void termostato::actionHot()
{pinMode(pinAct, OUTPUT);
	if ( temperature<tempEnd )
	{
		digitalWrite(pinAct,HIGH);
	}
	else{
	     digitalWrite(pinAct,LOW);
	
	}
}

void termostato::actionCold()
{   pinMode(pinAct, OUTPUT);
	if ( temperature>tempEnd )
	{
		digitalWrite(pinAct,HIGH);
	}
	else{
	     digitalWrite(pinAct,LOW);
	
	}
}

int termostato::Thermistor(int pin)
{
	pinT = pin;
	
}
double termostato::setRes(double r)
{
	res =r;
}
// codigo base http://www.arduino.cc/playground/ComponentLib/Thermistor2 



double termostato::getTemp()
{
	  int RawADC = analogRead(pinT);

  long Resistance;
  double Temp;

  
  Resistance=(((1024*res)/RawADC) - res);


  Temp = log(Resistance);
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Convert Kelvin to Celsius

   temperature = Temp;
  return Temp;  // Return the Temperature
	
}