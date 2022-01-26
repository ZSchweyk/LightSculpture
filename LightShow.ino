//------------------------------------------------------------------------
//                        LightShow Function Calls
//------------------------------------------------------------------------
// run the "LightShow" while the knob is in zone 1
//
// THIS SHOULD be a list of function calls to functions defined in the LightShow or Shared function definitions area
//
//



void runLightShow()
{
//  unsigned long startTime = millis(); // time we begin the light show, in milliseconds
//  int intermissionDelay = 200; // brief pause between displays
//  int postShowDelay = 1000; // longer delay at the end of the show
//  
//  Serial.println("Beginning Light Show.");
//  
//  //first display
//  fadeShowAllTheColors(100, 200, 2, 4);
//  if (fade.delayAndCheckForExit(intermissionDelay) == true) return;   // check knob during intermission
//  
//  //second display
//  blinkSingleLedsGoingClockwise(100, 100, 3);
//  if (fade.delayAndCheckForExit(intermissionDelay) == true) return;   // check knob during intermission
//
//  if (fade.delayAndCheckForExit(postShowDelay) == true) return;   // check knob during intermission
//  
//  Serial.print("Light Show finished.  Run time in milliseconds: ");
//  Serial.println(millis() - startTime);

  

 FlashAllWithFade(4);
 FlashBottomAndTop(250, 8);
 FadeTwoAtATime(1);
 BothCircles(15);



// OneCircle(10, "outer", "cw");
  
  
  
 FlashSequence1(200, 50, 25, 1, 3);
 FlashSequence1(50, 200, 25, 1, 1);  
 FlashSequence2(250, 50, 25, 1, 3); 
 FlashSequence2(50, 250, 25, 1, 1);  
 FlashSequence3(250, 50, 25, 3);
 FlashSequence3(50, 250, 25, 1);  
 FlashSequence4(250, 25, 25, 1, 4);
 FlashSequence4(25, 250, 25, 1, 1);  
 FlashSequence5(200, 50, 25, 2, 3);
 FlashSequence5(50, 200, 25, 2, 1);  
 FlashSequence6(300, 50, 50, 2); 
 FlashSequence6(50, 300, 50, 1);  
 FlashSequence7(150, 50, 50, 1, 4);
 FlashSequence7(50, 150, 50, 1, 2);  
 FlashSequence8(150, 50, 25, 1, 4);
 FlashSequence8(50, 150, 25, 1, 4);  
 FlashSequence9(150, 50, 25, 3, 4);
 FlashSequence9(50, 150, 25, 2, 2);  
 FlashSequence10(150, 50, 25, 3, 3); 

  
}


//------------------------------------------------------------------------
//                        LightShow Function Definitions
//------------------------------------------------------------------------
// All your function definitions for LightShow should be entered here
//

int fDelay(int milliseconds)
{
  if(fade.delayAndCheckForExit(milliseconds)) return;
}

void FlashAllWithFade(int repeat)
{
  for(int i = 0; i < repeat; i++)
  {
    fade.up(5);
    fade.down(5);
  }
}

void FlashBottomAndTop(int waitTime, double fadeTime)
{
  byte bottom[] = {2, 3, 4, 5, 6};
  byte top[] = {7, 8, 9, 10, 11};
  fDelay(waitTime);
  for(int i = 0; i < 2; i++)
  {
    fade.up(fadeTime, bottom, sizeof(bottom));
    fDelay(waitTime);
    fade.up(fadeTime, top, sizeof(top));
    fDelay(waitTime);
    fade.down(fadeTime, bottom, sizeof(bottom));
    fDelay(waitTime);
    fade.down(fadeTime, top, sizeof(top));
    fDelay(waitTime);

    fade.up(fadeTime, top, sizeof(top));
    fDelay(waitTime);
    fade.up(fadeTime, bottom, sizeof(bottom));
    fDelay(waitTime);
    fade.down(fadeTime, top, sizeof(top));
    fDelay(waitTime);
    fade.down(fadeTime, bottom, sizeof(bottom));
    fDelay(waitTime);
  }
}

