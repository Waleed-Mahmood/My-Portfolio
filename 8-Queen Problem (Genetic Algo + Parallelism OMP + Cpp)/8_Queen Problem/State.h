#ifndef State_H
#define State_H

#include "State.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

#define CHUNK 4


using namespace std;

class State {
public:

	string state;
	int fit_val;

	State() {
		state = generateState();
		Calculate_Fitness();
	}

	string generateState() {

		string state = "";
		int number;
		for (int i = 0; i < 8; i++) {
			// 1<=number<=8;
			number = rand() % 8 + 1;
			state.append(intToString(number));
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

		for (int i = 0; i < 8; i++) {
			diagonalIndex = 0;
			QueenCurrent = state.substr(i, 1);

			for (index = i + 1; index < 8; index++) {
				diagonalIndex = index - i;
				QueenNext = state.substr(index, 1);

				// Count side attacks.
				if (QueenCurrent == QueenNext) {
					fit_val -= 1;
				}

				// Count diagonal attacks.
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
		

		int start = 4;
		int end = 8;
		
		int newGene[2][8];

		for (int i = 0; i < 8; i++) {
			if (i<4) {
				newGene[1][i] = obj_State.state.at(i)-'0';
				newGene[0][i] = this->state.at(i) - '0';
			}
			else {
				newGene[0][i] = obj_State.state.at(i) - '0';
				newGene[1][i] = this->state.at(i) - '0';
			}
		}

		string s1 = "";
		string s2 = "";

		for (auto i = 0; i < 8; i++) {
			s1 += to_string(newGene[0][i]);
			s2 += to_string(newGene[1][i]);
		}
		obj_State.state = s2;
		this->state = s2;

	}

	void mutate() {
		
		int genePosition = rand() % 8;
		string newGene = intToString(rand() % 8 + 1);

		if (genePosition == 0) {
			state = newGene + state.substr(genePosition + 1);
		}
		else if (genePosition == 7) {
			state = state.substr(0, genePosition) + newGene;
		}
		else {
			state = state.substr(0, genePosition) + newGene + state.substr(genePosition + 1);
		}
	}

	string intToString(int i) {

		return to_string(i);
	}
	
	// Operator overloader to copy the states

	State* operator=(State* src) {
		State* desc = new State();
		desc->fit_val = src->fit_val;
		desc->state = src->state;
		return desc;
	}
};

#endif
