int pressurePin = A0;
int force; 
int motorSpeed;
int enable = 9;  // PWM pin
int motorPinA = 7;
int motorPinB = 8;

void setup() {
  Serial.begin(9600);
  pinMode(enable, OUTPUT);
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop() {
  force = analogRead(pressurePin);
  Serial.println(force);
// this would control the faster speed (clockwise)
  if (force > 511) {
    motorSpeed = map(force, 0, 1023, 0, 255);
    forward(motorSpeed);
  }
// this would control the slower speed (counter clockwise)
  if (force < 511) {
    motorSpeed = map(force, 0, 1023, 0, 255);
    reverse(motorSpeed);
  }

  if (force < 0) {
    brake();
  }

}

void forward(int s) {
  digitalWrite(enable, LOW);
  digitalWrite(motorPinA, HIGH);
  digitalWrite(motorPinB, LOW);
  analogWrite(enable, s);

}


void reverse(int s) {
  digitalWrite(enable, LOW);
  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, HIGH);
  analogWrite(enable, s);

}

void brake() {
  digitalWrite(enable, LOW);
  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, LOW);
  digitalWrite(enable, HIGH);

}
