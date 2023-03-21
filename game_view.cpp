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
    SetConsoleTitleA("Mafia Clicker");
    system("cls");
    title();
    hidecursor();
//    SetConsoleTextAttribute(h, 12);
//    cout << "Welcome to Mafia Clicker!" << endl << endl;
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
    cout << "\n\nPress SPACE to get a point" << endl;
    cout << "Press ESC two times to go back to menu";

}

void game_view::help() {
    system("cls");
    hidecursor();
    title();
    SetConsoleTextAttribute(h, 15);
    cout << "This is help:" << endl;
    cout << "Main goal of the game is just to have fun" << endl;
    cout << "While playing press space to get a point" << endl;
    cout << "After getting a certain number of points you'll level up" << endl;
    cout << "With every level you'll be promoted to the next rank in mafia structures" << endl;
    cout << "\nPress ESC to go back to menu" << endl;
}

void game_view::title() {
    SetConsoleTextAttribute(h, 10);
    cout <<"  __  __   _   ___ ___   _      ___ _    ___ ___ _  _____ ___" << endl;
    cout <<" |  \\/  | /_\\ | __|_ _| /_\\    / __| |  |_ _/ __| |/ / __| _ \\"<< endl;
    cout <<" | |\\/| |/ _ \\| _| | | / _ \\  | (__| |__ | | (__| ' <| _||   / "<< endl;
    cout << " |_|  |_/_/ \\_\\_| |___/_/ \\_\\  \\___|____|___\\___|_|\\_\\___|_|_\\ "<< endl << endl << endl;

}

void game_view::entry() {
    SetConsoleTextAttribute(h, 10);
    title();
    hidecursor();
    cout << "Press ENTER to start the game!";
    cout << endl;
//    int key = getch();
//    if (key == 27) terminate();

}

void game_view::hidecursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &info);
}




