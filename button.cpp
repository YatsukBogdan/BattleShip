#include "button.h"

Button::Button(double x, double y, double width, double height, String text){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    baseColor.r = 41;
    baseColor.g = 128;
    baseColor.b = 185;

    hoverColor.r = 52;
    hoverColor.g = 152;
    hoverColor.b = 219;

    this->shape.setPosition(x,y);
    this->shape.setSize(Vector2f(width, height));
    this->shape.setFillColor(baseColor);

    font.loadFromFile("C:/Users/Bubenyushka/Documents/CourseWork/century_gothic_bold.ttf");

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(height * 0.5);
    this->text.setPosition(Vector2f(x + width * 0.1, y + height * 0.25));
    this->text.setColor(Color::White);
}

bool Button::isPressed(){
    if (Mouse::isButtonPressed(Mouse::Left))
        if (isHovered())
            return true;
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
    this->shape.setFillColor(hoverColor);
}

void Button::activateNormalState(){
    this->shape.setFillColor(baseColor);
}

void Button::act(RenderWindow &window){
    this->draw(window);
    if (this->isHovered())
        this->activateHover();
    else this->activateNormalState();
}
