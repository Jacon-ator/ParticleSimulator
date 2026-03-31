#pragma once

#include <vector>

#include "particle.h"

namespace Verlet {

    void integrate(Particle& particle, float deltaTime)
    {
        sf::Vector2f currentPosition = particle.getCurrentPosition();
        sf::Vector2f newPosition = 2.0f * currentPosition - particle.getPreviousPosition() + particle.getAcceleration() *  deltaTime * deltaTime;
        
        particle.setPreviousPosition(currentPosition);
        particle.setCurrentPosition(newPosition);
    }

};