#ifndef SCENENODE_H_INCLUDED
#define SCENENODE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <memory.h>

class SceneNode
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
public:
    SceneNode();
private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};
#endif // SCENENODE_H_INCLUDED
