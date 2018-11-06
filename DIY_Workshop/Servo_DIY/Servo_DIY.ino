/*
  Author: André Ferraz
  Date: 24/10/2018
  DIY WorkShop
*/

/*
  Title: Servo Motor control
  Descrption:
  This example demonstrates the use of a servo motor, by inserting the
  angle (0-180) in the serial port.
*/

#include <Servo.h> // Avaliable at: https://github.com/arduino-libraries/Servo

//Constants
int servo = 5;  // pin where the servo is connected

//Variables
String serial_data;  // For incoming serial data
int servo_angle;  // To store servo angle


Servo servo_Motor;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
  servo_Motor.attach(servo);  // attaches the servo on pin 5 to the servo object
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming data until it recieve nothing else
    serial_data = Serial.readStringUntil("/r");
    // print the recieved data
    Serial.print("I received: ");
    Serial.print(serial_data);

    // Convert from a String to an Integer the data recieved
    servo_angle = serial_data.toInt();

    // write the servo angle on the servo
    servo_Motor.write(servo_angle);
  }
}
