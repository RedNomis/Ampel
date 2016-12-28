#ifndef TIMER_H_
#define TIMER_H_

#include "../src-gen/Ampel.h"

struct MyTimer
{
	int boolEnabled;
	Ampel *handle;
	sc_eventid event;
	unsigned int timerMS;
	int boolPeriodic;
	int timerCounter;
	uint32_t tickLast;
};

void TimerDecrease(void);

#endif // TIMER_H_
