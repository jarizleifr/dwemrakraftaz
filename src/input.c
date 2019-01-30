#include "libtcod.h"
#include "engine.h"
#include "input.h"

input_command_t input_commands[INPUT_COMMANDS_END] = {
	{ CMD_NONE,			TCODK_NONE,		false,  false,  false },

	{ CMD_MOVE_NORTH,	TCODK_UP,		false,	false,	false }, 
	{ CMD_MOVE_EAST,	TCODK_RIGHT,	false,	false,	false }, 
	{ CMD_MOVE_SOUTH,	TCODK_DOWN,		false,	false,	false }, 
	{ CMD_MOVE_WEST,	TCODK_LEFT,		false,	false,	false },
	
	{ CMD_ACCEPT,		TCODK_ENTER,	false,	false,	false },
	{ CMD_ACTION,		TCODK_SPACE,	false,	false,	false },
	{ CMD_BACK,			TCODK_ESCAPE,	false,	false,	false }
};

int input_process() {
	TCOD_key_t key = TCOD_console_check_for_keypress(TCOD_KEY_PRESSED);

	// Global keys
	if (key.vk == TCODK_ENTER && key.lalt)
		TCOD_console_set_fullscreen(!TCOD_console_is_fullscreen());
	
	if (TCOD_console_is_window_closed())
		engine_terminate();

	for (int i = 0; i < INPUT_COMMANDS_END; i++) {
		input_command_t cmd = input_commands[i];
		if (cmd.keycode == key.vk && cmd.ctrl == key.lctrl && cmd.alt == key.lalt && cmd.shift == key.shift)
			return cmd.command;
	}
	return CMD_NONE;
}