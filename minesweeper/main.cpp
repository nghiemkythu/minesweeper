#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
#include "function.h"
#include "Graphic.h"
#include "playsave.h"


int main()
{
    resizeConsole(Width, Height);
    SetConsoleTitle(TEXT("MineSweeper"));
    cout << "Hello, welcome to minesweeper." << endl;
    int menuSelection;
    do
    {
        cout << "1. New" << endl;
        cout << "2. Play" << endl;
        cout << "3. Options" << endl;
        cout << "4. Scores" << endl;
        cout << "5. Exit" << endl;
        cout << "Select: ";
        cin >> menuSelection;
        switch (menuSelection){
            case 1:
                system("cls");
                newgame();
                cout << endl;
                break;
            case 2:
                system("cls");
                play();
                cout << endl;
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (menuSelection >= 1 && menuSelection <= 4);
    return 0;
}
