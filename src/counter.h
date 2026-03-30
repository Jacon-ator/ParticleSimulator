#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <format>


struct Counter {
    public:
    Counter() {
        bool fontLoaded = font.openFromFile(FONT_PATH);
        if (fontLoaded)
        {
            // Emplace sets the constructor of the optional 
            text.emplace(font);
            text.value().setCharacterSize(characterSize);
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
    
    void decrement(int value = 1)
    {
        amount -= value;
    }
    
    void draw(sf::RenderWindow &window)
    {
        if (text.has_value())
        {
            std::string displayString = std::format("Particle Count = {}\n", getAmount());              
            text.value().setString(displayString);
            window.draw(text.value());
        }
    }
    
    private:
    int amount = 0;
    sf::Font font;
    std::optional<sf::Text> text;
    int characterSize = 42;
    const std::string FONT_PATH = "../src/assets/fonts/Overpass-Black.ttf";
};