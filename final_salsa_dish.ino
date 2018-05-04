//#include <Servo.h>
#include <VarSpeedServo.h>

//int gesturePin =

VarSpeedServo servo;
//Servo myservo;
const int myservo = 7;
int pos = 0; 

void setup() {
  servo.attach(myservo);
  servo.write(0,255,true);

}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(60,10,true);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(120,10,true);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(180,10,true);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(0);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }

}
