#ifndef ALIVE_CELL_HOVER
#define ALIVE_CELL_HOVER

#include "cell_state.h"

class AliveCellHover : public CellState{
public:
    void draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // ALIVE_CELL_HOVER

