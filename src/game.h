#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

enum GameState {
    MAIN_MENU,
    GAMEPLAY,
    GAME_OVER
};

class Game {
private:
    GameState state;
    WINDOW* mainMenu;

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