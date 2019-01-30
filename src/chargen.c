#include "libtcod.h"
#include "strdef.h"

#include "chargen.h"

#include "menu.h"

#include "engine.h"
#include "rendering.h"
#include "input.h"
#include "gamestate.h"

#include "party.h"

// ============================================================================
// Local
// ============================================================================

menu_t *racemenu;
character_t player_character;

// ============================================================================
// Menu selection functions
// ============================================================================

static void start() {
	menu_free(racemenu);
	gamestate_initialize();
	engine_set_state(STATE_GAME);
}

// ============================================================================
// Chargen functions
// ============================================================================

static void chargen_draw_stats() {
	TCOD_console_printf_ex(NULL, 12, 5, TCOD_BKGND_DEFAULT, TCOD_LEFT, 	"Strength  : 10");
	TCOD_console_printf_ex(NULL, 12, 6, TCOD_BKGND_DEFAULT, TCOD_LEFT, 	"Endurance : 10");
	TCOD_console_printf_ex(NULL, 12, 7, TCOD_BKGND_DEFAULT, TCOD_LEFT, 	"Finesse   : 10");
	TCOD_console_printf_ex(NULL, 12, 8, TCOD_BKGND_DEFAULT, TCOD_LEFT, 	"Intellect : 10");
	TCOD_console_printf_ex(NULL, 12, 9, TCOD_BKGND_DEFAULT, TCOD_LEFT, 	"Resolve   : 10");
	TCOD_console_printf_ex(NULL, 12, 10, TCOD_BKGND_DEFAULT, TCOD_LEFT, "Awareness : 10");
}

// ============================================================================
// Chargen State
// ============================================================================

void chargen_init() {
	// Create racemenu and set menu items
	racemenu = menu_new(7);
	racemenu->menu_items[0] = (menu_item_t){ strings[STR_RACE_01],	start };
	racemenu->menu_items[1] = (menu_item_t){ strings[STR_RACE_02], 	start };
	racemenu->menu_items[2] = (menu_item_t){ strings[STR_RACE_03],  start };
	racemenu->menu_items[3] = (menu_item_t){ strings[STR_RACE_04],	start };
	racemenu->menu_items[4] = (menu_item_t){ strings[STR_RACE_05],	start };
	racemenu->menu_items[5] = (menu_item_t){ strings[STR_RACE_06], 	start };
	racemenu->menu_items[6] = (menu_item_t){ strings[STR_RACE_07], 	start };
}

void chargen_run(int command) {
	switch (command) {
	case CMD_BACK:
		menu_free(racemenu);
		engine_set_state(STATE_MAINMENU);		
	break;
	case CMD_ACCEPT:
		menu_select(racemenu);
	break;
	
	case CMD_MOVE_NORTH:
		TCOD_console_clear(NULL);
		menu_selector_move(racemenu, -1);
	break;
	case CMD_MOVE_SOUTH:
		TCOD_console_clear(NULL);
		menu_selector_move(racemenu, 1);
	break;
	default:
	break;
	}
}

void chargen_draw() {
	TCOD_console_set_default_foreground(NULL, TCOD_white);
	TCOD_console_printf_frame(NULL, 0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT, false, TCOD_BKGND_DEFAULT, NULL);
	
	TCOD_console_set_default_foreground(NULL, col_white);
	TCOD_console_printf_ex(NULL, 20, 2, TCOD_BKGND_DEFAULT, TCOD_CENTER, "Character Creation");
	
	menu_draw(racemenu, 2, 5, TCOD_LEFT);
	chargen_draw_stats();
	
	TCOD_console_printf_rect(NULL, 2, 13, CONSOLE_WIDTH-4, 11, strings[STR_RACE_01_DESC + racemenu->current]);
}