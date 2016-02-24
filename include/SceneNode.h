#ifndef SCENENODE_H_INCLUDED
#define SCENENODE_H_INCLUDED
#include <memory>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <SFML/Graphics.hpp>
class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{

enum Layer
{
    Background,
    Air,
    LayerCount
};

public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);

private:
    virtual void  draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};


#endif // SCENENODE_H_INCLUDED
