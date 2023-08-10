#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <omp.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include "State.h"
#include "Selection.h"
#include "Print_Board.h"

using namespace std;

const int maxSelection = 50;
const int maxGeneration = 600;
const int No_Of_Queen = 8;

int main(int argc, char* argv[]) {

	srand(time(0));
	Print_Board obj_Print_Board(No_Of_Queen);

	State* States;


	States = new State[maxSelection];

	
	for (int i = 0; i < maxSelection; i++) {
		State state(No_Of_Queen);
		States[i] = state;
	}
	
	
	string* return_string=NULL;

	Selection obj_papulation(maxSelection);
	boolean breaker = false;
	
	for (int count = 0; count < maxGeneration && breaker != true; count++) {

		
		for (int i = 1; i < maxSelection; i++) {
			
			for (int j = 0; j < No_Of_Queen; j++) {
					States[i].state[j] = States[0].state[j];
			}
		}
		
		

		int cross_over = 0.4 * maxSelection;
		int mutate = cross_over + cross_over;
		
		for (int j = 0; j < mutate; j++) {
			States[j].mutate();
		}
		
		int cross_over_end = maxSelection - maxSelection * 0.1;

		
		for (int j = cross_over; j < cross_over_end; j++) {

				States[j].crossover(States[rand() % cross_over_end]);
		}
	
		for (int j = 0; j < maxSelection && breaker != true; j++) {
			
			States[j].Calculate_Fitness();
			if (States[j].fit_val == 28) {
				cout <<endl<< "-----------------------------------------------" << endl;
				cout <<endl<< "-----------------------------------------------" << endl;

				for (int i = 0; i < No_Of_Queen; i++) {
					cout << States[j].state[i] << " ";
				}

				cout << "\t	Fitness	:" << States[j].fit_val;

				cout << endl << "-----------------------------------------------" << endl;
				cout << endl << "-----------------------------------------------" << endl;
				return_string = States[j].state;
				breaker = true;
			}
			else {}
		}

		if(count + 1 == maxGeneration) {
			obj_papulation.Fitess(States);
			return_string = States[0].state;
			breaker = true;
		}

		if (breaker != true) {
			
			obj_papulation.Fitess(States);

			cout << "-----------------------------------------------" << endl;

			cout << "Iteration	: " << count << "|	";

			for (int i = 0; i < No_Of_Queen; i++) {
				cout << States[0].state[i] << " ";
			}

			cout << "\t	Fitness	:" << States[0].fit_val;

			cout << endl << "-----------------------------------------------" << endl;
		}
		
		else {}
	}

	
	obj_Print_Board.put_Queens(return_string);
	getch();

	return 0;
}
