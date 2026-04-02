#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <ranges>
#include <cmath>
#include <iostream>

#include "particle.h"

namespace CollisionDetection {

float getDistance(sf::Vector2f pos1, sf::Vector2f pos2);

void checkBoundaryCollision(Particle &particle, sf::Vector2u boundarySize)
{
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

void checkParticleCollision(std::vector<std::unique_ptr<Particle>> &particleVector, Particle &particle)
{
    auto it = std::ranges::find_if(particleVector, [&particle](const std::unique_ptr<Particle>& p) {
        return p.get() == &particle;
    });

    if (it != particleVector.end())
    {
        auto index = std::distance(particleVector.begin(), it);
        sf::Vector2f particlePosition = particleVector[index]->getCurrentPosition();
        float particleRadius = particleVector[index]->getRadius();

        for (int i = 0; i < index; i++)
        {
            sf::Vector2f otherParticlePosition = particleVector[i]->getCurrentPosition();
            if (float distance = getDistance(particlePosition, otherParticlePosition) < particleRadius)
            {
                float overlap = particleRadius * 2 - distance;
                
                std::cout << "Particles Collided" << std::endl;
            }
        }
    }

}

float getDistance(sf::Vector2f pos1, sf::Vector2f pos2)
{
    float x_value = (pos2.x - pos1.x ) * (pos2.x - pos1.x ); 
    float y_value = (pos2.y - pos1.y ) * (pos2.y - pos1.y ); 
    return std::sqrt(x_value + y_value);
}

};