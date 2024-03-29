#include "../include/SceneNode.h"

SceneNode::SceneNode()
    :mChildren()
    ,mParent(nullptr)
{

}
void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) -> bool {return p.get() == &node;});
    assert(found != mChildren.end());
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrrent(target, states);
    for (const Ptr& child : mChildren)
    {
        child->draw(target, states);
    }
}

void SceneNode::drawCurrrent(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
    for(const Ptr& child : mChildren)
    {
        child->update(dt);
    }
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform tr = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->mParent)
    {
        tr = node->getTransform() * tr;
    }
    return tr;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}
