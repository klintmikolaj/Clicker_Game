#include <iostream>
#include <windows.h>
#include "game_view.h"

//Uchwyt pod zmiane koloru tekstu
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
    model.add_level();
    cout << "Points: "; SetConsoleTextAttribute(h, 10); cout << model.get_points() << endl << endl; SetConsoleTextAttribute(h, 15);
    cout << "Level: "; SetConsoleTextAttribute(h, 10); cout << model.get_level() << endl << endl; SetConsoleTextAttribute(h, 15);
    cout << "To next level you need ";
    if (model.to_next_level() == 1) {SetConsoleTextAttribute(h, 10); cout << model.to_next_level(); SetConsoleTextAttribute(h, 15); cout << " click";}
    else {SetConsoleTextAttribute(h, 10); cout << model.to_next_level(); SetConsoleTextAttribute(h, 15); cout << " clicks"; }
    cout << endl << endl;
    cout << "Your current rank is: "; SetConsoleTextAttribute(h, 14); cout << char(206) << " "; cout << (model.ranks(model.get_level())); cout << " " << char(206); SetConsoleTextAttribute(h, 15);
    cout << endl;

}