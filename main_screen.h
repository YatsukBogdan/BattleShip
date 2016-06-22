#ifndef MAIN_SCREEN_IN_GAME
#define MAIN_SCREEN_IN_GAME

#include "SFML\Graphics.hpp"
#include "screen.h"
#include "button.h"

class MainScreen : public Screen {
private:
    RectangleShape background;
    Button *play;
    Button *options;
    Button *quit;
public:
    MainScreen();
    void act(RenderWindow &window);
    void draw(RenderWindow &window);
};

#endif
