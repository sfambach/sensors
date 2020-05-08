#define PIN A5


void setup() {
 Serial.begin(115200);
  pinMode(PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PIN)){
    Serial.println("x");
  }
}
