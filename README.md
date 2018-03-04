# Why STM32Duino
In this repo I am testing STM32 as an affordable substitute for the expensive Arduino MCU. Arduino UNO could easily cost 20 EUR. I know Arduino clones are available for around 4 USD, I don't really like the large footprint of the boards.

# Setup

## 3 USD Hardware setup
In order to work with a STM32 chip you'll need to obtain one and you'll need a USB to Serial device.

STM32 microprocessing boards are abundantly available on the web. Just search for "stm32f103c8t6" on AliExpress and you'll find the MCU on a break out board for less than $2.

In order to program the STM32 you'll need a USB to Serial device. I recommend using a CP2102 based adapter. Your favorite hardware supplier should be able to sell you one for about $1.

## Free Software

The easiest way to just get started is to wire up the STM32 and program it without a bootloader.

1. Download the files needed for the Arduino IDE by getting a ZIP from [https://github.com/rogerclarkmelbourne/Arduino_STM32](https://github.com/rogerclarkmelbourne/Arduino_STM32)
2. Add a hardware folder to your Arduino folder. On Windows that would be Documents\Arduino\hardware
3. Unzip and remove the "-master" from the folder name of the Arduino_STM32 files
4. Copy the folder into the Arduino hardware folder
5. Start the Arduino IDE and download support for SAM Boards from Tools > Boards Manager
6. In the IDE set the following preferences in the Tools menu:
  * Board: Generic STM32F103C series
  * Variant: STM32F103C8 (20k RAM, 64k Flash)
  * Upload method: Serial
7. Stick the USB to Serial device into a USB port of your computer
8. Now you should be able to select it in the Tools > Port menu as a COM port on Windows or a /dev/tty port on Mac / Linux
9. Compile the following Blink sketch
~~~~
// The STM32 has a LED on board attached to pin PC13
#define pinLED PC13

void setup() {
  Serial.begin(9600); // Open Serial port
  pinMode(pinLED, OUTPUT); // Set LED pinMode
  Serial.println("Setup completed"); // Print status to Serial  
}

void loop() {
  digitalWrite(pinLED, HIGH);
  delay(1000);
  digitalWrite(pinLED, LOW);
  Serial.println("Blink");  
}
~~~~
10 .On the board you will find two Boot jumpers
