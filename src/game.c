#include "libtcod.h"

#include "game.h"
#include "engine.h"
#include "rendering.h"
#include "input.h"
#include "gamestate.h"
#include "party.h"
#include "map.h"

#include "util.h"


void game_init() {
}

void game_run(int command) {
	switch (command) {
	
	case CMD_MOVE_NORTH:
		if (gamestate.party_offset - map.width >= 0)
			party_move(-map.width);
	break;
	case CMD_MOVE_EAST:
		if (gamestate.party_offset % map.width < map.width-1)
			party_move(1);
	break;
	case CMD_MOVE_SOUTH:
		if (gamestate.party_offset + map.width < map.width * map.height)
			party_move(map.width);
	break;
	case CMD_MOVE_WEST:
		if (gamestate.party_offset % map.width > 0)
			party_move(-1);
	break;
	
	case CMD_BACK:
		engine_set_state(STATE_MAINMENU);
	break;
	
	default:
	break;
	}
}

void game_draw() {
	console_draw_main();

	party_draw_roster(24, 1);
	
	// Calculate camera position from party position
	int x, y;
	util_xy_from_offset(&x, &y, gamestate.party_offset, map.width);
	
	int cam_x = x - 5;
	int cam_y = y - 5;
	
	if (cam_x < 0) cam_x = 0;
	if (cam_y < 0) cam_y = 0;
	if (cam_x > map.width-11) cam_x = map.width-11;
	if (cam_y > map.height-11) cam_y = map.height-11;

	int camera_offset = cam_x + cam_y * map.width;
	
	// Draw map and player sprite depending on camera position
	map_draw_map(camera_offset);
	console_draw_sprite(1+(x-cam_x)*2, 1+(y-cam_y)*2, party.characters[0].graphic);
}