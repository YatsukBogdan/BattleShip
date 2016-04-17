#include "main_screen.h"

MainScreen::MainScreen(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;
    double button_width = width * 0.4;
    double button_height = height * 0.2;
    play = new Button(width * 0.1, height * 0.1, button_width, button_height, "Play");
    options = new Button(width * 0.1, height * 0.4, button_width, button_height, "Options");
    quit = new Button(width * 0.1, height * 0.7, button_width, button_height, "Quit");
}

void MainScreen::act(RenderWindow &window){
    play->act(window);
    options->act(window);
    quit->act(window);

    if (quit->isPressed())
        window.close();
}
