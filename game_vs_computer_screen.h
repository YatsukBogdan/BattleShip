#ifndef GAME_VS_COMPUTER_SCREEN
#define GAME_VS_COMPUTER_SCREEN

#include "SFML\Graphics.hpp"
#include "screen.h"
#include "button.h"
#include "battlefield.h"
#include "game_gui.h"

class GameVsComputerScreen : public Screen{
private:
    RectangleShape background;
    RectangleShape background_try_again;
    GameGUI *gui;

    Button *exit;
    Button *try_again;
    Button *no;

    Clock try_again_timer;
    bool timer_reset;
public:
    GameVsComputerScreen();
    void act(RenderWindow &window);
};

#endif // GAME_VS_COMPUTER_SCREEN

