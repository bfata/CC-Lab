/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 9;           // the pin that the LED is attached to
int led1 = 10;
int led2 = 11;
int brightness = 0;    // how bright the LED is
int brightness2 = 0;
int brightness3 = 0;
int fadeAmount = 3;    // how many points to fade the LED by
int fadeAmount2 = 5;
int fadeAmount3 = 6;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  analogWrite(led1, brightness2); 
  analogWrite(led2, brightness3);  

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  brightness2 = brightness2 + fadeAmount2;
  brightness3 = brightness3 + fadeAmount3;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  if (brightness2 == 0 || brightness2 ==255) {
    fadeAmount2 = -fadeAmount2;
  }
  if (brightness3 == 0 || brightness3 ==255) {
    fadeAmount3 = -fadeAmount3;
  }
  // wait for 20 milliseconds to see the dimming effect    
  delay(20);                            


}




