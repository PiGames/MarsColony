#include "Checkbox.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		Checkbox::Checkbox()
		{
			this->functionsOn.fill( nullptr );
			this->functionsOff.fill( nullptr );
			this->isEnable = false;
			this->type = elementType_t::CHECKBOX;
		}

		void Checkbox::SetTexture( const sf::Texture& textureOff, const sf::Texture& textureOn )
		{
			this->textureOff = textureOn;
			this->textureOn = textureOff;

			if ( !this->isEnable )
			{
				this->texture = &this->textureOff;
			} else if ( this->isEnable )
			{
				this->texture = &this->textureOn;
			}

			this->sprite.setTexture( *this->texture );
		}

		void Checkbox::SetPosition( const sf::Vector2f& position )
		{
			this->position = position;
			this->sprite.setPosition( this->position );
		}

		void Checkbox::SetSize( const sf::Vector2f& size )
		{
			this->size = size;
			this->sprite.setScale( { this->size.x / this->texture->getSize().x, this->size.y / this->texture->getSize().y } );
		}

		void Checkbox::SetRect( const sf::Vector2f& position, const sf::Vector2f& size )
		{
			this->position = position;
			this->size = size;
			this->sprite.setPosition( this->position );
			this->sprite.setScale( { this->size.x / this->texture->getSize().x, this->size.y / this->texture->getSize().y } );
		}

		void Checkbox::AddCallbackOn( std::function<void()> function )
		{
			for ( auto &i : this->functionsOn )
			{
				if ( !i )
				{
					i = function; break;
				}
			}
		}

		void Checkbox::AddCallbackOff( std::function<void()> function )
		{
			for ( auto &i : this->functionsOff )
			{
				if ( !i )
				{
					i = function; break;
				}
			}
		}

		void Checkbox::use( const sf::Event& event )
		{
			if ( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
			{
				if ( this->sprite.getGlobalBounds().contains( static_cast<float>( event.mouseButton.x ), static_cast<float>( event.mouseButton.y ) ) )
				{
					if ( !this->isEnable )
					{
						this->enable();
					} else if ( this->isEnable )
					{
						this->disable();
					}
				}
			}
		}

		// Private

		void Checkbox::enable()
		{
			this->isEnable = true;
			this->texture = &this->textureOn;
			this->sprite.setTexture( *texture );
			for ( auto &i : this->functionsOn )
			{
				if ( i )
				{
					i();
				}
			}
		}

		void Checkbox::disable()
		{
			this->isEnable = false;
			this->texture = &this->textureOff;
			this->sprite.setTexture( *texture );
			for ( auto &i : this->functionsOff )
			{
				if ( i )
				{
					i();
				}
			}
		}
	}
}