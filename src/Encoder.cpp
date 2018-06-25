#include "Encoder.h"

void handle_interrupt_1()
{
	Encoder::instance_[0]->handler(0);
}

void handle_interrupt_2()
{
	Encoder::instance_[0]->handler(1);
}

void(*handler_function[MAX_ENCODER])()={handle_interrupt_1,handle_interrupt_2};

Encoder *Encoder::instance_[MAX_ENCODER];
int Encoder::encoder_index_=0;

Encoder::Encoder()
{
}

void Encoder::handler(int index)
{
	instance_[index]->ticks_++;	
	#ifdef MOTOR_ENCODER_DEBUG
	Serial.print("Encoder::handler:");
  Serial.print("\t");
	Serial.print(index);
  Serial.print("\t");
	Serial.print(instance_[index]->ticks_);
  Serial.print("\n");
	#endif
}

void Encoder::attach(int pin)
{		
	if (encoder_index_< MAX_ENCODER) {
		instance_[encoder_index_]=this;
		instance_[encoder_index_]->pin_=pin;
		instance_[encoder_index_]->ticks_=0;
		pinMode(pin, INPUT_PULLUP);
		attachInterrupt(digitalPinToInterrupt(pin), handler_function[encoder_index_], RISING);
		encoder_index_++;
	}
}
