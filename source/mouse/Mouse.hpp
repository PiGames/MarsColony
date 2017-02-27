// Created by: mvxxx
#pragma once

#include "engine/map/MapObject.hpp"
#include "engine/ResourceCache.hpp"
#include "engine/Config.hpp"

namespace mc
{
	//Mouse class
	//Represents mouse on the scene
	class Mouse : public pi::MapObject
	{
	public:
		Mouse( const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0, 0 } );

		static enum TYPE
		{
			SIMPLE = 0
		};

		void SetCursor( Mouse::TYPE type );
	};
}