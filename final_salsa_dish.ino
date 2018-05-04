//#include <Servo.h>
#include <VarSpeedServo.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;


VarSpeedServo servo;
//Servo myservo;
const int myservo = 7;
int pos = 0; 
//int pos_count;
//int new_pos_count;

void setup() {
    Serial.begin(115200);
//  this is the setup code for the gesture sensor

   if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);

//this is the setup code for the servo motor
  servo.attach(myservo);
  servo.write(0,255,true);

}

void loop() {

  uint8_t gesture = apds.readGesture();
//    if(gesture == APDS9960_DOWN) Serial.println("v");
//    if(gesture == APDS9960_UP) Serial.println("^");
//    if(gesture == APDS9960_LEFT) Serial.println("<");
//    if(gesture == APDS9960_RIGHT) Serial.println(">");

  if(gesture == APDS9960_RIGHT) {

      Serial.println(">");
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree

//      int pos_count + 60 = new_pos_count;
      servo.write(60,10,true);              // tell servo to go to position in variable 'pos'
      delay(10); // waits 15ms for the servo to reach the position

 
      }
  }

   if(gesture == APDS9960_LEFT) {

    Serial.println("<");
    for (pos = 60; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree

//      int pos_count - 60 = new_pos_count;
      servo.write(0,10,true);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
      }
  }



  
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(0);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }

}
