#include "board_cell.h"

BoardCell::BoardCell(int x, int y, double board_x, double board_y, double board_width) : Cell(x, y, board_x, board_y, board_width){
    base.r = 52;
    base.g = 152;
    base.b = 219;

    hover.r = 72;
    hover.g = 172;
    hover.b = 239;

    miss_base.r = 127;
    miss_base.g = 140;
    miss_base.b = 141;

    miss_hover.r = 147;
    miss_hover.g = 160;
    miss_hover.b = 161;

    missed = false;
}

void BoardCell::activateHover(){
    if (missed)
        shape.setFillColor(miss_hover);
    else shape.setFillColor(hover);
}

void BoardCell::setMissed(){
    missed = true;
}

bool BoardCell::isMissed(){
    return missed;
}

void BoardCell::activateNormalState(){
    if (missed)
        shape.setFillColor(miss_base);
    else shape.setFillColor(base);
}

void BoardCell::act(RenderWindow &window){
    draw(window);
    if (isHovered())
        activateHover();
    else activateNormalState();
}
