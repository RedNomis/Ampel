
#ifndef AMPEL_H_
#define AMPEL_H_

#include "../Src/sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'ampel'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Ampel_main_region_off,
	Ampel_main_region_off_r1_YellowOn,
	Ampel_main_region_off_r1_YellowOff,
	Ampel_main_region_on,
	Ampel_main_region_on_r1_Green,
	Ampel_main_region_on_r1_GreenYellow,
	Ampel_main_region_on_r1_Red,
	Ampel_main_region_on_r1_RedYellow,
	Ampel_main_region_on_r1_YellowGreen,
	Ampel_last_state
} AmpelStates;

/*! Type definition of the data structure for the AmpelIface interface scope. */
typedef struct
{
	sc_integer push;
	sc_boolean evPushButton_raised;
	sc_boolean dummy_raised;
} AmpelIface;

/*! Type definition of the data structure for the AmpelTimeEvents interface scope. */
typedef struct
{
	sc_boolean ampel_main_region_off_r1_YellowOn_tev0_raised;
	sc_boolean ampel_main_region_off_r1_YellowOff_tev0_raised;
	sc_boolean ampel_main_region_on_r1_Green_tev0_raised;
	sc_boolean ampel_main_region_on_r1_GreenYellow_tev0_raised;
	sc_boolean ampel_main_region_on_r1_Red_tev0_raised;
	sc_boolean ampel_main_region_on_r1_RedYellow_tev0_raised;
	sc_boolean ampel_main_region_on_r1_YellowGreen_tev0_raised;
} AmpelTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define AMPEL_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the Ampel state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	AmpelStates stateConfVector[AMPEL_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	AmpelIface iface;
	AmpelTimeEvents timeEvents;
} Ampel;

/*! Initializes the Ampel state machine data structures. Must be called before first usage.*/
extern void ampel_init(Ampel* handle);

/*! Activates the state machine */
extern void ampel_enter(Ampel* handle);

/*! Deactivates the state machine */
extern void ampel_exit(Ampel* handle);

/*! Performs a 'run to completion' step. */
extern void ampel_runCycle(Ampel* handle);

/*! Raises a time event. */
extern void ampel_raiseTimeEvent(const Ampel* handle, sc_eventid evid);

/*! Gets the value of the variable 'push' that is defined in the default interface scope. */ 
extern sc_integer ampelIface_get_push(const Ampel* handle);
/*! Sets the value of the variable 'push' that is defined in the default interface scope. */ 
extern void ampelIface_set_push(Ampel* handle, sc_integer value);
/*! Raises the in event 'evPushButton' that is defined in the default interface scope. */ 
extern void ampelIface_raise_evPushButton(Ampel* handle);

/*! Raises the in event 'dummy' that is defined in the default interface scope. */ 
extern void ampelIface_raise_dummy(Ampel* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean ampel_isActive(const Ampel* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean ampel_isFinal(const Ampel* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean ampel_isStateActive(const Ampel* handle, AmpelStates state);

#ifdef __cplusplus
}
#endif 

#endif /* AMPEL_H_ */
