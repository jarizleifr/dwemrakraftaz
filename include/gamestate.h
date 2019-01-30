#pragma once

typedef struct {
	int current_map;
	int party_offset;
} gamestate_t;

// Game State record
gamestate_t gamestate;

void gamestate_initialize();
void gamestate_load();