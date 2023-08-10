#ifndef State_H
#define State_H

#include "State.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>



using namespace std;

class State {
public:

	string* state;
	int fit_val;
	int No_Of_Queen;
	
	State(){}

	State(int No_Of_Queen) {
		this->No_Of_Queen = No_Of_Queen;
		state = generateState();
		Calculate_Fitness();
	}

	string* generateState() {

		string* state = new string[this->No_Of_Queen];
		int number;
		for (int i = 0; i < this->No_Of_Queen; i++) {
			number = rand() % this->No_Of_Queen + 1;
			state[i]=intToString(number);
		}
		return state;
	}
	
	void Calculate_Fitness() {
		
		fit_val = 28;
		string QueenCurrent;
		string QueenNext;
		int index;
		int currentQueenPosition, nextQueenPosition;
		int diagonalIndex;

		for (int i = 0; i < No_Of_Queen; i++) {
			diagonalIndex = 0;
			QueenCurrent = state[i];

			for (index = i + 1; index < No_Of_Queen; index++) {
				diagonalIndex = index - i;
				QueenNext = state[index];

				if (QueenCurrent == QueenNext) {
					fit_val -= 1;
				}

				currentQueenPosition = atoi(QueenCurrent.c_str());
				nextQueenPosition = atoi(QueenNext.c_str());

				if ((nextQueenPosition - currentQueenPosition) == diagonalIndex) {
					fit_val -= 1;
				}
				else if ((currentQueenPosition - nextQueenPosition) == diagonalIndex) {
					fit_val -= 1;
				}
			}
		}
	}
	
	void crossover(State obj_State) {
			

		int start = No_Of_Queen/2;
		int end = No_Of_Queen;
		
		int** newGene = new int*[2];
		for (int i = 0; i < 2;i++){
				newGene[i] = new int[No_Of_Queen];
		}

		for (int i = 0; i < end; i++) {
			if (i< start) {
				newGene[1][i] = stoi(obj_State.state[i]);
				newGene[0][i] = stoi(this->state[i]);
			}
			else {
				newGene[0][i] = stoi(obj_State.state[i]);
				newGene[1][i] = stoi(this->state[i]);
			}
		}

		for (auto i = 0; i < No_Of_Queen; i++) {
			obj_State.state[i] = to_string(newGene[0][i]);
			this->state[i] = to_string(newGene[1][i]);
		}

	}

	void mutate() {
		
		int genePosition = rand() % No_Of_Queen;
		string newGene = intToString(rand() % No_Of_Queen + 1);
		state[genePosition] = newGene;

	}

	string intToString(int i) {

		return to_string(i);
	}
	
};

#endif
