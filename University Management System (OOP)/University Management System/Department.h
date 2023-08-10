#pragma once

#include"Course.h"
#include"Teacher.h"
#include"Student.h"
#include"IT Manager.h"
#include"Registration.h"

#include<iostream>
using namespace std;

class Department {
private:
	char* deptName;
	Course** listOfCourses;		//Department--Course(Composition)
	int currentNoOfcourses;
	int maxCourseOffers;
	Teacher* Teacher_HOD;	//Departmetn--Teacher(Aggregation)
	int currentNoOfHOD;
	char* depHOD;
	char* HODpass;
	char* ITpass;
	long int HODid, ITid;
	char* depItMan;
	Teacher** listOfTeachers;	//Department--Teacher(Aggregation)
	int currentNoOfTeachers;
	int maxTeachers;
	IT_Manager* IT;	//Department--IT_Manager(Aggregation)
	int currentNoOfITManager;
	Student** listOfStudents;	//Depaertment--Student(Aggregation)
	int currentNoOfStudents;
	int maxStudents;
	Registration** listOfRegistration;
	int currentNoOfReg;
	int maxRegistration;

public:
	Department() {
		deptName = 0;
		Teacher_HOD = 0;
		currentNoOfHOD = 0;
		listOfCourses = 0;
		HODpass = 0;
		ITpass = 0;
		depHOD = 0;
		depItMan = 0;
		currentNoOfcourses = 0;
		maxCourseOffers = 0;
		maxTeachers = 0;
		currentNoOfTeachers = 0;
		listOfTeachers = 0;
		listOfStudents = 0;
		currentNoOfStudents = 0;
		maxStudents = 0;
		IT = 0;
		HODpass = 0;
		ITpass = 0;
		currentNoOfITManager = 0;
		listOfRegistration = 0;
		currentNoOfReg = 0;
		maxRegistration = 0;
	}

	Department(const char dName[], int max_Teachers, int maxC_Offers, int maxStd) {
		deptName = new char[strlen(dName) + 1];
		strcpy_s(deptName, strlen(dName) + 1, dName);

		maxCourseOffers = maxC_Offers;
		currentNoOfcourses = 0;
		listOfCourses = new Course * [maxCourseOffers];

		currentNoOfTeachers = 0;
		maxTeachers = max_Teachers;
		listOfTeachers = new Teacher * [maxTeachers];

		currentNoOfStudents = 0;
		maxStudents = maxStd;
		listOfStudents = new Student * [maxStudents];

		currentNoOfReg = 0;
		maxRegistration = 2000;
		listOfRegistration = new Registration * [maxRegistration];


		currentNoOfITManager = 0;
		currentNoOfHOD = 0;
		IT = 0;
		Teacher_HOD = 0;
		depHOD = 0;
		depItMan = 0;
	}

	/*Department(const Department& obj) {

		deptName = new char[strlen(obj.deptName) + 1];
		strcpy_s(deptName, strlen(obj.deptName) + 1, obj.deptName);

		maxCourseOffers = obj.maxCourseOffers;
		currentNoOfcourses = obj.maxCourseOffers;
		listOfCourses = new Course * [obj.maxCourseOffers];

		maxTeachers = obj.maxTeachers;
		currentNoOfTeachers = obj.currentNoOfTeachers;
		listOfTeachers = new Teacher * [obj.maxTeachers];

		maxStudents = obj.maxStudents;
		currentNoOfStudents = obj.currentNoOfStudents;
		listOfStudents = new Student * [obj.maxStudents];
	}*/

	Department& operator=(const Department& obj) {
		deptName = new char[strlen(obj.deptName) + 1];
		strcpy_s(deptName, strlen(obj.deptName) + 1, obj.deptName);

		maxCourseOffers = obj.maxCourseOffers;
		currentNoOfcourses = obj.currentNoOfcourses;
		listOfCourses = new Course * [obj.maxCourseOffers];

		currentNoOfTeachers = obj.currentNoOfTeachers;
		maxTeachers = obj.maxTeachers;
		listOfTeachers = new Teacher * [obj.maxTeachers];

		maxStudents = obj.maxStudents;
		currentNoOfStudents = obj.currentNoOfStudents;
		listOfStudents = new Student * [obj.maxStudents];

		currentNoOfReg = 0;
		maxRegistration = 2000;
		listOfRegistration = new Registration * [obj.maxRegistration];

		currentNoOfITManager = 0;
		currentNoOfHOD = 0;
		IT = 0;
		Teacher_HOD = 0;
		depHOD = 0;
		depItMan = 0;

		return *this;
	}

