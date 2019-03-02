/*
  Date: 02/03/2019
  DIY
*/

/*
  Title: Push Button Pull-up debounce
  Description:
  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 4 and turn a LED on and off when the button is pressed, maintaining 
  it's state.
  Pushbuttons often generate spurious open/close transitions when pressed, due to 
  mechanical and physical issues,these transitions may be read as multiple presses 
  in a very short time, leading to wrong state transitions. So we need to check 
  twice in a short period of time to make sure the pushbutton is definitely pressed.
*/

//Constants
int push_button = 4;    // the number of the pushbutton
int led_pin = 6;      // the number of the LED pin

// Variables
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// The following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(push_button, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);

  // set initial LED state
  digitalWrite(led_pin, ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int push_button_val = digitalRead(push_button);

  // check to see if you just pressed the button
  // If the switch changed, due to noise or pressing:
  if (push_button_val != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (push_button_val != buttonState) {
      buttonState = push_button_val;

      // only toggle the LED if the new button state is LOW
      if (buttonState == LOW) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(led_pin, ledState);

  // save the push_button_val. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = push_button_val;
}
