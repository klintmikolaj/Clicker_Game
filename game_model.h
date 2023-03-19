#ifndef EXAMPLEMVC_GAME_MODEL_H
#define EXAMPLEMVC_GAME_MODEL_H

#include <iostream>

using namespace std;


// Zadaniem tej klasy jest  przechowywanie informacji o stanie gry (np. liczbie punktów) oraz działanie na tych informacjach (np. zwiększanie liczby punktów)

class game_model {

public:

    int get_points();
    void add_points(int p);
    int get_level();
    int add_level();
    int to_next_level();
    int word(int p);

private:

    int points;
    int level;

};


#endif //EXAMPLEMVC_GAME_MODEL_H