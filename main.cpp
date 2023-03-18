#include <iostream>
#include "game_controller.h"

using namespace std;

int main() {
    game_model model;
    game_controller controller(model);
    controller.launch();
    return 0;
}
