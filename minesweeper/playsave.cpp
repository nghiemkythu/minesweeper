#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#include "playsave.h"
#include "struct.h"
#include "Graphic.h"
#include "function.h"
#include "score.h"
void playsavedgame(Thongtino tablesave[100][100], Thongtinbang& TTB, bool& trangthaichoi, int& time0, int& modeplay){
    ifstream file;
    file.open("gamestate.txt");
    file >> TTB.sohang >> TTB.socot >> TTB.sobom >> TTB.soco >> TTB.soodamo;
    for(int i = 0; i <= TTB.sohang-1; i++){
        for(int j = 0; j <= TTB.socot-1; j++){
            file >> tablesave[i][j].cobom >> tablesave[i][j].damo >> tablesave[i][j].camco >> tablesave[i][j].sobomlancan;
        }
    }
    file >> trangthaichoi;
    file >> time0;
    file >> modeplay;
    file.close();
}
void play(){
    Thongtinbang TTB;
    bool trangthaichoi;
    Thongtino tablesave[100][100];
    vitriphim VTP;
    int time0;
    bool dabamphim = false;
    int modeplay;
    playsavedgame(tablesave, TTB, trangthaichoi, time0, modeplay);
    vebang(tablesave, TTB, VTP, dabamphim);
    setColorBGTextXY(1, TTB.sohang+2, 15, 0, "Press Z to choose open a square.");
    setColorBGTextXY(1, TTB.sohang+4, 15, 0, "Press X to flag or mark.");
    setColorBGTextXY(1, TTB.sohang+6, 15, 0, "Press C to open other square which do not have flag around this square");
    setColorBGTextXY(1, TTB.sohang+7, 15, 0, "if the number of flag >= mine number around this square and this square opened.");
    setColorBGTextXY(1, TTB.sohang+9, 15, 0, "Press E to come back the menu.");
    clock_t start, ending;
    start = clock();

    xulyphim(tablesave, TTB, VTP, dabamphim, trangthaichoi, start, ending, time0, modeplay);

}
