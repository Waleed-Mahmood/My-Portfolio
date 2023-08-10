#pragma once
#include"Registration.h"
#include"Person.h"
#include<iostream>
using namespace std;

class Course;
class Student : public Person {
private:
	float* CGPA;
	long int* rollNO;
	Registration** listOfRegistration;	//Student--Registration(Aggregation)
	int currentNoOfReg;
	int maxCourseReg;


public:
	///*Student() {
	//	CGPA = nullptr;
	//	rollNO = nullptr;
	//	listOfRegistration = 0;
	//	currentNoOfReg = 0;
	//	maxCourseReg = 0;
	//}*/

	Student(const char fname[], const char lname[], const char gen[], int age, const char pass[],long int roll, float cgpa) : Person(fname, lname, gen, age,pass) {

		CGPA = new float;
		*CGPA = cgpa;

		rollNO = new long int;
		*rollNO = roll;
		maxCourseReg = 2000;
		listOfRegistration = new Registration * [maxCourseReg];
		currentNoOfReg = 0;
		
		cout << "Student() called\n";
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
	
	bool regStdCourse(Course C) {
		if (currentNoOfReg == maxCourseReg) {
			if (currentNoOfReg == maxCourseReg) {
				cout << "Max No Of Reg Reached!! :(\tIncreasing Limit By 1: " << endl;
				growList2D(listOfRegistration, maxCourseReg);
			}
			for (int i = 0; i < currentNoOfReg; i++) {
				listOfRegistration[currentNoOfReg++] = new Registration(&this->getStudent(), &C);

			}

		}
	}
	bool unRegStdCourse(Course C) {
		for (int i = 0; i < currentNoOfReg; i++) {
			if (listOfRegistration[i]->getCourse()==C.getCourse()) {
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


	//bool unRegCourse(Registration* reg) {//reg
	//	for (int i = 0; i < currentNoOfReg; i++) {
	//		if (reg->getCourse() == listOfRegistration[i]->getCourse()) {
	//			for (int j = i; j < currentNoOfReg - 1; j++) {
	//				listOfRegistration[j] = listOfRegistration[j + 1];
	//			}
	//			listOfRegistration[--currentNoOfReg] = 0;
	//			cout << "Course Successfully Unregistered :)" << endl;
	//			return true;
	//		}
	//		else
	//		{
	//			cout << "Course Not Found :(" << endl;
	//			return false;
	//		}

	//	}

	//}

	////bool withDrawCourse(Registration* reg) {//course to withdraw
	////	for (int i = 0; i < currentNoOfReg; i++) {
	////		if (listOfRegistration[i]->getCourse() == reg->getCourse()) {
	////		listOfRegistration[i]

	//		}
	//	}
	//}

	void printInformation()
	{
		Person::printInformation();
		cout << endl << "Roll No: " << *rollNO << "\tCGPA: " << *CGPA << endl;
	}

	void changeRollPass(long int e,const char p[]) {
		delete rollNO;
		rollNO = new long int;
		*rollNO = e;
		Person::changeP(p);
	}

	float* getCgpa() {
		return CGPA;
	}

	char* getStdPass() {
		return password;
	}
	long int* getRollNo() {
		return rollNO;
	}
	Student getStudent() {
		return *this;
	}

	~Student() {
		delete CGPA;
		delete rollNO;
		cout << "~Student() called\n";
	}

};
