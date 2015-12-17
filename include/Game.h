#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Event::key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
};


#endif // GAME_H_INCLUDED
