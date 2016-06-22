#include "enemy_field.h"
#include "time.h"

EnemyField::EnemyField(){
    setShipsInvisible();
    resizeBoard();
    fill();
}

void EnemyField::reset(){
    reset_field();
    setShipsInvisible();
    resizeBoard();
    fill();
}

void EnemyField::fill(){
    srand(time(0));
    int size = 4;
    while (!allShipsPlaced){
        int x = rand() % 10;
        int y = rand() % (10 - size - 1);
        current_ship->moveTo(x, y);
        if (addShipToArray(current_ship)){
            current_ship_index++;
            if (current_ship_index >= 1)
                size = 3;
            else if (current_ship_index >= 3)
                size = 2;
            else if (current_ship_index >= 6)
                size = 1;
            if (current_ship_index == 10) {
                allShipsPlaced = true;
                resizeBoard();
                return;
            }
            current_ship = ships[current_ship_index];
        }
        else {
            x = rand() % (10 - size - 1);
            y = rand() % 10;
            current_ship->moveTo(x, y);
            current_ship->rotate();
            if (addShipToArray(current_ship)){
                current_ship_index++;
                if (current_ship_index >= 1)
                    size = 3;
                else if (current_ship_index >= 3)
                    size = 2;
                else if (current_ship_index >= 6)
                    size = 1;
                if (current_ship_index == 10) {
                    allShipsPlaced = true;
                    resizeBoard();
                    return;
                }
                current_ship = ships[current_ship_index];
            }
        }
    }
}

void EnemyField::act(RenderWindow &window){
    updateMouse();
    draw(window);
}

void EnemyField::draw(RenderWindow &window){
    window.draw(background);
    for (int i = 0; i < 10 ; i++){
        for (int j = 0 ; j < 10; j++){
            board_cells[i][j]->act(window);
        }
    }
    for (int i = 0; i < 10 ; i++){
        ships[i]->act(window);
    }
}

bool EnemyField::shootBoard(){
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < ships[i]->getSize(); j++){
            if (ships[i]->cells[j]->isClicked() && ships[i]->cells[j]->isAlive()){
                ships[i]->cells[j]->kill();
                ships[i]->cells[j]->setVisible();
                if (!ships[i]->isAlive())
                    setMissedSquare(ships[i]);
                return false;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (board_cells[i][j]->isClicked() && !board_cells[i][j]->isMissed()){
                board_cells[i][j]->setMissed();
                return true;
            }
        }
    }
    return false;
}

void EnemyField::setShipsInvisible(){
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < ships[i]->getSize(); j++){
            ships[i]->cells[j]->setInvisible();
        }
    }
}

void EnemyField::resizeBoard(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    double background_width = 0.45 * width;
    double background_height = 0.45 * width;

    double background_x = 0.525 * width;
    double background_y = height/2 - background_width/2;

    background.setPosition(background_x, background_y);
    background.setSize(Vector2f(background_width, background_height));
    background.setFillColor(Color(41, 128, 185));

    for (int i = 0; i < 10; i++){
        ships[i]->resizeShip(background_x, background_y, background_width);
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            board_cells[i][j]->resizeCell(getX(), getY(), getWidth());
        }
    }
}
