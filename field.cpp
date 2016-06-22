#include "field.h"
#include "ship_factory.h"

Field::Field(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    double background_width = 0.9 * height;
    double background_height = 0.9 * height;

    double background_x = width/2 - background_width/2;
    double background_y = height/2 - background_width/2;

    background.setPosition(background_x, background_y);
    background.setSize(Vector2f(background_width, background_height));
    background.setFillColor(Color(41, 128, 185));


    int array[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0}};

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            field_array[i][j] = array[i][j];
        }
    }

    ShipFactory *shipFactory = new ShipFactory();

    ships[0] = shipFactory->getShip(4, getX(), getY(), getWidth());
    ships[1] = shipFactory->getShip(3, getX(), getY(), getWidth());
    ships[2] = shipFactory->getShip(3, getX(), getY(), getWidth());
    ships[3] = shipFactory->getShip(2, getX(), getY(), getWidth());
    ships[4] = shipFactory->getShip(2, getX(), getY(), getWidth());
    ships[5] = shipFactory->getShip(2, getX(), getY(), getWidth());
    ships[6] = shipFactory->getShip(1, getX(), getY(), getWidth());
    ships[7] = shipFactory->getShip(1, getX(), getY(), getWidth());
    ships[8] = shipFactory->getShip(1, getX(), getY(), getWidth());
    ships[9] = shipFactory->getShip(1, getX(), getY(), getWidth());

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            board_cells[i][j] = new BoardCell(i, j, getX(), getY(), getWidth());
        }
    }

    current_ship_index = 0;
    current_ship = ships[current_ship_index];

    allShipsPlaced = false;

    wrong_ship_placement = new Banner("You can't place ship there.");

}

void Field::reset_field(){
    double height = VideoMode::getDesktopMode().height;
    double width = VideoMode::getDesktopMode().width;

    double background_width = 0.9 * height;
    double background_height = 0.9 * height;

    double background_x = width/2 - background_width/2;
    double background_y = height/2 - background_width/2;

    background.setPosition(background_x, background_y);
    background.setSize(Vector2f(background_width, background_height));
    background.setFillColor(Color(41, 128, 185));


    int array[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0}};

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            field_array[i][j] = array[i][j];
        }
    }

    ShipFactory *shipFactory = new ShipFactory();

    ships[0] = shipFactory->getShip(4, getX(), getY(), getWidth());
    ships[1] = shipFactory->getShip(3, getX(), getY(), getWidth());
    ships[2] = shipFactory->getShip(3, getX(), getY(), getWidth());
    ships[3] = shipFactory->getShip(2, getX(), getY(), getWidth());
    ships[4] = shipFactory->getShip(2, getX(), getY(), getWidth());
    ships[5] = shipFactory->getShip(2, getX(), getY(), getWidth());
    ships[6] = shipFactory->getShip(1, getX(), getY(), getWidth());
    ships[7] = shipFactory->getShip(1, getX(), getY(), getWidth());
    ships[8] = shipFactory->getShip(1, getX(), getY(), getWidth());
    ships[9] = shipFactory->getShip(1, getX(), getY(), getWidth());

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            board_cells[i][j] = new BoardCell(i, j, getX(), getY(), getWidth());
        }
    }

    current_ship_index = 0;
    current_ship = ships[current_ship_index];

    allShipsPlaced = false;

    wrong_ship_placement = new Banner("You can't place ship there.");
}

void Field::act(RenderWindow &window){}
void Field::fill(){}

bool Field::addShipToArray(Ship *ship){
    int ship_size = ship->getSize();
    int ship_head_x = ship->getHeadX();
    int ship_head_y = ship->getHeadY();
    bool ship_vertical = ship->getVertical();

    bool placed = true;

    for (int i = 0; i < ship_size;i++){
        if (ship_vertical){
            if (checkNearbyCells(ship_head_x, ship_head_y + i)){
                field_array[ship_head_x][ship_head_y + i] = 2;
            }
            else {
                placed = false;
                break;
            }
        }
        else {
            if (checkNearbyCells(ship_head_x +i, ship_head_y)){
                field_array[ship_head_x + i][ship_head_y] = 2;
            }
            else {
                placed = false;
                break;
            }
        }
    }

    if (!placed){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (field_array[i][j] == 2) field_array[i][j] = 0;
            }
        }
        ship->activateError();
        wrong_ship_placement->activate();
    }
    else {
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (field_array[i][j] == 2) field_array[i][j] = 1;
            }
        }
    }

    return placed;
}

bool Field::checkNearbyCells(int x, int y){
    if (x != 0 && y != 0)
        if (field_array[x - 1][y - 1] == 1) return false;
    if (y != 0)
        if (field_array[x][y - 1] == 1) return false;
    if (x != 9 && y != 0)
        if (field_array[x + 1][y - 1] == 1) return false;
    if (x != 0)
        if (field_array[x - 1][y] == 1) return false;
    if (field_array[x][y] == 1) return false;
    if (x != 9)
        if (field_array[x + 1][y] == 1) return false;
    if (x != 0 && y != 9)
        if (field_array[x - 1][y + 1] == 1) return false;
    if (y != 9)
        if (field_array[x][y + 1] == 1) return false;
    if (x != 9 && y != 9)
        if (field_array[x + 1][y + 1] == 1) return false;
    return true;
}

void Field::setMissedSquare(Ship *ship){
    if (ship->getVertical()){
        for (int i = ship->getHeadX() - 1; i < ship->getHeadX() + 2 ; i++){
            for (int j = ship->getHeadY() - 1; j < ship->getHeadY() + ship->getSize() + 1 ; j++){
                if (i != -1 && j != -1 && i != 10 && j != 10){
                    board_cells[i][j]->setMissed();
                }
            }
        }
    }
    else {
        for (int i = ship->getHeadX() - 1; i < ship->getHeadX() + ship->getSize() + 1 ; i++){
            for (int j = ship->getHeadY() - 1; j < ship->getHeadY()  + 2 ; j++){
                if (i != -1 && j != -1 && i != 10 && j != 10){
                    board_cells[i][j]->setMissed();
                }
            }
        }
    }
}


void Field::act_game(RenderWindow &window){}

void Field::draw(RenderWindow &window){}

void Field::reset(){}

bool Field::isAllShipsPlaced(){}

bool Field::isLoose(){
    for (int i = 0; i < 10 ; i++){
        if (ships[i]->isAlive()) return false;
    }
    return true;
}

double Field::getX(){
    return background.getPosition().x;
}

double Field::getY(){
    return background.getPosition().y;
}

double Field::getWidth(){
    return background.getSize().x;
}

double Field::getHeight(){
    return background.getSize().y;
}

bool Field::shootBoard(){}

void Field::updateMouse(){
    mouse_x_board = (Mouse::getPosition().x - background.getPosition().x)/(background.getSize().x * 0.1);
    mouse_y_board = (Mouse::getPosition().y - background.getPosition().y)/(background.getSize().y * 0.1);
}
