#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#include "playsave.h"
#include "struct.h"
#include "Graphic.h"
#include "function.h"
#include "score.h"
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
	        if(a[i] > a[j]){
		        Swap(a[i], a[j]);
	        }
        }
    }
}
void ranksave(int& modeplay, int time){
    switch(modeplay)
    {
    case 1: //easy
    {
        int A1[12];
        int n1;
        ifstream fileeaseyrank;
        fileeaseyrank.open("easyrank.txt");
        fileeaseyrank >> n1;
        if(n1 < 10){
            for(int i = 0; i <= n1-1; i++){
                fileeaseyrank >> A1[i];
            }
            A1[n1] = time;
            Sort(A1, n1+1);
            n1++;
        }
        else{
            for(int i = 0; i <= n1-1; i++){
                fileeaseyrank >> A1[i];
            }
            A1[n1] = time;
            Sort(A1, n1+1);

        }
        fileeaseyrank.close();

        ofstream fileeaseyrank1 ("easyrank.txt");
        fileeaseyrank1 << n1 << endl;
        for(int i = 0; i <= n1-1; i++){
            fileeaseyrank1 << A1[i] << " ";
        }
        fileeaseyrank1.close();
        break;
    }
    case 2:// medium
    {
        int A2[12];
        int n2;
        ifstream filemediumrank;
        filemediumrank.open("mediumrank.txt");
        filemediumrank >> n2;
        if(n2 < 10){
            for(int i = 0; i <= n2-1; i++){
                filemediumrank >> A2[i];
            }
            A2[n2] = time;
            Sort(A2, n2+1);
            n2++;
        }
        else{
            for(int i = 0; i <= n2-1; i++){
                filemediumrank >> A2[i];
            }
            A2[n2] = time;
            Sort(A2, n2+1);

        }
        filemediumrank.close();

        ofstream filemediumrank1 ("mediumrank.txt");
        filemediumrank1 << n2 << endl;
        for(int i = 0; i <= n2-1; i++){
            filemediumrank1 << A2[i] << " ";
        }
        filemediumrank1.close();
        break;
    }
    case 3: //hard
    {
        int A3[12];
        int n3;
        ifstream filehardrank;
        filehardrank.open("hardrank.txt");
        filehardrank >> n3;
        if(n3 < 10){
            for(int i = 0; i <= n3-1; i++){
                filehardrank >> A3[i];
            }
            A3[n3] = time;
            Sort(A3, n3+1);
            n3++;
        }
        else{
            for(int i = 0; i <= n3-1; i++){
                filehardrank >> A3[i];
            }
            A3[n3] = time;
            Sort(A3, n3+1);

        }
        filehardrank.close();

        ofstream filehardrank1 ("hardrank.txt");
        filehardrank1 << n3 << endl;
        for(int i = 0; i <= n3-1; i++){
            filehardrank1 << A3[i] << " ";
        }
        filehardrank1.close();
        break;
    }
    default:
        break;
    }

}

void ranking(){
    setColorBGTextXY(1, 1, 15, 0, "Which mode game do you want to see the ranking: ");
    int n;
    cin >> n;
    switch(n)
    {
    case 1:
    {
        ifstream easy;
        easy.open("easyrank.txt");
        int n1;
        easy >> n1;
        cout << "top 10 easy mode:" << endl;
        for(int i = 0; i <= n1-1; i++){
            int a;
            easy >> a;
            cout << i+1 << ": " << a << endl;
        }
        easy.close();
        break;
    }
    case 2:
    {
        ifstream medium;
        medium.open("mediumrank.txt");
        int n2;
        medium >> n2;
        cout << "top 10 medium mode:" << endl;
        for(int i = 0; i <= n2-1; i++){
            int a;
            medium >> a;
            cout << i+1 << ": " << a << endl;
        }
        medium.close();
        break;
    }
    case 3:
    {
        ifstream hard;
        hard.open("hardrank.txt");
        int n3;
        hard >> n3;
        cout << "top 10 hard mode:" << endl;
        for(int i = 0; i <= n3-1; i++){
            int a;
            hard >> a;
            cout << i+1 << ": " << a << endl;
        }
        hard.close();
        break;
    }
    }
}
