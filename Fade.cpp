//      ******************************************************************
//      *                                                                *
//      *       Subroutines to support fading the LEDs up and down       *
//      *                                                                *
//      *             Stan Reifel                    1/26/13             *
//      *             Kyle Stewart                   3/11/16             *
//      *                                                                *
//      ******************************************************************

#include <Arduino.h> 
#include "Fade.h"


//
// global storage for PWM values
//
int ledPwm[lastLedNumber + 1];


//
//throb table - sinusoidal table normalize for eye linearity with a log function
//
const int throbTable[] PROGMEM = {
  0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 
  4, 4, 5, 6, 7, 8, 10, 12, 14, 17, 21, 26, 31, 38, 47, 57, 
  70, 85, 104, 126, 153, 185, 222, 266, 316, 375, 441, 516, 599, 691, 791, 899, 
  1012, 1130, 1250, 1370, 1487, 1599, 1702, 1793, 1870, 1931, 1972, 1993, 1993, 1972, 1931, 1870, 
  1793, 1702, 1599, 1487, 1370, 1250, 1130, 1012, 899, 791, 691, 599, 516, 441, 375, 316, 
  266, 222, 185, 153, 126, 104, 85, 70, 57, 47, 38, 31, 26, 21, 17, 14, 
  12, 10, 8, 7, 6, 5, 4, 4, 3, 3, 2, 2, 2, 2, 2, 1, 
  1, 1, 1, 1, 0, 0, 0, 0};


//------------------------------------------------------------------------


//
// constructor for the Fade class
//
Fade::Fade()
{
  //
  // configure the on/off switch as an input
  //
  pinMode(onOffSwitch, INPUT_PULLUP);
}


//------------------------------------------------------------------------
//                            Fading Up Subroutines
//------------------------------------------------------------------------

//
// fade up all the LEDs
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//
void Fade::up(byte fadeSpeed)
{
  byte allLedsArray[14] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15      };
  up(fadeSpeed, allLedsArray, sizeof(allLedsArray));
}

//
// fade up one or more LEDs, LEDs not specified are not changed
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//            ledArray = LED numbers to fade up
//            ledArrayLength = the number of LEDs to fade
//
void Fade::up(byte fadeSpeed, byte ledNumber)
{
  up(fadeSpeed, &ledNumber, 1);
}

void Fade::up(byte fadeSpeed, byte ledArray[], byte ledArrayLength)
{ 
  int tableStep;
  int PWMCycleCount;
  int tableIndex;
  int pwm;
  byte ledNum;
  byte ledIndex;
  int throbTableHalfLength;

  //
  // use the "fadeSpeed" value to compute how long the LEDs are on for each PWM cycle
  // and how quickly to step through the throb table
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);


  //
  // start with a PWM value for each LED set to 0, so LEDs not included in this 
  // fade will remain unchanged
  //
  for (ledNum = firstLedNumber; ledNum <= lastLedNumber; ledNum++)
  {
    ledPwm[ledNum] = 0;
  }


  //
  // loop to fade one or more LEDs up
  //
  throbTableHalfLength = getThrobTableHalfLength();
  for(tableIndex = 0; tableIndex < throbTableHalfLength; tableIndex += tableStep)
  { 
    //
    // check to see if the user has moved the knob.  if so, exit
    //
    if(getKnobPosition() != _knobZoneNumber) return;
    
    pwm = pgm_read_word(&throbTable[tableIndex]);

    for (ledIndex = 0; ledIndex < ledArrayLength; ledIndex++)
    {
      ledNum = ledArray[ledIndex];
      ledPwm[ledNum] = pwm;
    }

    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }

  
  //
  // after the fade, leave the LEDs turned on
  //
  for (ledIndex = 0; ledIndex < ledArrayLength; ledIndex++)
  {
    ledNum = ledArray[ledIndex];
    digitalWrite(ledNum, HIGH);
  }

}



//------------------------------------------------------------------------
//                            Fading Down Subroutines
//------------------------------------------------------------------------

//
// fade down all the LEDs
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//
void Fade::down(byte fadeSpeed)
{
  byte allLedsArray[14] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15      };
  down(fadeSpeed, allLedsArray, sizeof(allLedsArray));
}

//
// fade down one or more LEDs, LEDs not specified are not changed
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//            ledArray[] = LED numbers to fade down
//            ledArrayLength = the number of LEDs to fade
//

void Fade::down(byte fadeSpeed, byte ledNumber)
{
  down(fadeSpeed, &ledNumber, 1);
}

