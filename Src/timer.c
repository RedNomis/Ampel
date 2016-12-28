#include "timer.h"

#include "stm32f4xx_hal.h"

#include "sc_types.h"

struct MyTimer theTimerStruct;

void ampel_setTimer(Ampel* handle, const sc_eventid evid,
		const sc_integer time_ms, const sc_boolean periodic) {

	theTimerStruct.boolEnabled = 1;
	theTimerStruct.boolPeriodic = (int)periodic;
	theTimerStruct.event = evid;
	theTimerStruct.handle = handle;
	theTimerStruct.timerMS = time_ms;
	theTimerStruct.timerCounter = time_ms;
	theTimerStruct.tickLast = HAL_GetTick();
}

void ampel_unsetTimer(Ampel* handle, const sc_eventid evid) {
	theTimerStruct.boolEnabled = 0;
}

void TimerDecrease() {
	uint16_t myTicker = HAL_GetTick();
	int tickDiff = 0;

	if (!theTimerStruct.boolEnabled)
		return;

	tickDiff = myTicker - theTimerStruct.tickLast;
	if (tickDiff < 0) // uwTick hat overflow
			{
		tickDiff += ((2 ^ 16) - theTimerStruct.tickLast);
	}
	theTimerStruct.timerCounter -= tickDiff;
	theTimerStruct.tickLast = myTicker;

	if (theTimerStruct.timerCounter <= 0) // yeah doit!
			{
		ampel_raiseTimeEvent(theTimerStruct.handle,
				theTimerStruct.event);
		if (theTimerStruct.boolPeriodic)
			theTimerStruct.timerCounter = theTimerStruct.timerMS;
		else
			theTimerStruct.boolEnabled = 0;
	}
}
