#include "game_vs_computer_screen.h"
#include "current_screen.h"
#include "time.h"
#include "screen_cache_global.h"

GameVsComputerScreen::GameVsComputerScreen(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    background.setPosition(0, 0);
    background.setSize(Vector2f(width, height));
    background.setFillColor(Color(52, 73, 94));

    background_try_again.setPosition(0, 0);
    background_try_again.setSize(Vector2f(width, height));
    background_try_again.setFillColor(Color(0, 0, 0, 150));

    double button_width = width * 0.3;
    double button_height = height * 0.2;

    exit = new Button(0.9 * width, 0.04 * height, 0.05 * width, 0.05 * height, "Exit");
    try_again = new Button(width * 0.15, height * 0.4, button_width, button_height, "AGAIN");
    no = new Button(width * 0.55, height * 0.4, button_width, button_height, "LEAVE");

    gui = new GameGUI();

    timer_reset = true;
}

void GameVsComputerScreen::act(RenderWindow &window){
    window.draw(background);

    exit->act(window);

    if (gui->isGameOvered()){
        if (timer_reset){
            try_again_timer.restart();
            timer_reset = false;
        }
        gui->draw(window);
        if (try_again_timer.getElapsedTime().asSeconds() > 2){

            window.draw(background_try_again);

            try_again->act(window);
            if (try_again->isClicked()){
                gui->restart();
                timer_reset = true;

            }

            no->act(window);
            if (no->isClicked())
                current_screen = cache->getScreen("main");
        }
    }
    else gui->act(window);

    if (exit->isClicked())
        current_screen = cache->getScreen("play");
}
