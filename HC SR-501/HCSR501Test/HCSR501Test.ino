/** HC SR501 Test
 *   www.fambach.net
 *   GPL V2
*/

#define SR501PIN A0

void setup() {
  Serial.begin(115200);

  // init pin
  pinMode(A0, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(A0) == HIGH) {
    Serial.print("PIR activated ...");
    while (digitalRead(A0) == HIGH) {
      //Serial.print(".");
    }
    Serial.println(" now inactive");
  }
}
