
//Photoresistors
int photoPin1 = A0;
int photoPin2 = A1;

//Photoresistor Values
int photoVal1 = 0;
int photoVal2 = 0;

//LED Setup
int ledPin1 = 2;
int ledPin2 = 4;

//speaker setup
int speakerPin = 9;

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 
  1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;


void setup(){

  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop(){
  //Turn on LED's

  int sensor, degrees;

  // read the voltage from the voltage divider (sensor plus resistor)
  sensor = analogRead(2);

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


  //Photosensors
  photoVal1 = analogRead(photoPin1);
  photoVal2 = analogRead(photoPin2);

if(sensor<200){
  digitalWrite(ledPin1, HIGH);
}

  if(photoVal1 > 50){
    digitalWrite(ledPin2, HIGH);
  }
  if(photoVal2 > 50){
    for (int i = 0; i < length; i++) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo); // rest
      } 
      else {
        playNote(notes[i], beats[i] * tempo);
      }

      // pause between notes
      delay(tempo / 2); 
    }
  }
}
void OneWireReset(int Pin) // reset.  Should improve to act as a presence pulse
{
  digitalWrite(Pin, LOW);
  pinMode(Pin, OUTPUT); // bring low for 500 us
  delayMicroseconds(500);
  pinMode(Pin, INPUT);
  delayMicroseconds(500);
}

void OneWireOutByte(int Pin, byte d) // output byte d (least sig bit first).
{
  byte n;

  for(n=8; n!=0; n--)
  {
    if ((d & 0x01) == 1)  // test least sig bit
    {
      digitalWrite(Pin, LOW);
      pinMode(Pin, OUTPUT);
      delayMicroseconds(5);
      pinMode(Pin, INPUT);
      delayMicroseconds(60);
    }
    else
    {
      digitalWrite(Pin, LOW);
      pinMode(Pin, OUTPUT);
      delayMicroseconds(60);
      pinMode(Pin, INPUT);
    }

    d=d>>1; // now the next bit is in the least sig bit position.
  }




}



byte OneWireInByte(int Pin) // read byte, least sig byte first
{
  byte d, n, b;

  for (n=0; n<8; n++)
  {
    digitalWrite(Pin, LOW);
    pinMode(Pin, OUTPUT);
    delayMicroseconds(5);
    pinMode(Pin, INPUT);
    delayMicroseconds(5);
    b = digitalRead(Pin);
    delayMicroseconds(50);
    d = (d >> 1) | (b<<7); // shift d to right and insert b in most sig bit position
  }
  return(d);
}

//Tone Setup
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 
    'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'     };
  int tones[] = { 
    1915, 1700, 1519, 1432, 1275, 1136, 1014, 956     };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}




