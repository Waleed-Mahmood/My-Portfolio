#pragma once
#include<iostream>
#include<string.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
#define CHUNK 4

class Print_Board
{
    const int scale = 80;
    int x = 33;
    int y = 33;

    public:

    Print_Board(string q) {

        initwindow(515 + scale, 515 + scale, "8 Queen Problem");
        put_Queens(q);
    }

    int chartoint(char i) {

        return i - '0';
    }

    void put_Queens(string q) {
       
        cleardevice();
        readimagefile("images\\Board.jpg", 0, 0, 504 + scale, 504 + scale);

        //		6	---------------------------------------
           
//#pragma omp parallel for schedule(static,CHUNK)
      //  #pragma omp parallel for schedule(dynamic) 
//#pragma omp parallel for schedule(guided,CHUNK)
        #pragma omp parallel for schedule(runtime)
        for (int i = 0; i < 8; i++) {
            int j = chartoint(q.at(i))-1;
            readimagefile("images\\Queen.jpg", (0 + x) + 65 * i, (0 + y) + 65 * j, (61 + x) + 65 * i, (61 + y) + 65 * j);
        }

        //		6	---------------------------------------

    }


};
