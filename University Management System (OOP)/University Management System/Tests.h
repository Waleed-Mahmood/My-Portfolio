#pragma once
#include<iostream>
using namespace std;

class Tests {
private:
	double totalMarks;
	double obtMarks;
	double weightage;
	double sum;
	
public:
	Tests() {
		totalMarks = 0;
		obtMarks = 0;
		weightage = 0;
		sum = 0;
	

	}
	Tests(double tm, double om, double w) {
		totalMarks = tm;
		obtMarks = om;
		weightage = w;
		sum = 0;

	}

	void printMarks() {
		cout << "Mark Sheet: " << endl;
		cout << "Obtained Marks: " << obtMarks << "\tTotal Marks: " << totalMarks << "\t Weightage: " << weightage << endl;

	}

	double getTm() {
		return totalMarks;
	}

	double getOm() {
		return obtMarks;
	}

	double getW() {
		return weightage;
	}

	double getSum() {
		sum = (obtMarks / totalMarks) * weightage;
		return sum;
	}
};