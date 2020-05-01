/**
 * Code snippet to read data from KY-037 / KY-038 sound sensor board
 * define ports for digital and analog input
 * Fambach.net
 */


// please adapt to your wiring 
#define MIC_SIGNAL_PIN    A2
#define MIC_THRESHOLD_PIN 2

// factor to calculate voltage
const float VOLTAGE_FACTOR  = 5.0f / 1023.0f;



void setup(){

  // init serial port
  Serial.begin(115200);

  // init Pins
  pinMode(MIC_SIGNAL_PIN, INPUT);
  pinMode(MIC_THRESHOLD_PIN, INPUT);
  digitalWrite(MIC_SIGNAL_PIN, LOW);
  digitalWrite(MIC_THRESHOLD_PIN, LOW);
  //analogReference(DEFAULT);
  
}


void loop(){

  bool treshold = false;
  long  level = 0 ;
  String voltage = "";
 
  // get treshhold pin
  treshold = digitalRead(MIC_THRESHOLD_PIN);

  // get analog pin 
  level = analogRead(MIC_SIGNAL_PIN);

  // calc. average and invert
  voltage = String (((float)level)* VOLTAGE_FACTOR);

  // doing output
  char buffer[255];
  sprintf (buffer,"Treshold: %s Level: %4d Voltage: ",treshold?"ON ":"OFF", level);
  Serial.print(buffer);
  Serial.print(voltage);
  Serial.println();

//  delay(100);
}

