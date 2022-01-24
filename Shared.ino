//------------------------------------------------------------------------
//                        Shared Function Definitions
//------------------------------------------------------------------------
// All your function definitions that are shared should be entered here
//


//
// turn on the LEDs, one group of colors at a time
//
void fadeShowAllTheColors(int onTime, int offTime, byte repeatCount, byte fadeSpeed)
{ 
  byte count;
  byte redLedsArray[] = {};
  byte orangeLedsArray[] = {6, 8, 9, 10, 11, 12};
  byte yellowLedsArray[] = {2, 3, 4, 5, 7};
  byte greenLedsArray[] = {};
  byte blueLedsArray[] = {13, 14, 15};
  
  //
  // turn on all colors
  //
  for(count = 1; count <= repeatCount; count++)
  {
 
    fade.up(fadeSpeed, orangeLedsArray, sizeof(orangeLedsArray));  // turn on all the oranges
    if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time
    
    fade.up(fadeSpeed, yellowLedsArray, sizeof(yellowLedsArray));  // turn on all the yellows
    if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time

    fade.up(fadeSpeed, blueLedsArray, sizeof(blueLedsArray));  // turn on all the blues
    if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time

    fade.down(fadeSpeed);  // turn all the LEDs off
    if (fade.delayAndCheckForExit(offTime) == true) return;   // check knob during off time  
  }
  
}

