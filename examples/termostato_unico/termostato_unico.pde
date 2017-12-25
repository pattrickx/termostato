#include <termostato.h>
termostato termo;
void setup() {
   termo.setPinact(4); // seleciona pino de ação do termostato
   termo.setTempend(32); // seleciona temperatura de desligamento ou ligamento
   termo.Thermistor(0);  // seleciona pino de entrada do termisto 
   termo.setRes(10000);  // indica resistencia do termistor
   Serial.begin(9600);   // 
   
}

void loop() {
double temp= termo.getTemp(); //recebe temperatura 
 Serial.println(temp);        // imprime temperatura 
 termo.actionHot();           // função de aquecimento
}
