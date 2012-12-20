//Bobby Fata, The New School, 2012
//RGB LED Jelly
//Thanks to Mike Gruisin, SFE, 2011 for the Flex sensor test program


int green = 3;
int red = 5;
int blue = 6; 
int green2 = 9;
int red2 = 10;
int blue2 = 11;
int breathepause = 10;

int mDelay = 15;
int holder = 0;

void setup()
{
  // initialize serial communications
  Serial.begin(9600); 
  //set up pins to be outputs  
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(green2, OUTPUT);
}

void loop()
{
  int sensor, degrees;

  // read the voltage from the voltage divider (sensor plus resistor)
  sensor = analogRead(0);

  // convert the voltage reading to inches
  // the first two numbers are the sensor values for straight (768) and bent (853)
  // the second two numbers are the degree readings we'll map that to (0 to 90 degrees)
  degrees = map(sensor, 768, 853, 0, 90);
  // note that the above numbers are ideal, your sensor's values will vary
  // to improve the accuracy, run the program, note your sensor's analog values
  // when it's straight and bent, and insert those values into the above function.

  // print out the result
  Serial.print("analog input: ");
  Serial.print(sensor,DEC);
  Serial.print("   degrees: ");
  Serial.println(degrees,DEC);

  // pause before taking the next reading
  delay(100);    
  //for(int i=255; i>10; i--){ // for int i starting at 255; while i is greater than 10;
  //subtract one from i over and over until i is no longer greater than 10
  // analogWrite(blue, i);//every time i changes analog write the value of i to the blue LED
  // analogWrite(blue2, i);
  //delay(mDelay);
  //}

  analogWrite(red, 255);
  analogWrite(red2,255);
  analogWrite(blue,255);
  analogWrite(blue2,255);
  analogWrite(green,255);
  analogWrite(green2,255);

  if(sensor>155){
    for(int i=255; i>10; i--){
      analogWrite(blue2,0);
      analogWrite(blue,0);
      analogWrite(green,i);
      analogWrite(green2,i);
      analogWrite(red,255);
      analogWrite(red2,255);
    }
  }
  else if(sensor<68){
    for(int i=255; i>10; i--){ // for int i starting at 255; while i is greater than 10;
      //subtract one from i over and over until i is no longer greater than 10
      analogWrite(blue, i);//every time i changes analog write the value of i to the blue LED
      analogWrite(blue2, i);
      delay(mDelay);
    }

    for(int i=255; i>10; i--){
      analogWrite(red, i);
      analogWrite(blue, 255-i);
      analogWrite(red2, i);
      analogWrite(blue2, 255-i);
      delay(mDelay);
    }
    //delay(holder);
    //holder = random(1000, 5000);
    for(int i=10; i<255; i++){
      analogWrite(red, i);
      analogWrite(blue, 255-i);
      analogWrite(red2, i);
      analogWrite(blue2, 255-i);
      delay(mDelay);
    }
    //delay(holder);
    for(int i=10; i<255; i++){
      analogWrite(blue, i);
      analogWrite(green, 255-i);
      analogWrite(blue2, i);
      analogWrite(green2, 255-i);
      delay(mDelay);
    }
    

    for(int i=255; i>10; i--){
      analogWrite(red, i);
      analogWrite(green, 255-i);
      analogWrite(red2, i);
      analogWrite(green2, 255-i);
      delay(mDelay);
    }
 
    for(int i=10; i<255; i++){
      analogWrite(red, i);
      analogWrite(green, 255-i);
      analogWrite(red2, i);
      analogWrite(green2, 255-i);
      delay(mDelay);
    }
    for(int i=10; i<255; i++){
      analogWrite(green, i);
      analogWrite(green2, i);
      delay(mDelay);
    }
  }
  else {
    breathe();
  }
}













