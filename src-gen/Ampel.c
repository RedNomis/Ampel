
#include <stdlib.h>
#include <string.h>
#include "../Src/sc_types.h"
#include "Ampel.h"
#include "AmpelRequired.h"
/*! \file Implementation of the state machine 'ampel'
*/

/* prototypes of all internal functions */
static sc_boolean ampel_check_main_region_off_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_off_r1_YellowOn_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_off_r1_YellowOff_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1_Green_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1_GreenYellow_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1_Red_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1_RedYellow_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1_YellowGreen_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1__choice_0_tr0_tr0(const Ampel* handle);
static sc_boolean ampel_check_main_region_on_r1__choice_0_tr1_tr1(const Ampel* handle);
static void ampel_effect_main_region_off_tr0(Ampel* handle);
static void ampel_effect_main_region_off_r1_YellowOn_tr0(Ampel* handle);
static void ampel_effect_main_region_off_r1_YellowOff_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1_Green_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1_GreenYellow_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1_Red_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1_RedYellow_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1_YellowGreen_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1__choice_0_tr0(Ampel* handle);
static void ampel_effect_main_region_on_r1__choice_0_tr1(Ampel* handle);
static void ampel_enact_main_region_off_r1_YellowOn(Ampel* handle);
static void ampel_enact_main_region_off_r1_YellowOff(Ampel* handle);
static void ampel_enact_main_region_on_r1_Green(Ampel* handle);
static void ampel_enact_main_region_on_r1_GreenYellow(Ampel* handle);
static void ampel_enact_main_region_on_r1_Red(Ampel* handle);
static void ampel_enact_main_region_on_r1_RedYellow(Ampel* handle);
static void ampel_enact_main_region_on_r1_YellowGreen(Ampel* handle);
static void ampel_exact_main_region_off_r1_YellowOn(Ampel* handle);
static void ampel_exact_main_region_off_r1_YellowOff(Ampel* handle);
static void ampel_exact_main_region_on_r1_Green(Ampel* handle);
static void ampel_exact_main_region_on_r1_GreenYellow(Ampel* handle);
static void ampel_exact_main_region_on_r1_Red(Ampel* handle);
static void ampel_exact_main_region_on_r1_RedYellow(Ampel* handle);
static void ampel_exact_main_region_on_r1_YellowGreen(Ampel* handle);
static void ampel_enseq_main_region_off_default(Ampel* handle);
static void ampel_enseq_main_region_off_r1_YellowOn_default(Ampel* handle);
static void ampel_enseq_main_region_off_r1_YellowOff_default(Ampel* handle);
static void ampel_enseq_main_region_on_default(Ampel* handle);
static void ampel_enseq_main_region_on_r1_Green_default(Ampel* handle);
static void ampel_enseq_main_region_on_r1_GreenYellow_default(Ampel* handle);
static void ampel_enseq_main_region_on_r1_Red_default(Ampel* handle);
static void ampel_enseq_main_region_on_r1_RedYellow_default(Ampel* handle);
static void ampel_enseq_main_region_on_r1_YellowGreen_default(Ampel* handle);
static void ampel_enseq_main_region_default(Ampel* handle);
static void ampel_enseq_main_region_off_r1_default(Ampel* handle);
static void ampel_enseq_main_region_on_r1_default(Ampel* handle);
static void ampel_exseq_main_region_off(Ampel* handle);
static void ampel_exseq_main_region_off_r1_YellowOn(Ampel* handle);
static void ampel_exseq_main_region_off_r1_YellowOff(Ampel* handle);
static void ampel_exseq_main_region_on(Ampel* handle);
static void ampel_exseq_main_region_on_r1_Green(Ampel* handle);
static void ampel_exseq_main_region_on_r1_GreenYellow(Ampel* handle);
static void ampel_exseq_main_region_on_r1_Red(Ampel* handle);
static void ampel_exseq_main_region_on_r1_RedYellow(Ampel* handle);
static void ampel_exseq_main_region_on_r1_YellowGreen(Ampel* handle);
static void ampel_exseq_main_region(Ampel* handle);
static void ampel_exseq_main_region_off_r1(Ampel* handle);
static void ampel_exseq_main_region_on_r1(Ampel* handle);
static void ampel_react_main_region_off_r1_YellowOn(Ampel* handle);
static void ampel_react_main_region_off_r1_YellowOff(Ampel* handle);
static void ampel_react_main_region_on_r1_Green(Ampel* handle);
static void ampel_react_main_region_on_r1_GreenYellow(Ampel* handle);
static void ampel_react_main_region_on_r1_Red(Ampel* handle);
static void ampel_react_main_region_on_r1_RedYellow(Ampel* handle);
static void ampel_react_main_region_on_r1_YellowGreen(Ampel* handle);
static void ampel_react_main_region_on_r1__choice_0(Ampel* handle);
static void ampel_react_main_region__entry_Default(Ampel* handle);
static void ampel_react_main_region_off_r1__entry_Default(Ampel* handle);
static void ampel_react_main_region_on_r1__entry_Default(Ampel* handle);
static void ampel_clearInEvents(Ampel* handle);
static void ampel_clearOutEvents(Ampel* handle);


