/*
 * Cycles a three-LED common-anode package through the rainbow.
 *
 * Demonstrates fading multiple outputs, common-anode wiring, and the
 * use of functions to repeat similar tasks.
 *
 * Often, individual LEDs are wired in an "active high" configuration, so
 * a LOW output will cause the LED to turn off, and a HIGH output will
 * allow current to flow through the lamp.  Sometimes, packages of LEDs
 * will have a single ground pin for all of the diodes, called a "common
 * cathode."  These work on this same HIGH=ON, LOW=OFF principle.  You
 * just have to connect all of the positive legs of the diodes to their
 * respective output pins, and the common cathode goes to the ground.
 *
 * Other packages use the opposite wiring plan, offering a "common
 * anode."  You have to wire the shared pin to the +VDC source, and put
 * the resistors and diodes below the source.  To light the lamp, you set
 * the output LOW, and to extinguish the lamp, you set the output HIGH.
 * Signals which do useful things when given a low value are sometimes
 * called "active low."
 *
 * Wire a common-anode RGB LED package such that the anode connects to
 * the Arduino's +5V pin, and the other pins go to three PWM outputs to
 * allow for fading:  digital output pins 3, 5 and 6.  Don't forget to
 * put a resistor in series with every LED, or you'll burn it out!
 *
 * Ed Halley <ed@halley.cc>
 */

// Select which PWM-capable pins are to be used.
int redPin = 5;
int greenPin = 6;
int bluePin = 3;


// A function to fade UP an active-low or common-anode output.
// Optionally, specify a short delay value to slow the loop.
// (This would fade down an LED that was active high.)
//
void fadeUp(int pin, int d = 10)
{
  int i;
  for (i = 255; i >= 0; i--)
  {
    analogWrite(pin, i);
    delay(d);
  }
}

// A function to fade DOWN an active-low or common-anode output.
// Optionally, specify a short delay value to slow the loop.
// (This would fade up an LED that was active high.)
//
void fadeDown(int pin, int d = 10)
{
  int i;
  for (i = 0; i <= 255; i++)
  {
    analogWrite(pin, i);
    delay(d);
  }
}

// Set up our outputs, and give full high values so the
// LEDs start off.  Then fade in the blue LED.
//
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(A5, INPUT);
  digitalWrite(A5, HIGH);
  
    analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

delay(500);

    analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);

delay(500)    ;
analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

delay(500);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
delay(500);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);


  //fadeUp(bluePin);
 // fadeUp(greenPin);
  //fadeUp(redPin);
}

// The cycle of ramps will go through all of the primary
// and secondary hues in the RGB rainbow, and repeat.
//
void loop()
{
  /*
   fadeUp(redPin); 

  fadeUp(greenPin);
    fadeUp(bluePin);
   fadeDown(redPin);   
  fadeDown(greenPin);


  fadeDown(bluePin);
  
  
 
*/

  //analogWrite(redPin, 0);
  
  
  
  int btn = digitalRead(A5);
  if(btn == HIGH)
  {
    analogWrite(bluePin, 0);
        analogWrite(greenPin, 255);

  }
  else
  {
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
}
