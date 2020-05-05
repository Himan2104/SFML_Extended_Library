#include "pch.h"
#include "Button.hpp"

gui::Button::Button(sf::Vector2f size, std::string ButtonText, int CharSize)
{ 
	//variables
	adjustmentFactor = { 0.0f, 0.0f};

	//configuration
	box.setSize(size);
	text.setString(ButtonText);
	text.setCharacterSize(CharSize);
	box.setOrigin(box.getGlobalBounds().width / 2.0f, box.getGlobalBounds().height / 2.0f);
	adjustText();

	box.setFillColor(sf::Color::Magenta);
	text.setFillColor(sf::Color::White);
}

void gui::Button::changeAdjustmentFactor(sf::Vector2f& adjustmentFactor)
{
	this->adjustmentFactor = adjustmentFactor;
	adjustText();
}

void gui::Button::setFont(sf::Font& font)
{
	text.setFont(font);
	adjustmentFactor = { 0.0f, -text.getGlobalBounds().height / 2.0f };
	adjustText();
}

void gui::Button::setColor(sf::Color BoxColor, sf::Color TextColor)
{
	box.setFillColor(BoxColor);
	text.setFillColor(TextColor);
}

void gui::Button::setPosition(const sf::Vector2f& pos)
{
	box.setPosition(pos);
	adjustText();
}

sf::Vector2f gui::Button::getSize() const
{
	return box.getSize();
}

void gui::Button::setFunction(std::function<void(void)> ButtonFunction)
{
	this->ButtonFunction = ButtonFunction;
}

void gui::Button::render(sf::RenderTarget& renderTarget)
{
	renderTarget.draw(box);
	renderTarget.draw(text);
}

void gui::Button::EventHandler(sf::Event e, const sf::RenderWindow& window)
{
	sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(window));

	if (e.type == sf::Event::MouseButtonPressed)
		if (e.mouseButton.button == sf::Mouse::Left)
			if (box.getGlobalBounds().contains(m_pos))
				ButtonFunction();
		
}

void gui::Button::adjustText()
{
	text.setOrigin(text.getGlobalBounds().width/2.0f, text.getGlobalBounds().height/2.0f);
	text.setPosition(box.getPosition() + adjustmentFactor);
	
	while (text.getGlobalBounds().left < box.getGlobalBounds().left
		|| text.getGlobalBounds().left + text.getGlobalBounds().width
		> box.getGlobalBounds().left + box.getGlobalBounds().width
		|| text.getGlobalBounds().top < box.getGlobalBounds().top
		|| text.getGlobalBounds().top + text.getGlobalBounds().height
		> box.getGlobalBounds().top + box.getGlobalBounds().height)
	{
		text.setCharacterSize(text.getCharacterSize() - 1);
		text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
		text.setPosition(box.getPosition() + adjustmentFactor);
	}
}
