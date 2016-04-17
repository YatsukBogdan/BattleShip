#ifndef SCREEN
#define SCREEN

#include "SFML/Graphics.hpp"

class Screen{
public:
    virtual void act(sf::RenderWindow &window);
};

#endif // SCREEN