void ampel_init(Ampel* handle)
{
	sc_integer i;

	for (i = 0; i < AMPEL_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Ampel_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	ampel_clearInEvents(handle);
	ampel_clearOutEvents(handle);

	/* Default init sequence for statechart ampel */
	handle->iface.push = 0;

}

void ampel_enter(Ampel* handle)
{
	/* Default enter sequence for statechart ampel */
	ampel_enseq_main_region_default(handle);
}

void ampel_exit(Ampel* handle)
{
	/* Default exit sequence for statechart ampel */
	ampel_exseq_main_region(handle);
}

sc_boolean ampel_isActive(const Ampel* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Ampel_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean ampel_isFinal(const Ampel* handle)
{
   return bool_false;
}

static void ampel_clearInEvents(Ampel* handle)
{
	handle->iface.evPushButton_raised = bool_false;
	handle->iface.dummy_raised = bool_false;
	handle->timeEvents.ampel_main_region_off_r1_YellowOn_tev0_raised = bool_false;
	handle->timeEvents.ampel_main_region_off_r1_YellowOff_tev0_raised = bool_false;
	handle->timeEvents.ampel_main_region_on_r1_Green_tev0_raised = bool_false;
	handle->timeEvents.ampel_main_region_on_r1_GreenYellow_tev0_raised = bool_false;
	handle->timeEvents.ampel_main_region_on_r1_Red_tev0_raised = bool_false;
	handle->timeEvents.ampel_main_region_on_r1_RedYellow_tev0_raised = bool_false;
	handle->timeEvents.ampel_main_region_on_r1_YellowGreen_tev0_raised = bool_false;
}

static void ampel_clearOutEvents(Ampel* handle)
{
}

void ampel_runCycle(Ampel* handle)
{
	
	ampel_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < AMPEL_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Ampel_main_region_off_r1_YellowOn :
		{
			ampel_react_main_region_off_r1_YellowOn(handle);
			break;
		}
		case Ampel_main_region_off_r1_YellowOff :
		{
			ampel_react_main_region_off_r1_YellowOff(handle);
			break;
		}
		case Ampel_main_region_on_r1_Green :
		{
			ampel_react_main_region_on_r1_Green(handle);
			break;
		}
		case Ampel_main_region_on_r1_GreenYellow :
		{
			ampel_react_main_region_on_r1_GreenYellow(handle);
			break;
		}
		case Ampel_main_region_on_r1_Red :
		{
			ampel_react_main_region_on_r1_Red(handle);
			break;
		}
		case Ampel_main_region_on_r1_RedYellow :
		{
			ampel_react_main_region_on_r1_RedYellow(handle);
			break;
		}
		case Ampel_main_region_on_r1_YellowGreen :
		{
			ampel_react_main_region_on_r1_YellowGreen(handle);
			break;
		}
		default:
			break;
		}
	}
	
	ampel_clearInEvents(handle);
}

