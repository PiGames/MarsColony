#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "engine/pathfinder/PathFinder.hpp"

namespace pi
{
	class MovableObject
	{
	public:
		//Sets target and use pathfinder
		void setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to);

		//Returns state of moving
		bool isMoving();
		 
	private:

		std::queue<sf::Vector2f> targets;
	};	
}
