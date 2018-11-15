/*
  Date: 15/11/2018
  DIY
*/

/*
  Title: Light detector (LDR)
  Descrption:
  This program will use an LDR (Light Dependent Resistor), to detect the environment luminosity
  and turn on or off a light depending on it.
*/

//Constants
int sensorPin = A0;  // input pin for LDR
int ledPin = 4;  // input pin for LED

int sensorValue = 0;  // varaible to store de LDR value

void setup() {
  Serial.begin(9600); // sets serial port for communication
  pinMode(ledPin, OUTPUT);  // sets the ledPin as an OUTPUT
}

void loop() {
  // Read the value from the sensor, this will read values from 0 (0V) and 1023 (5V)
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen

  // Read the sensor value and depending on it, it turns on and off the light.
  if (sensorValue > 350) {

    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}
