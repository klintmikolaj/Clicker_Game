#include <iostream>
#include <windows.h>
#include "game_controller.h"
#include <conio.h>

//Sprawdzenie
//Sprawdzanie zakonczone

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
    int height = 4;


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

        if (y == 3) {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << char(16) << " EXIT THE GAME (YOUR PROGRESS WON'T BE SAVED!)  ";
            cout << char(17) << endl;
        }
        if (y != 3) {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "EXIT THE GAME" << endl;
        }

        if (y == 1 and a == 13) this->core();
        if (y == 2 and a == 13) this->view.help();
        if (y == 3 and a == 13) terminate();

        {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "\nIn menu maneuver with the arrows" << endl;
            cout << "Press ENTER to select" << endl;
        }

    }
}

void game_controller::core() {
        int key;
        this->view.update();
        do {
            if (key == 8)
            {
                clearing_level();
                clearing_points();
            }

            key = _getch();
            if (key == 32) {
                this->model.add_points(1);
                this->view.update();
//                cout << "MAX POINTS" << endl;
//                cout << model.highest_points(model.get_points()) << endl;
//                cout << "MAX LEVEL" << endl;
//                cout << model.highest_level(model.get_level()) << endl;
            }


        } while (key != 27);
}


void game_controller::clearing_level() {
    model.clear_level();
}

void game_controller::clearing_points() {
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    model.clear_points();
    view.update();
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n\nProgress has been cleared!" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}



