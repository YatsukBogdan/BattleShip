#include "ship.h"

Ship::Ship(int size, double board_x, double board_y, double board_width){
    head_x = -20;
    head_y = 0;

    this->size = size;
    vertical = true;

    for (int i = 0; i< size; i++){
        cells[i] = new ShipCell(head_x, head_y + i, board_x, board_y, board_width);
    }

    released = true;
    pressed = false;
}

void Ship::isPressed(Mouse::Button button){
    if (cells[0]->isHovered())
        if (Mouse::isButtonPressed(button)){
            released = false;
            pressed = true;
            return;
        }
    released = true;
    pressed = false;
}

bool Ship::isClicked(Mouse::Button button){
    isPressed(button);
    while(pressed){
        isPressed(button);
        if (released)
            return true;
    }
    return false;
}

bool Ship::isAlive(){
    for (int i = 0; i< size;i++){
        if(cells[i]->isAlive()) return true;
    }
    return false;
}

void Ship::moveTo(int x, int y){
    bool canBeMoved = true;
    for (int i = 0; i < size; i++){
        if (vertical){
            if (!cells[i]->canBeMoved(x, y + i)){
                canBeMoved = false;
                break;
            }
        }
        else {
            if (!cells[i]->canBeMoved(x + i, y)){
                canBeMoved = false;
                break;
            }
        }
    }
    if (canBeMoved){
        head_x = x;
        head_y = y;
        for (int i = 0; i < size; i++){
            vertical ? cells[i]->moveTo(x, y + i) : cells[i]->moveTo(x + i, y);
        }
    }
}

int Ship::getSize(){
    return size;
}

int Ship::getHeadX(){
    return head_x;
}

int Ship::getHeadY(){
    return head_y;
}
bool Ship::getVertical(){
    return vertical;
}

void Ship::activateError(){
    for (int i = 0; i < size; i++){
        cells[i]->activateError();
    }
}

void Ship::resizeShip(double board_x, double board_y, double board_width){
    for (int i = 0; i < size; i++){
        cells[i]->resizeCell(board_x, board_y, board_width);
    }
}

void Ship::rotate(){
    if (vertical && head_x + size  <= 10){
        for (int i = 1; i < size;i++){
            cells[i]->moveTo(head_x + i, head_y);
        }
        vertical = false;
    }
    else if (!vertical && head_y + size  <= 10){
        for (int i = 1; i < size;i++){
            cells[i]->moveTo(head_x, head_y + i);
        }
        vertical = true;
    }
}

void Ship::act(RenderWindow &window){
    for (int i = 0; i< size;i++){
        cells[i]->act(window);
    }
}

Ship *Ship::clone(){
    return new Ship(*this);
}
