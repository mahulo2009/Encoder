#include <Encoder.h>

#define ENCODER_TICKS_PER_REVOLUTION 21

Encoder encoder1(ENCODER_TICKS_PER_REVOLUTION);
Encoder encoder2(ENCODER_TICKS_PER_REVOLUTION);

void setup() {
  //Setup Serial line.
  Serial.begin(115200);
	//Attach encoder
  encoder1.attach(12);
  encoder2.attach(14);
}

void loop() {
  Serial.print("Encoder1:");
  Serial.print("\t");
  Serial.print(encoder1.getTicks());
  Serial.print("\t");
  Serial.print(encoder1.getVelocity(0.5));
  Serial.print("\t");
  Serial.print("Encoder2:");
  Serial.print("\t");
  Serial.print(encoder2.getTicks());
  Serial.print("\t");
  Serial.print(encoder2.getVelocity(0.5));
  Serial.print("\n");
	delay(500);
}
