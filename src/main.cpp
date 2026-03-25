#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

	// Creates the main window
	sf::RenderWindow window( sf::VideoMode( { 960, 540 } ), "SFML works!", sf::Style::Resize | sf::Style::Close);
	// Initializes a circle called `shape`
	sf::CircleShape shape( 200.f );
	// Sets the color of `shape` to green
	shape.setFillColor( sf::Color::Green );

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
			
		}

		// Clear the screen
		window.clear();
		// Draw `shape`
		window.draw( shape );
		// Update the window
		window.display();
	}
} 
