
#ifndef EXAMPLEMVC_GAME_CONTROLLER_H
#define EXAMPLEMVC_GAME_CONTROLLER_H

#include <iostream>
#include <conio.h>
#include "game_model.h"
#include "game_view.h"

using namespace std;

// Zadaniem tej klasy jest reagowanie na interakcje z klasy "view" i zmieniała ich wartość w klasie "model"
// Działanie programu

class game_controller {

public:

    explicit game_controller(game_model&, game_view&);
    void launch();
    void menu();
    void core();
    void clearing_points();
    void clearing_level();
//    void save(int, int);

private:
    game_view& view;
    game_model& model;
};


#endif //EXAMPLEMVC_GAME_CONTROLLER_H