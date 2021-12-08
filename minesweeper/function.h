#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "struct.h"
#include <stdlib.h>
#define Width 100
#define Height 50

void taobang(Thongtino table[100][100], Thongtinbang &TTB);
void khoitao(Thongtino table[100][100], int sohang, int socot, int sobom, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, clock_t &start);
void taobom(Thongtino table[100][100], Thongtinbang &TTB);
void xulyphim(Thongtino table[100][100], Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, clock_t &start, clock_t &ending, int time0, int& modeplay);
void moo(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, bool &trangthaichoi, bool& result);
void clickZ(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim,  bool &trangthaichoi, bool& result);
void clickX(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim);
void clickC(Thongtino table[100][100], int Sx, int Sy, Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim, bool &trangthaichoi, bool& result);
int dembom(Thongtino table[100][100], int row,int colum, Thongtinbang &TTB);
int demco(Thongtino table[100][100], int row,int colum, Thongtinbang &TTB);
void veo(Thongtino table[100][100], int Sx, int Sy, int chedo);
void vebang(Thongtino table[100][100], Thongtinbang &TTB, vitriphim &VTP, bool &dabamphim);
void chonchedo(Thongtino table[100][100], int &a, int &b, int &sobom, int& modeplay);
void newgame();
void savegame(Thongtino table[100][100], Thongtinbang &TTB, vitriphim &VTP, bool &trangthaichoi, int& time_save, int& modeplay);
void thang(Thongtino table[100][100], Thongtinbang &TTB,bool &trangthaichoi, bool& result);
void thua(Thongtino table[100][100], Thongtinbang &TTB, bool &trangthaichoi, bool& result);

#endif // FUNCTION_H_INCLUDED
