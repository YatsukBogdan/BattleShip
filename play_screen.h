#ifndef PLAY_SCREEN
#define PLAY_SCREEN

#include "SFML\Graphics.hpp"
#include "screen.h"
#include "button.h"

class PlayScreen : public Screen{
private:
    RectangleShape background;
    Button *one_vs_one;
    Button *vs_ai;
    Button *back;
public:
    PlayScreen();
    void act(RenderWindow &window);
};

#endif // PLAY_SCREEN

