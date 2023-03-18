
#ifndef EXAMPLEMVC_GAME_CONTROLLER_H
#define EXAMPLEMVC_GAME_CONTROLLER_H

#include <iostream>
#include <conio.h>
#include "game_model.h"

using namespace std;

class game_controller {

public:

    explicit game_controller(game_model& model);
    void launch();
    void update();

private:

    game_model& model;

};


#endif //EXAMPLEMVC_GAME_CONTROLLER_H