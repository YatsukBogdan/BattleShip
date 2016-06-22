#include "error_cell.h"

void ErrorCell::draw(sf::RenderWindow &window, sf::RectangleShape shape){
    shape.setFillColor(sf::Color(192, 57, 43));
    window.draw(shape);
}
