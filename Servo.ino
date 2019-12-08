/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 75;    // variable to store the servo position
int input = 2;
char inChar = ' ';
char state;
char lastState = 'A';

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);
  pinMode(input, INPUT);
  dump();
  delay(2000);
  dump();
}

void loop() {
if(Serial.available()) {
    inChar = (char)Serial.read();
  }
  if(lastState != inChar){
      if(inChar == 'D'){
        dump();
      }
  }
  lastState = inChar;
}

void dump(){
  for (int pos = 75; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 120; pos >= 75; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}
