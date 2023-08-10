#include<iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include "State.h"
#include "Selection.h"
#include "Print_Board.h"
#include<omp.h>
#include<ctime>
#include <chrono>
#include<windows.h>
#include <ratio>
#include<cmath>


using namespace std;

const int maxSelection = 20;
const int maxGeneration = 100000;
#define CHUNK 4


int main(int argc, char* argv[]) {

	srand(time(0));


	State* States;


	States = new State[maxSelection];

	//		1	---------------------------------------

	using namespace std::chrono;

	high_resolution_clock::time_point  Nulltime;


	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	//#pragma omp parallel for schedule(static,CHUNK)
   // #pragma omp parallel for schedule(dynamic) 
	//#pragma omp parallel for schedule(guided,CHUNK)
	#pragma omp parallel for schedule(runtime)
	for (int i = 0; i < maxSelection; i++) {
		States[i] = new State();
	}
	
	//		1	---------------------------------------
	
	string return_string = "";

	int selectionNumber = ceil(maxSelection / 2.0);
	Print_Board obj_Print_Board("11111111");

	boolean breaker = false;

	for (int i = 0; i < maxGeneration && breaker != true; i++) {

		Selection obj_papulation(maxSelection);

		obj_papulation.Fitess(States);
		obj_Print_Board.put_Queens(States[0].state);
		
		//		2	---------------------------------------
	//#pragma omp parallel for schedule(static,CHUNK)
//#pragma omp parallel for schedule(dynamic) 
//#pragma omp parallel for schedule(guided,CHUNK)
		#pragma omp parallel for schedule(runtime)
		for (int i = 1; i < maxSelection; i++) {
			States[i].state = States[0].state;
		}

		//		2	---------------------------------------

		int cross_over = 0.4 * maxSelection;
		int mutate = cross_over + cross_over;

		//		3	---------------------------------------
//#pragma omp parallel for schedule(static,CHUNK)
//#pragma omp parallel for schedule(dynamic) 
//#pragma omp parallel for schedule(guided,CHUNK)
		#pragma omp parallel for schedule(runtime)
		for (int j = 0; j < mutate; j++) {
			States[j].mutate();
		}

		//		3	---------------------------------------

		int crossover = maxSelection - maxSelection * 0.1;

		//		4	---------------------------------------
//#pragma omp parallel for schedule(static,CHUNK)
//#pragma omp parallel for schedule(dynamic) 
//#pragma omp parallel for schedule(guided,CHUNK)
		#pragma omp parallel for schedule(runtime)
		for (int j = 0; j < cross_over; j++) {

			States[j].crossover(States[rand() % crossover]);
		}

		//		4	---------------------------------------


		//		5	---------------------------------------
//#pragma omp parallel for schedule(static,CHUNK)
//#pragma omp parallel for schedule(dynamic) 
//#pragma omp parallel for schedule(guided,CHUNK)
		#pragma omp parallel for schedule(runtime)
		for (int j = 0; j < maxSelection && breaker != true; j++) {
			States[j].Calculate_Fitness();
			if (States[j].fit_val == 28) {
				cout << "*****" << States[j].state << "*******" << endl;
				return_string = States[j].state;
				breaker = true;
			}
		}

		//		5	---------------------------------------

		if (breaker != true) {
			cout << "*****" << States[0].state << "--------" << States[0].fit_val << endl;

		}
	}

	obj_Print_Board.put_Queens(return_string);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double, std::milli> time_span = t2 - t1;

	cout << "\n time taken by system =" << time_span.count() << " miliseconds";
	getch();
	
	return 0;
}