void Fade::down(byte fadeSpeed, byte ledArray[], byte ledArrayLength)
{ 
  int tableStep;
  int PWMCycleCount;
  int tableIndex;
  int pwm;
  byte ledNum;
  byte ledIndex;
  int throbTableHalfLength;

  //
  // start with a PWM value for each LED set to 0, so LEDs no included in this 
  // fade will remain unchanged
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);


  //
  // start with a PWM value for each LED set to 0, so LEDs not included in this 
  // fade will remain unchanged
  //
  for (ledNum = firstLedNumber; ledNum <= lastLedNumber; ledNum++)
  {
    ledPwm[ledNum] = 0;
  }

  //
  // loop to fade one or more LEDs down
  //
  throbTableHalfLength = getThrobTableHalfLength();
  for(tableIndex = throbTableHalfLength; tableIndex >= 0; tableIndex -= tableStep)
  { 
    //
    // check to see if the user has moved the knob.  if so, exit
    //
    if(getKnobPosition() != _knobZoneNumber) return;
    
    pwm = pgm_read_word(&throbTable[tableIndex]);

    for (ledIndex = 0; ledIndex < ledArrayLength; ledIndex++)
    {
      ledNum = ledArray[ledIndex];
      ledPwm[ledNum] = pwm;
    }

    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }

  //
  // after the fade, leave the LED turned off
  //
  for (ledIndex = 0; ledIndex < ledArrayLength; ledIndex++)
  {
    ledNum = ledArray[ledIndex];
    digitalWrite(ledNum, LOW);
  }
}


//------------------------------------------------------------------------
//                         Cross Fading Subroutines
//------------------------------------------------------------------------

//
// fade one LED up and at the same time fade a different LED down, LEDs not specified are not changed
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//            upArray[] = the LED numbers to fade up
//            upArrayLength = the number of LEDs in the upArray
//            downArray[] = the LED numbers to fade down
//            downArrayLength = the number of LEDs in the downArray
//

void Fade::crossFade(byte fadeSpeed, byte upNumber, byte downNumber)
{
  crossFade(fadeSpeed, &upNumber, 1, &downNumber, 1);
}

void Fade::crossFade(byte fadeSpeed, byte upArray[], byte upArrayLength, byte downArray[], byte downArrayLength)
{ 
  int tableStep;
  int PWMCycleCount;
  int upTableIndex;
  int downTableIndex;
  int pwm;
  byte ledNum;
  byte ledIndex;
  int throbTableHalfLength;

  //
  // use the "fadeSpeed" value to compute how long the LEDs are on for each PWM cycle
  // and how quickly to step through the throb table
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);


  //
  // start with a PWM value for each LED set to 0, so LEDs no included in this 
  // fade will remain unchanged
  //
  for (ledNum = firstLedNumber; ledNum <= lastLedNumber; ledNum++)
  {
    ledPwm[ledNum] = 0;
  }

  //
  // loop to fade LEDs
  //
  throbTableHalfLength = getThrobTableHalfLength();
  downTableIndex = throbTableHalfLength;
  for(upTableIndex = 0; upTableIndex < throbTableHalfLength; upTableIndex += tableStep, downTableIndex -= tableStep)
  { 
    //
    // check to see if the user has moved the knob.  if so, exit
    //
    if(getKnobPosition() != _knobZoneNumber) return;
    
    pwm = pgm_read_word(&throbTable[upTableIndex]);
    for (ledIndex = 0; ledIndex < upArrayLength; ledIndex++)
    {
      ledNum = upArray[ledIndex];
      ledPwm[ledNum] = pwm;
    }

    pwm = pgm_read_word(&throbTable[downTableIndex]);
    for (ledIndex = 0; ledIndex < downArrayLength; ledIndex++)
    {
      ledNum = downArray[ledIndex];
      ledPwm[ledNum] = pwm;
    }

    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }

  //
  // after the fade, turn the downs off, and the ups on
  //
  for (ledIndex = 0; ledIndex < upArrayLength; ledIndex++)
  {
    ledNum = upArray[ledIndex];
    digitalWrite(ledNum, HIGH);
  }
  for (ledIndex = 0; ledIndex < downArrayLength; ledIndex++)
  {
    ledNum = downArray[ledIndex];
    digitalWrite(ledNum, LOW);
  }
}


//------------------------------------------------------------------------
//                            Night Light Subroutines
//------------------------------------------------------------------------

