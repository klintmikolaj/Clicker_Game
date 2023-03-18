#ifndef EXAMPLEMVC_GAMEVIEW_H
#define EXAMPLEMVC_GAMEVIEW_H

#include <iostream>
#include <stdlib.h>
#include "game_model.h"

class game_view
{
public:
    explicit game_view(game_model&);
    void update();
private:
    game_model& model;
};


#endif //EXAMPLEMVC_GAMEVIEW_H