void FadeTwoAtATime(int repeat)
{
  byte setsOfTwo[][2] = {{2, 11}, {3, 10}, {4, 9}, {5, 8}, {6, 7}};
  int delayTime = 500;
  int originalDelayTime = delayTime;

  for(int count = 0; count < repeat; count ++)
  {
    for(int i = 0; i < 2; i++)
    {
      int boundary;
      if(i == 0)
      {
        boundary = 0;
      }
      else
      {
        boundary = originalDelayTime;
      }
      while(delayTime != boundary)
      {
        for(int row = 0; row < sizeof(setsOfTwo) / 2; row++)
        {
          if(row != sizeof(setsOfTwo) / 2 - 1)
          {
            digitalWrite(setsOfTwo[row][0], HIGH);
            digitalWrite(setsOfTwo[row][1], HIGH);
          }
          else
          {
            digitalWrite(setsOfTwo[row - 1][0], LOW);
            digitalWrite(setsOfTwo[row - 1][1], LOW);
            break;
          }
          
          if(row != 0)
          {
            digitalWrite(setsOfTwo[row - 1][0], LOW);
            digitalWrite(setsOfTwo[row - 1][1], LOW);
          }
          fDelay(delayTime);
        }
      
        for(int row = sizeof(setsOfTwo) / 2 - 1; row > -1; row--)
        {
          if(row != 0)
          {
            digitalWrite(setsOfTwo[row][0], HIGH);
            digitalWrite(setsOfTwo[row][1], HIGH);
          }
          else
          {
            digitalWrite(setsOfTwo[row + 1][0], LOW);
            digitalWrite(setsOfTwo[row + 1][1], LOW);
            break;
          }
          
          if(row != sizeof(setsOfTwo) / 2 - 1)
          {
            digitalWrite(setsOfTwo[row + 1][0], LOW);
            digitalWrite(setsOfTwo[row + 1][1], LOW);
          }
          fDelay(delayTime);
        }
  
        if(boundary == 0)
        {
          delayTime -= 50;
        }
        else
        {
          delayTime += 50;
        }
        Serial.println(delayTime);
      }
    }
  }
}

void BothCircles(int numCircles)
{
  byte outer[] = {2, 7, 11, 6};
  byte inner[] = {10, 8, 3, 5};
  for(int i = 0; i < numCircles; i++)
  {
    byte lastOn[2];
    for(int ledNum = 0; ledNum < sizeof(outer); ledNum++)
    {
      byte simultaneousLeds[2] = {outer[ledNum], inner[ledNum]};
      fade.up(6, simultaneousLeds, 2);

      fade.down(6, lastOn, 2);
      
      lastOn[0] = outer[ledNum];
      lastOn[1] = inner[ledNum];
    }
  }
}

void OneCircle(int numCircles, String outerOrInner, String dir)
{
  byte outer[] = {2, 7, 11, 6};
  byte inner[] = {10, 8, 3, 5};

  byte circle[4];

  if(outerOrInner == "outer")
  {
    for(int i = 0; i < 4; i++)
    {
      circle[i] = outer[i];
    }
  }
  else if(outerOrInner == "inner")
  {
    for(int i = 0; i < 4; i++)
    {
      circle[i] = inner[i];
    }
  }
  
  byte lastOn[1];

  int ledNumStart;
  int ledNumEnd;
  int increment;
  if(dir == "ccw")
  {
    ledNumStart = 0;
    ledNumEnd = 4;
    increment = 1;
  }
  else
  {
    ledNumStart = 3;
    ledNumEnd = -1;
    increment = -1;
  }

  
  for(int count = 0; count < numCircles; count++)
  {
    for(int ledNum = ledNumStart; ledNum != ledNumEnd; ledNum = ledNum + increment)
    {
      digitalWrite(circle[ledNum], HIGH);
      fade.down(10, lastOn, 1);
      fDelay(100);
      lastOn[0] = circle[ledNum];
    }
  }
}
      


void FlashSequence1(int InitialTimePeriodOn, int FinalTimePeriodOn, int IncreasingOnIncrement, int Repeat, int EndRepeat)
// The following function flashes all the LEDs from the bottom to the top.
// This function speeds up or slows down.
{
  int OneIntroDisplay[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
  //                         0 , 1 , 2, 3, 4, 5, 6, 7, 8, 9
  int index;
  int count;
  

if(InitialTimePeriodOn > FinalTimePeriodOn)
{
    for(InitialTimePeriodOn; InitialTimePeriodOn > FinalTimePeriodOn; InitialTimePeriodOn -= IncreasingOnIncrement)
    {
      
      for(count = 1; count <= Repeat; count++)
      {
        
        for(index = 0; index < 10; index++)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          // fade.up(1, OneIntroDisplay[index]);
          delay(InitialTimePeriodOn);
          // if (fade.delayAndCheckForExit(InitialTimePeriodOn) == true) return;
          // fade.down(1, OneIntroDisplay[index]);
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    
        digitalWrite(OneIntroDisplay[index=8], HIGH);
        // fade.up(1, OneIntroDisplay[index]);
        delay(InitialTimePeriodOn);
        // if (fade.delayAndCheckForExit(InitialTimePeriodOn) == true) return;
        // fade.down(1, OneIntroDisplay[index]);
        digitalWrite(OneIntroDisplay[index=8], LOW);
      
        for(index = 7; index > 0; index--)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          // fade.up(1, OneIntroDisplay[index]);
          delay(InitialTimePeriodOn);
          // if (fade.delayAndCheckForExit(InitialTimePeriodOn) == true) return;
          // fade.down(1, OneIntroDisplay[index]);
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
        
      }      
    }
}

if(InitialTimePeriodOn <= FinalTimePeriodOn)
{
    for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += IncreasingOnIncrement)
    {
      
      for(count = 1; count <= Repeat; count++)
      {
        
        for(index = 0; index < 10; index++)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          // delay(InitialTimePeriodOn);
          if (fade.delayAndCheckForExit(InitialTimePeriodOn) == true) return;
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    
        digitalWrite(OneIntroDisplay[index=8], HIGH);
        // delay(InitialTimePeriodOn);
        if (fade.delayAndCheckForExit(InitialTimePeriodOn) == true) return;
        digitalWrite(OneIntroDisplay[index=8], LOW);
      
        for(index = 7; index > 0; index--)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          // delay(InitialTimePeriodOn);
          if (fade.delayAndCheckForExit(InitialTimePeriodOn) == true) return;
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
        
      }      
    }
}

for(count = 1; count <= EndRepeat; count++)
{
        for(index = 0; index < 10; index++)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          // delay(InitialTimePeriodOn);
          if (fade.delayAndCheckForExit(FinalTimePeriodOn) == true) return;
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    
        digitalWrite(OneIntroDisplay[index=8], HIGH);
        // delay(InitialTimePeriodOn);
        if (fade.delayAndCheckForExit(FinalTimePeriodOn) == true) return;
        digitalWrite(OneIntroDisplay[index=8], LOW);
      
        for(index = 7; index > 0; index--)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          // delay(InitialTimePeriodOn);
          if (fade.delayAndCheckForExit(FinalTimePeriodOn) == true) return;
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    }
    
delay(1);
    
}

