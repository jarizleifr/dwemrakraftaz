#include "libtcod.h"
#include "rendering.h"
#include "party.h"
#include "map.h"
#include "engine.h"
#include "gamestate.h"
#include "combat.h"

#include "util.h"

void party_add_character(character_t character) {
	if (party.count < 6) {
		party.characters[party.count] = character;
		party.count++;
	}
}

void party_move(int offset) {
	int position = gamestate.party_offset + offset;

	if (map_flags(position, WALKABLE)) {
		int x, y;
		util_xy_from_offset(&x, &y, position, map.width);
		gamestate.party_offset = position;
	}
	
	// Random encounter
	int encounter = TCOD_random_get_int(NULL, 0, 100);
	if (encounter > 95) {
		party_encounter();
	}
}

static void party_encounter() {
	int tile = map.tiles[gamestate.party_offset];
	
	switch (tile) {
		default:
			map_load(MAP_COMBAT_FOREST);
		break;
	}
	engine_set_state(STATE_COMBAT);
}

void party_draw_roster(int x, int y) {
	int roster_end = y + party.count;
	for (int i = 0; y < roster_end; y++, i++) {
		character_t character = party.characters[i];
		
		// Determine color of the health string
		float percentage = (float)character.health / (float)character.health_max;
		if (percentage < 0.25) {
			TCOD_console_set_default_foreground(NULL, col_red);
		}
		else if (percentage < 0.75) {
			TCOD_console_set_default_foreground(NULL, col_yellow);
		}
		else if (percentage < 1.0) {
			TCOD_console_set_default_foreground(NULL, col_green);
		}
		else {
			TCOD_console_set_default_foreground(NULL, col_white);
		}
		
		// Print health
	
		TCOD_console_printf_ex(NULL, x+14, y, TCOD_BKGND_DEFAULT, TCOD_RIGHT, "%i", character.health);
		TCOD_console_set_default_foreground(NULL, col_white);		// Reset color to white
		
		// Print character name
		TCOD_console_printf(NULL, x, y, "%i>%s", i+1, character.name);
		TCOD_console_put_char(NULL, x+10, y, ':',	TCOD_BKGND_DEFAULT);
		
		// Print status indicator
		TCOD_console_put_char(NULL, x+14, y, 128 + character.status, TCOD_BKGND_DEFAULT);
	}
}