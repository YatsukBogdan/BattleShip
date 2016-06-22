#ifndef DEAD_CELL_HOVER
#define DEAD_CELL_HOVER
#include "cell_state.h"

class DeadCellHover : public CellState{
public:
    void draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // DEAD_CELL_HOVER

