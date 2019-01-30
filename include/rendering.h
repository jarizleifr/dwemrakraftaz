#pragma once

#include "libtcod.h"

#define CONSOLE_WIDTH	40
#define CONSOLE_HEIGHT	25

#define LOCKPICK_ICON   171
#define GOLD_ICON       172
#define FOOD_ICON	    173

#define SPRITES_START 256

enum {
// SPR_A_ Agents
// ============================================================================
	SPR_A_LORD,
	SPR_A_MAGE,
	SPR_A_RANGER,
	SPR_A_ASSASSIN,
	SPR_A_ORC,
	SPR_A_BLACKSMITH,
	
// SPR_I_ Items
// ============================================================================
	SPR_I_SWORD,
	
// SPR_T_ Tiles
// ============================================================================
	SPR_T_GRASS_01,
	SPR_T_GRASS_02,
	SPR_T_GRASS_03,
	SPR_T_GRASS_04,
	SPR_T_GRASS_05,
	SPR_T_GRASS_06,
	SPR_T_GRASS_07,
	SPR_T_TUNDRA,
	SPR_T_SNOW,
	SPR_T_SHRUB,
	SPR_T_FOREST,
	SPR_T_SWAMP,
	SPR_T_SAND,
	SPR_T_DESERT,
	SPR_T_HILLS,
	SPR_T_MOUNTAIN,
	SPR_T_MOUNTAIN_PEAK,
	SPR_T_ROAD_H,
	SPR_T_ROAD_V,
	SPR_T_ROAD_C_01,
	SPR_T_ROAD_C_02,
	SPR_T_ROAD_C_03,
	SPR_T_ROAD_C_04,
	SPR_T_ROAD_I,
	SPR_T_COAST_NW,
	SPR_T_COAST_N,
	SPR_T_COAST_NE,
	SPR_T_COAST_SW,
	SPR_T_COAST_S,
	SPR_T_COAST_SE,
	SPR_T_COAST_W,
	SPR_T_COAST_E,
	
// ============================================================================
	SPR_T_TOWN_01,
	SPR_T_TOWN_02,
	SPR_T_TOWN_03,
	SPR_T_TOWN_04,
	SPR_T_CASTLE,
	SPR_T_TOWER,
	SPR_T_FARM,
	SPR_T_HOUSE,
	SPR_T_RESERVED_01,
	SPR_T_RESERVED_02,
	SPR_T_LADDER_DOWN,
	SPR_T_LADDER_UP,
	SPR_T_STAIRS_01,
	SPR_T_STAIRS_02,
	SPR_T_RESERVED_03,
	SPR_T_BOULDER,
	SPR_T_TREE,
	SPR_T_STONE_WALL,
	SPR_T_STONE_WINDOW,
	SPR_T_STONE_FLOOR,
	SPR_T_WOOD_WALL,
	SPR_T_WOOD_WINDOW,
	SPR_T_WOOD_FLOOR,
	SPR_T_MARBLE_WALL,
	SPR_T_MARBLE_PILLAR,
	SPR_T_MARBLE_FLOOR,
	SPR_T_CAVE_WALL,
	SPR_T_CAVE_PILLAR,
	SPR_T_CAVE_FLOOR,
	SPR_T_RESERVED_04,
	SPR_T_RESERVED_05,
	SPR_T_RESERVED_06,
	
// ============================================================================
	SPR_T_CHAIR_LEFT,
	SPR_T_TABLE,
	SPR_T_CHAIR_RIGHT,
	SPR_T_BAR_STOOL,
	SPR_T_COUNTER,
	SPR_T_CARPET_01,
	SPR_T_CARPET_02,
	SPR_T_BED_01,
	SPR_T_BED_02,
	SPR_T_DRAWERS,
	SPR_T_BOOKCASE,
	SPR_T_RESERVED_07,
	SPR_T_RESERVED_08,
	SPR_T_RESERVED_09,	
	SPR_T_WELL,
	SPR_T_DOOR_01,
	SPR_T_DOOR_02,
	SPR_T_GRAVE,
	SPR_T_SHACKLES,
	SPR_T_BUCKET,
	SPR_T_BARREL,
	SPR_T_RESERVED_10,
	SPR_T_RESERVED_11,
	SPR_T_RESERVED_12,
	SPR_T_RESERVED_13,
	SPR_T_RESERVED_14,
	SPR_T_RESERVED_15,
	SPR_T_SIGN_TEMPLE,
	SPR_T_RESERVED_16,
	SPR_T_RESERVED_17,
	SPR_T_SIGN_WEAPON,
	SPR_T_SIGN_TAVERN,
	
// SPR_AT_ Animated Tiles
// ============================================================================
	SPR_AT_WATER,
	SPR_AT_VOLCANO,
	SPR_AT_FIREPLACE,
	SPR_AT_TORCH,
	SPR_AT_FOUNTAIN,
	
	SPR_AT_RESERVED_18,
	
	SPR_AT_MILL,
	SPR_AT_CAMPFIRE,
	SPR_AT_LAVA,
	
	SPR_AT_RESERVED_19,
	SPR_AT_RESERVED_20,
	SPR_AT_RESERVED_21,
	SPR_AT_RESERVED_22,
	SPR_AT_RESERVED_23,
	SPR_AT_RESERVED_24,
	SPR_AT_RESERVED_25,
	SPR_AT_RESERVED_26,
	SPR_AT_RESERVED_27,
	
// ============================================================================
	GRAPHICS_END
};

const TCOD_color_t col_black;
const TCOD_color_t col_white;
const TCOD_color_t col_red;
const TCOD_color_t col_yellow;
const TCOD_color_t col_green;

int timer;

void console_initialize();
void console_load_font();
void console_time();

void console_draw_main();
void console_clear_sprite(int x, int y);
void console_draw_sprite(int x, int y, int index);
void console_draw_sprite_flicker(int x, int y, int index, TCOD_color_t flicker);

void console_flush();