#include "dead_cell_hover.h"

void DeadCellHover::draw(sf::RenderWindow &window, sf::RectangleShape shape){
    shape.setFillColor(sf::Color(251, 96, 80));
    window.draw(shape);
}
