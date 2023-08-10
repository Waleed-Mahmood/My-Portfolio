#pragma once

#include"Person.h"
#include<iostream>
using namespace std;

class Employee :virtual public Person {
protected:

	static int empCount;
	char* designation;
	int telExtension;
	long int empId;

public:
	///*Employee() {
	//	empId=0;
	//	empCount=0;
	//	designation=0;
	//	telExtension=0;
	//}*/
	Employee(const char fname[], const char lname[], const char gen[], int age, int Id, const char pass[], const char design[], int telExt) :Person(fname, lname, gen, age,pass) {
		empId = Id;
		telExtension = telExt;
		designation = new char[strlen(design) + 1];
		strcpy_s(designation, strlen(design) + 1, design);
		empCount++;
	}

	void printInformation() {
		Person::printInformation();
		cout << endl << "Emp Id: " << empId << "\tEmp Designation: " << designation << "\tEmp Tel Ext.: " << telExtension << /* "\nTotal Emp: " << empCount <<*/ endl;

	}

	void changeID(long int e) {
		empId = e;
	}

	int getTelExt() {
		return telExtension;
	}

	long int getEmpID() {
		return empId;
	}

	~Employee() {
		delete[]designation;
		cout << "~Employee() called\n";
	}


};

int Employee::empCount = 0;
