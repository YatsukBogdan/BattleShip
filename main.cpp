#include "SFML/Graphics.hpp"
#include "button.h"
#include "current_screen.h"
#include "screen_cache_global.h"

Screen* current_screen;
ScreenCache* cache;

using namespace sf;

int main()
{

    RenderWindow window(VideoMode::getDesktopMode(), "BattleShip", Style::Fullscreen);

    cache = new ScreenCache();

    current_screen = cache->getScreen("main");

	while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::F12)
            {
                sf::Image screenshot = window.capture();
                screenshot.saveToFile("screenshot.png");
            }
        }

        current_screen->act(window);

        window.display();
    }

    return 0;
}
