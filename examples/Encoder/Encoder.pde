#include <Encoder.h>

Encoder encoder1;
Encoder encoder2;

void setup() {
  //Setup Serial line.
  Serial.begin(115200);
  // put your setup code here, to run once:
  encoder1.attach(12);
  encoder2.attach(14);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Encoder1:");
  Serial.print("\t");
  Serial.print(encoder1.getTicks());
  Serial.print("\t");
  Serial.print("Encoder2:");
  Serial.print("\t");
  Serial.print(encoder2.getTicks());
  Serial.print("\n");

	delay(100);
}