	void printDeptInfo() {

		cout << "Department Name: " << deptName << "\tTotal Teachers: " << currentNoOfTeachers << "\tCourses Offered: " << currentNoOfcourses << "\tTotal Students: " << currentNoOfStudents << endl;

	}

	void printAllDeptInfo() {
		cout << "*************************************************************" << endl;
		cout << "Department Name: " << deptName << "\tTotal Teachers: " << currentNoOfTeachers << "\tCourses Offered: " << currentNoOfcourses << "\tTotal Students: " << currentNoOfStudents << endl << endl;
		cout << "Department Teachers: " << endl;
		for (int i = 0; i < currentNoOfTeachers; ++i) {
			cout << i + 1 << ". ";
			listOfTeachers[i]->printInformation();
		}
		cout << "*************************************************************" << endl;

		cout << "Department Offered Courses: " << endl;
		for (int i = 0; i < currentNoOfcourses; ++i) {
			cout << i + 1 << ". ";
			listOfCourses[i]->printCourseInfo();
		}
		cout << "*************************************************************" << endl;

		cout << "Registered Students: " << endl;
		for (int i = 0; i < currentNoOfStudents; i++) {
			cout << i + 1 << ". ";
			listOfStudents[i]->printInformation();
		}
		cout << "*************************************************************" << endl;
	}

	void printDeptCourses() {
		cout << "*************************************************************" << endl;
		cout << "Department Name: " << deptName << "\tCourses Offered: " << currentNoOfcourses << endl << endl;
		cout << "Department Offered Courses: " << endl;
		for (int i = 0; i < currentNoOfcourses; ++i) {
			cout << i + 1 << ". ";
			listOfCourses[i]->printCourseInfo();
		}
		cout << "*************************************************************" << endl;
	}

	void printDeptStudents() {
		cout << "*************************************************************" << endl;
		cout << "Department Name: " << deptName << "\tTotal Students: " << currentNoOfStudents << endl << endl;
		cout << "Registered Students: " << endl;
		for (int i = 0; i < currentNoOfStudents; i++) {
			cout << i + 1 << ". ";
			listOfStudents[i]->printInformation();
		}
		cout << "*************************************************************" << endl;
	}

	void printDepTeachers() {
		cout << "*************************************************************" << endl;
		cout << "Department Name: " << deptName << "\tTotal Teachers: " << currentNoOfTeachers << endl << endl;
		cout << "Department Teachers: " << endl;
		for (int i = 0; i < currentNoOfTeachers; ++i) {
			cout << i + 1 << ". ";
			listOfTeachers[i]->printInformation();
		}
		cout << "*************************************************************" << endl;
	}

	void printDepHodIT() {
		cout << "Department Name:\t" << deptName << endl;
		cout << "Department HOD:\t" << depHOD;
		cout << "Department IT_Manager\t" << depItMan << endl;
	}

	void showHodPassword() {
		cout << "ID:\t" << HODid;
		cout << "Password:\t" << HODpass;
	}