void FlashSequence2(int InitialTimePeriodOn, int FinalTimePeriodOn, int IncreasingOnIncrement, int Repeat, int EndRepeat)
// The following function flashes each LED and its corresponding LED with it.
// This function speeds up or slows down.
{
  int Symmetry[10] = {11,6,10,5,9,4,8,3,7,2};
  //                   0,1,2 ,3,4,5,6,7,8,9
  int index;
  int count;
  
  for(InitialTimePeriodOn; InitialTimePeriodOn > FinalTimePeriodOn; InitialTimePeriodOn -= IncreasingOnIncrement)
  {

      for(count = 1; count <= Repeat; count++)
      {
      
        for(index = 0; index < 10; index += 2)
        {
          digitalWrite(Symmetry[index], HIGH);
          digitalWrite(Symmetry[index+1], HIGH);
          delay(InitialTimePeriodOn);
        }
  
        for(index = 0; index < 10; index += 2)
        {
          digitalWrite(Symmetry[index], LOW);
          digitalWrite(Symmetry[index+1], LOW);
          delay(InitialTimePeriodOn);
        }
   
        for(index = 9; index >-1; index -= 2)
        {
          digitalWrite(Symmetry[index], HIGH);
          digitalWrite(Symmetry[index-1], HIGH);
          delay(InitialTimePeriodOn);
        }
    
        for(index = 9; index >-1; index -= 2)
        {
          digitalWrite(Symmetry[index], LOW);
          digitalWrite(Symmetry[index-1], LOW);
          delay(InitialTimePeriodOn);
        }
      }
    
  } 
  
  for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += IncreasingOnIncrement)
  {
      for(count = 1; count <= Repeat; count++)
      {
      
        for(index = 0; index < 10; index += 2)
        {
          digitalWrite(Symmetry[index], HIGH);
          digitalWrite(Symmetry[index+1], HIGH);
          delay(InitialTimePeriodOn);
        }
  
        for(index = 0; index < 10; index += 2)
        {
          digitalWrite(Symmetry[index], LOW);
          digitalWrite(Symmetry[index+1], LOW);
          delay(InitialTimePeriodOn);
        }
   
        for(index = 9; index >-1; index -= 2)
        {
          digitalWrite(Symmetry[index], HIGH);
          digitalWrite(Symmetry[index-1], HIGH);
          delay(InitialTimePeriodOn);
        }
    
        for(index = 9; index >-1; index -= 2)
        {
          digitalWrite(Symmetry[index], LOW);
          digitalWrite(Symmetry[index-1], LOW);
          delay(InitialTimePeriodOn);
        }
      }
   
  }
  

  for(count = 1; count <= EndRepeat; count++)
  {
      
      for(index = 0; index < 10; index += 2)
      {
        digitalWrite(Symmetry[index], HIGH);
        digitalWrite(Symmetry[index+1], HIGH);
        delay(FinalTimePeriodOn);
      }
  
      for(index = 0; index < 10; index += 2)
      {
        digitalWrite(Symmetry[index], LOW);
        digitalWrite(Symmetry[index+1], LOW);
        delay(FinalTimePeriodOn);
      }
   
      for(index = 9; index >-1; index -= 2)
      {
        digitalWrite(Symmetry[index], HIGH);
        digitalWrite(Symmetry[index-1], HIGH);
        delay(FinalTimePeriodOn);
      }
    
      for(index = 9; index >-1; index -= 2)
      {
        digitalWrite(Symmetry[index], LOW);
        digitalWrite(Symmetry[index-1], LOW);
        delay(FinalTimePeriodOn);
      }
  }  
  
 delay(1); 
  
}

