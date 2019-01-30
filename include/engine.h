#pragma once

#include "libtcod.h"

enum {
	STATE_MAINMENU,
	STATE_CHARGEN,
	STATE_GAME,
	STATE_COMBAT,
	ENGINE_STATES_END
};

void engine_set_state(int state);
void engine_terminate();