#pragma once

// ============================================================================
// Map datatypes
// ============================================================================

typedef struct {
	const char *name;
	const char *filename;
} map_info_t;

typedef struct {
	const char *name;
	int width;
	int height;
	unsigned char *tiles;
} map_t;

typedef struct {
	unsigned char graphic;
	int flags;
} tile_t;

// Tiles
enum {
	
// 1st row
// ============================================================================
	TILE_GRASS_01,
	TILE_GRASS_02,
	TILE_GRASS_03,
	TILE_GRASS_04,
	TILE_GRASS_05,
	TILE_GRASS_06,
	TILE_GRASS_07,
	TILE_TUNDRA,
	TILE_SNOW,
	TILE_SHRUB,
	TILE_FOREST,
	TILE_SWAMP,
	TILE_SAND,
	TILE_DESERT,
	TILE_HILLS,
	TILE_MOUNTAIN,
	TILE_MOUNTAIN_PEAK,
	TILE_ROAD_H,
	TILE_ROAD_V,
	TILE_ROAD_C_01,
	TILE_ROAD_C_02,
	TILE_ROAD_C_03,
	TILE_ROAD_C_04,
	TILE_ROAD_I,
	TILE_COAST_NW,
	TILE_COAST_N,
	TILE_COAST_NE,
	TILE_COAST_SW,
	TILE_COAST_S,
	TILE_COAST_SE,
	TILE_COAST_W,
	TILE_COAST_E,

// 2nd row
// ============================================================================
	TILE_TOWN_01,
	TILE_TOWN_02,
	TILE_TOWN_03,
	TILE_TOWN_04,
	TILE_CASTLE,
	TILE_TOWER,
	TILE_FARM,
	TILE_HOUSE,
	TILE_RESERVED_01,
	TILE_RESERVED_02,
	TILE_LADDER_DOWN,
	TILE_LADDER_UP,
	TILE_STAIRS_01,
	TILE_STAIRS_02,
	TILE_RESERVED_03,
	TILE_BOULDER,
	TILE_TREE,
	TILE_STONE_WALL,
	TILE_STONE_WINDOW,
	TILE_STONE_FLOOR,
	TILE_WOOD_WALL,
	TILE_WOOD_WINDOW,
	TILE_WOOD_FLOOR,
	TILE_MARBLE_WALL,
	TILE_MARBLE_PILLAR,
	TILE_MARBLE_FLOOR,
	TILE_CAVE_WALL,
	TILE_CAVE_PILLAR,
	TILE_CAVE_FLOOR,
	TILE_RESERVED_04,
	TILE_RESERVED_05,
	TILE_RESERVED_06,

// 3rd row
// ============================================================================
	TILE_CHAIR_LEFT,
	TILE_TABLE,
	TILE_CHAIR_RIGHT,
	TILE_BAR_STOOL,
	TILE_COUNTER,
	TILE_CARPET_01,
	TILE_CARPET_02,
	TILE_BED_01,
	TILE_BED_02,
	TILE_DRAWERS,
	TILE_BOOKCASE,
	TILE_RESERVED_07,
	TILE_RESERVED_08,
	TILE_RESERVED_09,	
	TILE_WELL,
	TILE_DOOR_01,
	TILE_DOOR_02,
	TILE_GRAVE,
	TILE_SHACKLES,
	TILE_BUCKET,
	TILE_BARREL,
	TILE_RESERVED_10,
	TILE_RESERVED_11,
	TILE_RESERVED_12,
	TILE_RESERVED_13,
	TILE_RESERVED_14,
	TILE_RESERVED_15,
	TILE_SIGN_TEMPLE,
	TILE_RESERVED_16,
	TILE_RESERVED_17,
	TILE_SIGN_WEAPON,
	TILE_SIGN_TAVERN,

// 4th row, animated tiles
// ============================================================================
	TILE_WATER,
	TILE_VOLCANO,
	TILE_FIREPLACE,
	TILE_TORCH,
	TILE_FOUNTAIN,
	TILE_RESERVED_18,
	TILE_MILL,
	TILE_CAMPFIRE,
	TILE_LAVA,
	TILE_RESERVED_19,
	TILE_RESERVED_20,
	TILE_RESERVED_21,
	TILE_RESERVED_22,
	TILE_RESERVED_23,
	TILE_RESERVED_24,
	TILE_RESERVED_25,
	TILE_RESERVED_26,
	TILE_RESERVED_27,
// ============================================================================
	TILES_END
};

// Tile flags
enum {
	WALKABLE    = 1,
	TRANSPARENT = 2,
	RESERVED_2  = 4,
	RESERVED_3  = 8,
	RESERVED_4  = 16,
	RESERVED_5  = 32,
	RESERVED_6  = 64,
	RESERVED_7  = 128,
};

// Maps
enum {
	MAP_WORLD,
	MAP_COMBAT_FOREST,
	MAPS_END,
};

// Global for the map
map_t map;

extern map_info_t map_info[];

// Function declarations
extern void map_load();
extern int map_flags(int offset, int flags);
extern void map_clear();
extern void map_draw_map(int offset);
extern void map_draw_tile(int x, int y, unsigned char index);