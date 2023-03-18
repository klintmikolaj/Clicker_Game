#include <iostream>
#include <windows.h>
#include "game_view.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

game_view::game_view(game_model& model):model(model)
{
}

void game_view::update()
{
    SetConsoleTitleA("CC");
    system("cls");
    SetConsoleTextAttribute(h, 12);
    cout << "Welcome to CC!" << endl << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "Points: "<< model.get_points() << endl << endl;
    cout << "Level: "<< model.get_level() << endl << endl;
    cout << "Completed letters: ";
    model.word(model.get_level());
    cout << endl;
}