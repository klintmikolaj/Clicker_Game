#ifndef EXAMPLEMVC_GAME_MODEL_H
#define EXAMPLEMVC_GAME_MODEL_H

#include <iostream>

using namespace std;


// Zadaniem tej klasy jest  przechowywanie informacji o stanie gry (np. liczbie punktów) oraz działanie na tych informacjach (np. zwiększanie liczby punktów)
// Wyświetlanie

class game_model {

public:

    int get_points();

    void add_points(int p);

    int get_level();

    int add_level();

    int to_next_level();

    void clear_points();

    void clear_level();

    string ranks(int p);

    int highest_points(int p);

    int highest_level(int p);

private:

    int points = 0;
    int level = 1;
    int points_record = 0;
    int level_record = 1;

};


#endif //EXAMPLEMVC_GAME_MODEL_H