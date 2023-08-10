#ifndef Selection_H
#define Selection_H

#include "State.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;
#define CHUNK 4

class Selection {

public:

	int maxSelection;


	Selection(int maxsel) {
		this->maxSelection = maxsel;
		
	}
	
	

	void Fitess(State * States) {
		bool flag = true;
		State tempState;
		int j;
		while (flag) {
			flag = false;  // Assume no swap happened.
			for (j = 0; j < maxSelection - 1; j++) {
				if (States[j].fit_val < States[j + 1].fit_val) {
					tempState = States[j]; // the swap element.
					States[j] = States[j + 1];
					States[j + 1] = tempState;
					flag = true; // a swap occurred, so we continue.
				}
			}
		}
	}
	
};


#endif
