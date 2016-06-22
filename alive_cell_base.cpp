#include "alive_cell_base.h"

void AliveCellBase::draw(sf::RenderWindow &window, sf::RectangleShape shape){
    shape.setFillColor(sf::Color(189, 195, 199));
    window.draw(shape);
}
