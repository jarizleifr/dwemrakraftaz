// C library
#include <stdio.h>
#include <string.h>

// Library includes
#include "ini.h"
#include "libtcod.h"

// Header
#include "rendering.h"

// Other dependencies
#include "map.h"
#include "util.h"
#include "gamestate.h"

const TCOD_color_t col_black =  { 20,   12,  28 };
const TCOD_color_t col_white =  { 222, 238, 214 };
const TCOD_color_t col_red =    { 208,  70,  72 };
const TCOD_color_t col_yellow = { 218, 212,  94 };
const TCOD_color_t col_green =  { 109, 170,  44 };

struct {
	int index, frames;
} graphics[GRAPHICS_END] = {
	{ 0,   4 },	// SPR_A_LORD
	{ 4,   4 },	// SPR_A_MAGE
	{ 8,   1 },	// SPR_A_RANGER
	{ 12,  1 },	// SPR_A_ASSASSIN
	{ 32,  1 },	// SPR_A_ORC
	{ 64,  1 },	// SPR_A_BLACKSMITH
				
	{ 288, 1 },	// SPR_I_SWORD
				
	{ 320, 1 },	// SPR_T_GRASS_01
	{ 321, 1 },	// SPR_T_GRASS_02,
	{ 322, 1 },	// SPR_T_GRASS_03,
	{ 323, 1 },	// SPR_T_GRASS_04,
	{ 324, 1 },	// SPR_T_GRASS_05,
	{ 325, 1 },	// SPR_T_GRASS_06,
	{ 326, 1 },	// SPR_T_GRASS_07,
	{ 327, 1 },	// SPR_T_TUNDRA,
	{ 328, 1 },	// SPR_T_SNOW,
	{ 329, 1 },	// SPR_T_SHRUB,
	{ 330, 1 },	// SPR_T_FOREST,
	{ 331, 1 },	// SPR_T_SWAMP,
	{ 332, 1 },	// SPR_T_SAND,
	{ 333, 1 },	// SPR_T_DESERT,
	{ 334, 1 },	// SPR_T_HILLS,
	{ 335, 1 },	// SPR_T_MOUNTAIN,
	{ 336, 1 },	// SPR_T_MOUNTAIN_PEAK,
	{ 337, 1 },	// SPR_T_ROAD_H,
	{ 338, 1 },	// SPR_T_ROAD_V,
	{ 339, 1 },	// SPR_T_ROAD_C_01,
	{ 340, 1 },	// SPR_T_ROAD_C_02,
	{ 341, 1 },	// SPR_T_ROAD_C_03,
	{ 342, 1 },	// SPR_T_ROAD_C_04,
	{ 343, 1 },	// SPR_T_ROAD_I,
	{ 344, 1 },	// SPR_T_COAST_NW,
	{ 345, 1 },	// SPR_T_COAST_N,
	{ 346, 1 },	// SPR_T_COAST_NE,
	{ 347, 1 },	// SPR_T_COAST_SW,
	{ 348, 1 },	// SPR_T_COAST_S,
	{ 349, 1 },	// SPR_T_COAST_SE,
	{ 350, 1 },	// SPR_T_COAST_W,
	{ 351, 1 },	// SPR_T_COAST_E,
	
	{ 352, 1 },	// SPR_T_TOWN_01,
	{ 353, 1 },	// SPR_T_TOWN_02,
	{ 354, 1 },	// SPR_T_TOWN_03,
	{ 355, 1 },	// SPR_T_TOWN_04,
	{ 356, 1 },	// SPR_T_CASTLE,
	{ 357, 1 },	// SPR_T_TOWER,
	{ 358, 1 },	// SPR_T_FARM,
	{ 359, 1 },	// SPR_T_HOUSE,
		{ 360, 1 }, // RESERVED	
		{ 361, 1 }, // RESERVED	
	{ 362, 1 },	// SPR_T_LADDER_DOWN,
	{ 363, 1 },	// SPR_T_LADDER_UP,
	{ 364, 1 },	// SPR_T_STAIRS_01,
	{ 365, 1 },	// SPR_T_STAIRS_02,
		{ 366, 1 }, // RESERVED
	{ 367, 1 },	// SPR_T_BOULDER,
	{ 368, 1 },	// SPR_T_TREE,	
	{ 369, 1 },	// SPR_T_STONE_WALL,
	{ 370, 1 },	// SPR_T_STONE_WINDOW,
	{ 371, 1 },	// SPR_T_STONE_FLOOR,
	{ 372, 1 },	// SPR_T_WOOD_WALL,
	{ 373, 1 },	// SPR_T_WOOD_WINDOW,
	{ 374, 1 },	// SPR_T_WOOD_FLOOR,	
	{ 375, 1 },	// SPR_T_MARBLE_WALL,
	{ 376, 1 },	// SPR_T_MARBLE_PILLAR,
	{ 377, 1 },	// SPR_T_MARBLE_FLOOR,
	{ 378, 1 },	// SPR_T_CAVE_WALL,
	{ 379, 1 },	// SPR_T_CAVE_PILLAR,
	{ 380, 1 },	// SPR_T_CAVE_FLOOR,
		{ 381, 1 },	// RESERVED
		{ 382, 1 },	// RESERVED
		{ 383, 1 },	// RESERVED
		
	{ 384, 1 },	// SPR_T_CHAIR_LEFT,
	{ 385, 1 },	// SPR_T_TABLE,
	{ 386, 1 },	// SPR_T_CHAIR_RIGHT,
	{ 387, 1 },	// SPR_T_BAR_STOOL,
	{ 388, 1 },	// SPR_T_COUNTER,
	{ 389, 1 },	// SPR_T_CARPET_01,
	{ 390, 1 },	// SPR_T_CARPET_02,
	{ 391, 1 },	// SPR_T_BED_01,
	{ 392, 1 },	// SPR_T_BED_02,
	{ 393, 1 },	// SPR_T_DRAWERS,
	{ 394, 1 },	// SPR_T_BOOKCASE,
		{ 395, 1 },	// RESERVED
		{ 396, 1 },	// RESERVED
		{ 397, 1 },	// RESERVED
	{ 398, 1 },	// SPR_T_WELL,
	{ 399, 1 },	// SPR_T_DOOR_01,
	{ 400, 1 },	// SPR_T_DOOR_02,
	{ 401, 1 },	// SPR_T_GRAVE,
	{ 402, 1 },	// SPR_T_SHACKLES,
	{ 403, 1 },	// SPR_T_BUCKET,
	{ 404, 1 },	// SPR_T_BARREL,
		{ 405, 1 },	// RESERVED
		{ 406, 1 },	// RESERVED
		{ 407, 1 },	// RESERVED
		{ 408, 1 },	// RESERVED
		{ 409, 1 },	// RESERVED
		{ 410, 1 },	// RESERVED
	{ 411, 1 },	// SPR_T_SIGN_TEMPLE
	{ 412, 1 },	// SPR_T_SIGN_,
	{ 413, 1 },	// SPR_T_SIGN_,
	{ 414, 1 },	// SPR_T_SIGN_WEAPON,
	{ 415, 1 },	// SPR_T_SIGN_TAVERN,
		
	{ 416, 2 },	// SPR_AT_WATER,
	{ 418, 2 },	// SPR_AT_VOLCANO,
	{ 420, 2 },	// SPR_AT_FIREPLACE,
	{ 422, 2 },	// SPR_AT_TORCH,
	{ 424, 2 },	// SPR_AT_FOUNTAIN,
		{ 426, 2 },	// RESERVED
	{ 428, 2 },	// SPR_AT_MILL,
	{ 430, 2 },	// SPR_AT_CAMPFIRE,
		{ 432, 2 },	// RESERVED
		{ 434, 2 },	// RESERVED
		{ 436, 2 },	// RESERVED
		{ 438, 2 },	// RESERVED
		{ 440, 2 },	// RESERVED
		{ 442, 2 },	// RESERVED
		{ 444, 2 },	// RESERVED
		{ 446, 2 },	// RESERVED
		{ 448, 2 }  // RESERVED
};

