int pins[] = {0,1,2,3,4,5,6,7,8,9};
int plen = 10;
void setup()
{
  //Serial.begin(9600);
  for(int i = 0; i < plen; i++)
  {
    pinMode(pins[i],OUTPUT);
  }
  //plen = sizeof(pins);
}

int num = 3;
int spd = 50;
boolean up = true;
void loop()
{
  if(up)
  {
  for(int i = 0; i < plen + num; i++)
  {
    if(i < plen)
    {
      digitalWrite(pins[i],HIGH);
      
    }
    
    if(i >= num)
    {
      digitalWrite(pins[i-num],LOW);
    }
    
    delay(spd);
  }
  }
  else
  {
  for(int i = plen -1; i >= 0-num; i--)
  {
    if(i >= 0)
    {
      digitalWrite(pins[i],HIGH);
    }
    
    if(i <plen - num)
    {
      digitalWrite(pins[i + num],LOW);
    }
    delay(spd);
  }
  }
  up = !up;
  delay(spd * 2);
}


