# Arduino DIY

This repository contains some sketches of Arduino [projects](https://github.com/Naff16/Arduino_DIY/tree/master/DIY), that can help to start with Arduino development to your DIY projects.

## Sketches
1. [Blink](https://github.com/Naff16/Arduino_DIY/tree/master/DIY/Blink_DIY)
2. [Push button](https://github.com/Naff16/Arduino_DIY/tree/master/DIY/Push_Button_DIY)
3. [LDR](https://github.com/Naff16/Arduino_DIY/blob/master/DIY/LDR_DIY)
4. [Servo](https://github.com/Naff16/Arduino_DIY/tree/master/DIY/Servo_DIY)
5. [Servo_LDR](https://github.com/Naff16/Arduino_DIY/tree/master/DIY/Servo_LDR_DIY)
6. [RFID](https://github.com/Naff16/Arduino_DIY/tree/master/DIY/RFID_DIY)
7. [DHT](https://github.com/Naff16/Arduino_DIY/tree/master/DIY/DHT_DIY)

## How to start
1. Install Arduino IDE
	- [Arduino IDE](https://www.arduino.cc/en/Main/Software)

2. Choose the proper board
	- Tools -> Boards -> Arduino Uno (Or another)
3. Choose the correct port
	- Tools -> Port -> COM

## Installing arduino libraries
1. Download the required library
	1. Used in the examples:
		* [DHT_lib](https://github.com/adafruit/DHT-sensor-library)
		* [LCD_lib](https://github.com/marcoschwartz/LiquidCrystal_I2C)
		* [RFID_lib](https://github.com/miguelbalboa/rfid)
		* [Servo_lib](https://github.com/arduino-libraries/Servo)
2. Unzip it
3. Copy and paste it in C:\Users\Username\Documents\Arduino\libraries (If a regular installation this will be the path)
4. Open the Arduino IDE

## Troubleshooting
### -  Using clone boards
1. **Problem:** COM port not appearing.
	* **Solution:** Install CH340 drivers: [CH340](https://sparks.gogo.co.nz/ch340.html)
2. **Problem:** Progmam not compiling to the board.
	* **Solution 1:** Choose the correct board
	* **Solution 2:** Choose the (Old Bootloader) option for the processor 

## New projects
* **IOT**

## Authors
* **Naff16**
