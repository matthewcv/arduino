/*
alternate the leds, change speed with pot.
 If you push the button down, they'll flash on and off together.
 
 The circuit:
 Use the makershield
 * led1 to d1
 * led2 to d2
 * pot to a0
 * btn 1 to d0
 
*/

// constants won't change. They're used here to 
// set pin numbers:
const int pot = A0;     
const int led1 =  1;      
const int led2 =  2;    
const int btn = 0;
// variables will change:
int potState = 0;         
int led = led1;
int btnState = LOW;
void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);      
  pinMode(led2, OUTPUT);      
  pinMode(btn, INPUT);
}

void loop(){
 
  potState = analogRead(pot);
 btnState = digitalRead(btn);
 
 if(btnState == HIGH)
 {

  if (led == led1) {     
    // turn LED on:    
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, LOW); 
    led = led2;
  } 
  else {

    digitalWrite(led1, LOW); 
        digitalWrite(led2, HIGH);  
led = led1;
  }
  
 }
 else
 {
     if (led == led1) {     
    // turn LED on:    
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, HIGH); 
    led = led2;
  } 
  else {

    digitalWrite(led1, LOW); 
        digitalWrite(led2, LOW);  
led = led1;
  }
 }
  delay(potState);
}
