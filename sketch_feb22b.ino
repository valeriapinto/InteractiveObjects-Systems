const int switchPin = 8;
const int ledPin = 12;

int ledState = HIGH;         // the current state of the LED pin
int switchState;            // the current reading from the button pin
int lastSwitchState = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(switchPin, INPUT); 
   pinMode(ledPin, OUTPUT);
   int switchState = digitalRead(switchPin); // in order to see if the switch is being activated
  
}

void loop() {

  int switchState = digitalRead(switchPin); // in order to see if the switch is being activated
  Serial.println(switchState);

   
 if (switchState == 1){
 digitalWrite(ledPin, HIGH);
 //  light up LED
 //starts sensing if switch changed via pressing

 if (reading != lastSwitchState){

  lastDebounceTime = millis();

  // in order to find the current state, we need to subtract the total time minus the debounce time
  //and see if its greater than the debounce delay. if it is:

  if ((millis() - lastDebounceTime) > debounceDelay){

    // if the switch state changes
    if reading != switchState){
      switchState = reading;

        if (switchSate == HIGH){

          ledState =! ledState;
        }
    }
  }
 }
  // here we are setting the LED to its state
  digitalWrite(ledPin, ledState);
 } 
 }
