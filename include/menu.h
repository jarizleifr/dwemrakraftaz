#pragma once

#include "libtcod.h"

typedef struct {
	const char *name;
	void(*select)();
} menu_item_t;

typedef struct {
	int size, current;
	menu_item_t *menu_items;
} menu_t;

menu_t *menu_new(int size);

void menu_selector_move(menu_t *menu, int offset);
void menu_select(menu_t *menu);

void menu_draw(menu_t *menu, int x, int y, TCOD_bkgnd_flag_t alignment);
void menu_free(menu_t *menu);