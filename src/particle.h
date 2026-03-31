#pragma once

#include <SFML/Graphics.hpp>

class Particle {
    public:

        Particle(const sf::Color particleColor) 
        : color{particleColor} {
            previousPosition = position;
            circle.setOrigin(sf::Vector2f(getRadius(), getRadius()));
            circle.setPosition(position);
            circle.setRadius(getRadius());
            circle.setFillColor(color);
        };
        Particle(const sf::Color particleColor, const sf::Vector2f particlePosition) 
        : color{particleColor}, position(particlePosition) {
            previousPosition = position;
            circle.setOrigin(sf::Vector2f(getRadius(), getRadius()));
            circle.setPosition(position);
            circle.setRadius(getRadius());
            circle.setFillColor(color);
        };
        Particle(const sf::Color particleColor, const sf::Vector2f particlePosition, float particleSize) 
        : color{particleColor}, position(particlePosition), size(particleSize) {
            previousPosition = position;
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

        sf::Vector2f getPreviousPosition()
        {
            return previousPosition;
        }
        
        sf::Vector2f getCurrentPosition()
        {
            return position;
        }
        
        sf::Vector2f getAcceleration()
        {
            return acceleration;
        }

        void setPreviousPosition(sf::Vector2f newPreviousPosition)
        {
            previousPosition = newPreviousPosition;
        }

        void setCurrentPosition(sf::Vector2f newValue)
        {
            position = newValue;
            circle.setPosition(position);
        }
        
        void setAcceleration(sf::Vector2f newAcceleration)
        {
            acceleration = newAcceleration;
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
        sf::Vector2f previousPosition;
        sf::Vector2f acceleration = sf::Vector2f(0.0f, 100.0f);
        sf::CircleShape circle; 
};