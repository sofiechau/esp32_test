#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;
const int servoPin = 13;
void setup(){
  Serial.begin(115200);
  Serial.println("starging...");
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
}

void loop(){
  Serial.println("moving 0 deg");
  myServo.write(0);
  delay(2000);
  
  Serial.println("moving 90 deg");
  myServo.write(90);
  delay(2000);

  Serial.println("moving 180 deg");
  myServo.write(180);
  delay(2000);
}

