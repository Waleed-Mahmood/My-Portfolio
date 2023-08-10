#pragma once
#include<iostream>
#include"Course.h"
#include"Tests.h"
using namespace std;

class Student;

class Registration {
private:
	Student* Stud;
	Course* Cs;
	Tests** listOfTests;	//Registration--Tests(Composition)
	int currentTests;
	int maxTests;
	char Grade;
	bool withDraw;

	char attendance[200] = { 'p','a','p','a' };
	long int date[200] = { 120920120,13092020,14092020,15092020,16092020 };
public:
	Registration() {
		Stud = 0;
		Cs = 0;
		withDraw = false;
		listOfTests = 0;
		currentTests = 0;
		maxTests = 0;
	}

	Registration(Student* student, Course* course) {
		Stud = student;
		Cs = course;
		withDraw = false;
	}
	template<class Type>
	void growList2D(Type**& List, int& cap) {
		Type** temp = new Type * [cap + 1];
		for (int i = 0; i < cap; i++) {
			temp[i] = List[i];
		}
		delete[]List;
		List = temp;
		temp = NULL;
	}

	bool addMarks(double o, double t, double w) {
		if (currentTests == maxTests) {
			cout << "Max Test Limit Reached :(	Increasing Limit By 1" << endl;
			growList2D(listOfTests, maxTests);
		}
		listOfTests[currentTests++] = new Tests(t, o, w);
		cout << "Marks Successfully added :)" << endl;
	}

	void viewMarks() {
		for (int i = 0; i < currentTests; i++) {
			listOfTests[i]->printMarks();
		}
	}

	void assignGrade(const char g) {
			double sum=0;
		for (int i = 0; i < currentTests; i++) {
			sum = sum+listOfTests[i]->getSum();
		}
		cout << "TOTAL MARKS: 100" << "\tTOTAL Sum Obtained: " << sum;
		Grade = g;
	}
	
	char getGRADE() {
		return Grade;
	}


	char* getCourse() {
		return Cs->getCourse();
	}

	long int* getStudentRoll() {
		return Stud->getRollNo();
	}

	~Registration() {
		for (int i = 0; i < currentTests; i++) {
			delete listOfTests[i];
		}
		delete[] listOfTests;
	}


};
