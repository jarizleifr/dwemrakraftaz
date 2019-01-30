// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Header
#include "map.h"
// Other dependencies
#include "rendering.h"
#include "util.h"

map_info_t map_info[MAPS_END] = {
	{ "Worldmap", 	"world.map"	 	    },
	{ "Forest", 	"combat_forest.map" }
};

// Map Tile data lookup
tile_t tiles[TILES_END] = {
	
// 1st row
// ============================================================================
//	  Graphic		  		Flags
	{ SPR_T_GRASS_01, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRASS_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRASS_03, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRASS_04, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRASS_05, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRASS_06, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRASS_07, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_TUNDRA, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_SNOW, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_SHRUB, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_FOREST, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_SWAMP, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_SAND, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_DESERT, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_HILLS, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_MOUNTAIN, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_MOUNTAIN_PEAK, 	0 						},
	{ SPR_T_ROAD_H, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_ROAD_V, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_ROAD_C_01, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_ROAD_C_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_ROAD_C_03, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_ROAD_C_04, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_ROAD_I, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_NW, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_N, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_NE, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_SW, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_S, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_SE, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_W, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COAST_E, 		WALKABLE | TRANSPARENT 	},
	
// 2nd row
// ============================================================================
//	  Graphic		  		Flags
	{ SPR_T_TOWN_01, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_TOWN_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_TOWN_03, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_TOWN_04, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_CASTLE, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_TOWER, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_FARM, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_HOUSE, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_01, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_02, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_LADDER_DOWN, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_LADDER_UP, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_STAIRS_01, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_STAIRS_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_03, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_BOULDER, 		TRANSPARENT 			},
	{ SPR_T_TREE, 			TRANSPARENT 			},
	{ SPR_T_STONE_WALL, 	0						},
	{ SPR_T_STONE_WINDOW, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_STONE_FLOOR, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_WOOD_WALL, 		0						},
	{ SPR_T_WOOD_WINDOW, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_WOOD_FLOOR, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_MARBLE_WALL, 	0 						},
	{ SPR_T_MARBLE_PILLAR, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_MARBLE_FLOOR, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_CAVE_WALL, 		0 						},
	{ SPR_T_CAVE_PILLAR, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_CAVE_FLOOR, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_04, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_05, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_06, 	WALKABLE | TRANSPARENT 	},
	
// 3rd row
// ============================================================================
//	  Graphic		  		Flags
	{ SPR_T_CHAIR_LEFT, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_TABLE, 			TRANSPARENT 			},
	{ SPR_T_CHAIR_RIGHT, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_BAR_STOOL, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_COUNTER, 		TRANSPARENT 			},
	{ SPR_T_CARPET_01, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_CARPET_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_BED_01, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_BED_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_DRAWERS, 		TRANSPARENT 			},
	{ SPR_T_BOOKCASE, 		TRANSPARENT 			},
	{ SPR_T_RESERVED_07, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_08, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_09, 	WALKABLE | TRANSPARENT 	},	
	{ SPR_T_WELL, 			TRANSPARENT 			},
	{ SPR_T_DOOR_01, 		WALKABLE },
	{ SPR_T_DOOR_02, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_GRAVE, 			WALKABLE | TRANSPARENT 	},
	{ SPR_T_SHACKLES, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_BUCKET, 		WALKABLE | TRANSPARENT 	},
	{ SPR_T_BARREL, 		TRANSPARENT 			},
	{ SPR_T_RESERVED_10, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_11, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_12, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_13, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_14, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_RESERVED_15, 	WALKABLE | TRANSPARENT 	},
	{ SPR_T_SIGN_TEMPLE, 	TRANSPARENT 			},
	{ SPR_T_RESERVED_16, 	TRANSPARENT 			},
	{ SPR_T_RESERVED_17, 	TRANSPARENT 			},
	{ SPR_T_SIGN_WEAPON, 	TRANSPARENT 			},
	{ SPR_T_SIGN_TAVERN, 	TRANSPARENT 			},
	
// 4th row, animated tiles
// ============================================================================
//	  Graphic		  		Flags
	{ SPR_AT_WATER, 		TRANSPARENT 			},
	{ SPR_AT_VOLCANO, 		 						},
	{ SPR_AT_FIREPLACE, 	 						},
	{ SPR_AT_TORCH, 		WALKABLE | TRANSPARENT 	},
	{ SPR_AT_FOUNTAIN, 		TRANSPARENT 			},
	{ SPR_AT_RESERVED_18, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_MILL, 			WALKABLE | TRANSPARENT 	},
	{ SPR_AT_CAMPFIRE, 		WALKABLE | TRANSPARENT 	},
	{ SPR_AT_LAVA, 			TRANSPARENT 			},
	{ SPR_AT_RESERVED_19, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_20, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_21, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_22, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_23, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_24, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_25, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_26, 	WALKABLE | TRANSPARENT 	},
	{ SPR_AT_RESERVED_27, 	WALKABLE | TRANSPARENT 	}
};

void map_load(int index) {
	// Clear old map if loaded
	map_clear();
	
	char path[50] = "data/";
	strcat(path, map_info[index].filename);
	
	FILE *mapfile;
	mapfile = fopen(path, "rb");
	
	unsigned char buffer[2];
	fread(&buffer, sizeof(char), 2, mapfile);
	
	map.width = buffer[0] + 1;
	map.height = buffer[1] + 1;
		
	unsigned char mapbuffer[map.width * map.height];
	fread(&mapbuffer, sizeof(mapbuffer), 1, mapfile);
	
	int size = map.width * map.height;
	map.tiles = calloc(size, sizeof(unsigned char)); 
	
	for (int x = 0; x < map.width; x++) {
		for (int y = 0; y < map.height; y++) {
			int offset = x + y * map.height;
			map.tiles[offset] = mapbuffer[offset];
		}
	}
	
	map.name = map_info[index].name;
	fclose(mapfile);
}

void map_clear() {
	if (map.tiles) free(map.tiles);
}

int map_flags(int offset, int flags) {
	unsigned char t = map.tiles[offset];
	if (tiles[t].flags & flags)
		return 1;

	return 0;
}

// Draw map screen
void map_draw_map(int camera_offset) {
	int offx, offy;
	util_xy_from_offset(&offx, &offy, camera_offset, map.width);

	for (int x = 0; x < 11; x++) {
		for (int y = 0; y < 11; y++) {
			int mappos = (x+offx) + (y+offy) * map.width;
			TCOD_console_set_default_background(NULL, col_black);
			console_draw_sprite(1+x*2, 1+y*2, tiles[map.tiles[mappos]].graphic);
		}
	}
}