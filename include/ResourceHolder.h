#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED
#include <memory>
namespace Textures
{
enum ID {Landscape, Airplane, Missile};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier, const std::string& filename);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};
#include "ResourceHolder.inl"
#endif // RESOURCEHOLDER_H_INCLUDED
