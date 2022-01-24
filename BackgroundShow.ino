//------------------------------------------------------------------------
//                        BackgroundShow Function Calls
//------------------------------------------------------------------------
// run the "Background Show" while the knob is in zone 2
//
// THIS SHOULD be a list of function calls to functions defined in the BackgroundShow or Shared function definitions area
//
void runBackgroundShow()
{
  unsigned long startTime; // time we begin the light show, in milliseconds
  int intermissionDelay = 400; // brief pause between displays
  int postShowDelay = 2000; // longer delay at the end of the show
  
  Serial.println("Beginning Background Show.");
    
  //first display
  fadeBlinkSingleLedsGoingClockwise(100, 100, 1, 5); 
  if (fade.delayAndCheckForExit(intermissionDelay) == true) return;   // check knob during intermission

  //second display
  fadeShowAllTheColors(500, 1000, 1, 2);
  if (fade.delayAndCheckForExit(intermissionDelay) == true) return;   // check knob during intermission
  
  // third display
  crossFadeRightAndLeft(100, 100, 5, 2);
  if (fade.delayAndCheckForExit(intermissionDelay) == true) return;   // check knob during intermission
  
  if (fade.delayAndCheckForExit(postShowDelay) == true) return;   // check knob during intermission
  
  Serial.print(" Background Show finished.  Run time in milliseconds: ");
  Serial.println(millis() - startTime);
}



//------------------------------------------------------------------------
//                        BackgroundShow Function Definitions
//------------------------------------------------------------------------
// All your function definitions for BackgroundShow should be entered here
//

//
// fade an LED up and down, then move to the next LED in a clockwise direction
//
void fadeBlinkSingleLedsGoingClockwise(int onTime, int offTime, byte repeatCount, byte fadeSpeed)
{
  byte ledNumber;
  byte count;

  for(count = 1; count <= repeatCount; count++)
  {
    for(ledNumber = 8; ledNumber >= 2; ledNumber--)
    { 
      fade.up(fadeSpeed, ledNumber);
      if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time
 
      fade.down(fadeSpeed, ledNumber);
      if (fade.delayAndCheckForExit(offTime) == true) return;   // check knob during off time
    }

    for(ledNumber = 9; ledNumber <= 15; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber);
      if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time
 
      fade.down(fadeSpeed, ledNumber);
      if (fade.delayAndCheckForExit(offTime) == true) return;   // check knob during off time
    }
  }
  
}



//
// alternate all the LEDs on the right and left using crossFade
//
void crossFadeRightAndLeft(int onTime, int waitTime, byte repeatCount, byte fadeSpeed)
{
  byte count;
  byte leftArray[7] = {2, 3, 4, 5, 6, 7, 8};
  byte rightArray[7] = {9, 10, 11, 12, 13, 14, 15};
  
  fade.up(fadeSpeed, rightArray, sizeof(rightArray));
  if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time

  for(count = 1; count <= repeatCount; count++)
  {
    fade.crossFade(fadeSpeed, leftArray, sizeof(leftArray), rightArray, sizeof(rightArray));  // crossfade left up and right down
    if (fade.delayAndCheckForExit(waitTime) == true) return;   // check knob during wait time
    
    fade.crossFade(fadeSpeed, rightArray, sizeof(rightArray), leftArray, sizeof(leftArray));  // crossfade right up and left down
    if (fade.delayAndCheckForExit(waitTime) == true) return;   // check knob during wait time
  }

  fade.down(fadeSpeed, rightArray, sizeof(rightArray));  // turn off all LEDs
}
