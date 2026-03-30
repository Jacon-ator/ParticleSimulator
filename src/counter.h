#include <SFML/Graphics.hpp>
#include <string>
#include <format>

std::string FONT_PATH = "../src/assets/fonts/Overpass-Black.ttf";

struct Counter {
    public:
        Counter() {
            bool fontLoaded = font.openFromFile(FONT_PATH);
            if (fontLoaded)
            {
                sf::Text text(font);
                text.setCharacterSize(characterSize);
            }
            else
            {
                throw std::runtime_error("Failed to load font from " + FONT_PATH );
            }
        };

        int getAmount()
        {
            return amount;
        } 

        void increment(int value = 1)
        {
            amount += value;
        }

        void decrement(int value)
        {
            amount -= value;
        }

        std::string getDisplayStirng()
        {
            return displayString;
        }

        void draw(sf::RenderWindow &window)
        {
            if (text.has_value())
            {
                text.value().setString(displayString);
            }
        }

    private:
        int amount = 0;
        std::string displayString = std::format("Particle Count = {}\n", getAmount());
        sf::Font font;
        std::optional<sf::Text> text;
        int characterSize = 42;
};