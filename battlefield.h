#ifndef BATTLEFIELD
#define BATTLEFIELD

#include "current_player_turn.h"
#include "shoot.h"

class Battlefield {
private:
    Field *current_player;

    Field *yourField;
    Field *enemyField;

    Shoot *shootField;

    bool game_over;
public:
    Battlefield();
    bool isAllShipsPlaced();

    void draw(RenderWindow &window);

    bool isUserWin();
    void reset();
    bool isGameOvered();
    void changePlayer();
    void placing_ships(RenderWindow &window);
    void game(RenderWindow &window);
};

#endif // BATTLEFIELD

