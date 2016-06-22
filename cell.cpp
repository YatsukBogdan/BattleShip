#include "cell.h"

Cell::Cell(int x, int y, double board_x, double board_y, double board_width){
    this->x = x;
    this->y = y;

    this->board_x = board_x;
    this->board_y = board_y;
    this->board_width = board_width;

    x_screen = board_x + board_width * (0.1 * x + 0.005);
    y_screen = board_y + board_width * (0.1 * y + 0.005);
    width_screen = height_screen = board_width * 0.09;


    error_color.r = 231;
    error_color.g = 76;
    error_color.b = 60;

    fog.r = 127;
    fog.g = 140;
    fog.b = 141;

    this->shape.setPosition(x_screen, y_screen);
    this->shape.setSize(Vector2f(width_screen, height_screen));
    released = true;
    pressed = false;

    error = false;
}

void Cell::isPressed(){
    if (isHovered())
        if (Mouse::isButtonPressed(Mouse::Left)){
            released = false;
            pressed = true;
            return;
        }
    released = true;
    pressed = false;
}

bool Cell::isClicked(){
    isPressed();
    while(pressed){
        isPressed();
        if (released)
            return true;
    }
    return false;
}

bool Cell::isHovered(){
    double m_x = Mouse::getPosition().x;
    double m_y = Mouse::getPosition().y;
    if (m_x > x_screen && m_x < x_screen + width_screen && m_y > y_screen && m_y < y_screen + height_screen)
        return true;
    return false;
}

int Cell::getX(){
    return x;
}

int Cell::getY(){
    return y;
}

void Cell::draw(RenderWindow &window){
    window.draw(shape);
}

void Cell::activateHover(){}

void Cell::activateNormalState(){}

void Cell::activateError(){
    error_timer.restart();
    error = true;
}

void Cell::act(RenderWindow &window){}


void Cell::resizeCell(double board_x, double board_y, double board_width){
    x_screen = board_x + board_width * (0.1 * x + 0.005);
    y_screen = board_y + board_width * (0.1 * y + 0.005);
    width_screen = height_screen = board_width * 0.09;

    this->shape.setPosition(x_screen, y_screen);
    this->shape.setSize(Vector2f(width_screen, height_screen));
}


void Cell::updateShape(){
    this->shape.setPosition(x_screen, y_screen);
}
