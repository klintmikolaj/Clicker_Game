#include <iostream>
#include "game_model.h"

using namespace std;

int game_model::get_points() {
    return this->points;
}

void game_model::add_points(int p) {
    this->points += p;
}

int game_model::get_level() {
    return this->level;
}

int game_model::add_level() {
    if (this->points >= this->level * (this->level * 30))
    return this->level++;
}

int game_model::to_next_level() {
    return ((this->level * (this->level * 30)) - this->points);

}

int game_model::word(int p) {
    switch (p) {
        case 0:
            cout << char(244);
            break;
        case 1:
            cout << "✰ ✵";
            break;
        default:
            cout << "";
    }
}


