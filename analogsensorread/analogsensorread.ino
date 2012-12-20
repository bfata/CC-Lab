int sensorPin = A0;
int ledPin = 9;
int sensorValue = 0;
int newSensorValue;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(sensorPin);

  newSensorValue = map(sensorValue, 0,1023,0,255);
  analogWrite(ledPin, newSensorValue);

  Serial.print(newSensorValue);
}

