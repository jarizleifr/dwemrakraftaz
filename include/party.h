#pragma once

enum {
	STATUS_OK,
	STATUS_CONFUSED,
	STATUS_PARALYZED,
	STATUS_DEAD
};

typedef struct {
	char name[9];
	unsigned char graphic;
	int health, health_max;
	int attack, defense;
	int status;
} character_t;

typedef struct {
	character_t characters[6];
	unsigned char count;
} party_t;

party_t party;

void party_add_character(character_t character);
void party_move(int offset);
static void party_encounter();
void party_draw_roster(int x, int y);