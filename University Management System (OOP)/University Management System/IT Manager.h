#pragma once
#include"Person.h"
#include"Employee.h"
#include<iostream>
using namespace std;

class IT_Manager: public Employee {
	char* designation;
public:
	IT_Manager(const char fname[], const char lname[], const char gen[], int age, const char pass[], long int eId, const char design[], int telExt) :Employee(fname, lname, gen, age,eId,pass, design, telExt), Person(fname, lname, gen, age,pass)  {
		designation = new char[strlen(design) + 1];
		strcpy_s(designation, strlen(design) + 1, design);

	}

	void printInformation()
	{
		 Employee::printInformation();
		
	}

	char* getDesignation() {
		return designation;
	}

	long int getEmpId() {
		return empId;
	}

	char* getPassword() {
		return password;
	}

	~IT_Manager() {
		delete[]designation;
	}



};

