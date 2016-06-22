#include "ship_cell.h"

ShipCell::ShipCell(int x, int y, double board_x, double board_y, double board_width) : Cell(x, y, board_x, board_y, board_width){
    deadBaseState = new DeadCellBase();
    deadHoverState = new DeadCellHover();
    aliveBaseState = new AliveCellBase();
    aliveHoverState = new AliveCellHover();
    errorState = new ErrorCell();

    invisibleState = new InvisibleCell();

    visible = true;

    alive = true;

    activateNormalState();
}

void ShipCell::moveTo(int x, int y){
    this->x = x;
    this->y = y;
    x_screen = board_x + board_width * (0.1 * x + 0.005);
    y_screen = board_y + board_width * (0.1 * y + 0.005);
    updateShape();
}

bool ShipCell::canBeMoved(int x, int y){
    if (x < 0 || x > 9 || y < 0 || y > 9)
        return false;
    else return true;
}

bool ShipCell::isAlive(){
    return alive;
}

void ShipCell::kill(){
    alive = false;
}

void ShipCell::setInvisible(){
    visible = false;
}

void ShipCell::setVisible(){
    visible = true;
}

void ShipCell::activateHover(){
    if (!visible){
        currentState = invisibleState;
        return;
    }
    if (error){
        currentState = errorState;
        return;
    }
    if (alive)
        currentState = aliveHoverState;
    else currentState = deadHoverState;
}

void ShipCell::activateNormalState(){
    if (!visible){
        currentState = invisibleState;
        return;
    }
    if (error){
        currentState = errorState;
        return;
    }
    if (alive)
        currentState = aliveBaseState;
    else currentState = deadBaseState;
}

void ShipCell::act(RenderWindow &window){
    currentState->draw(window, shape);
    if (error_timer.getElapsedTime().asSeconds() > 1){
        error = false;
    }
    if (isHovered())
        activateHover();
    else activateNormalState();
}
