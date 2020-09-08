/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to set the knob color to pink. This value is stored in the 
  Qwiic Twist and will be loaded after each power-on.

  Also - the max I2C datarate for Qwiic Twist is 400kHz
  
  Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/15083

  Hardware Connections:
  Plug a Qwiic cable into the Qwiic Twist and a BlackBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 9600 baud to see the output
*/
#include <Wire.h>
#include "SparkFun_Qwiic_Twist_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_Twist
#include <SFE_MicroOLED.h>
TWIST twist; //Create instance of this object

#define PIN_RESET 9 
#define DC_JUMPER 1 
MicroOLED oled(PIN_RESET, DC_JUMPER);

void setup() {
  Serial.begin(9600);
  Serial.println("Qwiic Twist Example");
  Wire.begin();
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  delay(1000);     // Delay 1000 ms
  oled.clear(PAGE);

  if(twist.begin() == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }

  Wire.setClock(400000); //Optional: After Twist begin(), increase I2C speed to max, 400kHz

  //Set the knob color to pink
  twist.setColor(100, 10, 50); //Set the Red, Green, and Blue LED brightnesses

  //Set the know color to white
  //twist.setColor(255, 255, 255); //Set the Red, Green, and Blue LED brightnesses
}

void loop() {
  Serial.print("Count: ");
  Serial.print(twist.getCount());
  oled.clear(PAGE);     // Clear the screen
  oled.setFontType(0);  // Set font to type 0
  oled.setCursor(0, 0); // Set cursor to top-left
  //oled.write(twist.getCount());  // Write a byte out as a character
  //oled.display();
  int twistCount = twist.getCount();
  //oled.print(twist.getCount());
  //oled.display();
  
  if(twist.isPressed()){
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("Pressed!");
    oled.display();
    delay(1000);
    };
  if(0<= twistCount && twistCount <5){//---------------> red
    twist.setColor(255, 0, 0);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("RED");
    oled.display();
  } else if (5<= twistCount && twistCount <10){//------> green 
    twist.setColor(0, 255, 0);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("GREEN");
    oled.display();
  } else if (10<= twistCount && twistCount <15){//-----> violet
    twist.setColor(64, 0, 255);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("VIOLET");
    oled.display();
  } else if (15<= twistCount && twistCount <20){//-----> yellow
    twist.setColor(255, 255, 0);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("YELLOW");
    oled.display();
  } else if (20<= twistCount && twistCount <25){//-----> pink
    twist.setColor(128, 0, 255);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("PINK");
    oled.display();
  } else if (25<= twistCount && twistCount <30){//-----> blue
    twist.setColor(0, 255, 255);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("BLUE");
    oled.display();
  } else if (30<= twistCount && twistCount <35){//-----> orange
    twist.setColor(255, 100, 0);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("ORANGE");
    oled.display();
  }

  Serial.println();

  delay(10);
}
