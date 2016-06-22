#include "invisible_cell.h"

void InvisibleCell::draw(sf::RenderWindow &window, sf::RectangleShape shape){
    shape.setFillColor(sf::Color::Transparent);
    window.draw(shape);
}