	void showItPassword() {
		cout << "ID:\t" << ITid;
		cout << "Password:\t" << ITpass;
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

	void regHOD(const char fname[], const char lname[], const char gen[], int age, const char pass[], long int eId, const char design[], int telExt, int cAllowed) {
		if (currentNoOfHOD >= 1) {
			cout << "Max HOD Limit Reached! :(" << endl;
		}
		Teacher_HOD = new Teacher(fname, lname, gen, age, pass, eId, design, telExt, cAllowed);
		cout << "HOD Successfully Reagistered :)" << endl;
		currentNoOfHOD++;
		int j = 0; int s = 0;
		int i = 0;
		i = strlen(fname);
		j = strlen(lname);
		s = i + j + 1;
		depHOD = new char[s];
		HODid = eId;
		HODpass = new char[strlen(pass) + 1];
		strcpy_s(HODpass, strlen(pass) + 1, pass);

		strcpy_s(depHOD, i, fname);
		strcat_s(depHOD, s, lname);
		cout << depHOD;

	}

	void regItManager(const char fname[], const char lname[], const char gen[], int age, const char pass[], long int eId, const char design[], int telExt) {
		if (currentNoOfITManager == 1) {
			cout << "Max Teacher Limit Reached! :(" << endl;
		}
		IT = new IT_Manager(fname, lname, gen, age, pass, eId, design, telExt);
		cout << "IT Manager Successfully Registered :)" << endl;
		currentNoOfITManager++;
		int j = 0; int s = 0;
		int i = 0;
		i = strlen(fname) + 1;
		j = strlen(lname) + 1;
		s = i + j + 1;
		depItMan = new char[s];
		ITid = eId;
		ITpass = new char[strlen(pass) + 1];
		strcpy_s(ITpass, strlen(pass) + 1, pass);

		strcpy_s(depItMan, i, fname);
		strcat_s(depItMan, s, lname);
		cout << depItMan;

	}

	void regTeacher(Teacher& teach) {
		if (currentNoOfTeachers == maxTeachers) {
			cout << "Max Teacher Limit Reached! :(	Increasing Limit by 1" << endl;
			growList2D(listOfTeachers, maxTeachers);
		}

		listOfTeachers[currentNoOfTeachers++] = new Teacher(teach);
		cout << "Teacher Successfully Registered :)" << endl;

	}

	void regTeacher(const char fname[], const char lname[], const char gen[], int age, const char pass[], long int eId, const char design[], int telExt, int cAllowed) {
		if (currentNoOfTeachers == maxTeachers) {
			cout << "Max Teacher Limit Reached! :(	Increasing Limit by 1" << endl;
			growList2D(listOfTeachers, maxTeachers);
		}

		listOfTeachers[currentNoOfTeachers++] = new Teacher(fname, lname, gen, age, pass, eId, design, telExt, cAllowed);
		cout << "Teacher Successfully Registered :)" << endl;

	}

	void unRegTeacher(Teacher& teach) {
		for (int i = 0; i < currentNoOfTeachers; i++) {
			if (listOfTeachers[i]->getTeacherID() == teach.getTeacherID()) {
				for (int j = i; j < currentNoOfTeachers - 1; j++) {
					listOfTeachers[j] = listOfTeachers[j + 1];
				}
				listOfTeachers[--currentNoOfTeachers] = 0;
				cout << "Teacher Successfully Unregistered :)" << endl;
				break;
			}
			cout << "Matching <=" << i << "=>" << endl;
		}
	}

	void unRegTeacher(long int id) {
		for (int i = 0; i < currentNoOfTeachers; i++) {
			if (listOfTeachers[i]->getTeacherID() == id) {
				for (int j = i; j < currentNoOfTeachers - 1; j++) {
					listOfTeachers[j] = listOfTeachers[j + 1];
				}
				listOfTeachers[--currentNoOfTeachers] = 0;
				cout << "Teacher Successfully Unregistered :)" << endl;
				break;
			}
			cout << "Matching <=" << i << "=>" << endl;
		}
	}

	void regStudent(Student& std) {
		if (currentNoOfStudents == maxStudents) {
			cout << "Max Student Limit Reached! :(	Incresing Limit by 1" << endl;
			growList2D(listOfStudents, maxStudents);
		}
		listOfStudents[currentNoOfStudents++] = new Student(std);
		cout << "Student Successfully Registered :)" << endl;
	}

	void regStudent(const char fname[], const char lname[], const char gen[], int age, const char pass[], long int roll, float cgpa) {
		if (currentNoOfStudents == maxStudents) {
			cout << "Max Student Limit Reached! :(	Incresing Limit by 1" << endl;
			growList2D(listOfStudents, maxStudents);
		}
		listOfStudents[currentNoOfStudents++] = new Student(fname, lname, gen, age, pass, roll, cgpa);
		cout << "Student Successfully Registered :)" << endl;
	}

	void unRegStd(Student& std) {
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (listOfStudents[i]->getRollNo() == std.getRollNo()) {
				for (int j = i; j < currentNoOfStudents - 1; j++) {
					listOfStudents[j] = listOfStudents[j + 1];
				}
				listOfStudents[--currentNoOfStudents] = 0;
				cout << "Student Successfully Unregistered :)" << endl;
				break;
			}
			cout << "Matching <=" << i << "=>" << endl;
		}
	}

