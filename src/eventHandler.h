#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

namespace EventHandler {

    void handleEventResized(sf::RenderWindow &window)
    {
	    printf("Window Size = X: %i, Y: %i \n", window.getSize().x, window.getSize().y);
    }

    void handleTextEntered(const sf::Event::TextEntered* textEntered)
    {
	    if (textEntered->unicode < 128)
	        std::cout << "ASCII character typed: " << static_cast<char>(textEntered->unicode) << std::endl;
    }

    void handleKeyPressed(const sf::Event::KeyPressed *keyPressed, sf::RenderWindow &window, std::vector<std::unique_ptr<Particle>> &particleVector)
    {
        // switch (keyPressed->scancode)

	    if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
	    {
		    window.close();
	    }	
        if (keyPressed->scancode == sf::Keyboard::Scan::Up)
        {
            for (const std::unique_ptr<Particle> &particle : particleVector)
            {
                particle->setAcceleration({1000.0f, 0.0f});
            }
        }
    }

    void handleParticleSpawn(sf::RenderWindow &window, std::vector<std::unique_ptr<Particle>> &particleVector, Counter &particleCounter)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	    // Makes a new unique_ptr for a new particle
		std::unique_ptr<Particle> particle = std::make_unique<Particle>(sf::Color::Cyan, static_cast<sf::Vector2f>(mousePosition));
        // Adds the pointer to the new particle to the particleVector array
		// std::move takes the pointer ownership and moves it from heap to the vector
		particleVector.push_back(std::move(particle));
		// Incremets the particleCounter by 1
		particleCounter.increment();
    }



};