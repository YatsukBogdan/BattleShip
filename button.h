#ifndef BUTTON
#define BUTTON

#include "SFML/Graphics.hpp"

using namespace sf;

class Button{

private:
    Font font;
    Text text;

    Color baseColor;
    Color hoverColor;

    double x;
    double y;
    double width;
    double height;
    RectangleShape shape;

public:
    Button(double x, double y, double width, double height, String text);
    bool isPressed();
    bool isHovered();
    void updateRectangle();
    void activateHover();
    void activateNormalState();
    void draw(RenderWindow &window);
    void act(RenderWindow &window);
};

#endif // BUTTON

