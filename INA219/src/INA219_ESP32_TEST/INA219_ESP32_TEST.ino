/******************************************************************************
# Test of an INA219 
Sensor is connected to GPIO 22,23 of an ESP32

##Settings
Pin-setup for the two wire bus (I2C)
SDA - Wire Data
SCL - Wire Clock
I2C_ADDRESS - I2C Adress of the sensor

## Credits 
* Licence: AGPL3
* Author:  S. Fambach
Visit http://www.fambach.net if you want
******************************************************************************/

/*****************************************************************************/
// Debuging

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINT(x) Serial.print(x)
#else
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINT(x)
#endif

/*****************************************************************************/
// INA219 Setup
#include <Wire.h>
#include <Adafruit_INA219.h>

#define SDA 22
#define SDC 23
#define I2C_ADDRESS 0x40


Adafruit_INA219 ina219(I2C_ADDRESS);

/*****************************************************************************/
// XXXXXXXX

/*****************************************************************************/
// XXXXXXXX

/*****************************************************************************/
// XXXXXXXX

/*****************************************************************************/
// XXXXXXXX


/*****************************************************************************/
// Main Programm 

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA, SDC);

  if (! ina219.begin(&Wire)) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
}


void loop() {
  float ma = ina219.getCurrent_mA();

  DEBUG_PRINT("Current [mA]: ");
  DEBUG_PRINTLN(ma);

  delay(100);
}

// activate for serial event
/*void serialEvent(){
  DEBUG_PRINTLN("Serial Event");
}*/

/*****************************************************************************/
// Rest of implementations