#include <stdio.h>

#include "engine.h"
#include "rendering.h"
#include "input.h"
#include "map.h"

// Program state includes
#include "mainmenu.h"
#include "chargen.h"
#include "game.h"
#include "combat.h"

// ============================================================================
// Local
// ============================================================================

// Engine states
struct {
	void(*init)();			 // Run whenever state gets set
	void(*run)(int command); // Runs every frame, handles logic, accepts input as argument
	void(*draw)();			 // Runs every frame, handles rendering
} states[ENGINE_STATES_END] = {
//	  Init				Run				Draw
	{ mainmenu_init,	mainmenu_run,	mainmenu_draw },
	{ chargen_init,		chargen_run,	chargen_draw },
	{ game_init, 	 	game_run,   	game_draw },
	{ combat_init,	 	combat_run, 	combat_draw }
};

bool running = true;  // Engine status, program ends if false
int engine_state = 0; // Current engine state

// ============================================================================
// Game Engine / State machine
// ============================================================================

// Set engine state
void engine_set_state(int state)
{
	if (state >= 0 || state < ENGINE_STATES_END) {
		TCOD_console_clear(NULL);
		engine_state = state;
		states[engine_state].init();
	}
	else {
		printf("Error! Invalid engine state.");
		engine_terminate();
	}
}

void engine_terminate() {
	printf("Terminating program.");
	map_clear();		// Clear memory for maps
	running = false;	// Finally set program loop to terminate
}

// Main program loop
int main() {
	engine_set_state(STATE_MAINMENU);
	console_initialize();
	
	while (running) {
		int old_state = engine_state;
		states[engine_state].run(input_process());
		
		// If state changed, start loop from beginning
		if (old_state != engine_state) continue;
		
		// If engine was set to terminate in run function, break from loop
		if (running == false) break;
		
		// Otherwise handle rendering and time normally
		states[engine_state].draw();
		console_time();
		console_flush();
	}
	
	// If the main loop exited, end program
	return 0;
}