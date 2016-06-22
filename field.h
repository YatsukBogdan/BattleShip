#ifndef FIELD
#define FIELD

#include "SFML/Graphics.hpp"
#include "ship.h"
#include "banner.h"
#include "board_cell.h"
#include "shoot_field_interface.h"
#include <vector>

using namespace sf;
using namespace std;

class Field{
protected:

    Ship *ships[10];
    Banner *wrong_ship_placement;

    BoardCell *board_cells[10][10];

    int field_array[10][10];

    int mouse_x_board;
    int mouse_y_board;

    Ship *current_ship;
    int current_ship_index;
    bool allShipsPlaced;

    RectangleShape background;
public:
    Field();
    virtual void act(RenderWindow &window);
    virtual void fill();

    double getX();
    double getY();
    double getWidth();
    double getHeight();

    bool isLoose();
    void setMissedSquare(Ship *ship);
    bool addShipToArray(Ship *ship);
    bool checkNearbyCells(int x, int y);

    bool virtual shootBoard();
    bool virtual isAllShipsPlaced();
    void virtual act_game(RenderWindow &window);
    void virtual draw(RenderWindow &window);
    void reset_field();
    void virtual reset();
    void updateMouse();
};

#endif // FIELD

