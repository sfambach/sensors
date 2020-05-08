/**
 * Example from the library. 
 * I changed the two hardware serials to one software serial
 * More details under http://www.fambach.net/FTMini-Laser/
 * 
 * The original lib to be no longer existing in Git, install it via Arduino Gui (keyword = tfmini, Author= hideakitai)
 *  
 */

#include "TFmini.h"
#include <SoftwareSerial.h>

/**
 * Prepare the sensor
 */
SoftwareSerial mySerial(10, 11);  
TFmini tfmini;

void setup()
{
    Serial.begin(115200);

    // init the sensor
    mySerial.begin(TFmini::DEFAULT_BAUDRATE);
    tfmini.attach(mySerial);
}

void loop()
{
        // get some data from the sensor
        if (tfmini.available())
        {
            Serial.print("tfmini ");
            Serial.println(1);
            Serial.print("distance : ");
            Serial.println(tfmini.getDistance());
            Serial.print("strength : ");
            Serial.println(tfmini.getStrength());
            Serial.print("int time : ");
            Serial.println(tfmini.getIntegrationTime());
        }
}
