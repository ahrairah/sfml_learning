#ifndef SPRITENODE_H_INCLUDED
#define SPRITENODE_H_INCLUDED
#include "SceneNode.h"


class SpriteNode : public SceneNode
{
public:
    explicit SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Sprite mSprite;
};

#endif // SPRITENODE_H_INCLUDED