void FlashSequence3(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnIncrement, int EndRepeat)
{
  int Skipping[20] = {2,4,3,5,4,6,5,7,6,8,7,9,8,10,9,11,10,2,11,3};
  int index;
  int count;
  

  for(InitialTimePeriodOn; InitialTimePeriodOn > FinalTimePeriodOn; InitialTimePeriodOn -= OnIncrement)
  {
  
    for(index = 0; index < 20; index ++)
    {
      digitalWrite(Skipping[index], HIGH);
      delay(InitialTimePeriodOn);
      digitalWrite(Skipping[index +1], HIGH);
      digitalWrite(Skipping[index], LOW);
      digitalWrite(Skipping[index +1], LOW);
    }    
      
  }
  
  for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnIncrement)
  {
    
    for(index = 0; index < 20; index ++)
    {
      digitalWrite(Skipping[index], HIGH);
      delay(InitialTimePeriodOn);
      digitalWrite(Skipping[index +1], HIGH);
      digitalWrite(Skipping[index], LOW);
      digitalWrite(Skipping[index +1], LOW);
    }   
      
  }

  for(count = 1; count <= EndRepeat; count++)
  {
    
    for(index = 0; index < 20; index ++)
    {
      digitalWrite(Skipping[index], HIGH);
      delay(FinalTimePeriodOn);
      digitalWrite(Skipping[index +1], HIGH);
      digitalWrite(Skipping[index], LOW);
      digitalWrite(Skipping[index +1], LOW);
    }
    
  }
  
  delay(1);

}

void FlashSequence4(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnTimeIncrement, int Repeat, int EndRepeat)
{
  int JumpingBottom[8] = {11,7,10,8,9,8,10,7};
  int JumpingTop[8] = {6,2,5,3,4,3,5,2};
  int index;
  int count;

  if(InitialTimePeriodOn > FinalTimePeriodOn)
  {
    
    for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnTimeIncrement)
    {
      
    for(count = 1; count <= Repeat; count ++)
    {
      for(index = 0; index < 8; index ++)
      {
          digitalWrite(JumpingBottom[index], HIGH);
          digitalWrite(JumpingTop[index], HIGH);
          delay(InitialTimePeriodOn);
          digitalWrite(JumpingBottom[index+1], HIGH);
          digitalWrite(JumpingTop[index+1], HIGH);
          digitalWrite(JumpingBottom[index], LOW);
          digitalWrite(JumpingTop[index], LOW);
      }
    }
    
    }
    
  }

  if(InitialTimePeriodOn < FinalTimePeriodOn)
  {
    for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnTimeIncrement)
    {

      for(count = 1; count <= Repeat; count ++)
      {
        for(index = 0; index < 8; index ++)
        {
          digitalWrite(JumpingBottom[index], HIGH);
          digitalWrite(JumpingTop[index], HIGH);
          delay(InitialTimePeriodOn);
          digitalWrite(JumpingBottom[index+1], HIGH);
          digitalWrite(JumpingTop[index+1], HIGH);
          digitalWrite(JumpingBottom[index], LOW);
          digitalWrite(JumpingTop[index], LOW);
        }
      }
    }
  }
  
  for(count = 1; count <= EndRepeat; count ++)
  {
      for(index = 0; index < 8; index ++)
      {
          digitalWrite(JumpingBottom[index], HIGH);
          digitalWrite(JumpingTop[index], HIGH);
          delay(FinalTimePeriodOn);
          digitalWrite(JumpingBottom[index+1], HIGH);
          digitalWrite(JumpingTop[index+1], HIGH);
          digitalWrite(JumpingBottom[index], LOW);
          digitalWrite(JumpingTop[index], LOW);        
      }
    }

delay(1);

} 

