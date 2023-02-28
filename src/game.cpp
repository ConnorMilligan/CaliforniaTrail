#include "game.h"

void Game::init() {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);

    // Set up colors
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);

    // Set up the main menu screen
    mainMenu = newwin(0, 0, 0, 0);
    wbkgd(mainMenu, COLOR_PAIR(1));
    wprintw(mainMenu, "Press SPACE to start");
    refresh();
}

void Game::run() {
    while (true) {
        switch (state) {
            case MAIN_MENU:
                renderMainMenu();
                handleMainMenuInput();
                break;
            case GAMEPLAY:
                renderGameplay();
                handleGameplayInput();
                break;
            case GAME_OVER:
                renderGameOver();
                handleGameOverInput();
                break;
        }
    }
}

void Game::cleanup() {
    // Clean up ncurses
    delwin(mainMenu);
    endwin();
}

void Game::renderMainMenu() {
    wclear(mainMenu);
    wbkgd(mainMenu, COLOR_PAIR(1));
    wprintw(mainMenu, "Main Menu");
    wprintw(mainMenu, "\nPress SPACE to start");
    wrefresh(mainMenu);
}

void Game::handleMainMenuInput() {
    int ch = getch();
    if (ch == ' ') {
        state = GAMEPLAY;
    }
}

void Game::renderGameplay() {
    wclear(mainMenu);
    wbkgd(mainMenu, COLOR_PAIR(2));
    wprintw(mainMenu, "Gameplay");
    wrefresh(mainMenu);
}

void Game::handleGameplayInput() {
    int ch = getch();
    // Handle gameplay input
    if (ch == 'q') {
        state = GAME_OVER;
    }
}

void Game::renderGameOver() {
    wclear(mainMenu);
    wbkgd(mainMenu, COLOR_PAIR(3));
    wprintw(mainMenu, "Game Over");
    wprintw(mainMenu, "\nPress SPACE to restart");
    wrefresh(mainMenu);
}

void Game::handleGameOverInput() {
    int ch = getch();
    if (ch == ' ') {
        state = MAIN_MENU;
    }
}