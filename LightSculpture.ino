
//      ******************************************************************
//      *                                                                *
//      *     Arduino program light display for the Light sculpture      *
//      *                                                                *
//      *          YourNameGoesHere          TodaysDateGoesHere          *
//      *                                                                *
//      ******************************************************************

//
// Do not edit setup or loop in this program.
//
//  Your modifications should be made in the following locations:
//
// 0. Make sure you have REPLACED the YourLastFirstName with your actual LastFirstName of this file and the folder 
// 
// 1. Edit the Title Block above and replace YourNameGoesHere with your LastFirstName AND ENTER TodaysDate
//
// 2. Adding your own function definitions in the correct areas labeled with comments
//
// 3. Replace your delays with   if (fade.delayAndCheckForExit(delayTime, zoneNumber) == true) return;
//
// 4. Begin entering LightShow function calls inside the runLightShow function definition
//
// 5. Begin entering BackgroundShow function calls inside the runBackgroundShow function definition
//
// 6. After each fade, check if you need to exit with     if (fade.getKnobPosition() != zoneNumber) return;
//
// 7. Feel free to use, modify, or remove the example function definitions listed below:
//
//         void fadeShowAllTheColors(int onTime, int offTime, int repeatCount, int fadeSpeed, int zoneNumber)
//         void blinkSingleLedsGoingClockwise(int onTime, int offTime, int repeatCount, int zoneNumber)
//         void fadeBlinkSingleLedsGoingClockwise(int onTime, int offTime, int repeatCount, int fadeSpeed, int zoneNumber)
//         void crossFadeRightAndLeft(int onTime, int offTime, int repeatCount, int fadeSpeed, int zoneNumber)
//
//  Beware that changing other sections may cause your code to fail.
//
//                          Mr. Harlow & Mr. Stewart
//
//

#include "Fade.h"
Fade fade;

//
// top level setup function
//
void setup()
{  
  Serial.begin(115200); // Open serial monitor at 9600 baud for debuging using Serial.print Commands
  Serial.println("");       // prints a new line
  Serial.print("Beginning setup"); // prints "Begining setup" to the screen
  Serial.println("");       // prints a new line

  int pinNum;

  //
  // configure the LED pins as outputs
  //
  for(pinNum = firstLedNumber; pinNum <= lastLedNumber; pinNum++)
  {
    pinMode(pinNum, OUTPUT); 
//    Serial.print("pinNum  "); // prints "pinNum" to the screen
//    Serial.print(pinNum);     // prints the VALUE of pinNum to the screen
//    Serial.println("");       // prints a new line 
  } 

  Serial.println("Setup Complete"); // prints "Setup Complete" to the screen

}

//
// select the displays using the position of the knob
//
void loop()
{ 
  //
  // get the zone number that the knob is in:
  //  0 = off, 1 = light show, 2 = background, 3 = nightlight
  //
  byte knobZoneNumber = fade.getInitialKnobPosition();
  
  //
  // turn off all LEDs before starting the next show
  //
  fade.turnOffAllLeds();

  //
  // run the light show if knob in zone 1
  //
  if (knobZoneNumber == 1)
  {
    runLightShow();
  }

  //
  // run the background show if knob in zone 2
  //
  if (knobZoneNumber == 2)
  {
    runBackgroundShow();
  }

  //
  // run the nightlight if knob in zone 3
  //
  if (knobZoneNumber == 3)
  {
    fade.nightLightMode();
  }
}

