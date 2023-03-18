#include <iostream>
#include "game_controller.h"

using namespace std;

game_controller::game_controller(game_model& model) : model(model) {
}

void game_controller::launch() {
    this->update();
    int key;
    do {
        key = _getch();
        if (key == 13) {
            this->model.add_points(1);
            this->update();
        }
    }
    while (key != 27);
}

void game_controller::update() {
    system("cls");
    cout << "Console clicker!" << endl;
    cout << "Points: " << this->model.get_points() << endl;
}
