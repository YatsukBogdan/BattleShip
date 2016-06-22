#include "options_screen.h"
#include "current_screen.h"
#include "screen_cache_global.h"

OptionsScreen::OptionsScreen(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    background.setPosition(0,0);
    background.setSize(Vector2f(width, height));
    background.setFillColor(Color(52, 73, 94));

    back = new Button(width * 0.1, height * 0.1, width * 0.8, height * 0.8, "Back");
}

void OptionsScreen::act(RenderWindow &window){
    window.draw(background);

    back->act(window);

    if (back->isClicked())
        current_screen = cache->getScreen("main");
}
