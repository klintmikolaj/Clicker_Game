#ifndef EXAMPLEMVC_GAME_MODEL_H
#define EXAMPLEMVC_GAME_MODEL_H

#include <iostream>

using namespace std;


class game_model {

public:

    int get_points();
    void add_points(int p);

private:

    int points;

};


#endif //EXAMPLEMVC_GAME_MODEL_H