# Particle Simulator — TODO

## Physics & Movement
- [ ] Add velocity and acceleration vectors to `Particle` so particles actually move after being spawned
- [ ] Implement gravity (constant downward acceleration)
- [ ] Add boundary collision so particles bounce off window edges
- [ ] Add a delta time (`sf::Clock`) to make movement frame-rate independent

## Visuals
- [ ] Implement the stub `updateCounter` method in `counter.h` to actually render the counter using SFML
- [ ] Add color interpolation so particles change color as they age (e.g. cyan → red → transparent)
- [ ] Randomize particle size slightly on spawn for variety

## Interaction
- [ ] Add click-and-drag to spawn a burst of particles continuously while the mouse button is held
- [ ] Let scroll wheel control spawn size or speed

## Architecture
- [ ] Move the particle update loop (physics, lifetime) into a `ParticleSystem` class to keep `main.cpp` clean
- [ ] Fix the `counter.h` `updateCounter` stub — it currently does nothing