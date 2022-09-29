//
// Created by Morten Nobel-Jørgensen on 19/09/2017.
//

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include "Asteroid.hpp"
#include "sre/Renderer.hpp"
#include <random>

std::random_device rd;
std::default_random_engine eng(rd());

Asteroid::Asteroid(const sre::Sprite& sprite) : GameObject(sprite) {
    scale = glm::vec2(0.5f, 0.5f);
    winSize = sre::Renderer::instance->getDrawableSize();
    radius = 23;
    rotation = 0;
    std::uniform_real_distribution<float> distr(0.2, 0.8);
    position = winSize * distr(eng);

    velocity = glm::vec2(0.0f, 0.0f);
}

float Asteroid::getRadius() const {
    return radius;
}

void Asteroid::update(float deltaTime) {
    std::uniform_real_distribution<float> distr(0.0, 7.0);
    rotation += distr(eng);
}

void Asteroid::onCollision(std::shared_ptr<GameObject> other) {

}

void Asteroid::setRadius(float radius) {
    Asteroid::radius = radius;
}
