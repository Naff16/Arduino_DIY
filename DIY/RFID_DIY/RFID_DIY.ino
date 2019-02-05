/*
Date: 17/10/2018     
DIY       
*/

/*
Title: RFID tag detection                         
Description:                                                       
	This program detects a RFID tag, if the           
	tag is recognized a green led will light up       
	and a specific beep will sound, otherwise a       
	red led willlight up and another beep will sound. 
*/

/*
RDFD pins to Arduino Pins:
3.3v -> Pin 3.3V           
RST -> Pin 9               
GND -> GND                 
NC -> Not Connected        
MISO -> Pin 12             
MOSI -> Pin 11             
SCK -> Pin 13              
SDA -> Pin 10              
*/

//Libraries
#include <SPI.h> 
#include <MFRC522.h>  // Avaliable at: https://github.com/miguelbalboa/rfid

MFRC522 mfrc522(10, 9);  // MRFC instance creation

const int red_led = 7;
const int green_led = 6;
const int buzzer = 3;

void setup()
{
  Serial.begin(9600);  // set the baud rate for data transmission with the computer
  SPI.begin();  // start de SPI
  mfrc522.PCD_Init();  // start the MRFC
  pinMode(red_led, OUTPUT);  // define red_red pin as output
  pinMode(green_led, OUTPUT);  // define green_led pin as output
}
void loop()
{
  //here we have to wait for the card, when it is near to the sensor
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  //we can read it's value
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Tag:");
  String content = "";  // empty string initialization to write the tag UID
  int uid_size =  mfrc522.uid.size;  //see RFID tag unique identifier size (will be 4 in this case)

  // this cycle is run each position of the tag uid bytes.
  for (byte i = 0; i < uid_size; i++) {
    Serial.print(mfrc522.uid.uidByte[i], HEX); // print the hex value of each byte
    content.concat(String(mfrc522.uid.uidByte[i], HEX));  // Concatenate the 4 hex values in a single String
  }
  
  content.toUpperCase();  // Put the String to UpperCASE
  
  if ((content == "16B9C0F7") || (content ==  "E9F9D72A") || (content ==  "43CD873")) {  // if the readed tag match with the defined UID it will make the green led light up
    digitalWrite(green_led, HIGH);  // Change the pin state to HIGH, its the same as turn on the led
    tone(buzzer, 1000, 300);  // using tone we can define the (buzzer_pin, frequency, duration)
    delay(2000);  // 2s delay
    digitalWrite(green_led, LOW);  // Change the pin state to LOW, its the same as turn off the led
  } else {  // if not match it will make the red led light up
    digitalWrite(red_led, HIGH);  // Change the pin state to HIGH, its the same as turn on the led
    tone(buzzer, 500, 500);  // using tone we can define the (buzzer_pin, frequency, duration)
    delay(2000);  // 2s delay
    digitalWrite(red_led, LOW);  // Change the pin state to LOW, its the same as turn off the led
  }
  Serial.println();  // empty print
}
