#include <SFML/Graphics.hpp>
#include <iostream>
#include <format>
#include <vector>

#include "particle.h"
#include "counter.h"
#include "eventHandler.h"

int main()
{
	// Creates the main window
	sf::RenderWindow window( sf::VideoMode( { 960, 540 } ), "Particle Simulator", sf::Style::Resize | sf::Style::Close);
	Counter particleCounter;
	sf::Font font("../src/assets/fonts/Overpass-Black.ttf");
	sf::Text particleCountText(font);
	particleCountText.setCharacterSize(42);
	
	std::vector<std::unique_ptr<Particle>> particleVector;
	
	while ( window.isOpen() )
	{
		EventHandler eventHandler;
	// --- Event Logic --- 
		while ( const std::optional event = window.pollEvent() )
		{
			// If the event is the close event, close the window
			if ( event->is<sf::Event::Closed>() ) 
				window.close();
		
			// When window is resized, print size to console
			if ( event->is<sf::Event::Resized>())
				eventHandler.handleEventResized(window);
			
			// If the user enters text, print that ascii to console
			if (const auto* textEntered = event->getIf<sf::Event::TextEntered>())
				eventHandler.handleTextEntered(textEntered);
			
			// If the user pressed ESC, the window will close
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
				eventHandler.handleKeyPressed(keyPressed, window);

			// When user clicks, a particle is placed at their mouse position
			if (event->is<sf::Event::MouseButtonPressed>())
				eventHandler.handleParticleSpawn(window, particleVector, particleCounter);
		}
		
	// --- Render Loop ---

		// Clear the window at the start of the frame
		window.clear();
		
		// Draw the particle counter
		particleCounter.draw(window);

		// Draw every particle
		for (const auto& particle: particleVector)
		{
			particle->draw(window);
		}

		window.display();
	}
} 
