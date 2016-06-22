#include "main_screen.h"
#include "current_screen.h"
#include "screen_cache_global.h"

MainScreen::MainScreen(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    background.setPosition(0,0);
    background.setSize(Vector2f(width, height));
    background.setFillColor(Color(52, 73, 94));

    double button_width = width * 0.4;
    double button_height = height * 0.2;

    play = new Button(width * 0.1, height * 0.1, button_width, button_height, "Play");
    options = new Button(width * 0.1, height * 0.4, button_width, button_height, "Options");
    quit = new Button(width * 0.1, height * 0.7, button_width, button_height, "Quit");
}

void MainScreen::act(RenderWindow &window){
    window.draw(background);

    play->act(window);
    options->act(window);
    quit->act(window);

    if (play->isClicked())
        current_screen = cache->getScreen("play");
    if (options->isClicked())
        current_screen = cache->getScreen("options");
    if (quit->isClicked())
        current_screen = cache->getScreen("exit");
}

void MainScreen::draw(RenderWindow &window){
    window.draw(background);

    play->draw(window);
    options->draw(window);
    quit->draw(window);
}
