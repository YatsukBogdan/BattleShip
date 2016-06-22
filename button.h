#ifndef BUTTON
#define BUTTON

#include "SFML/Graphics.hpp"

using namespace sf;

class Button{

private:
    Font font;
    Text text;

    Color base;
    Color hover;

    double x;
    double y;
    double width;
    double height;
    RectangleShape shape;

    void isPressed();
    bool pressed;
    bool released;

public:
    Button(double x, double y, double width, double height, String text);
    bool isClicked();
    bool isReleased();
    bool isHovered();
    void updateRectangle();
    void activateHover();
    void activateNormalState();
    void draw(RenderWindow &window);
    void act(RenderWindow &window);
};

#endif // BUTTON

