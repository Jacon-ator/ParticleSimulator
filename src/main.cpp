#include <SFML/Graphics.hpp>
#include <iostream>
#include <format>
#include <vector>

#include "particle.h"
#include "counter.h"

int main()
{
	// Creates the main window
	sf::RenderWindow window( sf::VideoMode( { 960, 540 } ), "Particle Simulator", sf::Style::Resize | sf::Style::Close);
	Counter particleCounter;
	sf::Font font("../src/assets/fonts/Overpass-Black.ttf");
	sf::Text particleCountText(font);
	particleCountText.setCharacterSize(42);
	
	std::vector<std::unique_ptr<Particle>> particleVector;
	
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

			// When user clicks, a particle is placed at their mouse position
			if (event->is<sf::Event::MouseButtonPressed>())
			{
				// Sets position of mouse to vector variable
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				// Makes a new unique_ptr for a new particle
				auto particle = std::make_unique<Particle>(50.0f, sf::Color::Cyan, static_cast<sf::Vector2f>(mousePosition));
				// Adds the pointer to the new particle to the particleVector array
				// std::move takes the pointer ownership and moves it from heap to the vector
				particleVector.push_back(std::move(particle));
				// Incremets the particleCounter by 1
				particleCounter.increment();
			}
		}
		
		window.clear();
		
		for (const auto& particle: particleVector)
		{
			// particle->draw(window);
			particle->draw(window);
		}

		particleCountText.setString(std::format("Particle Count = {}\n", particleCounter.getAmount()));
		window.draw(particleCountText);
		window.display();
	}
} 
