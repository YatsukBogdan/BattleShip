#ifndef SHIP
#define SHIP

#include "ship_cell.h"

class Ship {
private:
    int head_x;
    int head_y;

    bool vertical;

    int size;

    void isPressed(Mouse::Button button);

    bool pressed;
    bool released;
public:
    Ship(int size, double board_x, double board_y, double board_width);

    ShipCell *cells[4];
    int getSize();
    int getHeadX();
    int getHeadY();
    bool getVertical();
    void act(RenderWindow &window);

    void resizeShip(double board_x, double board_y, double board_width);

    Ship *clone();
    bool isAlive();
    void moveTo(int x, int y);
    void rotate();
    void activateError();
    bool isHovered();
    bool isClicked(Mouse::Button button);
};

#endif // SHIP