void console_initialize() {
	// Load configuration file
	ini_t *config = ini_load("config.ini");
	const char *font = ini_get(config, "Setup", "font");
	if (!font)
		font = "fonts/font1x.png";

	// Initialize TCOD console and hide cursor
	TCOD_console_set_custom_font(font, TCOD_FONT_LAYOUT_ASCII_INROW | TCOD_FONT_TYPE_GREYSCALE, 64, 32);
	TCOD_console_init_root(CONSOLE_WIDTH, CONSOLE_HEIGHT, "Dwemrakraftaz", false, TCOD_RENDERER_SDL);
	console_load_font();

	TCOD_sys_set_fps(60);
	TCOD_mouse_show_cursor(false);

	TCOD_console_set_default_background(NULL, col_black);
	TCOD_console_rect(NULL, 0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT, true, TCOD_BKGND_SET);
	
	TCOD_console_set_default_foreground(NULL, col_white);
	
	timer = 0;
	
	// Free config file from memory
	ini_free(config);
}

// Map sprites to game
void console_load_font() {
	int a = 256;

	for (int row = 64; row < 32; row++) {
		TCOD_console_map_ascii_codes_to_font(a, 64, 0, row);
		a += 64;
	}
}

// Draw default frames that are used by multiple states
void console_draw_main() {
	int s = CONSOLE_WIDTH-16;
	
	// Set foreground to unadultered white for frame drawing
	TCOD_console_set_default_foreground(NULL, TCOD_white);
	
	TCOD_console_printf_frame(NULL, 0,   0, s,  CONSOLE_HEIGHT, false, TCOD_BKGND_DEFAULT, NULL);	// Draw map border
	TCOD_console_printf_frame(NULL, s-1, 0, 17, 8, false, TCOD_BKGND_DEFAULT, NULL);				// Draw roster border
	TCOD_console_printf_frame(NULL, s-1, 7, 17, CONSOLE_HEIGHT-7, false, TCOD_BKGND_DEFAULT, NULL);	// Draw data border
	
	//TCOD_console_printf_frame(NULL, s-1, 7, 17, 3, false, TCOD_BKGND_DEFAULT, NULL);	// Draw resources border
	//TCOD_console_printf_frame(NULL, s-1, 9, 17, 4, false, TCOD_BKGND_DEFAULT, NULL);	// Draw time border
	
	// Draw three-way frame connectors
	TCOD_console_set_char(NULL, s-1, 		     0,  	   		     194);
	TCOD_console_set_char(NULL, s-1, 		     CONSOLE_HEIGHT-1, 	 193);
	TCOD_console_set_char(NULL, s-1, 		     7, 				 195);
	TCOD_console_set_char(NULL, CONSOLE_WIDTH-1, 7, 				 180);
	
	// Reset color to custom white
	TCOD_console_set_default_foreground(NULL, col_white);
	
	// Draw current map name
	TCOD_console_printf_ex(NULL, 12, CONSOLE_HEIGHT-2, TCOD_BKGND_DEFAULT, TCOD_CENTER, "%s", map.name);

	// Draw map name border blocks
	TCOD_console_put_char(NULL, 1, CONSOLE_HEIGHT-2, TCOD_CHAR_BLOCK3, TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, s-2, CONSOLE_HEIGHT-2, TCOD_CHAR_BLOCK3, TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, 2, CONSOLE_HEIGHT-2, TCOD_CHAR_BLOCK2, TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, s-3, CONSOLE_HEIGHT-2, TCOD_CHAR_BLOCK2, TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, 3, CONSOLE_HEIGHT-2, TCOD_CHAR_BLOCK1, TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, s-4, CONSOLE_HEIGHT-2, TCOD_CHAR_BLOCK1, TCOD_BKGND_DEFAULT);

	TCOD_console_put_char(NULL, s, 8, FOOD_ICON, TCOD_BKGND_DEFAULT);
	TCOD_console_printf(NULL, s+1, 8, "%i", 999);
	TCOD_console_put_char(NULL, s+5, 8, LOCKPICK_ICON, TCOD_BKGND_DEFAULT);
	TCOD_console_printf(NULL, s+6, 8, "%i", 99);
	TCOD_console_put_char(NULL, s+9, 8, GOLD_ICON, TCOD_BKGND_DEFAULT);
	
	TCOD_console_printf(NULL, s+10, 8, "%i", 99999);
	TCOD_console_printf(NULL, s, 10, "Mandaugas 28th");
	TCOD_console_printf(NULL, s, 11, "Harvestmoon 569");
}

