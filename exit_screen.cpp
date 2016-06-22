#include "exit_screen.h"
#include "current_screen.h"
#include "screen_cache_global.h"
#include "main_screen.h"

ExitScreen::ExitScreen(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    background.setPosition(0,0);
    background.setSize(Vector2f(width, height));
    background.setFillColor(Color(0, 0, 0, 150));

    double button_width = width * 0.3;
    double button_height = height * 0.2;

    yes = new Button(width * 0.15, height * 0.4, button_width, button_height, "YES");
    no = new Button(width * 0.55, height * 0.4, button_width, button_height, "NO");
}

void ExitScreen::act(RenderWindow &window){
    MainScreen* main_back = (MainScreen*)cache->getScreen("main");
    main_back->draw(window);
    window.draw(background);

    yes->act(window);
    no->act(window);

    if (yes->isClicked())
        window.close();

    if (no->isClicked())
        current_screen = cache->getScreen("main");
}
