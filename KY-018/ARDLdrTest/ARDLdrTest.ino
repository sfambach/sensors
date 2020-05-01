void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
}
void loop() {
  int LDR = analogRead(A0);
  Serial.println(LDR);
}

