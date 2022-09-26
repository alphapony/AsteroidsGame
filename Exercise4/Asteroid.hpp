#pragma once
#include "GameObject.hpp"
#include "Collidable.hpp"

class Asteroid : public GameObject, public Collidable {
public:
    Asteroid(const sre::Sprite& sprite);
    float getRadius() const;
    void onCollision(std::shared_ptr<GameObject> other) override;
    void setRadius(float radius);
    glm::vec2 velocity;

private:
    glm::vec2 winSize;

protected:
    float radius = 0;
};


