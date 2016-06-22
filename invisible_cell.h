#ifndef INVISIBLE_CELL
#define INVISIBLE_CELL

#include "cell_state.h"

class InvisibleCell : public CellState{
public:
    void draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // INVISIBLE_CELL

