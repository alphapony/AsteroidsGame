//
// Created by Morten Nobel-Jørgensen on 19/09/2017.
//

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include "Laser.hpp"
#include "sre/Renderer.hpp"
#include <random>

inline float random_range(float min, float max){
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

Laser::Laser(const sre::Sprite& sprite) : GameObject(sprite) {
    scale = glm::vec2(0.5f, 0.5f);
    winSize = sre::Renderer::instance->getDrawableSize();
    radius = 23;
    rotation = 0;
    position = winSize * random_range(0.2, 0.8);
    velocity = glm::vec2(random_range(-80.0, 80.0), random_range(-80.0, 80.0));
}

float Laser::getRadius() const {
    return radius;
}

void Laser::update(float deltaTime) {
    position += velocity * deltaTime;
}

void Laser::onCollision(std::shared_ptr<GameObject> other) {

}

void Laser::setRadius(float radius) {
    Laser::radius = radius;
}
