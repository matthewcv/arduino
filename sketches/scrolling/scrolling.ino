int pins[] = {0,1,2,3,4,5,6,7,8,9};
int plen = 10;
void setup()
{
  //Serial.begin(9600);
  for(int i = 0; i < sizeof(pins); i++)
  {
    pinMode(pins[i],OUTPUT);
  }
  //plen = sizeof(pins);
}

int what = LOW;
void loop()
{
   if(what == LOW){what = HIGH;}
   else{ what = LOW;}
  
  //Serial.println(what);
  for(int i = 0; i < plen; i++)
  {
    digitalWrite(pins[i],what);
    delay(250);
  }


}