void FlashSequence5(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnTimeIncrement, int TogetherRepeat, int TogetherRepeatEnd)
// Can speed up or slow down.
{
  int CollisionExplosionTop[5] = {2,6,3,5,4};
  int CollisionExplosionBottom[5] = {7,11,8,10,9};
  int index;
  int count;
  

    if(InitialTimePeriodOn >= FinalTimePeriodOn)
    {
      for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnTimeIncrement)
      {
    
        for(count = 1; count <= TogetherRepeat; count ++)
        {

            digitalWrite(CollisionExplosionTop[index], HIGH);
            digitalWrite(CollisionExplosionTop[index +1], HIGH);
            digitalWrite(CollisionExplosionBottom[index], HIGH);
            digitalWrite(CollisionExplosionBottom[index +1], HIGH);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], HIGH);
            digitalWrite(CollisionExplosionTop[index + 3], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 2], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 3], HIGH);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 4], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 4], HIGH);
            delay(InitialTimePeriodOn);
            
            
            
            digitalWrite(CollisionExplosionTop[index + 4], LOW);
            digitalWrite(CollisionExplosionBottom[index + 4], LOW);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], LOW);
            digitalWrite(CollisionExplosionTop[index + 3], LOW);
            digitalWrite(CollisionExplosionBottom[index + 2], LOW);
            digitalWrite(CollisionExplosionBottom[index + 3], LOW);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index], LOW);
            digitalWrite(CollisionExplosionTop[index +1], LOW);
            digitalWrite(CollisionExplosionBottom[index], LOW);
            digitalWrite(CollisionExplosionBottom[index +1], LOW);
            delay(InitialTimePeriodOn);
            
        }
        
      }
      
        for(count = 1; count <= TogetherRepeatEnd; count ++)
        {

            digitalWrite(CollisionExplosionTop[index], HIGH);
            digitalWrite(CollisionExplosionTop[index +1], HIGH);
            digitalWrite(CollisionExplosionBottom[index], HIGH);
            digitalWrite(CollisionExplosionBottom[index +1], HIGH);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], HIGH);
            digitalWrite(CollisionExplosionTop[index + 3], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 2], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 3], HIGH);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 4], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 4], HIGH);
            delay(FinalTimePeriodOn);
            
            
            
            digitalWrite(CollisionExplosionTop[index + 4], LOW);
            digitalWrite(CollisionExplosionBottom[index + 4], LOW);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], LOW);
            digitalWrite(CollisionExplosionTop[index + 3], LOW);
            digitalWrite(CollisionExplosionBottom[index + 2], LOW);
            digitalWrite(CollisionExplosionBottom[index + 3], LOW);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index], LOW);
            digitalWrite(CollisionExplosionTop[index +1], LOW);
            digitalWrite(CollisionExplosionBottom[index], LOW);
            digitalWrite(CollisionExplosionBottom[index +1], LOW);
            delay(FinalTimePeriodOn);
            
        }      
      
    }


    if(InitialTimePeriodOn <= FinalTimePeriodOn)
    {
      for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnTimeIncrement)
      {
    
        for(count = 1; count <= TogetherRepeat; count ++)
        {

            digitalWrite(CollisionExplosionTop[index], HIGH);
            digitalWrite(CollisionExplosionTop[index +1], HIGH);
            digitalWrite(CollisionExplosionBottom[index], HIGH);
            digitalWrite(CollisionExplosionBottom[index +1], HIGH);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], HIGH);
            digitalWrite(CollisionExplosionTop[index + 3], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 2], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 3], HIGH);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 4], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 4], HIGH);
            delay(InitialTimePeriodOn);
            
            
            
            digitalWrite(CollisionExplosionTop[index + 4], LOW);
            digitalWrite(CollisionExplosionBottom[index + 4], LOW);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], LOW);
            digitalWrite(CollisionExplosionTop[index + 3], LOW);
            digitalWrite(CollisionExplosionBottom[index + 2], LOW);
            digitalWrite(CollisionExplosionBottom[index + 3], LOW);
            delay(InitialTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index], LOW);
            digitalWrite(CollisionExplosionTop[index +1], LOW);
            digitalWrite(CollisionExplosionBottom[index], LOW);
            digitalWrite(CollisionExplosionBottom[index +1], LOW);
            delay(InitialTimePeriodOn);
            
        }
        
      }
      
        for(count = 1; count <= TogetherRepeatEnd; count ++)
        {

            digitalWrite(CollisionExplosionTop[index], HIGH);
            digitalWrite(CollisionExplosionTop[index +1], HIGH);
            digitalWrite(CollisionExplosionBottom[index], HIGH);
            digitalWrite(CollisionExplosionBottom[index +1], HIGH);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], HIGH);
            digitalWrite(CollisionExplosionTop[index + 3], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 2], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 3], HIGH);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 4], HIGH);
            digitalWrite(CollisionExplosionBottom[index + 4], HIGH);
            delay(FinalTimePeriodOn);
            
            
            
            digitalWrite(CollisionExplosionTop[index + 4], LOW);
            digitalWrite(CollisionExplosionBottom[index + 4], LOW);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index + 2], LOW);
            digitalWrite(CollisionExplosionTop[index + 3], LOW);
            digitalWrite(CollisionExplosionBottom[index + 2], LOW);
            digitalWrite(CollisionExplosionBottom[index + 3], LOW);
            delay(FinalTimePeriodOn);
            
            digitalWrite(CollisionExplosionTop[index], LOW);
            digitalWrite(CollisionExplosionTop[index +1], LOW);
            digitalWrite(CollisionExplosionBottom[index], LOW);
            digitalWrite(CollisionExplosionBottom[index +1], LOW);
            delay(FinalTimePeriodOn);
            
        }      
      
    }      
  
  delay(1);
  
}

void FlashSequence6(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnIncrement, int Repeat)
// This function can speed up or slow down.
{
  
  int TopCollide[5] = {2,6,3,5,4};
  int BottomRun[5] = {7,8,9,10,11};
  int index;
  int count;
 
   // Turns on 6, 2, 7
    digitalWrite(TopCollide[index], HIGH);
    digitalWrite(TopCollide[index + 1], HIGH);
    digitalWrite(BottomRun[index], HIGH);
    delay(InitialTimePeriodOn);
 
  for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnIncrement)
  {
  
    for(count = 1; count <= Repeat; count ++)
    {

// Turns on 3, 5, 8
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 1], HIGH);
    
