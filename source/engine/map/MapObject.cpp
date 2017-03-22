#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject( std::weak_ptr<sf::Texture> texture, const std::string & name, const sf::Vector2f& pos )
		:position( pos ), Entity( name )
	{
		object.setTexture( *texture.lock() );
	}

	void MapObject::SetUnitPosition( const sf::Vector2i& position )
	{
		this->object.setPosition(
			position.x*constants::cell::CELL_DIMENSIONS.x,
			position.y*constants::cell::CELL_DIMENSIONS.y );
	}
}

