#include "screen.h"

void Screen::act(sf::RenderWindow &window){}

Screen *Screen::clone(){
    return new Screen(*this);
}
