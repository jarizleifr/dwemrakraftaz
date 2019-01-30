#include "gamestate.h"

#include "rendering.h"

#include "map.h"
#include "party.h"

void gamestate_initialize() {
	

	//party_add_character((character_t){ "Grimoald", 	SPR_A_LORD, 	385, 385, 15, 12, STATUS_OK } );
	//party_add_character((character_t){ "Sergius", 	SPR_A_RANGER, 	240, 240, 12, 10, STATUS_OK } );
	//party_add_character((character_t){ "Otto",  	SPR_A_ASSASSIN, 185, 185, 10, 8,  STATUS_OK } );
	//party_add_character((character_t){ "Hamilcar", 	SPR_A_MAGE, 	90,  90,  8,  4,  STATUS_OK } );
	//party_add_character((character_t){ "Eberulf", 	SPR_A_MAGE, 	0,   0,	  6,  2,  STATUS_OK	} );
	
	gamestate.current_map = MAP_WORLD;
	gamestate.party_offset = 19035;
	
	map_load(gamestate.current_map);
}

void gamestate_load() {

}