#ifndef Encoder_H
#define Encoder_H

#include "Arduino.h"

#define ENCODER_DEBUG 1

#define MAX_ENCODER 2

class Encoder {
  public:
		static Encoder *instance_[MAX_ENCODER];
		static int encoder_index_;
		Encoder(int ticks_per_revolution);
		void attach(int pin);
		void handler(int index);  
		float getVelocity(float dt);
		inline unsigned int getTicks() { return ticks_;}
  private:
  	int pin_;
  	unsigned int ticks_;
		unsigned int previous_ticks_;
		float angle_per_tic_;
};
#endif
