// create an empty array for 100 MovingCircle objects
int a = 100;

MovingCircle[] myCircleArray = new MovingCircle[a];

void setup() {
  size(500, 500);
  smooth();
  noStroke();

  // and actually create the objects and populate the
  // array with them
  for (int i=0; i<myCircleArray.length; i++) {
    myCircleArray[i] = new MovingCircle(200, 200, 15);
  }
}

void draw() {
  fill(0, 75);
  rect(0, 0, width, height);
  //background(0); //remove if you want to stop streaking

  // iterate through every moving circle
  for (int i=0; i<myCircleArray.length; i++) {

    myCircleArray[i].update();
    myCircleArray[i].checkCollisions();
    myCircleArray[i].drawCircle();
  }
}

