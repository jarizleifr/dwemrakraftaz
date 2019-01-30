#include <stdio.h>

#include "libtcod.h"

#include "mainmenu.h"

#include "menu.h"

// System headers
#include "engine.h"
#include "input.h"
#include "rendering.h"

// ============================================================================
// Local
// ============================================================================

menu_t *mainmenu;

// ============================================================================
// Menu selection functions
// ============================================================================

// Start a new game
static void newgame() {
	menu_free(mainmenu);
	engine_set_state(STATE_CHARGEN);
}

// Load game
static void loadgame() {
	
}

// Exit game
static void exitgame() {
	engine_terminate();
}

// ============================================================================
// Mainmenu State
// ============================================================================

void mainmenu_init() {
	// Create the main menu and set menu items
	mainmenu = menu_new(3);
	mainmenu->menu_items[0] = (menu_item_t){ "Forge a New Legend", 			   newgame  };
	mainmenu->menu_items[1] = (menu_item_t){ "Continue a Previous Saga", 	   loadgame };
	mainmenu->menu_items[2] = (menu_item_t){ "Leave and Forfeit Your Destiny", exitgame };
}

void mainmenu_run(int command) {
	switch (command) {
	case CMD_BACK:
		engine_terminate();
	break;
	case CMD_ACCEPT:
		menu_select(mainmenu);
	break;
	
	case CMD_MOVE_NORTH:
		menu_selector_move(mainmenu, -1);
	break;
	case CMD_MOVE_SOUTH:
		menu_selector_move(mainmenu, 1);
	break;
	default:
	break;
	}
}

void mainmenu_draw() {
	TCOD_console_set_default_foreground(NULL, TCOD_white);
	TCOD_console_printf_frame(NULL, 0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT, false, TCOD_BKGND_DEFAULT, NULL);
	
	TCOD_console_set_default_foreground(NULL, col_white);
	TCOD_console_printf_ex(NULL, 20, 2, TCOD_BKGND_DEFAULT, TCOD_CENTER, "DWEMRAKRAFTAZ");
	TCOD_console_printf_ex(NULL, 20, 3, TCOD_BKGND_DEFAULT, TCOD_CENTER, "Champions of Wychmist");

	menu_draw(mainmenu, 20, 12, TCOD_CENTER);
	
	// Draw copyright notice
	TCOD_console_printf_ex(NULL, 20, CONSOLE_HEIGHT-2, TCOD_BKGND_DEFAULT, TCOD_CENTER, "  2018 Antti Joutsi");
	TCOD_console_put_char(NULL, 11, CONSOLE_HEIGHT-2, 184, TCOD_BKGND_DEFAULT);	
}
