#ifndef EXIT_SCREEN
#define EXIT_SCREEN

#include "SFML\Graphics.hpp"
#include "screen.h"
#include "button.h"

class ExitScreen : public Screen {
private:
    RectangleShape background;

    Font font;
    Text are_you_sure;
    Button *yes;
    Button *no;
public:
    ExitScreen();
    void act(RenderWindow &window);
};

#endif // EXIT_SCREEN