	void unRegStd(long int id) {
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (*listOfStudents[i]->getRollNo() == id) {
				for (int j = i; j < currentNoOfStudents - 1; j++) {
					listOfStudents[j] = listOfStudents[j + 1];
				}
				listOfStudents[--currentNoOfStudents] = 0;
				cout << "Student Successfully Unregistered :)" << endl;
				break;
			}
			cout << "Matching <=" << i << "=>" << endl;
		}
	}

	bool addRegistratioin(long int roll, const char cName[]) {
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (*listOfStudents[i]->getRollNo() == roll) {
				for (int j = 0; j < currentNoOfcourses; j++) {
					if (strcmp(listOfCourses[j]->getCourse(), cName) == 0) {
						listOfRegistration[currentNoOfReg++] = new Registration(&listOfStudents[i]->getStudent(), &listOfCourses[j]->getCobj());
						cout << "Registration Successfull :)" << endl;
						return 1;
					}
				}
				cout << "Registration Unsuccessfull :(" << endl;
				return 0;
			}

		}
		cout << "Registration Unsuccessfull :(" << endl;
		return 0;
	}

	bool addTest(long int emp,const char cName[],double t,double o,double w) {
		for (int i = 0; i < currentNoOfTeachers; i++) {
			if (listOfTeachers[i]->getEmpID()==emp)	{
				for (int j = 0; j < currentNoOfcourses; j++) {
					if (strcmp(listOfCourses[i]->getCourse(),cName)==0)	{
						for (int k = 0; k < currentNoOfReg; k++) {
							if (strcmp(listOfRegistration[k]->getCourse(), cName)) {
								listOfRegistration[k]->addMarks(o, t, w);
							}
						}
					}
				}
			}
		}
	}

	bool assignGRade(const char g,const char cName[]) {
		for (int i = 0; i < currentNoOfReg; i++) {
			if (strcmp(listOfRegistration[i]->getCourse(), cName) == 0) {
				listOfRegistration[i]->assignGrade(g);
				cout << "Grade Successfully Assigned :)" << endl;
				return 1;
			}
		}
		cout << "Grade Assigning Unsuccessfull :(" << endl;
		return 0;
		
	}

	bool addStdCorRegistratioin(long int roll, const char cName[]) {
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (*listOfStudents[i]->getRollNo() == roll) {
				for (int j = 0; j < currentNoOfcourses; j++) {
					if (strcmp(listOfCourses[j]->getCourse(), cName) == 0) {
						listOfCourses[j]->regStdCourse(listOfStudents[i]->getStudent());
						listOfStudents[i]->regStdCourse(listOfCourses[j]->getCobj());
						cout << "Registration Successfull :)" << endl;
						return 1;
					}
				}
				cout << "Registration Unsuccessfull :(" << endl;
				return 0;
			}

		}
		cout << "Registration Unsuccessfull :(" << endl;
		return 0;
	}

	bool delStdCorRegistratioin(long int roll, const char cName[]) {
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (*listOfStudents[i]->getRollNo() == roll) {
				for (int j = 0; j < currentNoOfcourses; j++) {
					if (strcmp(listOfCourses[j]->getCourse(), cName) == 0) {
						listOfCourses[j]->unRegStdCourse(listOfStudents[i]->getStudent());
						listOfStudents[i]->unRegStdCourse(listOfCourses[j]->getCobj());
						cout << "Successfully Unregistered :)" << endl;
						return 1;
					}
				}
				cout << "Operation Unsuccessfull :(" << endl;
				return 0;
			}

		}
		cout << "Operation Unsuccessfull :(" << endl;
		return 0;
	}

	bool delRegistration(long int roll, const char cName[]) {
		for (int i = 0; i < currentNoOfReg; i++) {
			if (*listOfRegistration[i]->getStudentRoll() == roll && strcmp(listOfRegistration[i]->getCourse(), cName) == 0) {
				for (int j = i; j < currentNoOfReg - 1; j++) {
					listOfRegistration[j] = listOfRegistration[j + 1];
				}
				listOfRegistration[--currentNoOfReg] = 0;
				cout << "Successfully Unregistered :)" << endl;
				return 1;
			}
			cout << "Matching <=" << i << "=>" << endl;
		}
		cout << "Operation Unsuccessfull :(" << endl;
		return 0;
	}

	void addCourse(const char cCode[], const char cName[]) {
		if (currentNoOfcourses == maxCourseOffers) {
			cout << "Max Course Limit Reached! :(	Increasing Limit by 1" << endl;
			growList2D(listOfCourses, maxCourseOffers);
		}

		listOfCourses[currentNoOfcourses++] = new Course(cCode, cName);
		cout << "Course Successfully Added :)" << endl;

	}

	void unRegCourse(const char cCode[], const char cName[]) {
		for (int i = 0; i < currentNoOfcourses; i++) {
			if (strcmp(listOfCourses[i]->getCourseCode(), cCode) == 0 && strcmp(listOfCourses[i]->getCourse(), cName) == 0) {
				for (int j = i; j < currentNoOfcourses - 1; j++) {
					listOfCourses[j] = listOfCourses[j + 1];
				}
				listOfCourses[--currentNoOfcourses] = 0;
				cout << "Course Successfully Unregistered :)" << endl;
				break;
			}
			cout << "Matching <=" << i << "=>" << endl;
		}
	}

	void assignCourse_Teach(long int emp, const char cName[]) {
		int j = 0;
		for (int i = 0; i < currentNoOfcourses; i++) {
			if (strcmp(listOfCourses[i]->getCourse(), cName) == 0)	//Course found
			{
				for (int j = 0; j < currentNoOfTeachers; j++) {
					if (listOfTeachers[j]->getEmpID() == emp) {

						cout << "Successfully Assigned Course To Teacher :)" << endl;
						listOfCourses[i]->assignTeachCourse(listOfTeachers[j]->getTeacher());
						j = i;
						break;

					}

				}

			}
			cout << "Matching <=" << i << "=>" << endl;
		}
	}

	bool changePassID(long int id, const char p[]) {
		long int e;
		char pa[100];
		for (int i = 0; i < currentNoOfTeachers; i++) {
			if (listOfTeachers[i]->getEmpID() == id && strcmp(listOfTeachers[i]->getPassword(), p) == 0) {
				cout << "Enter new (long int)ID:	";
				cin >> e;
				cout << "Enter Password: ";
				cin >> pa;
				listOfTeachers[i]->changePassId(e, pa);
				cout << "Successfully Changed :)" << endl;
				return 1;
			}
		}
		cout << "Operation Unsuccessful :(" << endl;
		return 0;


	}

	bool changeStdPassId(long int e, const char p[]) {
		long int ei;
		char pa[100];
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (*listOfStudents[i]->getRollNo() == e && strcmp(listOfStudents[i]->getPassword(), p) == 0) {
				cout << "Enter new (long int)ID:	";
				cin >> ei;
				cout << "Enter Password: ";
				cin >> pa;
				listOfStudents[i]->changeRollPass(ei, pa);
				cout << "Successfully Changed :)" << endl;
				return 1;
			}
		}
		cout << "Operation Unsuccessful :(" << endl;
		return 0;

	}

	bool authTecPassword(long int id, const char pass[]) {
		for (int i = 0; i < currentNoOfTeachers; i++) {
			if (listOfTeachers[i]->getEmpID() == id && strcmp(listOfTeachers[i]->getTecPass(), pass) == 0) {
				return 1;
			}
		}
		return 0;
	}

	bool authStuPassword(long int id, const char pass[]) {
		for (int i = 0; i < currentNoOfStudents; i++) {
			if (*listOfStudents[i]->getRollNo() == id && strcmp(listOfStudents[i]->getPassword(), pass) == 0) {
				return 1;
			}
		}
		return 0;
	}

	bool authItPassword(long int id, const char pass[]) {
		if (IT->getEmpID() == id && strcmp(IT->getPassword(), pass) == 0) {
			return 1;
		}
		return 0;
	}
		
	void viewStdGrades(const char cName[]) {
		for (int i = 0; i < currentNoOfReg; i++) {
			if (strcmp(listOfRegistration[i]->getCourse(), cName) == 0) {
				cout<<listOfRegistration[i]->getGRADE();
				 listOfRegistration[i]->viewMarks();
			}
		}
	}

	void viewMarks() {
		for (int i = 0; i < currentNoOfReg; i++) {
			listOfRegistration[i]->viewMarks();
		}
	}

	Department getobj() {
		return *this;
	}

	void getDeptName() {
		cout << "Department Name: " << deptName;
	}

	~Department() {
		for (int i = 0; i < currentNoOfcourses; i++) {
			delete listOfCourses[i];
		}
		delete[]listOfCourses;
	}

};

