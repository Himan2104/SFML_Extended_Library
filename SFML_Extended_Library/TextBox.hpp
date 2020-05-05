#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"
#include<functional>
#include<iostream>
#include<stdlib.h>

namespace gui
{
	class TextBox : public guibase
	{
	public:
		TextBox(sf::Vector2f size = sf::Vector2f(128.0f, 32.0f), std::string label = "No Label");

		void setFont(sf::Font& font);

		void setColor(sf::Color FillColor = sf::Color::Black, sf::Color OutlineColor = sf::Color::Magenta, sf::Color TextColor = sf::Color::White);

		void setPosition(const sf::Vector2f& pos) override;

		sf::Vector2f getSize() const override;

		void EventHandler(sf::Event e, const sf::RenderWindow& window) override;

		void render(sf::RenderTarget& renderTarget) override;

	private:
		sf::RectangleShape box;
		sf::Text label;

		std::string str;
		sf::Text inputText;

		bool isActive;

		void checkClick(sf::Event e, const sf::RenderWindow& window);
		void adjustInputText();
		void adjustLabel();

		
	};

}