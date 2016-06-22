#include "game_gui.h"

GameGUI::GameGUI(){
    battlefield = new Battlefield();

    place_your_ships = new Banner("Place your ships.");
    you_win = new Banner("You Win!");
    you_loose = new Banner("You Loose.");

    show_winner = false;
}

void GameGUI::act(RenderWindow &window){
    if (battlefield->isAllShipsPlaced()){
        battlefield->game(window);
        if (battlefield->isGameOvered()){
            show_winner = true;
        }
    }
    else battlefield->placing_ships(window);
}

bool GameGUI::isGameOvered(){
    return battlefield->isGameOvered();
}

void GameGUI::restart(){
    battlefield->reset();
}

void GameGUI::draw(RenderWindow &window){
    battlefield->draw(window);
    if (show_winner){
        if (battlefield->isUserWin()){
            you_win->activate();
            you_win->act(window);
        }
        else {
            you_loose->activate();
            you_loose->act(window);
        }
    }
}
