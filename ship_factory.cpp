#include "ship_factory.h"

Ship *ShipFactory::getShip(int size, double board_x, double board_y, double board_width){
    switch(size){
        case 4:
            return new Ship(4, board_x, board_y, board_width);
        case 3:
            return new Ship(3, board_x, board_y, board_width);
        case 2:
            return new Ship(2, board_x, board_y, board_width);
        case 1:
            return new Ship(1, board_x, board_y, board_width);
    }
}
