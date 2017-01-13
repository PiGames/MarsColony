#pragma once

/*
	Disabling warning C4458 - "declaration of 'x' hides class member".
*/
#pragma warning(disable:4458)

#include <string>
#include <map>

namespace pi
{
	namespace constants
	{
		namespace version
		{
			constexpr std::uint8_t MAJOR = 0;
			constexpr std::uint8_t MINOR = 1;
			constexpr std::uint8_t RELEASE = 0;
		}

		namespace pathfinder
		{
			namespace flagNames
			{
				constexpr auto COLLIDABLE = "COLLIDABLE";
			}
		}

		namespace mapManager
		{
			const std::map<std::string, std::pair<int8_t, int8_t>> unitDirections =
			{ {"NORTH",std::pair<int8_t,int8_t>(0,-1)},
			  {"NORTH_EAST",std::pair<int8_t,int8_t>(1,-1)}, 
			  { "EAST",std::pair<int8_t,int8_t>(1,0)},
			  { "SOUTH_EAST",std::pair<int8_t,int8_t>(1,1)},
			  { "SOUTH",std::pair<int8_t,int8_t>(0,1)},
			  { "SOUTH_WEST",std::pair<int8_t,int8_t>(-1,1)},
			  { "WEST",std::pair<int8_t,int8_t>(-1,0)},
			  { "NORT_WEST",std::pair<int8_t,int8_t>(-1,-1)} };

			constexpr auto NORTH = "NORTH";
			constexpr auto NORTH_EAST = "NORTH_EAST";
			constexpr auto EAST = "EAST";
			constexpr auto SOUTH_EAST = "SOUTH_EAST";
			constexpr auto SOUTH = "SOUTH";
			constexpr auto SOUTH_WEST = "SOUTH_WEST";
			constexpr auto WEST = "WEST";
			constexpr auto NORTH_WEST = "NORTH_WEST";
		}

		namespace ui
		{
			constexpr std::uint8_t MAX_CALLBACKS = 8;
			constexpr std::uint8_t MAX_UIELEMENTS = 32;
			constexpr std::uint8_t NUMBER_OF_UI_ELEMENTS = 4;
		}
		
		namespace console
		{
			constexpr std::uint8_t MAX_COMMANDS = 32;
			constexpr std::uint8_t DEAFULT_TEXT_SIZE = 12;
			constexpr std::uint8_t DEAFULT_NUMBER_OF_LINES = 19;
			constexpr std::uint8_t DEAFULT_TEXT_SIZE_IN_LINE = 80;
		}

		namespace worldConstructor
		{
			constexpr auto CELL = "Cell";
			constexpr auto TEXTURE_FILE_PATH = "data/textures/textureAtlas.png";
			constexpr auto ID_FILE_PATH = "id.txt";
		}

		namespace soundSystem
		{
			constexpr auto SOUND_PATH = "data/sound/";
			constexpr auto SOUND_FORMAT = ".ogg";
		}

		namespace stateMachine
		{
			constexpr std::int8_t EXIT_STATE = -1;
		}

		namespace saveSystem
		{
			constexpr char COMMENT = '#';
		}

		namespace error
		{
			namespace movableObject
			{
				constexpr auto WRONG_USE_MOVE = "Wrong use of move() method. Firstly make sure that object is moving.";
			}

			namespace soundSystem
			{
				constexpr auto ALREADY_EXIST = "Sound with given name already exist ";
				constexpr auto DOES_NOT_EXIST_IN_FOLDER = "Sound with given name isn't in source folder";
				constexpr auto DOES_NOT_EXIST_IN_SYSTEM = "Sound with given name doesn't exist in system. Firstly you need add it to system. Use emplaceSound (std::string name)";
			}

			namespace stateMachine
			{
				constexpr auto NO_STATES = "StateMachine: Cannot run, no states";
				constexpr auto CANNOT_SWITCH = "StateMachine: Cannot switch states, switching to ";
			}

			namespace saveSystem
			{
				constexpr auto CANNOT_OPEN = "SaveSystem: Cannot open file: ";
				constexpr auto CANNOT_SAVE = "SaveSystem: Cannot save to file: ";
				constexpr auto CANNOT_UPDATE_CANNOT_FOUND = "SaveSystem: Cannot update variable, cannot find: ";
			}

			namespace resourceCache
			{
				constexpr auto CANNOT_GET_NO_PATH = "ResourceCache: cannot return proper resource, no name has given";
				constexpr auto CANNOT_GET_CANNOT_LOAD = "ResourceCache: cannot return proper resource, cannot load from path: ";
			}
		}
	}
}