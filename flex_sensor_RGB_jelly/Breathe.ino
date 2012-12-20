void breathe(){
   for(int i=255; i>30; i--){ // for int i starting at 255; while i is greater than 10;
    //subtract one from i over and over until i is no longer greater than 10
    analogWrite(blue, i);//every time i changes analog write the value of i to the blue LED
    analogWrite(blue2, i);
    analogWrite(red, i);
    analogWrite(red2, i);
    analogWrite(green, i);
    analogWrite(green2, i);
    delay(5);
   }
   
  for(int i=30; i<255; i++){ // for int i starting at 255; while i is greater than 10;
    //subtract one from i over and over until i is no longer greater than 10
    analogWrite(blue, i);//every time i changes analog write the value of i to the blue LED
    analogWrite(blue2, i);
    analogWrite(red, i);
    analogWrite(red2, i);
    analogWrite(green, i);
    analogWrite(green2, i);
    delay(5);
  }
}
