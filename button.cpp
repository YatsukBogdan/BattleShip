#include "button.h"
#include "stdio.h"

Button::Button(double x, double y, double width, double height, String text){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    base.r = 41;
    base.g = 128;
    base.b = 185;

    hover.r = 52;
    hover.g = 152;
    hover.b = 219;

    this->shape.setPosition(x,y);
    this->shape.setSize(Vector2f(width, height));
    this->shape.setFillColor(base);

    font.loadFromFile("D:/CourseWork/century_gothic_bold.ttf");

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(height * 0.5);
    this->text.setPosition(Vector2f(x + width * 0.1, y + height * 0.25));
    this->text.setColor(Color::White);

    released = true;
}

void Button::isPressed(){
    if (isHovered())
        if (Mouse::isButtonPressed(Mouse::Left)){
            released = false;
            pressed = true;
            return;
        }
    released = true;
    pressed = false;
}

bool Button::isClicked(){
    isPressed();
    while(pressed){
        isPressed();
        if (released)
            return true;
    }
    return false;
}

bool Button::isHovered(){
    double m_x = Mouse::getPosition().x;
    double m_y = Mouse::getPosition().y;
    if (m_x > x && m_x < x + width && m_y > y && m_y < y + height)
        return true;
    return false;
}

void Button::updateRectangle(){
    shape.setPosition(x, y);
    shape.setSize(Vector2f(width, height));
}

void Button::draw(RenderWindow &window){
    window.draw(shape);
    window.draw(text);
}

void Button::activateHover(){
    shape.setFillColor(hover);
}

void Button::activateNormalState(){
    shape.setFillColor(base);
}

void Button::act(RenderWindow &window){
    draw(window);
    if (isHovered())
        activateHover();
    else activateNormalState();
}
