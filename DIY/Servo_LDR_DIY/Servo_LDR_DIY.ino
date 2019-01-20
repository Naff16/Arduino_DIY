/*
  Date: 20/01/2019
  DIY
*/

/*
  Title: Servo controled by light (LDR)
  Description:
  This program will use an LDR (Light Dependent Resistor), to detect the environment luminosity
  and control the angle of a servo motor.
  LDR (0 -> Light / 1024 -> No light).
  Servo motor ( 0° -> Closed / 180° -> Open).
*/

#include <Servo.h> // Avaliable at: https://github.com/arduino-libraries/Servo

//Constants
int sensorPin = A0;  // input pin for LDR
int servoPin = 5;  // pin where the servo is connected

int sensorValue = 0;  // varaible to store de LDR value
int servo_angle;  // To store servo angle

Servo servo_Motor;  // create servo object to control a servo

void setup() {
  Serial.begin(9600); // sets serial port for communication
  servo_Motor.attach(servoPin);  // attaches the servo on pin 5 to the servo object
}

void loop() {
  // Read the value from the sensor, this will read values from 0 (0V) and 1023 (5V)
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen

  // The map function will map the range from the LDR (0-1024) to the servo angle (0-180)
  // map(value, fromLow, fromHigh, toLow, toHigh)
  servo_angle = map(sensorValue, 0, 1024, 0, 180);  
  
  // write the servo angle
  servo_Motor.write(servo_angle);
  
  delay(500);
}
