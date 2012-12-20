int red = 3;
int blue = 6;
int green = 5; 
int red2 = 9;
int blue2 = 10;
int green2 = 11;

int mDelay = 15;
int holder = 0;
void setup(){

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(green2, OUTPUT);
  //digitalWrite(red, HIGH);
  //digitalWrite(green, HIGH);
  //digitalWrite(blue, HIGH);
}

void loop(){
  // holder = int(random(5000, 15000));
  // mDelay = int(random(15, 40));

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
  //holder = int(random(5000, 15000));
  //mDelay = int(random(15, 40));

  for(int i=255; i>10; i--){
    analogWrite(red, i);
    analogWrite(green, 255-i);
    analogWrite(red2, i);
    analogWrite(green2, 255-i);
    delay(mDelay);
  }
  //delay(holder);
  //holder = random(1000, 5000);
  for(int i=10; i<255; i++){
    analogWrite(red, i);
    analogWrite(green, 255-i);
    analogWrite(red2, i);
    analogWrite(green2, 255-i);
    delay(mDelay);
  }
  //delay(holder);
  for(int i=10; i<255; i++){
    analogWrite(green, i);
    analogWrite(green2, i);
    delay(mDelay);
  }
}



