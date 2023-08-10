#pragma once
#include"Person.h"
#include"Student.h"
#include"Teacher.h"

#include<iostream>
using namespace std;

class TA :public Student, public Teacher {
public:
	TA(const char fname[], const char lname[], const char gen[], int age, int roll, float cgpa, int courseAll, int _courseCount, int telExt) :Student(fname, lname, gen, age, roll, cgpa), Teacher(fname, lname, gen, age, roll, "TA", telExt,courseAll, _courseCount), Person(fname, lname, gen, age) {// Person(fname, lname, age)    else default constructor will	
		cout << "TA() called\n";

	}

	void printInformation() {
		Teacher::printInformation();
		cout << "CGPA:" << Student::getCgpa() << endl;
	}
	~TA() {
		cout << "~TA() called\n";
	}

};
