#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED
#include <memory>
#include <assert.h>
#include <map>
namespace Textures
{
enum ID {Eagle, Raptor};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier, const std::string& filename);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
    template<typename Parameter>
    void load(Identifier id, const std::string filename, const Parameter& secondParam);
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
#include "ResourceHolder.inl"
#endif // RESOURCEHOLDER_H_INCLUDED
