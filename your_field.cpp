#include "your_field.h"
#include "time.h"

YourField::YourField(){}

void YourField::reset(){
    reset_field();
}

bool YourField::shootBoard(){
    srand(time(0));
    while (true){
        int x = rand() % 10;
        int y = rand() % 10;
        for (int i = 0; i < 10; i++){
            for(int j = 0; j < ships[i]->getSize(); j++){
                if (ships[i]->cells[j]->getX() == x && ships[i]->cells[j]->getY() == y && ships[i]->cells[j]->isAlive()){
                    ships[i]->cells[j]->kill();
                    if (!ships[i]->isAlive())
                        setMissedSquare(ships[i]);
                    return false;
                }
            }
        }
        if (!board_cells[x][y]->isMissed()){
            board_cells[x][y]->setMissed();
            return true;
        }
    }
}

void YourField::fill(){
    current_ship->moveTo(mouse_x_board, mouse_y_board);
    if (current_ship->isClicked(Mouse::Left)){
        if (addShipToArray(current_ship)){
            current_ship_index++;
            if (current_ship_index == 10) {
                allShipsPlaced = true;
                resizeBoard();
                return;
            }
            current_ship = ships[current_ship_index];
        }
    }
    if (current_ship->isClicked(Mouse::Right)){
        current_ship->rotate();
    }
}

void YourField::draw(RenderWindow &window){
    window.draw(background);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            board_cells[i][j]->act(window);
        }
    }
    for (int i = 0; i < 10; i++){
        ships[i]->act(window);
    }
}

void YourField::resizeBoard(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    double background_width = 0.45 * width;
    double background_height = 0.45 * width;

    double background_x = 0.025 * width;
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

bool YourField::isAllShipsPlaced(){
    return allShipsPlaced;
}

void YourField::act(RenderWindow &window){
    draw(window);

    updateMouse();
    wrong_ship_placement->act(window);
    fill();
}

void YourField::act_game(RenderWindow &window){
    updateMouse();
    draw(window);
}
