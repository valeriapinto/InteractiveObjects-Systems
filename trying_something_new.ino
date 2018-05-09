//#include <Servo.h>
#include <VarSpeedServo.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;
#include <Adafruit_NeoPixel.h>


VarSpeedServo servo;
//Servo myservo;
const int myservo = 7;
int pos = 0; 
int current_pos = 0;
int sixty  = 60;
int pos_angle = 0;

// This is the Neo-pixel code 
#define PIN            6

// There are 24 but 32 works, 24 doesnt
#define NUMPIXELS      32

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
Serial.begin(115200);

   if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //gesture sensor set up
  apds.enableProximity(true);
  apds.enableGesture(true);

  //servo motor set up
  servo.attach(myservo);
  servo.write(0,255,true);
  
  // neo pixel set up
  pixels.begin();
  pixels.setBrightness(30);

  //Set pixels off
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    pixels.show();
    }

}

void loop() {

uint8_t gesture = apds.readGesture();

    
    if(gesture == APDS9960_RIGHT && pos_angle<180) {

          Serial.println(">");

          //Set pixels off
          for(int i=0;i<NUMPIXELS;i++){
            pixels.setPixelColor(i, pixels.Color(0,0,0)); 
            pixels.show();
            }
  
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

    
     if(gesture == APDS9960_LEFT && pos_angle>0) {

          Serial.println("<");

          //Set pixels off
          for(int i=0;i<NUMPIXELS;i++){
            pixels.setPixelColor(i, pixels.Color(0,0,0)); 
            pixels.show();
            }

            
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

    if(gesture == APDS9960_UP) {

      Serial.println("^");



          if (pos_angle == 0){
              //medium yellow

              for(int i=0;i<NUMPIXELS;i++){
              pixels.setPixelColor(i, pixels.Color(100,190,5,0)); //green
              pixels.show();
              delay(30);
            }

            for(int i=0;i<NUMPIXELS;i++){
              pixels.setPixelColor(i, pixels.Color(250,205,5,0)); //yellow
              pixels.show();
              delay(30);
            }
          }

          else if (pos_angle == 60){
            //spicy orange
            
            for(int i=0;i<NUMPIXELS;i++){
              pixels.setPixelColor(i, pixels.Color(100,190,5,0)); //green
              pixels.show();
              delay(30);
            }

            for(int i=0;i<NUMPIXELS;i++){
              pixels.setPixelColor(i, pixels.Color(250,205,5,0)); //yellow
              pixels.show();
              delay(30);
            }
            for(int i=0;i<NUMPIXELS;i++){
            pixels.setPixelColor(i, pixels.Color(250,80,5,0)); //orange
            pixels.show();
            delay(30);
            }
          }

          else if (pos_angle == 120){
            //mild green

            for(int i=0;i<NUMPIXELS;i++){
            pixels.setPixelColor(i, pixels.Color(100,190,5,0)); //green
            pixels.show();
            }
          }

          else if (pos_angle == 180){
            //super spicy red

           for(int i=0;i<NUMPIXELS;i++){
              pixels.setPixelColor(i, pixels.Color(100,190,5,0)); //green
              pixels.show();
              delay(30);
            }

            for(int i=0;i<NUMPIXELS;i++){
              pixels.setPixelColor(i, pixels.Color(250,205,5,0)); //yellow
              pixels.show();
              delay(30);
            }
            for(int i=0;i<NUMPIXELS;i++){
            pixels.setPixelColor(i, pixels.Color(250,80,5,0)); //orange
            pixels.show();
            delay(30);
            }
             for(int i=0;i<NUMPIXELS;i++){
             pixels.setPixelColor(i, pixels.Color(255,0,0,0)); //red
             pixels.show();
             delay(30);
              }
          }     

    }
      
}

//    if(gesture == APDS9960_DOWN) Serial.println("v");