// Turns off 6, 2, 7
    digitalWrite(TopCollide[index], LOW);
    digitalWrite(TopCollide[index + 1], LOW);
    digitalWrite(BottomRun[index], LOW);
    delay(InitialTimePeriodOn);    

// Turns on 4, 9
    digitalWrite(TopCollide[index + 4], HIGH);
    digitalWrite(BottomRun[index + 2], HIGH);

    
// Turns off 3, 5, 8
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 1], LOW); 
    delay(InitialTimePeriodOn);
    
// Turns on 3, 5, 10
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 3], HIGH);

    
// Turns off 4, 9
    digitalWrite(TopCollide[index + 4], LOW);
    digitalWrite(BottomRun[index + 2], LOW);
    delay(InitialTimePeriodOn);
    
// Turns on 2, 6, 11
    digitalWrite(TopCollide[index], HIGH);
    digitalWrite(TopCollide[index + 1], HIGH);
    digitalWrite(BottomRun[index + 4], HIGH);
    
// Turns off 3, 5, 10
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 3], LOW);
    delay(InitialTimePeriodOn);
   
// Turns on 3, 5, 10
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 3], HIGH);
   
// Turns off 2, 6, 11
    digitalWrite(TopCollide[index], LOW);
    digitalWrite(TopCollide[index + 1], LOW);
    digitalWrite(BottomRun[index + 4], LOW);
    delay(InitialTimePeriodOn);
    
// Turns on 4, 9
    digitalWrite(TopCollide[index + 4], HIGH);
    digitalWrite(BottomRun[index + 2], HIGH);
    
// Turns off 3, 5, 10
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 3], LOW);
    delay(InitialTimePeriodOn);
    
// Turns on 3, 5, 8
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 1], HIGH);
    
// Turns off 4, 9
    digitalWrite(TopCollide[index + 4], LOW);
    digitalWrite(BottomRun[index + 2], LOW);
    delay(InitialTimePeriodOn);

// Turns on 6, 2, 7
    digitalWrite(TopCollide[index], HIGH);
    digitalWrite(TopCollide[index + 1], HIGH);
    digitalWrite(BottomRun[index], HIGH);

// Turns off 3, 5, 8
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 1], LOW);
    delay(InitialTimePeriodOn);
    
  }
  
  }
  
  for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnIncrement)
  {
  
    for(count = 1; count <= Repeat; count ++)
    {

// Turns on 3, 5, 8
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 1], HIGH);
    
// Turns off 6, 2, 7
    digitalWrite(TopCollide[index], LOW);
    digitalWrite(TopCollide[index + 1], LOW);
    digitalWrite(BottomRun[index], LOW);
    delay(InitialTimePeriodOn);    

// Turns on 4, 9
    digitalWrite(TopCollide[index + 4], HIGH);
    digitalWrite(BottomRun[index + 2], HIGH);

    
// Turns off 3, 5, 8
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 1], LOW); 
    delay(InitialTimePeriodOn);
    
// Turns on 3, 5, 10
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 3], HIGH);

    
// Turns off 4, 9
    digitalWrite(TopCollide[index + 4], LOW);
    digitalWrite(BottomRun[index + 2], LOW);
    delay(InitialTimePeriodOn);
    
// Turns on 2, 6, 11
    digitalWrite(TopCollide[index], HIGH);
    digitalWrite(TopCollide[index + 1], HIGH);
    digitalWrite(BottomRun[index + 4], HIGH);
    
// Turns off 3, 5, 10
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 3], LOW);
    delay(InitialTimePeriodOn);
   
// Turns on 3, 5, 10
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 3], HIGH);
   
// Turns off 2, 6, 11
    digitalWrite(TopCollide[index], LOW);
    digitalWrite(TopCollide[index + 1], LOW);
    digitalWrite(BottomRun[index + 4], LOW);
    delay(InitialTimePeriodOn);
    
// Turns on 4, 9
    digitalWrite(TopCollide[index + 4], HIGH);
    digitalWrite(BottomRun[index + 2], HIGH);
    
// Turns off 3, 5, 10
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 3], LOW);
    delay(InitialTimePeriodOn);
    
// Turns on 3, 5, 8
    digitalWrite(TopCollide[index + 2], HIGH);
    digitalWrite(TopCollide[index + 3], HIGH);
    digitalWrite(BottomRun[index + 1], HIGH);
    
// Turns off 4, 9
    digitalWrite(TopCollide[index + 4], LOW);
    digitalWrite(BottomRun[index + 2], LOW);
    delay(InitialTimePeriodOn);

// Turns on 6, 2, 7
    digitalWrite(TopCollide[index], HIGH);
    digitalWrite(TopCollide[index + 1], HIGH);
    digitalWrite(BottomRun[index], HIGH);

