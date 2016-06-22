#ifndef ERROR_CELL
#define ERROR_CELL

#include "cell_state.h"

class ErrorCell : public CellState{
    void draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // ERROR_CELL

