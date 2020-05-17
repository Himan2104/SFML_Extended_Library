#include"pch.h"
#include<iostream> 
#include<SFML/Graphics.hpp>
#include"Button.hpp"
#include"TextBox.hpp"
#include"CheckBox.hpp"

int main()
{
	sf::RenderWindow window({ 800,600 }, "SFML-STATIC");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/consola.ttf");

	gui::Button newButton(font, sf::Vector2f(128.0f,32.0f), "YEET");

	newButton.setPosition({ 400, 300 });
	newButton.setFunction(	[]() {std::cout << "YEET!"; }	);

	newButton.setTextStyle(sf::Text::Bold | sf::Text::Italic);

	gui::CheckBox newBox(font,"LODA HAI KYA?", 5.769f);
	newBox.setPosition(sf::Vector2f(100.0f, 100.0f));

	//main loop
	while (window.isOpen())
	{
		//handle events
		sf::Event e;
		while (window.pollEvent(e))
		{
			newButton.EventHandler(e, window);
			newBox.EventHandler(e, window);
			if (e.type == sf::Event::Closed) window.close();
		}

		//update
	
		//render
		window.clear();
		newButton.render(window);
		newBox.render(window);
		window.display();
	}
	return 0;
}
