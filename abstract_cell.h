#ifndef ABSTRACT_CELL
#define ABSTRACT_CELL

#include "SFML/Graphics.hpp"

using namespace sf;

class AbstractCell{
protected:
    RectangleShape shape;

    Color error_color;

    Color fog;

    void isPressed();
    bool pressed;
    bool released;

    bool error;

    Clock error_timer;
public:
    AbstractCell();
    bool isClicked();
    bool isHovered();

    int getX();
    int getY();

    void draw(RenderWindow &window);
    virtual void activateHover();
    virtual void activateNormalState();
    void activateError();
    void virtual act(RenderWindow &window);

    virtual void updateShape();
    virtual void resizeCell();
};

#endif // ABSTRACT_CELL