void console_time() {
	timer++;
	if (timer >= 240) {
		timer = 0;
	}
}

void console_clear_sprite(int x, int y) {
	TCOD_console_put_char(NULL, x,   y,   32,	TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, x+1, y,   32,	TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, x,   y+1, 32,	TCOD_BKGND_DEFAULT);
	TCOD_console_put_char(NULL, x+1, y+1, 32,	TCOD_BKGND_DEFAULT);
}

void console_draw_sprite(int x, int y, int g) {
	int offset = (graphics[g].index / 32) * 64;
	int i = SPRITES_START + offset + graphics[g].index * 2;
	
	if (graphics[g].frames == 4) {
		int f = timer / 60;
		i += f*2;
	}
	else if (graphics[g].frames == 2) {
		int f = timer / 60;
		i += (f % 2) * 2;
	}
	// Draw sprites with unadultered white
	TCOD_console_set_default_foreground(NULL, TCOD_white);
	TCOD_console_put_char(NULL, x,   y,   i,	TCOD_BKGND_SET);
	TCOD_console_put_char(NULL, x+1, y,   i+1,	TCOD_BKGND_SET);
	TCOD_console_put_char(NULL, x,   y+1, i+64,	TCOD_BKGND_SET);
	TCOD_console_put_char(NULL, x+1, y+1, i+65,	TCOD_BKGND_SET);
	
	TCOD_console_set_default_foreground(NULL, col_white);
}

void console_draw_sprite_animated(int x, int y, int index, unsigned char *frame) {

}

void console_draw_sprite_flicker(int x, int y, int index, TCOD_color_t bg) {
	int f = timer / 20;
	if (f % 2 != 0) {
		TCOD_console_set_default_background(NULL, bg);
	}
	else {
		TCOD_console_set_default_background(NULL, col_black);		
	}
	console_draw_sprite(x, y, index);
	TCOD_console_rect(NULL, x, y, 2, 2, false, TCOD_BKGND_SET);
	TCOD_console_set_default_background(NULL, col_black);
}

void console_flush() {
	TCOD_console_flush();
}