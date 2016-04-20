#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED
#include "Entity.h"
#include "ResourceHolder.h"

class Aircraft : public Entity
{
public:
    enum Type
    {
        Eagle,
        Raptor
    };
public:
    explicit Aircraft(Type type, const TextureHolder& textures);
private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    Type mType;
    sf::Sprite mSprite;
};

#endif // AIRCRAFT_H_INCLUDED
