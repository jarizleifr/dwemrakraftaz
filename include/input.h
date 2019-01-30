#pragma once

typedef struct {
	int command;
	int keycode;
	bool alt;
	bool ctrl;
	bool shift;
} input_command_t;

enum {
	CMD_NONE,
	CMD_MOVE_NORTH,
	CMD_MOVE_EAST,
	CMD_MOVE_SOUTH,
	CMD_MOVE_WEST,
	CMD_ACCEPT,
	CMD_ACTION,
	CMD_BACK,
	INPUT_COMMANDS_END
};

int input_process();