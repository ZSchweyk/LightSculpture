//      ******************************************************************
//      *                                                                *
//      *               DPEA LED Sculpture - Fading Class                *
//      *                                                                *
//      *             Stan Reifel  v1                1/26/13             *
//      *             Kyle Stewart v2                3/11/16             *
//      *                                                                *
//      ******************************************************************

#ifndef Fade_h
#define Fade_h
#include <avr/pgmspace.h>
#include <Arduino.h>

//
// IO pin constants
//
const byte firstLedNumber = 2;
const byte lastLedNumber = 15;
const byte onOffSwitch = 18;


//
// global storage for PWM values
//

extern const int throbTable[] PROGMEM;


//
// the Fade class
//
class Fade
{
public:

  Fade();
  // fade.up
  void up(byte fadeSpeed);                                       // fade up the entire set of LEDs with fadeSpeed
  void up(byte fadeSpeed, byte ledNumber);                       // fade up a single LEDs with fadeSpeed
  void up(byte fadeSpeed, byte ledArray[], byte ledArrayLength); // fade up an array of LEDs with fadeSpeed
  
  void down(byte fadeSpeed);                                       // fade down the entire set of LEDs with fadeSpeed
  void down(byte fadeSpeed, byte ledNumber);                       // fade down a single LEDs with fadeSpeed
  void down(byte fadeSpeed, byte ledArray[], byte ledArrayLength); // fade down an array of LEDs with fadeSpeed

  // crossFade 
  void crossFade(byte fadeSpeed, byte upNumber, byte downNumber);
  void crossFade(byte fadeSpeed, byte upArray[], byte upArrayLength, byte downArray[], byte downArrayLength);
  
  void nightLightMode();

  byte getInitialKnobPosition();    
  byte getKnobPosition();
  byte getKnobPosition(int *ZoneValue);
  boolean delayAndCheckForExit(int delayTime);
  
  void turnOffAllLeds();

private:

  byte _knobZoneNumber;
  
  void getFadeSpeedValues(byte fadeSpeed, int *PWMCycleCount, int *tableStep);
  int getThrobTableLength();
  int getThrobTableHalfLength();
  void pwmAllPins(int PWMCycleCount);
};

#endif


