#ifndef GAME_H
#define GAME_H

#include <curses.h>
#include <pdcsdl.h>
#include <SDL.h>

enum GameState {
    MAIN_MENU,
    GAMEPLAY,
    GAME_OVER
};

class Game {
private:
    GameState state;
    WINDOW* mainMenu;
    int maxx, maxy;

    void renderMainMenu();
    void handleMainMenuInput();

    void renderGameplay();
    void handleGameplayInput();

    void renderGameOver();
    void handleGameOverInput();
    
public:
    Game() : state(MAIN_MENU) {}
    
    void init();
    void run();
    void cleanup();
};

#endif