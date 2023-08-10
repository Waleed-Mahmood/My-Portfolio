#pragma once
#include"Person.h"
#include"Employee.h"
#include<iostream>
using namespace std;
class Course;

class Teacher : public Employee {
private:
	static int courseCount;
	char* designation;
	Course** listOfCourses;	//Teacher--Course(Aggregation)
	int currentNoOfCourses;
	int maxAllowedCourses;


public:
	
	Teacher(const char fname[], const char lname[], const char gen[], int age, const char pass[], long int eId, const char design[], int telExt, int cAllowed) :Employee(fname, lname, gen, age, eId,pass, design, telExt), Person(fname, lname, gen, age,pass) {
		
		designation = new char[strlen(design) + 1];
		strcpy_s(designation, strlen(design) + 1, design);

		maxAllowedCourses = cAllowed;
		listOfCourses = new Course * [maxAllowedCourses];
		currentNoOfCourses = 0;

		cout << "Teacher() called\n";
	}
	
	////Teacher(const Teacher& obj) {
	////	courseCount = new int;
	////	*courseCount = *obj.courseCount;
	////	
	////	designation = new char[strlen(obj.designation) + 1];
	////	strcpy_s(designation, strlen(obj.designation) + 1, obj.designation);
	/////*	maxAllowedCourses = obj.maxAllowedCourses;
	////	listOfCourses = new Course * [obj.maxAllowedCourses];
	////	currentNoOfCourses = obj.currentNoOfCourses;*/
	////	cout << "Teacher(Teacher&obj) called\n";
	////}

	void printInformation()
	{
		Employee::printInformation();
		/*cout << endl << "NUMBER OF COURSE: " << *courseCount << endl;*/

	}
	
	void changePassId(long int ei,const char P[]) {
		Person::changeP(P);
		Employee::changeID(ei);
	}
		
	Teacher getTeacher() {
		return *this;
	}

	long int getTeacherID() {
		return empId;
	}

	char* getTecPass() {
		return password;
	}

	int getCount() {
		return courseCount;
	}

	char* getDesignation() {
		return designation;
	}




	~Teacher() {
		cout << "~Teacher() called\n";
		delete[]designation;

	}
};
int  Teacher:: courseCount = 0;