#define SDL_MAIN_HANDLED

#include <curses.h>
#include "game.h"

int main(int argc, char **argv) {    
    Game game;
    game.init();
    game.run();
    game.cleanup();

    return 0;
}
