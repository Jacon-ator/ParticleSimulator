#pragma once

#include <SFML/Graphics.hpp>

#include "particle.h"

namespace CollisionDetection {

void checkBoundaryCollision(Particle &particle, sf::RenderWindow &window)
{
    const sf::Vector2u boundarySize = window.getSize();
    const float particleRadius = particle.getRadius(); 
    sf::Vector2f currentPosition = particle.getCurrentPosition();
    float damping = 0.55;

    if (currentPosition.x > boundarySize.x - particleRadius)
    {
        sf::Vector2f previousPosition = particle.getPreviousPosition();
        float velocityX = currentPosition.x - previousPosition.x;

        particle.setCurrentPosition({boundarySize.x - particleRadius, currentPosition.y});
        particle.setPreviousPosition({(boundarySize.x - particleRadius) + velocityX * damping, previousPosition.y});
    }
    if (currentPosition.y > boundarySize.y - particleRadius)
    {
        sf::Vector2f previousPosition = particle.getPreviousPosition();
        float velocityY = currentPosition.y - previousPosition.y;
        
        particle.setCurrentPosition({currentPosition.x, boundarySize.y - particleRadius});
        particle.setPreviousPosition({previousPosition.x, (boundarySize.y - particleRadius) + velocityY * damping});
    }
    if (currentPosition.x < 0 + particleRadius)
    {
        sf::Vector2f previousPosition = particle.getPreviousPosition();
        float velocityX = currentPosition.x - previousPosition.x;
        
        particle.setCurrentPosition({particleRadius, currentPosition.y});
        particle.setPreviousPosition({particleRadius + velocityX * damping, previousPosition.y});
    }
    if (currentPosition.y < 0 + particleRadius)
    {
        sf::Vector2f previousPosition = particle.getPreviousPosition();
        float velocityY = currentPosition.y - previousPosition.y;

        particle.setCurrentPosition({currentPosition.x, particleRadius});
        particle.setPreviousPosition({previousPosition.x, particleRadius + velocityY * damping});
    }
}

};