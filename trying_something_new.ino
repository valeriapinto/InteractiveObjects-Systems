//#include <Servo.h>
#include <VarSpeedServo.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;


VarSpeedServo servo;
//Servo myservo;
const int myservo = 7;
int pos = 0; 
int current_pos;
int sixty  = 60;
int pos_angle;


void setup() {
Serial.begin(115200);

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

    
    if(gesture == APDS9960_RIGHT) {

          Serial.println(">");
          Serial.println(servo.read());
          current_pos = servo.read();
          pos_angle = current_pos + sixty;
          Serial.println(pos_angle);
          
          for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          servo.write(pos_angle,10,true);              // tell servo to go to position in variable 'pos'
          delay(15);
          break;

        }
     }

    
     if(gesture == APDS9960_LEFT) {

          Serial.println("<");
          Serial.println(servo.read());
          current_pos = servo.read();
          pos_angle = current_pos - sixty;
          Serial.println(pos_angle);
          
          for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          servo.write(pos_angle,10,true);              // tell servo to go to position in variable 'pos'
          delay(15);
          break;


      }
}
      
}


//
//     if(gesture == APDS9960_DOWN) Serial.println("v");
//    if(gesture == APDS9960_UP) Serial.println("^");

