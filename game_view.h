#ifndef EXAMPLEMVC_GAMEVIEW_H
#define EXAMPLEMVC_GAMEVIEW_H

#include <iostream>
#include "game_model.h"

// Zadaniem tej klasy jest wyswietlanie uzytkownikowi wszelkich informacji
// Zbieranie danych
class game_view
{
public:
    explicit game_view(game_model&);
    void update();
private:
    game_model& model;
};


#endif //EXAMPLEMVC_GAMEVIEW_H