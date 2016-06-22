#ifndef OPTIONS_SCREEN
#define OPTIONS_SCREEN

#include "SFML\Graphics.hpp"
#include "screen.h"
#include "button.h"

class OptionsScreen : public Screen {
private:
    RectangleShape background;
    Button *back;
public:
    OptionsScreen();
    void act(RenderWindow &window);
};

#endif // OPTIONS_SCREEN

