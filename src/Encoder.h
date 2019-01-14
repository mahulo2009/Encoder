#ifndef Encoder_H
#define Encoder_H


#include "Arduino.h"
#include <EncoderBase.h>

//#define ENCODER_DEBUG 1

//Maximun number of encoder this class can handle.
#define MAX_ENCODER 4

class Encoder : public EncoderBase {
  public:
	static Encoder *instance_[MAX_ENCODER];
	static int encoder_index_;

	Encoder(int ticks_per_revolution);			//constructor with ticks per revolution

	virtual void setupDirection(int direction)			//encoder direction positive fordware negative backware
		{ this->direction_=direction;};				

	virtual double getVelocity(double dt);				//velocity [radians per second]

	void attach(int pin);						//attach the encoder interrupt pin
	void handler(int index);  					//handle the interruption
	inline long getTicks() { return ticks_;}	//total number of ticks 

  private:
  	int pin_;									//interrupt pin
  	long ticks_;								//total number of ticks
	long previous_ticks_;						//store previous ticks since getVelocity was called 
	double angle_per_tic_;						//factor to convert from ticks to angle.
	int direction_;								//encoder direction positive fordware negative backware	
};
#endif
