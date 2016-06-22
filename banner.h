#ifndef BANNER
#define BANNER

#include "SFML/Graphics.hpp"

using namespace sf;

class Banner{
private:
    double x;
    double y;
    double width;
    double height;

    RectangleShape background;

    Text text;
    Font font;

    Clock show_timer;
    bool show;
public:
    Banner(String text);
    void draw(RenderWindow &window);
    void act(RenderWindow &window);

    void activate();

};

#endif // BANNER

