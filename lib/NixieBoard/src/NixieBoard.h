/*
Library for my custom Nixie board. Not portable
Nathan Safran - 6/30/2023
*/

#ifndef NixieBoard_h
#define NixieBoard_h
#include "Arduino.h"

#define ALLON 15
#define BOTON 6
#define ALLOFF 0

class NixieBoard
{
  public:
    NixieBoard(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);
    void writeToNixieScroll(int hours, int minutes, int seconds, int divider);
    void writeToNixie(int hours, int minutes, int seconds, int divider);  //write numbers to the nixie tubes
    void writeToNixieRAW(int hours, int minutes, int seconds, int divider); //write arbitary data to the nixie tubes
    void antiPoison();

  private:
    int _dataPin;
    int _clockPin;
    int _latchPin;
    int _currentHours;
    int _currentMinutes;
    int _currentSeconds;
    int convertToNixe(int num); //convert 2 digit number to display on nixie tubes
  
    unsigned long _timeSinceLastScroll;

};

#endif
