#pragma once
//#include"TA.h"\

#include"Teacher.h"
#include"Student.h"
#include<iostream>
using namespace std;

class Registration;

class Course {
private:
	char* courseName;
	char* courseCode;
	Registration** listOfRegistration;	//Course--Registration(Aggregation)
	int currentNoOfReg;
	int maxReg;
	Teacher* T;
	//TA* _TA;	//Aggregation

public:
	Course() {
		T = 0;
		strcpy_s(courseCode, strlen("No Code") + 1, "No Code");
		strcpy_s(courseName, strlen("No Name") + 1, "No Name");
		listOfRegistration = 0;
		currentNoOfReg = 0;
		maxReg = 0;
		T = 0;
	}

	Course(const char cCode[], const char cName[]) {
		courseName = new char[strlen(cName) + 1];
		strcpy_s(courseName, strlen(cName) + 1, cName);

		courseCode = new char[strlen(cCode) + 1];
		strcpy_s(courseCode, strlen(cCode) + 1, cCode);
		maxReg = 2000;
		listOfRegistration = new Registration * [maxReg];
		currentNoOfReg = 0;
		T = 0;
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

	char* getCourseCode() {
		return courseCode;
	}

	char* getCourse() {
		return courseName;
	}

	Course getCobj() {
		return *this;
	}

	void printCourseInfo() {
		cout << "Course Code: " << courseCode << "\tCourse Name: " << courseName << endl;
	}

	void regStdCourse(Student S) {

		if (currentNoOfReg == maxReg) {
			cout << "Max No Of Reg Reached!! :(\tIncreasing Limit By 1: " << endl;
			growList2D(listOfRegistration, maxReg);
		}
		for (int i = 0; i < currentNoOfReg; i++) {
			listOfRegistration[currentNoOfReg++] = new Registration(&S, &this->getCobj());
			cout << "Successfully Registered :)" << endl;
		}	
	}

	bool unRegStdCourse(Student S) {
		for (int i = 0; i < currentNoOfReg; i++) {
			if (listOfRegistration[i]->getStudentRoll()==S.getRollNo()) {
				for (int j = i; j < currentNoOfReg - 1; j++) {
					listOfRegistration[j] = listOfRegistration[j + 1];
				}
				listOfRegistration[--currentNoOfReg] = 0;
				cout << "Course Successfully Unregistered :)" << endl;
				return true;
			}
			else
			{
				cout << "Course Not Found :(" << endl;
				return false;
			}
			}
		}


	void assignTeachCourse(Teacher teach) {
		T = &teach;
		T->printInformation();
		cout << "Course Assigned\t" << courseCode << "\t" << courseName << endl;

	}

	~Course() {
		delete[]courseName;

	}


};