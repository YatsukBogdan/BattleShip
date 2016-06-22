#include "battlefield.h"
#include "time.h"
#include "field_creator.h"

Battlefield::Battlefield(){
    srand(time(0));

    FieldCreator *fieldCreator = new FieldCreator();

    yourField = fieldCreator->FactoryMethod(1);
    enemyField = fieldCreator->FactoryMethod(2);

    game_over = false;

    rand() % 2 ? current_player = yourField : current_player = enemyField;

    shootField = new Shoot();

    shootField->setShooter(current_player);
}

void Battlefield::placing_ships(RenderWindow &window){
    yourField->act(window);
}

void Battlefield::game(RenderWindow &window){
    yourField->act_game(window);
    enemyField->act(window);

    shootField->setShooter(current_player);

    if (shootField->shoot())
        changePlayer();
    if (current_player->isLoose())
        game_over = true;
}

bool Battlefield::isAllShipsPlaced(){
    return yourField->isAllShipsPlaced();
}

void Battlefield::changePlayer(){
    if (current_player == yourField)
        current_player = enemyField;
    else current_player = yourField;
}

bool Battlefield::isGameOvered(){
    return game_over;
}

void Battlefield::reset(){
    srand(time(0));

    yourField->reset();
    enemyField->reset();

    game_over = false;

    rand() % 2 ? current_player = yourField : current_player = enemyField;
}

bool Battlefield::isUserWin(){
    if (enemyField->isLoose())
        return true;
    return false;
}

void Battlefield::draw(RenderWindow &window){
    yourField->draw(window);
    enemyField->draw(window);
}

