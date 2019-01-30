// C libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Library includes
#include "libtcod.h"

// Header
#include "combat.h"

// Other dependencies
#include "engine.h"
#include "rendering.h"
#include "input.h"
#include "gamestate.h"
#include "map.h"

#include "party.h"

#include "util.h"

// ============================================================================
// Local
// ============================================================================

enum {
	NORMAL,
	AMBUSHED
};

typedef enum {
	CONTROLLER_DEAD,		// Dead or Inactive entity
	CONTROLLER_PLAYER,		// Player controlled entity
	CONTROLLER_ENEMY,		// AI controlled entity
	CONTROLLER_CONFUSED,	// Confused entity, random actions
} controller_t;

// Positions for player party
static const unsigned char p_pos[2][6] = {
	{ 103, 104, 105, 114, 115, 116 },			// Normal
	{ 48,  72,  50,  70,  71,  49  }			// Ambushed
};
// Enemy positions
static const unsigned char e_pos[2][16] = {
	{ 2, 4, 6, 8, 12, 14, 16, 18, 20, 24, 26, 28, 30, 36, 38, 40 }, // Normal
	{ 2, 4, 6, 8, 12, 14, 16, 18, 20, 24, 26, 28, 30, 36, 38, 40 }	// Ambushed
};

// Combat Entity
typedef struct {
	controller_t 	controller;			// Controller
	unsigned short 	offset; 			// Position on map
	unsigned char 	graphic;			// Graphic to use

	int 			health, maxhealth;	// Health	
	int 			attack, defense;	// Temp stats for combat
} c_entity_t;

// Combat Effect - Used for projectiles and graphic effects
typedef struct {
	bool active;
	int offset;
	int graphic;
	int timer;
} c_effect_t;

c_entity_t *entities;		// Pointer to an array of combat entities
c_effect_t effect;			// Graphical effect for projectiles, spells, hit effects etc.
unsigned char entity_count; // Total count of entities
unsigned char current_turn; // Index of entity currently acting its turn

// ============================================================================
// Entity Logic
// ============================================================================

static void combat_kill_entity() {

}

static void combat_attack_entity(int i) {
	entities[i].health -= entities[current_turn].attack;
	if (entities[i].health <= 0)
		entities[i].controller = CONTROLLER_DEAD;
	current_turn++;
}

static void combat_move_entity(int offset) {
	int position = entities[current_turn].offset + offset;
	
	for (int i = 0; i < entity_count; i++) {
		if (entities[i].offset == position && entities[i].controller != CONTROLLER_DEAD) {
			if (entities[i].controller == CONTROLLER_ENEMY)
				combat_attack_entity(i);
			return;
		}
	}
	
	if (map_flags(position, WALKABLE)) {
		entities[current_turn].offset = position;
		current_turn++;
	}
}

// Player controlled entity takes turn
static void combat_player_turn(int command) {
	int pos = entities[current_turn].offset;
	switch (command) {
		case CMD_BACK:
			combat_finish();
			map_load(gamestate.current_map);
			engine_set_state(STATE_GAME);
		break;
		// Spacebar skips turn
		case CMD_ACTION:
			// TODO: Increase defense if omitting turn
			current_turn++;
		break;
		case CMD_MOVE_NORTH:
			if (pos - map.width >= 0)
				combat_move_entity(-map.width);
		break;
		case CMD_MOVE_EAST:
			if (pos % map.width < map.width-1) {
				combat_move_entity(1);
			}
		break;
		case CMD_MOVE_SOUTH:
			if (pos + map.width < map.width * map.height)
				combat_move_entity(map.width);
		break;
		case CMD_MOVE_WEST:
			if (pos % map.width > 0)
				combat_move_entity(-1);
		break;
		break;
		default:
		break;
	}
}

// Enemy controlled entity takes turn
static void combat_enemy_turn() {
	current_turn++;
}

// Confused entity takes turn
static void combat_confused_turn() {
	current_turn++;
}

// ============================================================================
// Combat State
// ============================================================================

void combat_init() {
	int size = 22;
	entities = calloc(size, sizeof(c_entity_t));
	entity_count = size;
	
	// Loop through the player party and create combat entities accordingly
	for (int i = 0; i < party.count; i++) {
		c_entity_t character = { 
			CONTROLLER_PLAYER,				 // Controller
			p_pos[NORMAL][i], 				 // Spawn position
			party.characters[i].graphic, 	 // Graphic used
			party.characters[i].health, 	 // Health
			party.characters[i].health_max,  // Maximum Health
			party.characters[i].attack, 	 // Attack
			party.characters[i].defense  	 // Defense
		};
		// Assign character to combatant list
		entities[i] = character;
	}
	
	// Create enemies
	for (int i = 0; i < 16; i++) {
		entities[party.count+i] = (c_entity_t){ CONTROLLER_ENEMY, e_pos[NORMAL][i], SPR_A_ORC, 50, 50, 5, 5 };
	}
}

// Loop through entities and draw them on map
static void combat_draw_entities() {
	for (int c = 0; c < entity_count; c++) {
		if (entities[c].controller == CONTROLLER_DEAD) continue;
			
		int x, y;
		util_xy_from_offset(&x, &y, entities[c].offset, 11);

		if (current_turn == c) {
			console_draw_sprite_flicker(1+x*2, 1+y*2, entities[c].graphic, col_white);
		}
		else {
			console_draw_sprite(1+x*2, 1+y*2, entities[c].graphic);
		}
	}
}

// Run combat state
void combat_run(int command) {
	if (current_turn >= 22)
		current_turn = 0;
	
	controller_t c = entities[current_turn].controller;
	
	while (c == CONTROLLER_DEAD) {
		current_turn++;
		c = entities[current_turn].controller;
	}
	
	if (c == CONTROLLER_PLAYER) {
		combat_player_turn(command);
	}
	else if (c == CONTROLLER_ENEMY) {
		combat_enemy_turn();
	}
}

// Draw combat state
void combat_draw() {
	console_draw_main();
	party_draw_roster(24, 1);
	map_draw_map(0);
	combat_draw_entities();
}

// Free entities when exiting combat
void combat_finish() {
	free(entities);
}
