#include "shoot.h"

bool Shoot::shoot(){
    if (shooter != NULL){
        return shooter->shootBoard();
    }
    else return false;
}

void Shoot::setShooter(Field *shooter){
    this->shooter = shooter;
}
