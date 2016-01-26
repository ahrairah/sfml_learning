#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED
#include <memory>
#include "Game.h"

class TextureHolder
{
private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
    void load(Textures::ID id, const std::string& filename);
};

#endif // RESOURCEHOLDER_H_INCLUDED
