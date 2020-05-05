#include"pch.h"
#include<iostream> 
#include<SFML/Graphics.hpp>
#include"Button.hpp"
#include"TextBox.hpp";

int main()
{
	sf::RenderWindow window({ 800,600 }, "SFML-STATIC");
	window.setFramerateLimit(60);

	gui::TextBox newButton;
	

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/consola.ttf");

	newButton.setFont(font);
	newButton.setPosition({ 400, 300 });
	//newButton.setFunction([]() {std::cout << "Cool!"; });

	//main loop
	while (window.isOpen())
	{
		//handle events
		sf::Event e;
		while (window.pollEvent(e))
		{
			newButton.EventHandler(e, window);
			if (e.type == sf::Event::Closed) window.close();
		}

		//update
	
		//render
		window.clear();
		newButton.render(window);
		window.display();
	}
	return 0;
}