//
// display all the LEDs using a brightness set by the knob, as long as the knob is in zone 3
//
void Fade::nightLightMode()
{ 
  byte knobZone;
  int pwm;
  byte ledNumber;
  int tableIndex;
  int knobZoneValue;

  while(true)
  {
    //
    // check if the knob is not in starting knob zone, if not then return
    //
    knobZone = getKnobPosition(&knobZoneValue);
    if (knobZone != _knobZoneNumber)
    {
      return;
    }

    //
    // determine a PWM value from the knob
    //
    tableIndex = map(knobZoneValue, 0, 320, 0, getThrobTableHalfLength());
    pwm = pgm_read_word(&throbTable[tableIndex]);

    //
    // set the LED brightness
    //
    for (ledNumber = firstLedNumber; ledNumber <= lastLedNumber; ledNumber++)
    {
      ledPwm[ledNumber] = pwm;
    }
    pwmAllPins(1);
  }  
}


//------------------------------------------------------------------------
//                             Knob Subroutines
//------------------------------------------------------------------------

//
// return the state of the user mode and update _knobZoneNumber
//    Exit:  0 returned if on/off switch in the off position
//           1 returned if in the left zone
//           2 returned if in the middle zone
//           3 returned if in the right zone
//           -1 returned if in the no zone
//
byte Fade::getInitialKnobPosition()
{ 
  int ZoneValue;
  
  _knobZoneNumber = getKnobPosition(&ZoneValue);

  return(_knobZoneNumber);
}

//
// return the state of the user mode
//    Exit:  0 returned if on/off switch in the off position
//           1 returned if in the left zone
//           2 returned if in the middle zone
//           3 returned if in the right zone
//           -1 returned if in the no zone
//
byte Fade::getKnobPosition()
{ 
  int ZoneValue;

  return(getKnobPosition(&ZoneValue));
}



//
// return the state of the user mode
//    Exit:  0 returned if on/off switch in the off position
//           1 returned if in the left zone
//           2 returned if in the middle zone
//           3 returned if in the right zone
//           -1 returned if in the no zone
//          *ZoneValue = where in the zone the knob is in (0 to 330)
//
byte Fade::getKnobPosition(int *ZoneValue)
{ 
  int knobZone;
  int analogValue;
  const int ZoneWidth = 330;
  const int startOfZoneOne = 0;
  const int startOfZoneTwo = (1023 / 2) - (ZoneWidth / 2);
  const int startOfZoneThree = 1023 - ZoneWidth;


  //
  // check if the on/off switch is off
  // 
  if (digitalRead(onOffSwitch) == HIGH)
  {
    *ZoneValue = 0;
    turnOffAllLeds();
    knobZone = 0;
    return(knobZone);
  }

  //
  // switch is on, read the pot position
  //
  analogValue = analogRead(5);


  //
  // determine what zone the knob is in
  //
  if ((analogValue >= startOfZoneOne) && (analogValue <= startOfZoneOne + ZoneWidth))
  {
    *ZoneValue = analogValue - startOfZoneOne;
    knobZone = 1;
    return(knobZone);
  }

  if ((analogValue >= startOfZoneTwo) && (analogValue <= startOfZoneTwo + ZoneWidth))
  {
    *ZoneValue = analogValue - startOfZoneTwo;
    knobZone = 2;
    return(knobZone);
  }

  if ((analogValue >= startOfZoneThree) && (analogValue <= startOfZoneThree + ZoneWidth))
  {
    *ZoneValue = analogValue - startOfZoneThree;
    knobZone = 3;
    return(knobZone);
  }

  *ZoneValue = 0;
  turnOffAllLeds();
  knobZone = -1;
  return(knobZone);
}


//
// delay the requested amount unless the knob switches out of the current zone
// Enter: delayTime is the desired length of delay in milliseconds
// Exit : true if the knob has changed zones
//        false otherwise
// 
boolean Fade::delayAndCheckForExit(int delayTime)
{
  unsigned long startTime = millis(); // get the Arduino clock time to begin
  
  //
  // continue looking for the knob to leave the current zone during delay
  //
  while(millis() < startTime + delayTime)
  {
    if(getKnobPosition() != _knobZoneNumber) return true;
  }
  
  // after the delay is over, return false to indicate the current zone did not change
  return false;
}
  

//------------------------------------------------------------------------
//                           Support Subroutines
//------------------------------------------------------------------------

//
// turn off all the LEDs
//
void Fade::turnOffAllLeds()
{
  byte ledNumber;

  for (ledNumber = firstLedNumber; ledNumber <= lastLedNumber; ledNumber++)
  {
    digitalWrite(ledNumber, LOW);
  }  
}



