#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Aircraft : public Entity
{
public:
    enum Type
    {
        Eagle,
        Raptor
    };
public:
    explicit Aircraft(Type type);

private:
    Type mType;
};

#endif // AIRCRAFT_H_INCLUDED
