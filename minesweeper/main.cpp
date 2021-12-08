#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
#include "function.h"
#include "Graphic.h"
#include "playsave.h"
#include "score.h"

int main()
{
    resizeConsole(Width, Height);
    SetConsoleTitle(TEXT("MineSweeper"));
    //cout << "Hello, welcome to minesweeper." << endl;
    setColorBGTextXY(1, 1, 15, 0, "Hello, welcome to minesweeper.");
    int menuSelection;
    do
    {
        //cout << "1. New" << endl;
        setColorBGTextXY(1, 2, 15, 0, "1. New");
        //cout << "2. Play" << endl;
        setColorBGTextXY(1, 3, 15, 0, "2. Play");
        //cout << "3. Options" << endl;
        setColorBGTextXY(1, 4, 15, 0, "3. Scores");
        //cout << "4. Scores" << endl;
        setColorBGTextXY(1, 5, 15, 0, "4. Options");
        //cout << "5. Exit" << endl;
        setColorBGTextXY(1, 6, 15, 0, "5. Exit");
        //cout << "Select: ";
        setColorBGTextXY(1, 7, 15, 0, "Select: ");
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

                break;
            case 3:
                system("cls");
                ranking();
                while (true){
                    cout << endl << "Press 1 to break. ";
                    int n;
                    cin >> n;
                    if(n == 1)
                        break;
                }
                system("cls");
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (menuSelection >= 1 && menuSelection <= 4);
    return 0;
}
