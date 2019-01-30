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

static const int archetype_stats[9][6] = {
	{ 11, 10, 10,  9, 10, 10 },
	{ 10, 11,  9, 10, 11,  9 },
	{  9, 10,  9, 11, 11, 10 },
	{ 10, 10, 10, 10, 10, 10 },
	{ 10, 10, 10, 10, 10, 10 },
	{ 10, 10, 10, 10, 10, 10 },
	{ 10, 10, 10, 10, 10, 10 },
	{ 10, 10, 10, 10, 10, 10 },
	{ 10, 10, 10, 10, 10, 10 },
};

static menu_t *archetypemenu;
static character_t player_character;
static int statistics[6];
static int icon;

// ============================================================================
// Menu selection functions
// ============================================================================

static void start() {
	menu_free(archetypemenu);
	party_add_character((character_t){ "Jaroslav", 	icon, 100, 100, 20, 15, STATUS_OK } );
	gamestate_initialize();
	engine_set_state(STATE_GAME);
}

// ============================================================================
// Chargen functions
// ============================================================================

static void reroll() {
	TCOD_console_clear(NULL);
	int c = archetypemenu->current;
	for (int i = 0; i < 6; i++) {
		int roll = 	TCOD_random_get_int(NULL, -2, 2);
		statistics[i] = archetype_stats[c][i] + roll;
	}
}

static void chargen_change_icon(int offset) {
	if (icon + offset >= 0 && icon + offset < 6)
		icon += offset;
}

static void chargen_draw_stats(int x, int y) {
	TCOD_console_printf_ex(NULL, x, y,   TCOD_BKGND_DEFAULT, TCOD_LEFT, "STR:%i", statistics[0]);
	TCOD_console_printf_ex(NULL, x, y+1, TCOD_BKGND_DEFAULT, TCOD_LEFT, "END:%i", statistics[1]);
	TCOD_console_printf_ex(NULL, x, y+2, TCOD_BKGND_DEFAULT, TCOD_LEFT, "FIN:%i", statistics[2]);
	TCOD_console_printf_ex(NULL, x, y+3, TCOD_BKGND_DEFAULT, TCOD_LEFT, "INT:%i", statistics[3]);
	TCOD_console_printf_ex(NULL, x, y+4, TCOD_BKGND_DEFAULT, TCOD_LEFT, "RES:%i", statistics[4]);
	TCOD_console_printf_ex(NULL, x, y+5, TCOD_BKGND_DEFAULT, TCOD_LEFT, "AWA:%i", statistics[5]);
	/*
	TCOD_console_printf_ex(NULL, x+8, y,   TCOD_BKGND_DEFAULT, TCOD_LEFT, "Sword      :%i", 25);
	TCOD_console_printf_ex(NULL, x+8, y+1, TCOD_BKGND_DEFAULT, TCOD_LEFT, "Stealth    :%i", 10);
	TCOD_console_printf_ex(NULL, x+8, y+2, TCOD_BKGND_DEFAULT, TCOD_LEFT, "Disguise   :%i", 8);
	TCOD_console_printf_ex(NULL, x+8, y+3, TCOD_BKGND_DEFAULT, TCOD_LEFT, "Lockpicking:%i", 20);
	TCOD_console_printf_ex(NULL, x+8, y+4, TCOD_BKGND_DEFAULT, TCOD_LEFT, "Leadership :%i", 33);
	TCOD_console_printf_ex(NULL, x+8, y+5, TCOD_BKGND_DEFAULT, TCOD_LEFT, "Thaumaturgy:%i", 10);
	*/
}

// ============================================================================
// Chargen State
// ============================================================================

void chargen_init() {
	icon = SPR_A_LORD;
	int archetypes = 9;
	// Create archetypemenu and set menu items
	archetypemenu = menu_new(archetypes);
	
	for (int i = 0; i < archetypes; i++) {
		archetypemenu->menu_items[i] = (menu_item_t){ strings[STR_ARCHETYPE_01+i], start };
	}
	reroll();
}

void chargen_run(int command) {
	switch (command) {
	case CMD_BACK:
		menu_free(archetypemenu);
		engine_set_state(STATE_MAINMENU);		
	break;
	case CMD_ACCEPT:
		menu_select(archetypemenu);
	break;

	case CMD_ACTION:
		reroll();
	break;
	
	case CMD_MOVE_NORTH:
		if (menu_selector_move(archetypemenu, -1)) {
			reroll();
		}
	break;
	case CMD_MOVE_SOUTH:
		if (menu_selector_move(archetypemenu, 1)) {
			reroll();
		}
	break;
	
	case CMD_MOVE_WEST:
		chargen_change_icon(-1);
	break;
	case CMD_MOVE_EAST:
		chargen_change_icon(1);
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
	
	menu_draw(archetypemenu, 2, 5, TCOD_LEFT);
	chargen_draw_stats(12, 8);
	
	TCOD_console_printf_rect(NULL, 2, 16, CONSOLE_WIDTH-4, 11, strings[STR_ARCHETYPE_01_DESC + archetypemenu->current]);
	
	console_draw_sprite(12, 5, icon);
	
	TCOD_console_printf(NULL, 1, CONSOLE_HEIGHT-2, "%c%c: Select  %c%c: Icon  Spacebar: Reroll", 24, 25, 27, 26);
}