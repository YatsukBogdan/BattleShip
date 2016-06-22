#include "alive_cell_hover.h"

void AliveCellHover::draw(sf::RenderWindow &window, sf::RectangleShape shape){
    shape.setFillColor(sf::Color(209, 215, 219));
    window.draw(shape);
}
