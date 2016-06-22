#ifndef SCREEN_CACHE
#define SCREEN_CACHE

#include "screen.h"
#include "main_screen.h"
#include "exit_screen.h"
#include "play_screen.h"
#include "options_screen.h"
#include "game_vs_computer_screen.h"
#include "map"

using namespace std;

class ScreenCache{
    MainScreen* main_screen_cache;
    ExitScreen* exit_screen_cache;
    PlayScreen* play_screen_cache;
    OptionsScreen* options_screen_cache;
    GameVsComputerScreen* game_vs_computer_screen_cache;
public:
    ScreenCache();
    Screen* getScreen(string screen);
    void loadChache();
};

#endif // SCREEN_CACHE
