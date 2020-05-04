#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"

namespace gui
{
	class Button : public guibase
	{
	public:
		Button(sf::Vector2f size = sf::Vector2f(256.0f, 64.0f), std::string ButtonText = "NewButton", int CharSize = 30);
	
	private:


	};
}

