import processing.core.*; 
import processing.xml.*; 

import java.applet.*; 
import java.awt.Dimension; 
import java.awt.Frame; 
import java.awt.event.MouseEvent; 
import java.awt.event.KeyEvent; 
import java.awt.event.FocusEvent; 
import java.awt.Image; 
import java.io.*; 
import java.net.*; 
import java.text.*; 
import java.util.*; 
import java.util.zip.*; 
import java.util.regex.*; 

public class array_class extends PApplet {

// create an empty array for 100 MovingCircle objects
int a = 100;

MovingCircle[] myCircleArray = new MovingCircle[a];

public void setup() {
  size(500, 500);
  smooth();
  noStroke();

  // and actually create the objects and populate the
  // array with them
  for (int i=0; i<myCircleArray.length; i++) {
    myCircleArray[i] = new MovingCircle(200, 200, 15);
  }
}

public void draw() {
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

class MovingCircle {

  float x;
  float y;
  float xSpeed;
  float ySpeed;

  float circleSize;

  float c1;
  float c2;
  float c3;

  MovingCircle(float xpos, float ypos, float csize) {
    x = xpos;
    y = ypos;
    circleSize = csize;

    xSpeed = random(-10, 10);
    ySpeed = random(-10, 10);
  }

  public void update() {
    x += xSpeed;

    y += ySpeed;
  }

  public void checkCollisions() {

    float r = circleSize/2;

    if ( (x<r) || (x>width-r)) {
      xSpeed = -xSpeed;
    } 

    if ( (y<r) || (y>height-r)) {
      ySpeed = -ySpeed;
    }
  }

  public void drawCircle() {
    c1 = 10+y/2;
    c2 = 100+ x/50;
    c3 = map(sin(.2f), -1, 1, 0, 255);

    fill(c1, c2, c3);
    ellipse(x, y, circleSize, circleSize);
  }
}
  static public void main(String args[]) {
    PApplet.main(new String[] { "--bgcolor=#FFFFFF", "array_class" });
  }
}