// Turns off 3, 5, 8
    digitalWrite(TopCollide[index + 2], LOW);
    digitalWrite(TopCollide[index + 3], LOW);
    digitalWrite(BottomRun[index + 1], LOW);
    delay(InitialTimePeriodOn);
    
  }
  
  }  
   
  delay(1);
  
}

void FlashSequence7(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnTimeIncrement, int Repeat, int EndRepeat)
// If you have time, add an array and extra code with the opposite flashing of LEDs.
{
  int FlashOn[5] = {2,8,4,10,6};
  int Poking[8] = {11,5,9,3,7,3,9,5};
  int index;
  int count;
  
  for(index = 0; index < 5; index ++)
  {
    digitalWrite(FlashOn[index], HIGH);
  }
  
  delay(InitialTimePeriodOn);
  

for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnTimeIncrement)
{
  for(count = 1; count <= Repeat; count ++)
  {
    for(index = 0; index < 8; index ++)
    {
      digitalWrite(Poking[index], HIGH);
      delay(InitialTimePeriodOn);
      digitalWrite(Poking[index], LOW);
    }    
  }
}

for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnTimeIncrement)
{
  for(count = 1; count <= Repeat; count ++)
  {
    for(index = 0; index < 8; index ++)
    {
      digitalWrite(Poking[index], HIGH);
      delay(InitialTimePeriodOn);
      digitalWrite(Poking[index], LOW);
    }    
  }
}

  for(count = 1; count <= EndRepeat; count ++)
  {
    
    for(index = 0; index <8; index ++)
    {
      digitalWrite(Poking[index], HIGH);
      delay(FinalTimePeriodOn);
      digitalWrite(Poking[index], LOW);      
    }
    
  }
  
  for(index = 0; index < 5; index ++)
  {
    digitalWrite(FlashOn[index], LOW);
  }
  
  delay(1);
  
}

