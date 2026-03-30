#pragma once

#include <SFML/Graphics.hpp>

class Particle {
    public:

        Particle(const sf::Color particleColor) 
        : color{particleColor} {
            circle.setOrigin(sf::Vector2f(getRadius(), getRadius()));
            circle.setPosition(position);
            circle.setRadius(getRadius());
            circle.setFillColor(color);
        };
        Particle(const sf::Color particleColor, const sf::Vector2f particlePosition) 
        : color{particleColor}, position(particlePosition) {
            circle.setOrigin(sf::Vector2f(getRadius(), getRadius()));
            circle.setPosition(position);
            circle.setRadius(getRadius());
            circle.setFillColor(color);
        };
        Particle(const sf::Color particleColor, const sf::Vector2f particlePosition, float particleSize) 
        : color{particleColor}, position(particlePosition), size(particleSize) {
            circle.setOrigin(sf::Vector2f(getRadius(), getRadius()));
            circle.setPosition(position);
            circle.setRadius(getRadius());
            circle.setFillColor(color);
        };

        float getSize()
        {
            return size;
        }

        float getRadius()
        {
            return size / 2;
        }

        sf::Vector2f getPosition()
        {
            return position;
        }

        void setPosition(sf::Vector2f newPosition)
        {
            position = newPosition;
        }

        void setColor(sf::Color newColor)
        {
            color = newColor;
        }

        
        void draw(sf::RenderWindow& window)
        {
            window.draw(circle);
        }

    private:
        float size = 20.0f;
        sf::Color color = sf::Color::Cyan;
        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);
        sf::CircleShape circle; 
};