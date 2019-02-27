/*
  Date: 24/10/2018
  DIY
*/

/*
  Title: Humidity and temperature sensor display
  Description:
  This program will read a temperature and humidity
  sensor and display both values in a LCD display
  16x02 using I2C protocol. A pre-defined value of
  humdity/temperature will trigger a relay when the
  value is reached.
*/

//Libraries
#include <DHT.h>;  // Avaliable at https://github.com/adafruit/DHT-sensor-library
#include <LiquidCrystal_I2C.h> //Avaliable at https://github.com/marcoschwartz/LiquidCrystal_I2C

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay = 8; // Relay pin

//Variables
int humi;  //Stores humidity value
int temp; //Stores temperature value


int air_conditioning(int temperature) {  // Function to turn relay ON and OFF based in the temperature value.

  if (temperature > 18) {
    digitalWrite(relay, HIGH);  // Turn Relay ON
    Serial.print("The relay is ON\n");
  }
  else {
    digitalWrite(relay, LOW);  // Turn Relay OFF
    Serial.print("The relay is OFF\n");
  }
return;
}

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.begin(); // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight
  pinMode(relay, OUTPUT);  // initialize digital pin relay as an output.
}

void loop()
{
  //Read data and store it to variables humi and temp
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print("%, Temperature: ");
  Serial.print(temp);
  Serial.println("ºC");

  // Call the relay function
  air_conditioning(temp);
  
  //Print in the LCD 16x02 the temp and humidity values
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(humi);
  lcd.print("%");
  
  delay(1000); //Delay 1 sec.
}
