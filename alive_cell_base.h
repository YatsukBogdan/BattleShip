#ifndef ALIVE_CELL_BASE
#define ALIVE_CELL_BASE

#include "cell_state.h"

class AliveCellBase : public CellState{
public:
    void draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // ALIVE_CELL_BASE

