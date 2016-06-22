#ifndef CELL_STATE
#define CELL_STATE

#include "SFML/Graphics.hpp"

class CellState{
public:
    void virtual draw(sf::RenderWindow &window, sf::RectangleShape shape);
};

#endif // CELL_STATE

