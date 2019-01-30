#pragma once

enum {
	STR_RACE_01,
	STR_RACE_02,
	STR_RACE_03,
	STR_RACE_04,
	STR_RACE_05,
	STR_RACE_06,
	STR_RACE_07,
// ============================================================================
	STR_RACE_01_DESC,
	STR_RACE_02_DESC,
	STR_RACE_03_DESC,
	STR_RACE_04_DESC,
	STR_RACE_05_DESC,
	STR_RACE_06_DESC,
	STR_RACE_07_DESC,
// ============================================================================
	STRINGS_END
};

const char* const strings[STRINGS_END] = {
	"Human",									// STR_RACE_01
	"Half-Elf",									// STR_RACE_02
	"Elf",										// STR_RACE_03
	"Dwarf",									// STR_RACE_04
	"Gnome",									// STR_RACE_05
	"Halfling",									// STR_RACE_06
	"Orlok",									// STR_RACE_07
// ============================================================================
	"Humans are ",								// STR_RACE_01_DESC
	"Half-Elves",								// STR_RACE_02_DESC
	"Elves",									// STR_RACE_03_DESC
	"Dwarves",									// STR_RACE_04_DESC
	"Gnomes",									// STR_RACE_05_DESC
	"Halflings",								// STR_RACE_06_DESC
	"Orloks",									// STR_RACE_07_DESC
};