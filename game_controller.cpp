#include <iostream>
#include <windows.h>
#include "game_controller.h"
#include <conio.h>

//Uchwyt pod zmiane koloru tekstu
//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

game_controller::game_controller(game_model& model, game_view &view) : model(model), view(view) {
}

void game_controller::launch() {
    view.entry();
    this->menu();
}

void game_controller::menu() {
    int width = 1;
    int height = 3;


    int x = 0, y = 0;


    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);


    while (true) {
        int a = getch();
        if (a == 224) {
            a = getch();
            if (a == 80) y = (y + 1) % height;
            else if (a == 72) y = (y - 1 + height) % height;
            else if (a == 75) x = (x - 1 + width) % width;
            else if (a == 77) x = (x + 1) % width;
        }
        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        view.title();
        if (y == 1) {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << char(16) << "  START CLICKING BOSS  ";
            cout << char(17) << endl;
        }
        if (y != 1) {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "START CLICKING BOSS " << endl;
        }
        if (y == 2) {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << char(16) << " HELP ME  ";
            cout << char(17) << endl;
        }
        if (y != 2) {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "HELP ME" << endl;
        }

        if (y == 1 && a == 13) this->core();
        if (y == 2 && a == 13) this->view.help();

        {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "\nIn menu maneuver with the arrows" << endl;
        }

    }
}

void game_controller::core() {
        int key;
        this->view.update();
        do {
            key = _getch();
            if (key == 32) {
                this->model.add_points(1);
                this->view.update();
            }
        } while (key != 27);
}