void ampel_raiseTimeEvent(const Ampel* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(AmpelTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean ampel_isStateActive(const Ampel* handle, AmpelStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Ampel_main_region_off :
			result = (sc_boolean) (handle->stateConfVector[0] >= Ampel_main_region_off
				&& handle->stateConfVector[0] <= Ampel_main_region_off_r1_YellowOff);
			break;
		case Ampel_main_region_off_r1_YellowOn :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_off_r1_YellowOn
			);
			break;
		case Ampel_main_region_off_r1_YellowOff :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_off_r1_YellowOff
			);
			break;
		case Ampel_main_region_on :
			result = (sc_boolean) (handle->stateConfVector[0] >= Ampel_main_region_on
				&& handle->stateConfVector[0] <= Ampel_main_region_on_r1_YellowGreen);
			break;
		case Ampel_main_region_on_r1_Green :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_on_r1_Green
			);
			break;
		case Ampel_main_region_on_r1_GreenYellow :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_on_r1_GreenYellow
			);
			break;
		case Ampel_main_region_on_r1_Red :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_on_r1_Red
			);
			break;
		case Ampel_main_region_on_r1_RedYellow :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_on_r1_RedYellow
			);
			break;
		case Ampel_main_region_on_r1_YellowGreen :
			result = (sc_boolean) (handle->stateConfVector[0] == Ampel_main_region_on_r1_YellowGreen
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void ampelIface_raise_evPushButton(Ampel* handle)
{
	handle->iface.evPushButton_raised = bool_true;
}
void ampelIface_raise_dummy(Ampel* handle)
{
	handle->iface.dummy_raised = bool_true;
}


sc_integer ampelIface_get_push(const Ampel* handle)
{
	return handle->iface.push;
}
void ampelIface_set_push(Ampel* handle, sc_integer value)
{
	handle->iface.push = value;
}

/* implementations of all internal functions */

static sc_boolean ampel_check_main_region_off_tr0_tr0(const Ampel* handle)
{
	return handle->iface.evPushButton_raised;
}

static sc_boolean ampel_check_main_region_off_r1_YellowOn_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_off_r1_YellowOn_tev0_raised;
}

static sc_boolean ampel_check_main_region_off_r1_YellowOff_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_off_r1_YellowOff_tev0_raised;
}

static sc_boolean ampel_check_main_region_on_r1_Green_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_on_r1_Green_tev0_raised;
}

static sc_boolean ampel_check_main_region_on_r1_GreenYellow_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_on_r1_GreenYellow_tev0_raised;
}

static sc_boolean ampel_check_main_region_on_r1_Red_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_on_r1_Red_tev0_raised;
}

static sc_boolean ampel_check_main_region_on_r1_RedYellow_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_on_r1_RedYellow_tev0_raised;
}

static sc_boolean ampel_check_main_region_on_r1_YellowGreen_tr0_tr0(const Ampel* handle)
{
	return handle->timeEvents.ampel_main_region_on_r1_YellowGreen_tev0_raised;
}

static sc_boolean ampel_check_main_region_on_r1__choice_0_tr0_tr0(const Ampel* handle)
{
	return (handle->iface.push == 1) ? bool_true : bool_false;
}

static sc_boolean ampel_check_main_region_on_r1__choice_0_tr1_tr1(const Ampel* handle)
{
	return (handle->iface.push == 0) ? bool_true : bool_false;
}

static void ampel_effect_main_region_off_tr0(Ampel* handle)
{
	ampel_exseq_main_region_off(handle);
	ampelIface_offYellow(handle);
	ampel_enseq_main_region_on_default(handle);
}

static void ampel_effect_main_region_off_r1_YellowOn_tr0(Ampel* handle)
{
	ampel_exseq_main_region_off_r1_YellowOn(handle);
	ampel_enseq_main_region_off_r1_YellowOff_default(handle);
}

static void ampel_effect_main_region_off_r1_YellowOff_tr0(Ampel* handle)
{
	ampel_exseq_main_region_off_r1_YellowOff(handle);
	ampel_enseq_main_region_off_r1_YellowOn_default(handle);
}

static void ampel_effect_main_region_on_r1_Green_tr0(Ampel* handle)
{
	ampel_exseq_main_region_on_r1_Green(handle);
	ampel_enseq_main_region_on_r1_GreenYellow_default(handle);
}

