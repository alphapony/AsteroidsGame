//
// Created by Morten Nobel-Jørgensen on 19/09/2017.
//

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include "Asteroid.hpp"
#include "sre/Renderer.hpp"
#include <random>

inline float random_range(float min, float max)
{
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

Asteroid::Asteroid(const sre::Sprite& sprite) : GameObject(sprite) {
    scale = glm::vec2(0.5f, 0.5f);
    winSize = sre::Renderer::instance->getDrawableSize();
    radius = 23;
    rotation = 0;
    position = winSize * random_range(0.2, 0.8);
    velocity = glm::vec2(0.0f, 0.0f);
    moveSpeed = random_range(0.2, 0.8);
    rotationSpeed = random_range(0.0, 7.0);
}

float Asteroid::getRadius() const {
    return radius;
}

void Asteroid::update(float deltaTime) {
    rotation += rotationSpeed * deltaTime;
    position += velocity * deltaTime;
}

void Asteroid::onCollision(std::shared_ptr<GameObject> other) {

}

void Asteroid::setRadius(float radius) {
    Asteroid::radius = radius;
}
