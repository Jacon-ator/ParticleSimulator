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

void checkParticleCollision(std::vector<std::unique_ptr<Particle>> &particleVector)
{
    std::size_t vectorSize = particleVector.size();
    if (vectorSize > 1)
    {
        for (int i = 0; i < vectorSize; i++)
        {
            sf::Vector2f particleIPosition = particleVector[i]->getCurrentPosition();
            float particleIRadius = particleVector[i]->getRadius();

            for (int j = i + 1 ; j < vectorSize; j++)
            {
                sf::Vector2f particleJPosition = particleVector[j]->getCurrentPosition();
                float particleJRadius = particleVector[j]->getRadius();
                
                float overlap = particleIRadius + particleJRadius;
                float distance = getDistance(particleIPosition, particleJPosition);
                
                if (distance < overlap)
                {
                    std::cout << "Collision Detected" << std::endl;
                }
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