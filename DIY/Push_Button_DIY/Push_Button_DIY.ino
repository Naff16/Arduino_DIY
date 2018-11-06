/*
  Date: 24/10/2018
  DIY
*/

/*
  Title: Push Button Pull-up
  Descrption:
  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and turn a LED on when pressed.
*/

//Constants
int led_pin = 4;
int push_button = 2;

void setup() {
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(push_button, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int push_button_val = digitalRead(push_button);
  //print out the value of the pushbutton
  Serial.println(push_button_val);

  // When the push-button value is HIGH (Not pressed) will not turn the LED.
  // when it's pressed the push button value is LOW (PRESSED) and will turn the LED ON.
  if (push_button_val == HIGH) {
    digitalWrite(led_pin, LOW);
  } else {
    digitalWrite(led_pin, HIGH);
  }
}
