int photoPin = A0;
int ledPin = 10;
int photoVal = 0;

void setup(){

  Serial.begin(9600);
  Serial.println("photoResistor GOOO");
  pinMode(10, OUTPUT);
}

void loop(){
  photoVal = analogRead(photoPin);
  
  Serial.print("photo value: ");
  Serial.println(photoVal);
  
  if(photoVal < 40){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
 // analogWrite(ledPin, photoVal/3);
  delay(20);
}
