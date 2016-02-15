#ifndef SCENENODE_H_INCLUDED
#define SCENENODE_H_INCLUDED
#include <memory>
#include <vector>
#include <assert.h>
#include <algorithm>
class SceneNode
{

public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};


#endif // SCENENODE_H_INCLUDED
