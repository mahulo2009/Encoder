#ifndef Motor_Encoder_H
#define Motor_Encoder_H

#include "Arduino.h"

#define MOTOR_ENCODER_DEBUG 1

#define MAX_ENCODER 2

class Encoder {
  public:
		static Encoder *instance_[MAX_ENCODER];
		static int encoder_index_;
		Encoder();
		void attach(int pin);
		void handler(int index);  
		inline unsigned int getTicks() {
			return ticks_;
		}	   
  private:
  	int pin_;
  	unsigned int ticks_;
};
#endif
