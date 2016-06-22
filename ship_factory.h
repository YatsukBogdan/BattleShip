#ifndef SHIP_FACTORY
#define SHIP_FACTORY

#include "ship_4_cells.h"
#include "ship_3_cells.h"
#include "ship_2_cells.h"
#include "ship_1_cell.h"
#include "map"

using namespace std;

class ShipFactory {
public:
    Ship *getShip(int size, double board_x, double board_y, double board_width);
};

#endif // SHIP_FACTORY

