#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "Aircraft.h"
class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    ResourceHolder<sf::Texture, Textures::ID> textures;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
};


#endif // GAME_H_INCLUDED
