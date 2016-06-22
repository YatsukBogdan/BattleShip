#include "screen_cache.h"

ScreenCache::ScreenCache(){
    loadChache();
}

Screen* ScreenCache::getScreen(string screen){
    if (screen.compare("main") == 0)
        return main_screen_cache;
    else if (screen.compare("exit") == 0)
        return exit_screen_cache;
    else if (screen.compare("play") == 0)
        return play_screen_cache;
    else if (screen.compare("options") == 0)
        return options_screen_cache;
    else if (screen.compare("game_vs_computer") == 0)
        return game_vs_computer_screen_cache;
    else return NULL;
}

void ScreenCache::loadChache(){
    main_screen_cache = new MainScreen();
    exit_screen_cache = new ExitScreen();
    play_screen_cache = new PlayScreen();
    options_screen_cache = new OptionsScreen();
    game_vs_computer_screen_cache = new GameVsComputerScreen();
}
