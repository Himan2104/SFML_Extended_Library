#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"

namespace gui
{
	class CheckBox : public guibase
	{
	public:
		CheckBox(sf::Font& font, std::string label = "NoLabel", float scale = 1.0f);
		~CheckBox();

		bool getStatus();

		void EventHandler(sf::Event e, const sf::RenderWindow& window) override;
		void setPosition(const sf::Vector2f& pos) override;
		sf::Vector2f getSize()const override;
		void render(sf::RenderTarget& renderTarget) override;

	private:
		sf::RectangleShape box;
		sf::RectangleShape tick;
		sf::Text label;

		float scale;

		bool status;

		void adjustPositions();
	};
}

