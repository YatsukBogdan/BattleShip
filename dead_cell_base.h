#ifndef DEAD_CELL
#define DEAD_CELL

#include "cell_state.h"

class DeadCellBase : public CellState{
public:
    void draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // DEAD_CELL

