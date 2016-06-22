#include "play_screen.h"
#include "game_vs_computer_screen.h"
#include "current_screen.h"
#include "screen_cache_global.h"

PlayScreen::PlayScreen(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    background.setPosition(0,0);
    background.setSize(Vector2f(width, height));
    background.setFillColor(Color(52, 73, 94));

    double button_width = width * 0.4;
    double button_height = height * 0.2;

    one_vs_one = new Button(width * 0.1, height * 0.1, button_width, button_height, "1 VS 1");
    vs_ai = new Button(width * 0.1, height * 0.4, button_width, button_height, "VS Comp");
    back = new Button(width * 0.8, height * 0.8, width * 0.1, height * 0.1, "Back");
}

void PlayScreen::act(RenderWindow &window){
    window.draw(background);

    one_vs_one->act(window);
    vs_ai->act(window);
    back->act(window);


    if (vs_ai->isClicked())
        current_screen = new GameVsComputerScreen();
    if (back->isClicked())
        current_screen = cache->getScreen("main");
}
