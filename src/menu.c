#include <stdlib.h>
#include <stdbool.h>

#include "libtcod.h"

#include "rendering.h"
#include "menu.h"

menu_t *menu_new(int size) {
	menu_t *menu = malloc(sizeof*menu);
	menu->menu_items = malloc(size * sizeof(menu_item_t));
	menu->current = 0;
	menu->size = size;
	return menu;
}

bool menu_selector_move(menu_t *menu, int offset) {
	if (menu->current + offset >= 0 && menu->current + offset < menu->size) {
		menu->current += offset;
		return true;
	}
	return false;
}

void menu_select(menu_t *menu) {
	menu->menu_items[menu->current].select();
}

void menu_draw(menu_t *menu, int x, int y, TCOD_bkgnd_flag_t alignment) {
	for (int i = 0; i < menu->size; i++) {
		// If selected, use inverted colors
		if (menu->current == i) {
			TCOD_console_set_default_background(NULL, col_white);
			TCOD_console_set_default_foreground(NULL, col_black);
		}
		else {
			TCOD_console_set_default_background(NULL, col_black);
			TCOD_console_set_default_foreground(NULL, col_white);
		}
		
		TCOD_console_printf_ex(NULL, x, y+i, TCOD_BKGND_SET, alignment, menu->menu_items[i].name);
	}
	// Reset colors to default
	TCOD_console_set_default_background(NULL, col_black);
	TCOD_console_set_default_foreground(NULL, col_white);
}

void menu_free(menu_t *menu) {
	free(menu->menu_items);
	free(menu);
}