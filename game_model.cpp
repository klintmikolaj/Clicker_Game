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

string game_model::ranks(int p) {
    switch(p)
    {
        case 1:
            return "Crook";
        case 2:
            return "Soldier";
        case 3:
            return "Caporegime";
        case 4:
            return "Consigliere";
        case 5:
            return "Underboss";
        case 6:
            return "Boss";
        default:
            return "Godfather";
    }
}

