#ifndef Encoder_H
#define Encoder_H

#include "Arduino.h"

//#define ENCODER_DEBUG 1

//Maximun number of encoder this class can handle.
#define MAX_ENCODER 4

class Encoder {
  public:
		static Encoder *instance_[MAX_ENCODER];
		static int encoder_index_;
		Encoder(int ticks_per_revolution);								//constructor with ticks per revolution
		void attach(int pin);															//attach the encoder interrupt pin
		void handler(int index);  												//handle the interruption
		float getVelocity(float dt);											//velocity [radians per second]
		inline unsigned int getTicks() { return ticks_;}	//total number of ticks 
  private:
  	int pin_;																					//interrupt pin
  	unsigned int ticks_;															//total number of ticks
		unsigned int previous_ticks_;											//store previous ticks since getVelocity was called 
		float angle_per_tic_;															//factor to convert from ticks to angle.
};
#endif
