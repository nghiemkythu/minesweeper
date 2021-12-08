#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "function.h"
#include "struct.h"
#include "Graphic.h"
#include "score.h"

void xoabang(Thongtino table[100][100], Thongtinbang &TTB){
    for (int i = 0; i < TTB.sohang; i++){
        for(int j = 0; j < TTB.socot; j++){
            table[i][j].camco = false;
            table[i][j].cobom = false;
            table[i][j].damo = false;
            table[i][j].sobomlancan = 0;
        }
    }
}
void chonchedo(Thongtino table[100][100], int &row, int &col, int &sobom, int& modeplay){
    cout << "Choose game mode." << endl;
    cout << endl;
    cout << "1. easy" << endl;
    cout << "2. medium" << endl;
    cout << "3. hard"<< endl;
    cout << "4. custom" << endl;
    cout << "Select: ";
    cin >> modeplay;
    switch(modeplay)
    {
    case 1:
        row = 8;
        col = 8;
        sobom = 10;
        system("cls");
        break;
    case 2:
        row = 16;
        col = 16;
        sobom = 40;
        system("cls");
        break;
    case 3:
        row = 30;
        col = 30;
        sobom = 99;
        system("cls");
        break;
    case 4:
        cout << "so hang: ";
        cin >> row;
        cout << "socot: ";
        cin >> col;
        cout << "sobom: ";
        cin >> sobom;
        system("cls");
        break;
    }
}
void khoitao(Thongtino table[100][100], int sohang, int socot, int sobom, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, clock_t &start){
    TTB.sobom = sobom;
    TTB.socot = socot;
    TTB.sohang = sohang;
    TTB.soco = 0;
    TTB.soodamo = 0;

    //taobang(table, TTB);

    taobom(table, TTB);

    vebang(table, TTB, VTP, dabamphim);
    trangthaichoi = true;
    setColorBGTextXY(1, sohang+2, 15, 0, "Press Z to choose open a square.");
    setColorBGTextXY(1, sohang+4, 15, 0, "Press X to flag or mark.");
    setColorBGTextXY(1, sohang+6, 15, 0, "Press C to open other square which do not have flag around this square");
    setColorBGTextXY(1, sohang+7, 15, 0, "if the number of flag >= mine number around this square and this square opened.");
    setColorBGTextXY(1, TTB.sohang+9, 15, 0, "Press E to come back the menu.");
    start = clock();
}
int toadoX(int Sx){
    return 2*Sx;
}
int toadoY(int Sy){
    return Sy;
}
void veo(Thongtino table[100][100], int Sx, int Sy, int chedo){
    switch(chedo)
    {
    case 0:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 10, "  ");
        break;
    case 1:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "1 ");
        break;
    case 2:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "2 ");
        break;
    case 3:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "3 ");
        break;
    case 4:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "4 ");
        break;
    case 5:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "5 ");
        break;
    case 6:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "6 ");
        break;
    case 7:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "7 ");
        break;
    case 8:
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 15, "8 ");
        break;
    case 9: //đen
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 8, "  ");
        break;
    case 10: //trắng
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 7, "  ");
        break;
    case 11: //con trỏ
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 0, " ");
        break;
    case 12: // cắm cờ
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 12, 13, "P ");
        break;
    case 13: // cắm cờ sai
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 15, 16, "Px");
        break;
    case 14: // cắm cờ đúng
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 12, 14, "B ");
        break;
    case 15: // hiện bom ẩn
        setColorBGTextXY(toadoX(Sx), toadoY(Sy), 0, 12, "B ");
        break;
    }
}
void vebang(Thongtino table[100][100], Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim){
    for(int i = 0; i < TTB.sohang; i++){
        for(int j = 0; j < TTB.socot; j++){
            if(table[i][j].camco){
                veo(table, j, i, 12);
            }
            else if(table[i][j].sobomlancan){
                veo(table, j, i, table[i][j].sobomlancan);
            }
            else if(table[i][j].damo){
                veo(table, j, i, 0);
            }
            else if(((i+j) % 2) == 0){
                veo(table, j, i, 9);
            }
            else{
                veo(table, j, i, 10);
            }
        }
    }
    if(dabamphim){
        veo(table, VTP.x, VTP.y, 11);
        dabamphim = false;
    }

}
void taobom(Thongtino table[100][100], Thongtinbang &TTB){
    int sobom = TTB.sobom;
    int Sx, Sy;
    time_t t;
    srand((unsigned) time(&t));
    while(sobom){
        //while((Sx == 0 && Sy == 0) || (Sx == TTB.sohang - 1 && Sy == TTB.socot - 1) || (Sx == TTB.sohang - 1 && Sy == 1) || (Sx == 1 && Sy == TTB.socot - 1)){
            //srand((unsigned) time(&t));
        Sx = rand() % TTB.sohang;
        Sy = rand() % TTB.socot;
        //}
        if(table[Sx][Sy].cobom){
            continue;
        }

        table[Sx][Sy].cobom = true;

        sobom--;
    }
}
int dembom(Thongtino table[100][100], int row,int colum, Thongtinbang &TTB){
    int sobom = 0;
    for (int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(row + i >= 0 && row + i <=TTB.sohang-1 && colum + j >= 0 && colum + j <=TTB.socot-1){
                if(table[row+i][colum+j].cobom) sobom += 1;
            }
        }
    }
    return sobom;
}
int demco(Thongtino table[100][100], int row,int colum, Thongtinbang &TTB){
    int soco = 0;
    for (int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(row + i >= 0 && row + i <=TTB.sohang-1 && colum + j >= 0 && colum + j <=TTB.socot-1){
                if(table[row+i][colum+j].camco) soco += 1;
            }
        }
    }
    return soco;
}
void xulyphim(Thongtino table[100][100], Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, clock_t &start, clock_t &ending, int time0, int& modeplay){
    bool result;
    while(true){
        char c = getch();
        if(c == -32){
            c = getch();
            if(c == 72){
                dabamphim = true;
                if(VTP.y == 0) VTP.y = TTB.sohang - 1;
                else VTP.y -= 1;
                if(trangthaichoi){
                    vebang(table, TTB, VTP, dabamphim);
                }
            }
            if(c == 80){
                //cout << "Ban vua an phim mui ten xuong!" << endl;
                dabamphim = true;
                if(VTP.y == TTB.sohang - 1) VTP.y = 0;
                else VTP.y += 1;
                if(trangthaichoi){
                    vebang(table, TTB, VTP, dabamphim);
                }
            }
            if(c == 75){
                //cout << "Ban vua an phim mui ten sang trai!" << endl;
                dabamphim = true;
                if(VTP.x == 0) VTP.x = TTB.socot - 1;
                else VTP.x -= 1;
                if(trangthaichoi){
                    vebang(table, TTB, VTP, dabamphim);
                }
            }
            if(c == 77){
                //cout << "Ban vua an phim mui ten sang phai!" << endl;
                dabamphim = true;
                if(VTP.x == TTB.socot - 1) VTP.x = 0;
                else VTP.x += 1;
                if(trangthaichoi){
                    vebang(table, TTB, VTP, dabamphim);
                }
            }
        }
        else{
            int a = c;

            if(a == 122){
                //cout << "ban nhan z -> mo o" << endl;
                if(trangthaichoi){
                    dabamphim = true;
                    clickZ(table, VTP.y, VTP.x, TTB, VTP, dabamphim, trangthaichoi, result);
                }
            }
            if(a == 120){
                //cout << "ban nhan x -> cam co" << endl;
                if(trangthaichoi){
                    dabamphim = true;
                    clickX(table, VTP.y, VTP.x, TTB, VTP, dabamphim);

                }
            }
            if(a == 101){
                system("cls");
                break;
            }
            if(a == 99){
                if(trangthaichoi){
                    dabamphim = true;
                    clickC(table, VTP.y, VTP.x, TTB, VTP, dabamphim, trangthaichoi, result);
                }
            }
            if(a == 13){ //save game
                if(trangthaichoi){
                    ending = clock();
                    int time_save = ((double) (ending - start))/CLOCKS_PER_SEC;
                    time_save += time0;
                    savegame(table, TTB, VTP, trangthaichoi, time_save, modeplay);
                }
            }
        }
        if(!trangthaichoi){
            if(result){
                ending = clock();
                int time = ((double) (ending - start))/CLOCKS_PER_SEC;
                time += time0;
                setColorBGTextXY(toadoX(TTB.socot+4), 4, 15, 0, "Total time: %d s", time);
                ranksave(modeplay, time);
                xoabang(table, TTB);
                setColorBGTextXY(toadoX(TTB.socot+4), 6, 15, 0, "new game (y/n)? ");
                char n;
                cin >> n;
                if(n == 'y'){
                    system("cls");
                    newgame();
                    break;
                }
                else{
                    system("cls");
                    return;
                }
            }
            else{
                xoabang(table, TTB);
                setColorBGTextXY(toadoX(TTB.socot+4), 6, 15, 0, "new game (y/n)? ");
                char n;
                cin >> n;
                if(n == 'y'){
                    system("cls");
                    newgame();
                    break;
                }
                else{
                    system("cls");
                    return;
                }
            }
        }
    }
}
void moo(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, bool &trangthaichoi, bool& result){
    if(!table[Sx][Sy].damo && !table[Sx][Sy].camco){
        table[Sx][Sy].damo = true;
        if(table[Sx][Sy].cobom){
            thua(table, TTB, trangthaichoi, result);
        }
        else{
            //table[Sx][Sy].damo = true;
            TTB.soodamo++;
            int sobom = dembom(table, Sx, Sy, TTB);
            if(sobom){
                table[Sx][Sy].sobomlancan = sobom;
            }
            else{
                for ( int i = Sx-1; i <= Sx+1; i++){
                    for(int j = Sy-1; j <= Sy+1; j++){
                        if(i>= 0 && i <= TTB.sohang-1 && j>=0 && j <= TTB.socot-1){
                            moo(table, i, j, TTB, trangthaichoi, result);
                        }
                    }
                }
            }
        }
    }
}
void clickZ(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, bool& result){
    if(!table[Sx][Sy].damo && !table[Sx][Sy].camco){
        moo(table, Sx, Sy, TTB, trangthaichoi, result);
        if(trangthaichoi){
            vebang(table, TTB, VTP, dabamphim);
            if((TTB.sobom + TTB.soodamo) == (TTB.socot*TTB.sohang)){
                thang(table, TTB, trangthaichoi, result);
            }
        }
    }
}
void thang(Thongtino table[100][100], Thongtinbang &TTB, bool &trangthaichoi, bool& result){
    result = true;
    trangthaichoi = false;
}
void thua(Thongtino table[100][100], Thongtinbang &TTB, bool &trangthaichoi, bool& result){
    for(int i = 0; i < TTB.sohang; i++){
        for(int j = 0; j < TTB.socot; j++){
            if(table[i][j].camco){
                if(table[i][j].cobom){
                    veo(table, j, i, 14);
                }
                else veo(table, j, i, 13);
            }
            else{
                if(table[i][j].cobom){
                    veo(table, j, i, 15);
                }
            }
        }
    }
    result = false;
    trangthaichoi = false;
}
void clickX(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim){
    if(!table[Sx][Sy].damo){
        if(table[Sx][Sy].camco){
            TTB.soco--;
            table[Sx][Sy].camco = false;
        }
        else{
            TTB.soco++;
            table[Sx][Sy].camco = true;
        }
    }
    vebang(table, TTB, VTP, dabamphim);
}
void clickC(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, bool& result){
    if(table[Sx][Sy].damo && table[Sx][Sy].sobomlancan){
        int socoxungquanh = demco(table, Sx, Sy, TTB);
        if(table[Sx][Sy].sobomlancan <= socoxungquanh){
            for ( int i = Sx-1; i <= Sx+1; i++){
                for(int j = Sy-1; j <= Sy+1; j++){
                    if(i>= 0 && i <= TTB.sohang-1 && j>=0 && j <= TTB.socot-1){
                        moo(table, i, j, TTB, trangthaichoi, result);
                    }
                }
            }
            if(trangthaichoi) vebang(table, TTB, VTP, dabamphim);
            if((TTB.sobom + TTB.soodamo) == (TTB.socot*TTB.sohang)){
                thang(table, TTB, trangthaichoi, result);
            }
        }
    }
}
void newgame(){
    Thongtinbang TTB;
    vitriphim VTP;
    Thongtino table[100][100];
    int time0 = 0;
    bool dabamphim = false;
    bool trangthaichoi = false;
    int a, b, sobom;
    int modeplay;
    chonchedo(table, a, b, sobom, modeplay);
    clock_t start, ending;

    khoitao(table, a, b, sobom, TTB, VTP, dabamphim, trangthaichoi, start);
    xulyphim(table, TTB, VTP, dabamphim, trangthaichoi, start, ending, time0, modeplay);
    //xoabang(TTB);
}
void savegame(Thongtino table[100][100], Thongtinbang &TTB, vitriphim &VTP, bool &trangthaichoi, int& time_save, int& modeplay){
    ofstream file ("gamestate.txt");
    file << TTB.sohang <<endl;
    file << TTB.socot <<endl;
    file << TTB.sobom <<endl;
    file << TTB.soco <<endl;
    file << TTB.soodamo <<endl;
    for(int i = 0; i <= TTB.sohang-1; i++){
        for(int j = 0; j <= TTB.socot-1; j++){
            file << table[i][j].cobom << " " << table[i][j].damo << " " << table[i][j].camco << " " << table[i][j].sobomlancan << endl;
        }
    }
    file << trangthaichoi << endl;
    file << time_save << endl;
    file << modeplay;
    file.close();
}
