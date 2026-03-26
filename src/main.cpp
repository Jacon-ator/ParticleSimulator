#include <SFML/Graphics.hpp>
#include <iostream>

#include "particle.h"

int main()
{

	// Creates the main window
	sf::RenderWindow window( sf::VideoMode( { 960, 540 } ), "Particle Simulator", sf::Style::Resize | sf::Style::Close);

	Particle particle(100.0f, sf::Vector2(0.0f, 0.0f));
	particle.setColor(sf::Color::Green);

	// // Sets the origin of the cursor to be in the middle of the particle
	// particle.setOrigin(sf::Vector2f(particle.getRadius(), particle.getRadius()));

	// While application is open
	while ( window.isOpen() )
	{
		// Process Events
		while ( const std::optional event = window.pollEvent() )
		{
			// If the event is the close event, close the window
			if ( event->is<sf::Event::Closed>() ) 
			{
				window.close();
			}

			// When window is resized, print size to console
			if ( event->is<sf::Event::Resized>())
			{
				// std::cout << "Window Size = X: " << window.getSize().x << " Y: " << window.getSize().y << std::endl;
				printf("Window Size = X: %i, Y: %i \n", window.getSize().x, window.getSize().y);
			}

			// If the user enters text, print that ascii to console
			if (const auto* textEntered = event->getIf<sf::Event::TextEntered>())
			{
    			if (textEntered->unicode < 128)
        			std::cout << "ASCII character typed: " << static_cast<char>(textEntered->unicode) << std::endl;
			}

			// If the user pressed ESC, the window will close
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
				{
					window.close();
				}
			}
			
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			particle.setPosition(static_cast<sf::Vector2f>(mousePosition));
		} 

		// Clear the screen
		window.clear();
		// Draw `particle`
		particle.draw(window);
		// Update the window
		window.display();
	}
} 
