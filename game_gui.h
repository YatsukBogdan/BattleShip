#ifndef GAME_GUI
#define GAME_GUI

#include "battlefield.h"

class GameGUI{
private:
    Battlefield *battlefield;

    Banner *place_your_ships;

    Banner *you_win;
    Banner *you_loose;

    bool show_winner;
    Clock close_timer;
public:
    GameGUI();

    void draw(RenderWindow &window);
    void restart();
    bool isGameOvered();
    void game();
    void act(RenderWindow &window);
};

#endif // GAME_GUI

