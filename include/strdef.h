#pragma once

enum {
// ============================================================================
	STR_ARCHETYPE_01,
	STR_ARCHETYPE_02,
	STR_ARCHETYPE_03,
	STR_ARCHETYPE_04,
	STR_ARCHETYPE_05,
	STR_ARCHETYPE_06,
	STR_ARCHETYPE_07,
	STR_ARCHETYPE_08,
	STR_ARCHETYPE_09,
// ============================================================================
	STR_ARCHETYPE_01_DESC,
	STR_ARCHETYPE_02_DESC,
	STR_ARCHETYPE_03_DESC,
	STR_ARCHETYPE_04_DESC,
	STR_ARCHETYPE_05_DESC,
	STR_ARCHETYPE_06_DESC,
	STR_ARCHETYPE_07_DESC,
	STR_ARCHETYPE_08_DESC,
	STR_ARCHETYPE_09_DESC,
// ============================================================================
	STRINGS_END
};

const char* const strings[STRINGS_END] = {
// ============================================================================
	"Fighter",									// STR_RACE_01
	"Paladin",									// STR_RACE_02
	"Priest",									// STR_RACE_03
	"Thief",									// STR_RACE_04
	"Assassin",									// STR_RACE_05
	"Ranger",									// STR_RACE_06
	"Wizard",									// STR_RACE_07
	"Monk",										// STR_RACE_07
	"Barbarian",								// STR_RACE_07
// ============================================================================
	"Fighters live and die for combat. They can be anything from a noble swordfighter to a bloodthirsty mercenary.", // STR_RACE_01_DESC
	"Paladins are knights devoted to a spiritual cause. They combine martial prowess with divine magic",	// STR_RACE_02_DESC
	"Priests are divine casters, who conjure magic from their connection to their deity.",								// STR_RACE_03_DESC
	"Thief desc",								// STR_RACE_04_DESC
	"Assassin desc",							// STR_RACE_05_DESC
	"Ranger desc",								// STR_RACE_06_DESC
	"Wizard desc",									// STR_RACE_07_DESC
	"Monk desc",									// STR_RACE_07_DESC
	"Barbarian desc"									// STR_RACE_07_DESC
// ============================================================================
};