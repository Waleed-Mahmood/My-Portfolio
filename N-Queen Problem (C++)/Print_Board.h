#pragma once
#include<iostream>
#include<string.h>
#include <omp.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

using namespace std;

class Print_Board
{
    const int scale = 11;
    int div;
    int No_Of_Queens;
    int spacing;

    public:

    Print_Board(int No_Of_Queens) {
        
        this->No_Of_Queens = No_Of_Queens;

        bool breaker = false;
        this->div = 1;

        for (int i=8;breaker!=true;i+=i) {
            if (i == No_Of_Queens) {
                breaker = true;
            }
            else {
                this->div += this->div;
            }
        }


        this->spacing = 4;

        string x = to_string(this->No_Of_Queens) + " Queen Problem";
        int n = x.length();
        char *char_array=new char[n+1];
        strcpy(char_array, x.c_str());

        initwindow(640 + scale, 640 + scale, char_array);
        
        string *s = new string[this->No_Of_Queens];

        for (int i = 0; i < this->No_Of_Queens; i++) {
            s[i] = "1";
        }
        
        put_Queens(s);
    }

    int chartoint(char i) {

        return i - '0';
    }

    void put_Queens(string* q) {
       
        cleardevice();
        int c_change = 1;
        omp_set_num_threads(2);

        #pragma omp parallel for 

        for (int i = 0; i < this->No_Of_Queens; i++) {

          
            for (int j = 0; j < this->No_Of_Queens; j++) {
                if (c_change == 1) {
                    readimagefile("images\\White_Back.jpg", (80 * i) / div, (80 * j) / div, (80 + 80 * i) / div, (80 + 80 * j) / div);
                    c_change = 0;
                }
                else {
                    readimagefile("images\\Brown_Back.jpg", (80 * i) / div, (80 * j) / div, (80 + 80 * i) / div, (80 + 80 * j) / div);
                    c_change = 1;
                }
            }
    
            if (c_change == 1) {
                c_change = 0;
            }
            else {
                c_change = 1;
            }
        }
 


        for (int i = 0; i < this->No_Of_Queens; i++) {
            int j = stoi(q[i]) - 1;
            readimagefile("images\\Queen.jpg", (spacing+80 * i) / div, (spacing+80 * j) / div, (80 - spacing + 80 * i) / div, (80 - spacing + 80 * j) / div);
        }


        
    }


};
