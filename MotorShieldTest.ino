 
//#include <Servo.h>
int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;
int buzzer = 4;
//Servo myservo; 
int servo = 2;
bool val = false;
//Servo myServo;

char inChar = ' ';
char state;
char lastState = 'A';

void setup()

{
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT);
pinMode(servo, OUTPUT);
pinMode(buzzer, OUTPUT);
//myServo.attach(9);
Serial.begin(9600);
beep();
}
void loop()
{
  if(Serial.available()) {
    inChar = (char)Serial.read();
  }

  // do something different depending on the 
  // range value:
  if(lastState != inChar){
    if(inChar == 'H'){
      forward(3000);
      delay(2000);
      turnRight();
      delay(2000);
      forward(3000);
      delay(2000);
      turnRight();
      delay(2000);
      turnRight();
      delay(2000);
      //Dump hotdog here
      //Now returning back to position
      forward(3000);
      delay(2000);
      turnLeft();
      delay(2000);
      forward(3000);
      delay(2000);
      turnRight();
      delay(2000);
      turnRight();
      delay(2000);
    }
    else if (inChar == 'N'){
      forward(3000);
      delay(2000);
      turnLeft();
      delay(2000);
      forward(3000);
      delay(2000);
      turnRight();
      delay(2000);
      turnRight();
      delay(2000);
      //Dump hotdog here
      //Now returning back to position
      forward(3000);
      delay(2000);
      turnRight();
      delay(2000);
      forward(3000);
      delay(2000);
      turnRight();
      delay(2000);
      turnRight();
      delay(2000);
    }
  }
  lastState = inChar;
} 

void beep(){
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
}


void forward(int time){
  digitalWrite(M1,HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 255);
  analogWrite(E2, 197);
  delay(time);
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

void turnRight(){
  digitalWrite(M1,LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 255);
  analogWrite(E2, 197);
  delay(700);
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}
void turnLeft(){
  digitalWrite(M1,HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, 255);
  analogWrite(E2, 197);
  delay(690);
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}



  
