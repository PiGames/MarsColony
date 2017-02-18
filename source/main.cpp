#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/game/Game.hpp"
#include "states/PlayState.hpp"
#include "states/MenuState.hpp"

int main()
{
	pi::MapManager::Init({ 16,16 });
	try
	{
		pi::Game game({ 1280, 720 }, "Mars Colony", 60u);

		pi::Logger::Log("Mars Colony v" + std::to_string(pi::constants::version::MAJOR) + "." + std::to_string(pi::constants::version::MINOR) + "." + std::to_string(pi::constants::version::RELEASE), pi::Logger::MessageType::Info, pi::Logger::OutputType::Both);

		game.addState<mc::MenuState>((short)mc::States::Menu);
		game.addState<mc::PlayState>((short)mc::States::Play);
		game.run();
	}
	catch (std::exception& e)
	{
		pi::Logger::Log("EXCPTION: " + *e.what(), pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
		std::cin.get();
	}


	return 0;
}