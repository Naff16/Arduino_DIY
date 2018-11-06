/*
  Author: André Ferraz
  Date: 05/11/2018
  DIY WorkShop
*/

/*
  Title: Blink
  Descrption:
  This program will turn on and off an LED.
*/

//Constant
int led_pin = 3; // LED pin

void setup() {
  pinMode(led_pin, OUTPUT);  // initialize digital pin led_pin as an output.
}

void loop() {
  digitalWrite(led_pin, HIGH);  // turn the LED on 
  delay(1000);                   
  digitalWrite(led_pin, LOW);  // turn the LED off 
  delay(1000);                       
}
