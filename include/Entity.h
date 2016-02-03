#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <SFML/Graphics.hpp>

class Entity
{
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;
private:
    sf::Vector2f mVelocity;
};

#endif // ENTITY_H_INCLUDED
