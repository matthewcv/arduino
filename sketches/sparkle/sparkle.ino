int pins[] = {0,1,2,3,4,5,6,7,8,9};
int plen = 10;

int offs[] ={0,2,4,6,8};
int loff = 5;
int ons[] = {1,3,5,7,9};
int lon = 5;
void setup()
{
  //Serial.begin(9600);
  for(int i = 0; i < plen; i++)
  {
    pinMode(pins[i],OUTPUT);
  }
  for(int i = 0; i < plen; i++)
  {
    digitalWrite(pins[i], LOW);
  }
}


void loop()
{
  int on = random(0,loff);
  int off = random(0,lon);
  
  int temp = offs[on];
  offs[on] = ons[off];
  ons[off] = temp;
  
  for(int i = 0; i < loff; i++)
  {
    digitalWrite(offs[i], LOW);
  }
    for(int i = 0; i < lon; i++)
  {
    digitalWrite(ons[i], HIGH);
  }
  delay(150);
}