static void ampel_effect_main_region_on_r1_GreenYellow_tr0(Ampel* handle)
{
	ampel_exseq_main_region_on_r1_GreenYellow(handle);
	ampel_enseq_main_region_on_r1_Red_default(handle);
}

static void ampel_effect_main_region_on_r1_Red_tr0(Ampel* handle)
{
	ampel_exseq_main_region_on_r1_Red(handle);
	ampel_enseq_main_region_on_r1_RedYellow_default(handle);
}

static void ampel_effect_main_region_on_r1_RedYellow_tr0(Ampel* handle)
{
	ampel_exseq_main_region_on_r1_RedYellow(handle);
	ampel_enseq_main_region_on_r1_YellowGreen_default(handle);
}

static void ampel_effect_main_region_on_r1_YellowGreen_tr0(Ampel* handle)
{
	ampel_exseq_main_region_on_r1_YellowGreen(handle);
	ampel_react_main_region_on_r1__choice_0(handle);
}

static void ampel_effect_main_region_on_r1__choice_0_tr0(Ampel* handle)
{
	ampel_enseq_main_region_on_r1_GreenYellow_default(handle);
}

static void ampel_effect_main_region_on_r1__choice_0_tr1(Ampel* handle)
{
	ampel_exseq_main_region_on(handle);
	ampel_enseq_main_region_off_default(handle);
}

