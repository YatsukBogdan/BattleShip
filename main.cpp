#include "SFML/Graphics.hpp"
#include "button.h"
#include "main_screen.h"
#include "act_screen.h"

using namespace sf;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode::getDesktopMode()/*VideoMode(800, 600)*/, "BattleShip", Style::Fullscreen, settings);

    Screen* current_screen = new MainScreen();

	while (window.isOpen())
	{
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
				window.close();
		}

        window.clear(Color(52, 73, 94));

        current_screen->act(window);

        window.display();
    }

    return 0;
}
