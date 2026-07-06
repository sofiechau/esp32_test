#include <Arduino.h>
#include <Keypad.h>
#include <ESP32Servo.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {23,22,21,19};
byte colPins[COLS] = {18,5,4,2};
String input = "";
String password = "1234";
Servo myServo;
const int servoPin = 13;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  Serial.println("enter password");
  myServo.attach(servoPin);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    input += key;
    if (input.length() == 4) {
      if (input == password) {
        Serial.println("Access granted");
        myServo.write(0);
        delay(2000);
        myServo.write(90);
        delay(2000);
        myServo.write(0);
        delay(2000);
      } else {
        Serial.println("Access denied");
      }
      input = "";
    }
  }
}
  
  