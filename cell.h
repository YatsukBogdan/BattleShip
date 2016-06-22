#ifndef CELL
#define CELL

#include "SFML/Graphics.hpp"

using namespace sf;

class Cell{
protected:
    int x;
    int y;
    double x_screen;
    double y_screen;
    double width_screen;
    double height_screen;

    double board_x;
    double board_y;
    double board_width;

    RectangleShape shape;

    Color error_color;

    Color fog;

    void isPressed();
    bool pressed;
    bool released;

    bool error;

    Clock error_timer;
public:
    Cell(int x, int y, double board_x, double board_y, double board_width);
    bool isClicked();
    bool isHovered();

    int getX();
    int getY();

    void draw(RenderWindow &window);
    virtual void activateHover();
    virtual void activateNormalState();
    void activateError();
    void virtual act(RenderWindow &window);

    void updateShape();
    void resizeCell(double board_x, double board_y, double board_width);
};

#endif // CELL