void FlashSequence8(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnTimeIncrement, int Repeat, int EndRepeat)
{
  int HoppingInUnisonRight[6] = {2,4,3,5,4,6};
  int HoppingInUnisonLeft[6] = {7,9,8,10,9,11};
  int index;
  int count;
 
 
  for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnTimeIncrement)
  {
    
    for(count = 1; count <= Repeat; count ++)
    {
      for(index = 0; index < 5; index += 1)
      {
        digitalWrite(HoppingInUnisonRight[index], HIGH);
        digitalWrite(HoppingInUnisonLeft[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(HoppingInUnisonRight[index], LOW);
        digitalWrite(HoppingInUnisonLeft[index], LOW);
      }
  
      for(index = 5; index > 0; index -= 1)
      {
        digitalWrite(HoppingInUnisonRight[index], HIGH);
        digitalWrite(HoppingInUnisonLeft[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(HoppingInUnisonRight[index], LOW);
        digitalWrite(HoppingInUnisonLeft[index], LOW);
      }  
    }
  }

  for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnTimeIncrement)
  {
    for(count = 1; count <= Repeat; count ++)
    {
      for(index = 0; index < 5; index += 1)
      {
        digitalWrite(HoppingInUnisonRight[index], HIGH);
        digitalWrite(HoppingInUnisonLeft[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(HoppingInUnisonRight[index], LOW);
        digitalWrite(HoppingInUnisonLeft[index], LOW);
      }
  
      for(index = 5; index > 0; index -= 1)
      {
        digitalWrite(HoppingInUnisonRight[index], HIGH);
        digitalWrite(HoppingInUnisonLeft[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(HoppingInUnisonRight[index], LOW);
        digitalWrite(HoppingInUnisonLeft[index], LOW);
      }  
    }    
  }
  
  for(count = 1; count <= EndRepeat; count ++)
  {
      for(index = 0; index < 5; index += 1)
      {
        digitalWrite(HoppingInUnisonRight[index], HIGH);
        digitalWrite(HoppingInUnisonLeft[index], HIGH);
        delay(FinalTimePeriodOn);
        digitalWrite(HoppingInUnisonRight[index], LOW);
        digitalWrite(HoppingInUnisonLeft[index], LOW);
      }
  
      for(index = 5; index > 0; index -= 1)
      {
        digitalWrite(HoppingInUnisonRight[index], HIGH);
        digitalWrite(HoppingInUnisonLeft[index], HIGH);
        delay(FinalTimePeriodOn);
        digitalWrite(HoppingInUnisonRight[index], LOW);
        digitalWrite(HoppingInUnisonLeft[index], LOW);
      }  
  }
  
  delay(1);
  
}

void FlashSequence9(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnTimeIncrement, int Repeat, int EndRepeat)
{
  int ReverseTop[5] = {2,3,4,5,6};
  int ReverseBottom[5] = {11,10,9,8,7};
  int index;
  int count;
  
  for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnTimeIncrement)
  {
    for(count = 1; count <= Repeat; count ++)
    {
      for(index = 0; index < 4; index ++)
      {
        digitalWrite(ReverseTop[index], HIGH);
        digitalWrite(ReverseBottom[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(ReverseTop[index], LOW);
        digitalWrite(ReverseBottom[index], LOW);
      }
  
      for(index = 4; index > 0; index --)
      {
        digitalWrite(ReverseTop[index], HIGH);
        digitalWrite(ReverseBottom[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(ReverseTop[index], LOW);
        digitalWrite(ReverseBottom[index], LOW);    
      }    
    }
  }
  
  for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnTimeIncrement)
  {
    for(count = 1; count <= Repeat; count ++)
    {
      for(index = 0; index < 4; index ++)
      {
        digitalWrite(ReverseTop[index], HIGH);
        digitalWrite(ReverseBottom[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(ReverseTop[index], LOW);
        digitalWrite(ReverseBottom[index], LOW);
      }
  
      for(index = 4; index > 0; index --)
      {
        digitalWrite(ReverseTop[index], HIGH);
        digitalWrite(ReverseBottom[index], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(ReverseTop[index], LOW);
        digitalWrite(ReverseBottom[index], LOW);    
      }    
    }
  }
  
  for(count = 1; count <= EndRepeat; count ++)
  {
      for(index = 0; index < 4; index ++)
      {
        digitalWrite(ReverseTop[index], HIGH);
        digitalWrite(ReverseBottom[index], HIGH);
        delay(FinalTimePeriodOn);
        digitalWrite(ReverseTop[index], LOW);
        digitalWrite(ReverseBottom[index], LOW);
      }
  
      for(index = 4; index > 0; index --)
      {
        digitalWrite(ReverseTop[index], HIGH);
        digitalWrite(ReverseBottom[index], HIGH);
        delay(FinalTimePeriodOn);
        digitalWrite(ReverseTop[index], LOW);
        digitalWrite(ReverseBottom[index], LOW);    
      }    
    }  
    
  delay(1);
  
}

void FlashSequence10(int InitialTimePeriodOn, int FinalTimePeriodOn, int OnTimeIncrement, int Repeat, int EndRepeat)
{
  int Everything[10] = {2,3,4,5,6,7,8,9,10,11};
  int TopTop[3] = {2,3,4};
  int TopRight[3] = {4,5,6};
  int BottomLeft[3] = {7,8,9};
  int BottomBottom[3] = {9,10,11};
  
  int index;
  int count;
  
  if(InitialTimePeriodOn >= FinalTimePeriodOn)
  {
    for(InitialTimePeriodOn; InitialTimePeriodOn >= FinalTimePeriodOn; InitialTimePeriodOn -= OnTimeIncrement)
    {
      for(count = 1; count <= Repeat; count ++)
      {
        for(index = 0; index < 10; index ++)
        {
          digitalWrite(Everything[index], HIGH);
        }
        
        delay(InitialTimePeriodOn);
        
        for(index = 0; index < 10; index ++)
        {
          digitalWrite(Everything[index], LOW);
        }        
        
        delay(InitialTimePeriodOn);
        
      }
    }
  }   
  
  if(InitialTimePeriodOn <= FinalTimePeriodOn)
  {
    for(InitialTimePeriodOn; InitialTimePeriodOn <= FinalTimePeriodOn; InitialTimePeriodOn += OnTimeIncrement)
    {
      for(count = 1; count <= Repeat; count ++)
      {
        for(index = 0; index < 10; index ++)
        {
          digitalWrite(Everything[index], HIGH);
        }
        
        delay(InitialTimePeriodOn);
        
        for(index = 0; index < 10; index ++)
        {
          digitalWrite(Everything[index], LOW);
        }
        
        delay(InitialTimePeriodOn);
        
      }
    }    
  }
  
  for(count = 1; count <= EndRepeat; count ++)
  {
    for(index = 0; index < 10; index ++)
    {
      digitalWrite(Everything[index], HIGH);
    }
        
    delay(FinalTimePeriodOn);
        
    for(index = 0; index < 10; index ++)
    {
      digitalWrite(Everything[index], LOW);
    }
        
    delay(FinalTimePeriodOn);   
  }
  
  delay(1000);
  
}


//
// turn on the LEDs, one at a time
//
void blinkSingleLedsGoingClockwise(int onTime, int offTime, byte repeatCount)
{
  byte count;
  byte pinNumber;

  for(count = 1; count <= repeatCount; count++)
  {
    for(pinNumber = 8; pinNumber >= 2; pinNumber--)
    { 
      digitalWrite(pinNumber, HIGH);
      if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time
      digitalWrite(pinNumber, LOW);
      if (fade.delayAndCheckForExit(offTime) == true) return;   // check knob during off time
    }

    for(pinNumber = 9; pinNumber <= 15; pinNumber++)
    { 
      digitalWrite(pinNumber, HIGH);
      if (fade.delayAndCheckForExit(onTime) == true) return;   // check knob during on time
      digitalWrite(pinNumber, LOW);
      if (fade.delayAndCheckForExit(offTime) == true) return;   // check knob during off time
    }
  
  }
}