/* Entry action for state 'YellowOn'. */
static void ampel_enact_main_region_off_r1_YellowOn(Ampel* handle)
{
	/* Entry action for state 'YellowOn'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_off_r1_YellowOn_tev0_raised) , 500, bool_false);
	ampelIface_onYellow(handle);
}

/* Entry action for state 'YellowOff'. */
static void ampel_enact_main_region_off_r1_YellowOff(Ampel* handle)
{
	/* Entry action for state 'YellowOff'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_off_r1_YellowOff_tev0_raised) , 500, bool_false);
	ampelIface_offYellow(handle);
}

/* Entry action for state 'Green'. */
static void ampel_enact_main_region_on_r1_Green(Ampel* handle)
{
	/* Entry action for state 'Green'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_Green_tev0_raised) , 5 * 1000, bool_false);
	ampelIface_onGreen(handle);
}

/* Entry action for state 'GreenYellow'. */
static void ampel_enact_main_region_on_r1_GreenYellow(Ampel* handle)
{
	/* Entry action for state 'GreenYellow'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_GreenYellow_tev0_raised) , 2 * 1000, bool_false);
	ampelIface_onYellow(handle);
}

/* Entry action for state 'Red'. */
static void ampel_enact_main_region_on_r1_Red(Ampel* handle)
{
	/* Entry action for state 'Red'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_Red_tev0_raised) , 10 * 1000, bool_false);
	ampelIface_onRed(handle);
	handle->iface.push = 0;
}

/* Entry action for state 'RedYellow'. */
static void ampel_enact_main_region_on_r1_RedYellow(Ampel* handle)
{
	/* Entry action for state 'RedYellow'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_RedYellow_tev0_raised) , 2 * 1000, bool_false);
	ampelIface_onYellow(handle);
}

/* Entry action for state 'YellowGreen'. */
static void ampel_enact_main_region_on_r1_YellowGreen(Ampel* handle)
{
	/* Entry action for state 'YellowGreen'. */
	ampel_setTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_YellowGreen_tev0_raised) , 5 * 1000, bool_false);
	ampelIface_onGreen(handle);
}

/* Exit action for state 'YellowOn'. */
static void ampel_exact_main_region_off_r1_YellowOn(Ampel* handle)
{
	/* Exit action for state 'YellowOn'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_off_r1_YellowOn_tev0_raised) );		
}

/* Exit action for state 'YellowOff'. */
static void ampel_exact_main_region_off_r1_YellowOff(Ampel* handle)
{
	/* Exit action for state 'YellowOff'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_off_r1_YellowOff_tev0_raised) );		
}

/* Exit action for state 'Green'. */
static void ampel_exact_main_region_on_r1_Green(Ampel* handle)
{
	/* Exit action for state 'Green'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_Green_tev0_raised) );		
	ampelIface_offGreen(handle);
}

/* Exit action for state 'GreenYellow'. */
static void ampel_exact_main_region_on_r1_GreenYellow(Ampel* handle)
{
	/* Exit action for state 'GreenYellow'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_GreenYellow_tev0_raised) );		
	ampelIface_offYellow(handle);
}

/* Exit action for state 'Red'. */
static void ampel_exact_main_region_on_r1_Red(Ampel* handle)
{
	/* Exit action for state 'Red'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_Red_tev0_raised) );		
	ampelIface_offRed(handle);
}

/* Exit action for state 'RedYellow'. */
static void ampel_exact_main_region_on_r1_RedYellow(Ampel* handle)
{
	/* Exit action for state 'RedYellow'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_RedYellow_tev0_raised) );		
	ampelIface_offYellow(handle);
}

/* Exit action for state 'YellowGreen'. */
static void ampel_exact_main_region_on_r1_YellowGreen(Ampel* handle)
{
	/* Exit action for state 'YellowGreen'. */
	ampel_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ampel_main_region_on_r1_YellowGreen_tev0_raised) );		
	ampelIface_offGreen(handle);
}

/* 'default' enter sequence for state off */
static void ampel_enseq_main_region_off_default(Ampel* handle)
{
	/* 'default' enter sequence for state off */
	ampel_enseq_main_region_off_r1_default(handle);
}

/* 'default' enter sequence for state YellowOn */
static void ampel_enseq_main_region_off_r1_YellowOn_default(Ampel* handle)
{
	/* 'default' enter sequence for state YellowOn */
	ampel_enact_main_region_off_r1_YellowOn(handle);
	handle->stateConfVector[0] = Ampel_main_region_off_r1_YellowOn;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state YellowOff */
static void ampel_enseq_main_region_off_r1_YellowOff_default(Ampel* handle)
{
	/* 'default' enter sequence for state YellowOff */
	ampel_enact_main_region_off_r1_YellowOff(handle);
	handle->stateConfVector[0] = Ampel_main_region_off_r1_YellowOff;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state on */
static void ampel_enseq_main_region_on_default(Ampel* handle)
{
	/* 'default' enter sequence for state on */
	ampel_enseq_main_region_on_r1_default(handle);
}

/* 'default' enter sequence for state Green */
static void ampel_enseq_main_region_on_r1_Green_default(Ampel* handle)
{
	/* 'default' enter sequence for state Green */
	ampel_enact_main_region_on_r1_Green(handle);
	handle->stateConfVector[0] = Ampel_main_region_on_r1_Green;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state GreenYellow */
static void ampel_enseq_main_region_on_r1_GreenYellow_default(Ampel* handle)
{
	/* 'default' enter sequence for state GreenYellow */
	ampel_enact_main_region_on_r1_GreenYellow(handle);
	handle->stateConfVector[0] = Ampel_main_region_on_r1_GreenYellow;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Red */
static void ampel_enseq_main_region_on_r1_Red_default(Ampel* handle)
{
	/* 'default' enter sequence for state Red */
	ampel_enact_main_region_on_r1_Red(handle);
	handle->stateConfVector[0] = Ampel_main_region_on_r1_Red;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state RedYellow */
static void ampel_enseq_main_region_on_r1_RedYellow_default(Ampel* handle)
{
	/* 'default' enter sequence for state RedYellow */
	ampel_enact_main_region_on_r1_RedYellow(handle);
	handle->stateConfVector[0] = Ampel_main_region_on_r1_RedYellow;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state YellowGreen */
static void ampel_enseq_main_region_on_r1_YellowGreen_default(Ampel* handle)
{
	/* 'default' enter sequence for state YellowGreen */
	ampel_enact_main_region_on_r1_YellowGreen(handle);
	handle->stateConfVector[0] = Ampel_main_region_on_r1_YellowGreen;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void ampel_enseq_main_region_default(Ampel* handle)
{
	/* 'default' enter sequence for region main region */
	ampel_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void ampel_enseq_main_region_off_r1_default(Ampel* handle)
{
	/* 'default' enter sequence for region r1 */
	ampel_react_main_region_off_r1__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void ampel_enseq_main_region_on_r1_default(Ampel* handle)
{
	/* 'default' enter sequence for region r1 */
	ampel_react_main_region_on_r1__entry_Default(handle);
}

/* Default exit sequence for state off */
static void ampel_exseq_main_region_off(Ampel* handle)
{
	/* Default exit sequence for state off */
	ampel_exseq_main_region_off_r1(handle);
}

/* Default exit sequence for state YellowOn */
static void ampel_exseq_main_region_off_r1_YellowOn(Ampel* handle)
{
	/* Default exit sequence for state YellowOn */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_off_r1_YellowOn(handle);
}

/* Default exit sequence for state YellowOff */
static void ampel_exseq_main_region_off_r1_YellowOff(Ampel* handle)
{
	/* Default exit sequence for state YellowOff */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_off_r1_YellowOff(handle);
}

/* Default exit sequence for state on */
static void ampel_exseq_main_region_on(Ampel* handle)
{
	/* Default exit sequence for state on */
	ampel_exseq_main_region_on_r1(handle);
}

/* Default exit sequence for state Green */
static void ampel_exseq_main_region_on_r1_Green(Ampel* handle)
{
	/* Default exit sequence for state Green */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_on_r1_Green(handle);
}

/* Default exit sequence for state GreenYellow */
static void ampel_exseq_main_region_on_r1_GreenYellow(Ampel* handle)
{
	/* Default exit sequence for state GreenYellow */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_on_r1_GreenYellow(handle);
}

/* Default exit sequence for state Red */
static void ampel_exseq_main_region_on_r1_Red(Ampel* handle)
{
	/* Default exit sequence for state Red */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_on_r1_Red(handle);
}

/* Default exit sequence for state RedYellow */
static void ampel_exseq_main_region_on_r1_RedYellow(Ampel* handle)
{
	/* Default exit sequence for state RedYellow */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_on_r1_RedYellow(handle);
}

/* Default exit sequence for state YellowGreen */
static void ampel_exseq_main_region_on_r1_YellowGreen(Ampel* handle)
{
	/* Default exit sequence for state YellowGreen */
	handle->stateConfVector[0] = Ampel_last_state;
	handle->stateConfVectorPosition = 0;
	ampel_exact_main_region_on_r1_YellowGreen(handle);
}

/* Default exit sequence for region main region */
static void ampel_exseq_main_region(Ampel* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of ampel.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Ampel_main_region_off_r1_YellowOn :
		{
			ampel_exseq_main_region_off_r1_YellowOn(handle);
			break;
		}
		case Ampel_main_region_off_r1_YellowOff :
		{
			ampel_exseq_main_region_off_r1_YellowOff(handle);
			break;
		}
		case Ampel_main_region_on_r1_Green :
		{
			ampel_exseq_main_region_on_r1_Green(handle);
			break;
		}
		case Ampel_main_region_on_r1_GreenYellow :
		{
			ampel_exseq_main_region_on_r1_GreenYellow(handle);
			break;
		}
		case Ampel_main_region_on_r1_Red :
		{
			ampel_exseq_main_region_on_r1_Red(handle);
			break;
		}
		case Ampel_main_region_on_r1_RedYellow :
		{
			ampel_exseq_main_region_on_r1_RedYellow(handle);
			break;
		}
		case Ampel_main_region_on_r1_YellowGreen :
		{
			ampel_exseq_main_region_on_r1_YellowGreen(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void ampel_exseq_main_region_off_r1(Ampel* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of ampel.main_region.off.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Ampel_main_region_off_r1_YellowOn :
		{
			ampel_exseq_main_region_off_r1_YellowOn(handle);
			break;
		}
		case Ampel_main_region_off_r1_YellowOff :
		{
			ampel_exseq_main_region_off_r1_YellowOff(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void ampel_exseq_main_region_on_r1(Ampel* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of ampel.main_region.on.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Ampel_main_region_on_r1_Green :
		{
			ampel_exseq_main_region_on_r1_Green(handle);
			break;
		}
		case Ampel_main_region_on_r1_GreenYellow :
		{
			ampel_exseq_main_region_on_r1_GreenYellow(handle);
			break;
		}
		case Ampel_main_region_on_r1_Red :
		{
			ampel_exseq_main_region_on_r1_Red(handle);
			break;
		}
		case Ampel_main_region_on_r1_RedYellow :
		{
			ampel_exseq_main_region_on_r1_RedYellow(handle);
			break;
		}
		case Ampel_main_region_on_r1_YellowGreen :
		{
			ampel_exseq_main_region_on_r1_YellowGreen(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state YellowOn. */
static void ampel_react_main_region_off_r1_YellowOn(Ampel* handle)
{
	/* The reactions of state YellowOn. */
	if (ampel_check_main_region_off_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_off_tr0(handle);
	}  else
	{
		if (ampel_check_main_region_off_r1_YellowOn_tr0_tr0(handle) == bool_true)
		{ 
			ampel_effect_main_region_off_r1_YellowOn_tr0(handle);
		} 
	}
}

/* The reactions of state YellowOff. */
static void ampel_react_main_region_off_r1_YellowOff(Ampel* handle)
{
	/* The reactions of state YellowOff. */
	if (ampel_check_main_region_off_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_off_tr0(handle);
	}  else
	{
		if (ampel_check_main_region_off_r1_YellowOff_tr0_tr0(handle) == bool_true)
		{ 
			ampel_effect_main_region_off_r1_YellowOff_tr0(handle);
		} 
	}
}

/* The reactions of state Green. */
static void ampel_react_main_region_on_r1_Green(Ampel* handle)
{
	/* The reactions of state Green. */
	if (ampel_check_main_region_on_r1_Green_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_on_r1_Green_tr0(handle);
	} 
}

/* The reactions of state GreenYellow. */
static void ampel_react_main_region_on_r1_GreenYellow(Ampel* handle)
{
	/* The reactions of state GreenYellow. */
	if (ampel_check_main_region_on_r1_GreenYellow_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_on_r1_GreenYellow_tr0(handle);
	} 
}

/* The reactions of state Red. */
static void ampel_react_main_region_on_r1_Red(Ampel* handle)
{
	/* The reactions of state Red. */
	if (ampel_check_main_region_on_r1_Red_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_on_r1_Red_tr0(handle);
	} 
}

/* The reactions of state RedYellow. */
static void ampel_react_main_region_on_r1_RedYellow(Ampel* handle)
{
	/* The reactions of state RedYellow. */
	if (ampel_check_main_region_on_r1_RedYellow_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_on_r1_RedYellow_tr0(handle);
	} 
}

/* The reactions of state YellowGreen. */
static void ampel_react_main_region_on_r1_YellowGreen(Ampel* handle)
{
	/* The reactions of state YellowGreen. */
	if (ampel_check_main_region_on_r1_YellowGreen_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_on_r1_YellowGreen_tr0(handle);
	} 
}

/* The reactions of state null. */
static void ampel_react_main_region_on_r1__choice_0(Ampel* handle)
{
	/* The reactions of state null. */
	if (ampel_check_main_region_on_r1__choice_0_tr0_tr0(handle) == bool_true)
	{ 
		ampel_effect_main_region_on_r1__choice_0_tr0(handle);
	}  else
	{
		if (ampel_check_main_region_on_r1__choice_0_tr1_tr1(handle) == bool_true)
		{ 
			ampel_effect_main_region_on_r1__choice_0_tr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void ampel_react_main_region__entry_Default(Ampel* handle)
{
	/* Default react sequence for initial entry  */
	ampel_enseq_main_region_off_default(handle);
}

/* Default react sequence for initial entry  */
static void ampel_react_main_region_off_r1__entry_Default(Ampel* handle)
{
	/* Default react sequence for initial entry  */
	ampel_enseq_main_region_off_r1_YellowOn_default(handle);
}

/* Default react sequence for initial entry  */
static void ampel_react_main_region_on_r1__entry_Default(Ampel* handle)
{
	/* Default react sequence for initial entry  */
	ampel_enseq_main_region_on_r1_Green_default(handle);
}


