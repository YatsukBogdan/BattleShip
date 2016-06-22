#include "dead_cell_base.h"

void DeadCellBase::draw(sf::RenderWindow &window, sf::RectangleShape shape){
    shape.setFillColor(sf::Color(231, 76, 60));
    window.draw(shape);
}
