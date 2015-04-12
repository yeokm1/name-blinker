#include "LowPower.h"

#define NUM_LETTERS 9

#define PIN_K1 A5
#define PIN_H2 A4
#define PIN_E3 A3
#define PIN_N4 A2
#define PIN_G5 11

#define PIN_M6 2
#define PIN_E7 3 
#define PIN_N8 9
#define PIN_G9 10

const int PINS[NUM_LETTERS] = {PIN_K1, PIN_H2, PIN_E3, PIN_N4, PIN_G5
                    , PIN_M6, PIN_E7, PIN_N8, PIN_G9};

int currentPinToLight = 0;

void setup() {
  pinMode(PIN_K1, OUTPUT);
  pinMode(PIN_H2, OUTPUT);
  pinMode(PIN_E3, OUTPUT);
  pinMode(PIN_N4, OUTPUT);
  pinMode(PIN_G5, OUTPUT);
  
  pinMode(PIN_M6, OUTPUT);
  pinMode(PIN_E7, OUTPUT);
  pinMode(PIN_N8, OUTPUT);
  pinMode(PIN_G9, OUTPUT);

}

void loop() {
  if(currentPinToLight >= NUM_LETTERS){
    currentPinToLight = 0;
  }
  
  
  onlyTurnOnThisLED(currentPinToLight);
  
 
  currentPinToLight++;
  
  customDelay();
}


void onlyTurnOnThisLED(int pinPositionNumber){

  for(int currentPos = 0; currentPos < NUM_LETTERS; currentPos++){

    if(currentPos == pinPositionNumber){
      digitalWrite(PINS[currentPos], HIGH);
    } else {
      digitalWrite(PINS[currentPos], LOW);
    }  
  }
}

void customDelay(){
  LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_250MS, ADC_OFF, BOD_OFF);
}
