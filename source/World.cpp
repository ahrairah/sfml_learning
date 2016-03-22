#include "../include/World.h"

World::World(sf::RenderWindow& window):
    mWindow(window),
    mWorldView(window.getDefaultView()),
    mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
    mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
{
    loadTextures();
    buildScene();
    mWorldView.setCenter(mSpawnPosition);
}
