#include <SFML/Graphics.hpp>

class Particle : sf::CircleShape {
    public:

        Particle(float size, sf::Vector2f position) {};
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
            circle.setOrigin(sf::Vector2f(getRadius(), getRadius()));
            circle.setPosition(position);
            circle.setRadius(getRadius());
            circle.setFillColor(color);
            window.draw(circle);
        }

    private:
        float size = 50.0f;
        sf::Color color = sf::Color::Cyan;
        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);
        sf::CircleShape circle;
};