//
// use the "fadeSpeed" value to compute how long the LEDs are on for 
// each PWM cycle and how quickly to step through the throb table
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//
void Fade::getFadeSpeedValues(byte fadeSpeed, int *PWMCycleCount, int *tableStep)
{
  switch(fadeSpeed)
  {
  case 10:
    {
      *PWMCycleCount = 1;
      *tableStep = 10;
      break;
    }

  case 9:
    {
      *PWMCycleCount = 1;
      *tableStep = 8;
      break;
    }

  case 8:
    {
      *PWMCycleCount = 1;
      *tableStep = 6;
      break;
    }

  case 7:
    {
      *PWMCycleCount = 1;
      *tableStep = 4;
      break;
    }

  case 6:
    {
      *PWMCycleCount = 1;
      *tableStep = 3;
      break;
    }

  case 5:
    {
      *PWMCycleCount = 1;
      *tableStep = 2;
      break;
    }

  case 4:
    {
      *PWMCycleCount = 1;
      *tableStep = 1;
      break;
    }

  case 3:
    {
      *PWMCycleCount = 2;
      *tableStep = 1;
      break;
    }

  case 2:
    {
      *PWMCycleCount = 3;
      *tableStep = 1;
      break;
    }

  case 1:
    {
      *PWMCycleCount = 5;
      *tableStep = 1;
      break;
    }

  default:
    {
      *PWMCycleCount = 1;
      *tableStep = 1;
      break;
    }
  }
}



//
// get the length of the throb table (the size of the array)
//
int Fade::getThrobTableLength()
{
  return(sizeof(throbTable) / sizeof(int));
}



//
// get half the length of the throb table (the size of the array)
//
int Fade::getThrobTableHalfLength()
{
  return((sizeof(throbTable) / sizeof(int)) / 2);
}



//
// PWM all pins with a value between 0 and 2000, for aprox n milliseconds
//    Enter:  ledPwm[] contains the array of PWM values, corresponding to each LED
//            PWMCycleCount = number of times the PWM should be cycled.  Typical values
//              are 1 or 2 or 3
//
void Fade::pwmAllPins(int PWMCycleCount)
{ 
  int i;
  int j;

  for (j = 0; j < PWMCycleCount; j++)
  { //
    // turn on all LEDS that have a PWM value greater than 0
    //
    if (ledPwm[2]) bitSet(PORTD, 2); 
    if (ledPwm[3]) bitSet(PORTD, 3); 
    if (ledPwm[4]) bitSet(PORTD, 4); 
    if (ledPwm[5]) bitSet(PORTD, 5); 
    if (ledPwm[6]) bitSet(PORTD, 6); 
    if (ledPwm[7]) bitSet(PORTD, 7);
    if (ledPwm[8]) bitSet(PORTB, 0); 
    if (ledPwm[9]) bitSet(PORTB, 1); 
    if (ledPwm[10]) bitSet(PORTB, 2);  
    if (ledPwm[11]) bitSet(PORTB, 3);  
    if (ledPwm[12]) bitSet(PORTB, 4); 
    if (ledPwm[13]) bitSet(PORTB, 5); 
    if (ledPwm[14]) bitSet(PORTC, 0); 
    if (ledPwm[15]) bitSet(PORTC, 1); 

    //
    // loop for one PWM cycle, turning off each LED at the right PWM value
    //
    for (i = 1; i <= 2000; i++)
    { 
      if (i == ledPwm[2]) bitClear(PORTD, 2);
      if (i == ledPwm[3]) bitClear(PORTD, 3);
      if (i == ledPwm[4]) bitClear(PORTD, 4);
      if (i == ledPwm[5]) bitClear(PORTD, 5);
      if (i == ledPwm[6]) bitClear(PORTD, 6);
      if (i == ledPwm[7]) bitClear(PORTD, 7);
      if (i == ledPwm[8]) bitClear(PORTB, 0);
      if (i == ledPwm[9]) bitClear(PORTB, 1);
      if (i == ledPwm[10]) bitClear(PORTB, 2);
      if (i == ledPwm[11]) bitClear(PORTB, 3);
      if (i == ledPwm[12]) bitClear(PORTB, 4);
      if (i == ledPwm[13]) bitClear(PORTB, 5);
      if (i == ledPwm[14]) bitClear(PORTC, 0);
      if (i == ledPwm[15]) bitClear(PORTC, 1);
    }
  }
}





