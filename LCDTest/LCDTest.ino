/*
	This code is free software: you can 
	redistribute it and/or modify it under the terms of the GNU 
	General Public License as published by the Free Software 
	Foundation, either version 3 of the License, or (at your option) 
	any later version.

	This code is distributed in the hope 
	that it will be useful, but WITHOUT ANY WARRANTY; without even 
	the implied warranty of MERCHANTABILITY or FITNESS FOR A 
	PARTICULAR PURPOSE. See the GNU General Public License for more 
	details.

	You should have received a copy of the GNU General Public License
	along with this code. If not, see 
	<http://www.gnu.org/licenses/>.
*/

// LED Pin
#define pinLED PC13

/* *******************************************************
/  Libraries
*/
#include <Wire.h>
#include "LiquidCrystal_I2C.h" // Needed for operating the LCD screen

/* *******************************************************
*/

/* *******************************************************
/  LCD
*/
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
/* *******************************************************
*/

void setup() {            //This function gets called when the Arduino starts
  Serial.begin(9600);     //This code sets up the Serial port at 9600 baud rate

  pinMode(pinLED, OUTPUT); // Set LED pinMode

  delay(500);
  
  Serial.println("LCD Test");

  // Initialize the LCD and print a message
  lcd.init(); // start the LCD
  lcd.backlight(); // enable the backlight
  lcd.clear(); // Clear the screen from any character
  lcd.setCursor(0,0); // Start writing from position 0 row 0, so top left
  lcd.print("LCD Test");
  delay(1000);
  
}

/* *******************************************************
/  Loop, this code is constantly repeated
*/ 
void loop() {
  digitalWrite(pinLED, HIGH);
  delay(1000);
  digitalWrite(pinLED, LOW);
  Serial.println("LCD Test is running");
}
