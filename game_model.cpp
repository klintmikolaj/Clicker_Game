#include <iostream>
#include "game_model.h"

using namespace std;

int game_model::get_points() {
    return this->points;
}

void game_model::add_points(int p) {
    this->points += p;
}
