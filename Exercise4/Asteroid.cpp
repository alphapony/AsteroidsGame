//
// Created by Morten Nobel-Jørgensen on 19/09/2017.
//

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include "Asteroid.hpp"
#include "sre/Renderer.hpp"

Asteroid::Asteroid(const sre::Sprite& sprite) : GameObject(sprite) {
    scale = glm::vec2(0.5f, 0.5f);
    winSize = sre::Renderer::instance->getDrawableSize();
    radius = 23;
    position = winSize * 0.5f;
    velocity = glm::vec2(0.0f, 0.0f);
}

float Asteroid::getRadius() const {
    return radius;
}

void Asteroid::onCollision(std::shared_ptr<GameObject> other) {

}

void Asteroid::setRadius(float radius) {
    Asteroid::radius = radius;
}
