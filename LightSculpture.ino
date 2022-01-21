void setup()
{
    int pinNumber;
  
  for(pinNumber = 2; pinNumber <= 15; pinNumber++)
  { 
    pinMode(pinNumber, OUTPUT);
  }
}

void loop()
{ 
  Serial.begin(115200);
  // Serial.println("Starting...");
  FlashSequence1(200, 50, 25, 1, 3);
  // Serial.println("Done with 1");
  FlashSequence1(50, 200, 25, 1, 1);  
  // Serial.println("Done with 2");
  FlashSequence2(250, 50, 25, 1, 3); 
  // Serial.println("Done with 3");
  FlashSequence2(50, 250, 25, 1, 1);  
  // Serial.println("Done with 4");
  FlashSequence3(250, 50, 25, 3);
  // Serial.println("Done with 5");
  FlashSequence3(50, 250, 25, 1);  
  // Serial.println("Done with 6");
  FlashSequence4(250, 25, 25, 1, 4);
  // Serial.println("Done with 7");
  FlashSequence4(25, 250, 25, 1, 1);  
  // Serial.println("Done with 8");
  FlashSequence5(200, 50, 25, 2, 3);
  // Serial.println("Done with 9");
  FlashSequence5(50, 200, 25, 2, 1);  
  // Serial.println("Done with 10");
  FlashSequence6(300, 50, 50, 2); 
  // Serial.println("Done with 1");
  FlashSequence6(50, 300, 50, 1);  
  // Serial.println("Done with 12");
  FlashSequence7(150, 50, 50, 1, 4);
  // Serial.println("Done with 13");
  FlashSequence7(50, 150, 50, 1, 2);  
  // Serial.println("Done with 14");
  FlashSequence8(150, 50, 25, 1, 4);
  // Serial.println("Done with 15");
  FlashSequence8(50, 150, 25, 1, 4);  
  // Serial.println("Done with 16");
  FlashSequence9(150, 50, 25, 3, 4);
  // Serial.println("Done with 17");
  FlashSequence9(50, 150, 25, 2, 2);  
  // Serial.println("Done with 18");
  FlashSequence10(150, 50, 25, 3, 3); 
  // Serial.println("Done with 19");
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
          delay(InitialTimePeriodOn);
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    
        digitalWrite(OneIntroDisplay[index=8], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(OneIntroDisplay[index=8], LOW);
      
        for(index = 7; index > 0; index--)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          delay(InitialTimePeriodOn);
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
          delay(InitialTimePeriodOn);
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    
        digitalWrite(OneIntroDisplay[index=8], HIGH);
        delay(InitialTimePeriodOn);
        digitalWrite(OneIntroDisplay[index=8], LOW);
      
        for(index = 7; index > 0; index--)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          delay(InitialTimePeriodOn);
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
          delay(FinalTimePeriodOn);
          digitalWrite(OneIntroDisplay[index], LOW);
        } 
    
        digitalWrite(OneIntroDisplay[index=8], HIGH);
        delay(FinalTimePeriodOn);
        digitalWrite(OneIntroDisplay[index=8], LOW);
      
        for(index = 7; index > 0; index--)
        {
          digitalWrite(OneIntroDisplay[index], HIGH);
          delay(FinalTimePeriodOn);
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
