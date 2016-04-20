#ifndef SCENENODE_H_INCLUDED
#define SCENENODE_H_INCLUDED
#include <memory>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <vector>
#include <memory>
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
    void update(sf::Time dt);
    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;

private:
    virtual void  draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};


#endif // SCENENODE_H_INCLUDED
