#include "banner.h"

Banner::Banner(String text){
    double screen_height = VideoMode::getDesktopMode().height;
    double screen_width = VideoMode::getDesktopMode().width;

    x = 0.125 * screen_width;
    y = 0.666 * screen_height;

    width = 0.75 * screen_width;
    height = 0.222 * screen_height;

    this->background.setPosition(x, y);
    this->background.setSize(Vector2f(width, height));
    this->background.setFillColor(Color(0, 0, 0, 150));

    font.loadFromFile("D:/CourseWork/century_gothic_bold.ttf");

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(height * 0.3);
    this->text.setPosition(Vector2f(x + width * 0.1, y + height * 0.25));
    this->text.setColor(Color::White);

    show = false;
}

void Banner::draw(RenderWindow &window){
    window.draw(background);
    window.draw(text);
}

void Banner::act(RenderWindow &window){
    if (show && show_timer.getElapsedTime().asSeconds() < 1){
        this->draw(window);
    }
    else {
        show = false;
    }
}

void Banner::activate(){
    show_timer.restart();
    show = true;
}
