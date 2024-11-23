#include <iostream>
#include <string>

#ifdef _WIN32
#define WINDOWS_SYSTEM
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "include/maze.h"

using namespace std;

void clearScreen(){
    #ifdef __linux__
    system("clear");
    #else
    system("cls");
    #endif
}

void sleep(int seconds){
    #ifdef WINDOWS_SYSTEM
    Sleep(seconds * 1000);
    #else
    sleep(seconds);
    #endif
}

int main(int, char**){
    string filename;
    cout << "Informe o nome do arquivo (arquivo.txt): ";
    cin >> filename;

    Maze maze(filename);

    clearScreen();

    string mazeString;

    for (int y = 0; y < maze.getHeight(); y++) {
        for (int x = 0; x < maze.getWidth(); x++) {
            mazeString += (maze.isBlocked(x, y) ? "##" : "  ");
        }
        mazeString += "\n"; // Quebra de linha após cada linha do labirinto
    }

    mazeString += "(0, 0)\n";
    cout << mazeString;
    sleep(2);

    clearScreen();
    mazeString = "";
    for (int y = 0; y < maze.getHeight(); y++) {
        for (int x = 0; x < maze.getWidth(); x++) {
            mazeString += (maze.isBlocked(x, y) ? "##" : "  ");
        }
        mazeString += "\n"; // Quebra de linha após cada linha do labirinto
    }

    mazeString += "(0, 1)\n";
    cout << mazeString;
    sleep(2);

    clearScreen();
    mazeString = "";
    for (int y = 0; y < maze.getHeight(); y++) {
        for (int x = 0; x < maze.getWidth(); x++) {
            mazeString += (maze.isBlocked(x, y) ? "##" : "  ");
        }
        mazeString += "\n"; // Quebra de linha após cada linha do labirinto
    }

    mazeString += "(1, 0)\n";
    cout << mazeString;
    sleep(2);

    clearScreen();
    mazeString = "";
    for (int y = 0; y < maze.getHeight(); y++) {
        for (int x = 0; x < maze.getWidth(); x++) {
            mazeString += (maze.isBlocked(x, y) ? "##" : "  ");
        }
        mazeString += "\n"; // Quebra de linha após cada linha do labirinto
    }

    mazeString += "(1, 1)\n";
    cout << mazeString;
    sleep(2);

    system("pause");
}