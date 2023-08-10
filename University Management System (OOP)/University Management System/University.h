#pragma once
#include"Department.h"
#include"Student.h"
#include"Teacher.h"
#include<iostream>
#include<fstream>
using namespace std;


Department d1, d2, d3, d4, d5;
class University {

private:
	char* uniName;
	int maxDepartments;
	int maxDepTeacher;
	int currentDept;
	Department** listOfDepartments;	//University--Department(Composition)&(Dept are created right away)
	/*dept()ogin*/


public:
	University() {
		uniName = 0;
		maxDepartments = 0;
		currentDept = 0;
		listOfDepartments = 0;
		maxDepTeacher = 0;
	}

	University(const char uName[], int maxDept) {
		uniName = new char[strlen(uName) + 1];
		strcpy_s(uniName, strlen(uName) + 1, uName);

		maxDepartments = maxDept;
		currentDept = 0;
		maxDepTeacher = 0;

		listOfDepartments = new Department * [maxDepartments];	//(Dept are created right away)
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

	void startUP() {
		char name[50];
		int maxT, maxC, maxS;
		ifstream startfile("StartUP.txt");
		int i = 0;
		while (startfile >> name >> maxC >> maxT >> maxS) {
			if (i == 0) {
				d1 = buildDepartment(name, maxC, maxT, maxS);
				d1.printDeptInfo();

			}
			if (i == 1) {
				d2 = buildDepartment(name, maxC, maxT, maxS);
				d2.printDeptInfo()
					;
			}
			if (i == 2) {
				d3 = buildDepartment(name, maxC, maxT, maxS);
				d3.printDeptInfo();
			}
			if (i == 3) {
				d4 = buildDepartment(name, maxC, maxT, maxS);
				d4.printDeptInfo();
			}
			if (i == 4) {
				d5 = buildDepartment(name, maxC, maxT, maxS);
				d5.printDeptInfo();
			}
			if (i == 5) {
				break;
			}
			i++;
		}
		startfile.close();

		Teacher t1("Kamaran", "Ali", "M", 45, "rty123", 12223, "PHD", 344, 10);
		Teacher t2("Ali", "Hamza", "M", 65, "wert43", 223, "PHD", 304, 8);
		Teacher t3("Rania", "Hussain", "F", 35, "adff3", 20024, "MPHIL", 306, 2);
		Teacher t4("Anam", "Kamran", "F", 35, "lkjhh6", 20025, "MS", 306, 2);
		Teacher t5("Waleed", "Mahmood", "M", 35, "m65rg5", 20026, "MPHIL", 306, 2);
		Teacher t6("Kareem", "Ajmal", "M", 37, "23td", 20027, "MS", 306, 2);
		Teacher t7("Abdullah", "Khan", "M", 30, "bvft54", 20028, "MPHIL", 306, 2);

		Student s1("s", "t", "M", 24, "fgkkf90", 3456, 3.45F);
		Student s2("ww", "t", "M", 22, "oiuyt6", 3400, 3.67F);
		Student s3("Ali", "ahmed", "M", 19, "eroplm2", 9930, 2.8F);

		//add courses
		ifstream cFile("Course.txt");
		char cn[20];
		char cc[20];
		int c = 0;

		while (cFile >> cc >> cn) {
			if (c <= 4) {
				d1.addCourse(cc, cn);
			}
			if (c > 4 && c <= 6) {
				d2.addCourse(cc, cn);

			}
			if (c > 6 && c <= 9) {
				d3.addCourse(cc, cn);
			}
			if (c > 9 && c <= 11) {
				d4.addCourse(cc, cn);
			}
			if (c == 12) {
				d5.addCourse(cc, cn);
			}
			c++;
		}

		d1.regHOD("Zafar", "Adnan", "M", 47, "qwerty123", 1122, "PHD", 300, 10);
		d1.regItManager("Azhar", "Ali", "M", 48, "werty123", 0101, "IT", 773);
		d1.regTeacher(t1);
		d1.regTeacher(t2);
		d1.regTeacher(t3);
		d1.regStudent(s1);
		d1.regStudent(s2);
		d1.addRegistratioin(3456, "PF-A");

		d2.regHOD("Waleed", "Mahmood", "M", 35, "qwerty345", 2233, "MPHIL", 306, 2);
		d2.regItManager("Ahmed", "Mahmood", "M", 45, "werty345", 0202, "IT", 774);
		d2.regTeacher(t4);
		d2.regStudent(s3);

		d3.regHOD("Hashim", "Akram", "M", 40, "qwerty678", 3344, "PHD", 700, 5);
		d3.regItManager("Hashim", "Akmal", "M", 39, "werty678", 0303, "IT", 775);
		d3.regTeacher(t5);

		d4.regHOD("Kareem", "Ajmal", "M", 37, "qwerty321", 4455, "MPHIL", 709, 5);
		d4.regItManager("Shahzad", "Iqbal", "M", 57, "werty321", 0404, "IT", 776);
		d4.regTeacher(t6);

		d5.regHOD("Ali", "Hamza", "M", 60, "qwerty543", 5566, "PHD", 710, 8);
		d5.regItManager("Shaheed", "Hamza", "M", 60, "werty543", 0505, "IT", 777);
		d5.regTeacher(t7);

		d1.printDeptInfo();

		//input window

		int D = 0; char user[40];
		int I = 0, G = 0;
		int Q = -1;
		long int id;
		char pas[50];
		cout << "Available Departments: " << endl;
		for (int i = 0; i < currentDept; i++) {
			cout << i << "-	";
			listOfDepartments[i]->getDeptName();
			cout << endl;
		}
		cout << endl << "\nSelect Department (0-4):\t";
		cin >> D;
		switch (D) {
		case 0:
			/* identitification + functionalities{*/

			
			cout << "Your's Identity (0-3): " << endl;
			cout << "0-	HOD" << "\n1-	IT-Manager" << "\n2-	Teacher" << "\n3-	Student" << endl;
			cin >> I;
			cout << endl;
			if (I == 0) {
				cout << "Show HOD ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d1.showHodPassword();
				}

				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d1.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 4) {
						cout << "HOD Funtionalities: " << endl;
						cout << "0-\tAssign courses to teachers\n1-\tRegister a course for a student\n2-\tUnregister a course for a student\n3-\tView grades of a specific course\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-4) : " << endl;
						cin >> Q;
						if (Q == 0) {
							id = 0; pas[0] = '\0';
							d1.printDepTeachers();
							d1.printDeptCourses();
							cout << "Enter Teacher's ID:	";
							cin >> id;
							cout << "Enter CourseName:	";
							cin >> pas;
							d1.assignCourse_Teach(id, pas);
						}
						if (Q == 1) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d1.addRegistratioin(id, pas);
						}
						if (Q == 2) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d1.delRegistration(id, pas);
						}
						if (Q == 3) {
							id = 0; pas[0] = '\0'; char gra;
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gra;
							d1.assignGRade(gra, pas);
							cout << endl;
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 1) {
				cout << "Show ITmanager ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d1.showItPassword();
				}
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d1.authItPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					Q = -1;
					char fn[30], ln[30], g[10], pas[100], d[15];
					long int Id, e;
					int tell, ca, a;
					float gpa;
					while (Q != 5) {
						cout << "IT-Manager Funtionalities: " << endl;
						cout << "0-\tCreate account of Teacher\n1-\tDelete account of Teacher\n2-\tCreate account of students\n3-\tDelete accounts of students\n4-\tMaintain accounts (e.g. change Rollno(UserName), password, etc.)\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (0-5) : " << endl;
						cin >> Q;
						if (Q == 0) {

							cout << "Enter FirstName,LastName,Gender(M/F),Age,ID,Password,Designation(PHD,MPHIL,MS),Tel Extension,Course Allowed: " << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> d >> tell >> c;
							d1.regTeacher(fn, ln, g, a, pas, Id, d, tell, c);
						}
						if (Q == 1) {

							cout << "Enter Employee ID: " << endl;
							cin >> e;
							d1.unRegTeacher(e);

						}
						if (Q == 2) {
							cout << "Enter FirstName,LastName,Gender(M/F),Age,RollNo,Password,CGPA" << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> gpa;
							d1.regStudent(fn, ln, g, a, pas, Id, gpa);
						}
						if (Q == 3) {
							cout << "Enter Roll No: " << endl;
							cin >> e;
							d1.unRegStd(e);

						}
						if (Q == 4) {
							a = -1;
							while (a != 2) {
								cout << "Select Teacher(0)/Student(1)/Exit(2): ";
								cin >> a;
								if (a == 0) {
									cout << "Enter Current EmployeeId(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d1.changePassID(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}
								if (a == 1) {
									cout << "Enter Current RollNO(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d1.changeStdPassId(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}

							}

						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 2) {
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d1.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 5) {
						cout << "Teacher Funtionalities: " << endl;
						cout << "2-\tManage Evaluation of students(e.g. Marks, Weightage)\n3-\tView evaluation report of a specific course displaying all evaluations of all the students of that course\n4-\tAssign grades to students\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (2-5) : " << endl;
						cin >> Q;

						if (Q == 2) {
							int z, x, v;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Total Obtained & Weightage: ";
							cin >> z >> x >> v;
							cout << endl;
							d1.addTest(id, pas, z, x, v);
						}
						if (Q == 3) {
							cout << "Enter Course Name: ";
							cin >> pas;
							d1.viewStdGrades(pas);
							d1.viewMarks();
						}
						if (Q == 4) {
							char gr;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gr;
							d1.assignGRade(gr, pas);
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 3) {
				cout << "Enter ID(Roll NO) & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d1.authStuPassword(id, pas)) {
					cout << "Login Successful :)" << endl;
					while (Q != 6) {
						cout << "Student Funtionalities: " << endl;
						cout << "0-\tRegister course\n1-\tUnregister a course\n2-\tView marksheet of a specific course\n3-\tChange password\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-6) : " << endl;
						cin >> Q;
						if (Q == 0) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d1.addStdCorRegistratioin(id, pas);

						}
						if (Q == 1) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d1.delStdCorRegistratioin(id, pas);

						}

						if (Q == 2) {
							cout << "Enter CourseName: ";
							cin >> pas;
							d1.viewStdGrades(pas);
						}

						if (Q == 3) {
							cout << "Enter Current RollNO(Username):	";
							cin >> id;
							cout << "Enter Current Password:	";
							cin >> pas;
							d1.changeStdPassId(id, pas);
							cout << "New ID and Password: ";
							cout << id << "	" << pas;

						}

					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			break;
		case 1:
			/* identitification + functionalities{*/

			cout << "Your's Identity (0-3): " << endl;
			cout << "0-	HOD" << "\n1-	IT-Manager" << "\n2-	Teacher" << "\n3-	Student" << endl;
			cin >> I;
			cout << endl;
			if (I == 0) {
				cout << "Show HOD ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d2.showHodPassword();
				}

				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d2.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 4) {
						cout << "HOD Funtionalities: " << endl;
						cout << "0-\tAssign courses to teachers\n1-\tRegister a course for a student\n2-\tUnregister a course for a student\n3-\tView grades of a specific course\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-4) : " << endl;
						cin >> Q;
						if (Q == 0) {
							id = 0; pas[0] = '\0';
							d2.printDepTeachers();
							d2.printDeptCourses();
							cout << "Enter Teacher's ID:	";
							cin >> id;
							cout << "Enter CourseName:	";
							cin >> pas;
							d2.assignCourse_Teach(id, pas);
						}
						if (Q == 1) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d2.addRegistratioin(id, pas);
						}
						if (Q == 2) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d2.delRegistration(id, pas);
						}
						if (Q == 3) {
							id = 0; pas[0] = '\0'; char gra;
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gra;
							d2.assignGRade(gra, pas);
							cout << endl;
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 1) {
				cout << "Show ITmanager ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d2.showItPassword();
				}
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d2.authItPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					Q = -1;
					char fn[30], ln[30], g[10], pas[100], d[15];
					long int Id, e;
					int tell, ca, a;
					float gpa;
					while (Q != 5) {
						cout << "IT-Manager Funtionalities: " << endl;
						cout << "0-\tCreate account of Teacher\n1-\tDelete account of Teacher\n2-\tCreate account of students\n3-\tDelete accounts of students\n4-\tMaintain accounts (e.g. change Rollno(UserName), password, etc.)\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (0-5) : " << endl;
						cin >> Q;
						if (Q == 0) {

							cout << "Enter FirstName,LastName,Gender(M/F),Age,ID,Password,Designation(PHD,MPHIL,MS),Tel Extension,Course Allowed: " << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> d >> tell >> c;
							d2.regTeacher(fn, ln, g, a, pas, Id, d, tell, c);
						}
						if (Q == 1) {

							cout << "Enter Employee ID: " << endl;
							cin >> e;
							d2.unRegTeacher(e);

						}
						if (Q == 2) {
							cout << "Enter FirstName,LastName,Gender(M/F),Age,RollNo,Password,CGPA" << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> gpa;
							d2.regStudent(fn, ln, g, a, pas, Id, gpa);
						}
						if (Q == 3) {
							cout << "Enter Roll No: " << endl;
							cin >> e;
							d2.unRegStd(e);

						}
						if (Q == 4) {
							a = -1;
							while (a != 2) {
								cout << "Select Teacher(0)/Student(1)/Exit(2): ";
								cin >> a;
								if (a == 0) {
									cout << "Enter Current EmployeeId(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d2.changePassID(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}
								if (a == 1) {
									cout << "Enter Current RollNO(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d2.changeStdPassId(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}

							}

						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 2) {
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d2.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 5) {
						cout << "Teacher Funtionalities: " << endl;
						cout << "2-\tManage Evaluation of students(e.g. Marks, Weightage)\n3-\tView evaluation report of a specific course displaying all evaluations of all the students of that course\n4-\tAssign grades to students\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (2-5) : " << endl;
						cin >> Q;

						if (Q == 2) {
							int z, x, v;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Total Obtained & Weightage: ";
							cin >> z >> x >> v;
							cout << endl;
							d2.addTest(id, pas, z, x, v);
						}
						if (Q == 3) {
							cout << "Enter Course Name: ";
							cin >> pas;
							d2.viewStdGrades(pas);
							d2.viewMarks();
						}
						if (Q == 4) {
							char gr;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gr;
							d2.assignGRade(gr, pas);
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 3) {
				cout << "Enter ID(Roll NO) & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d2.authStuPassword(id, pas)) {
					cout << "Login Successful :)" << endl;
					while (Q != 6) {
						cout << "Student Funtionalities: " << endl;
						cout << "0-\tRegister course\n1-\tUnregister a course\n2-\tView marksheet of a specific course\n3-\tChange password\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-6) : " << endl;
						cin >> Q;
						if (Q == 0) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d2.addStdCorRegistratioin(id, pas);

						}
						if (Q == 1) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d2.delStdCorRegistratioin(id, pas);

						}

						if (Q == 2) {
							cout << "Enter CourseName: ";
							cin >> pas;
							d2.viewStdGrades(pas);
						}

						if (Q == 3) {
							cout << "Enter Current RollNO(Username):	";
							cin >> id;
							cout << "Enter Current Password:	";
							cin >> pas;
							d2.changeStdPassId(id, pas);
							cout << "New ID and Password: ";
							cout << id << "	" << pas;

						}

					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			break;
		case 2:
			/* identitification + functionalities{*/

			cout << "Your's Identity (0-3): " << endl;
			cout << "0-	HOD" << "\n1-	IT-Manager" << "\n2-	Teacher" << "\n3-	Student" << endl;
			cin >> I;
			cout << endl;
			if (I == 0) {
				cout << "Show HOD ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d3.showHodPassword();
				}

				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d3.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 4) {
						cout << "HOD Funtionalities: " << endl;
						cout << "0-\tAssign courses to teachers\n1-\tRegister a course for a student\n2-\tUnregister a course for a student\n3-\tView grades of a specific course\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-4) : " << endl;
						cin >> Q;
						if (Q == 0) {
							id = 0; pas[0] = '\0';
							d3.printDepTeachers();
							d3.printDeptCourses();
							cout << "Enter Teacher's ID:	";
							cin >> id;
							cout << "Enter CourseName:	";
							cin >> pas;
							d3.assignCourse_Teach(id, pas);
						}
						if (Q == 1) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d3.addRegistratioin(id, pas);
						}
						if (Q == 2) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d3.delRegistration(id, pas);
						}
						if (Q == 3) {
							id = 0; pas[0] = '\0'; char gra;
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gra;
							d3.assignGRade(gra, pas);
							cout << endl;
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 1) {
				cout << "Show ITmanager ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d3.showItPassword();
				}
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d3.authItPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					Q = -1;
					char fn[30], ln[30], g[10], pas[100], d[15];
					long int Id, e;
					int tell, ca, a;
					float gpa;
					while (Q != 5) {
						cout << "IT-Manager Funtionalities: " << endl;
						cout << "0-\tCreate account of Teacher\n1-\tDelete account of Teacher\n2-\tCreate account of students\n3-\tDelete accounts of students\n4-\tMaintain accounts (e.g. change Rollno(UserName), password, etc.)\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (0-5) : " << endl;
						cin >> Q;
						if (Q == 0) {

							cout << "Enter FirstName,LastName,Gender(M/F),Age,ID,Password,Designation(PHD,MPHIL,MS),Tel Extension,Course Allowed: " << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> d >> tell >> c;
							d3.regTeacher(fn, ln, g, a, pas, Id, d, tell, c);
						}
						if (Q == 1) {

							cout << "Enter Employee ID: " << endl;
							cin >> e;
							d3.unRegTeacher(e);

						}
						if (Q == 2) {
							cout << "Enter FirstName,LastName,Gender(M/F),Age,RollNo,Password,CGPA" << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> gpa;
							d3.regStudent(fn, ln, g, a, pas, Id, gpa);
						}
						if (Q == 3) {
							cout << "Enter Roll No: " << endl;
							cin >> e;
							d3.unRegStd(e);

						}
						if (Q == 4) {
							a = -1;
							while (a != 2) {
								cout << "Select Teacher(0)/Student(1)/Exit(2): ";
								cin >> a;
								if (a == 0) {
									cout << "Enter Current EmployeeId(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d3.changePassID(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}
								if (a == 1) {
									cout << "Enter Current RollNO(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d3.changeStdPassId(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}

							}

						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 2) {
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d3.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 5) {
						cout << "Teacher Funtionalities: " << endl;
						cout << "2-\tManage Evaluation of students(e.g. Marks, Weightage)\n3-\tView evaluation report of a specific course displaying all evaluations of all the students of that course\n4-\tAssign grades to students\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (2-5) : " << endl;
						cin >> Q;

						if (Q == 2) {
							int z, x, v;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Total Obtained & Weightage: ";
							cin >> z >> x >> v;
							cout << endl;
							d3.addTest(id, pas, z, x, v);
						}
						if (Q == 3) {
							cout << "Enter Course Name: ";
							cin >> pas;
							d3.viewStdGrades(pas);
							d3.viewMarks();
						}
						if (Q == 4) {
							char gr;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gr;
							d3.assignGRade(gr, pas);
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 3) {
				cout << "Enter ID(Roll NO) & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d3.authStuPassword(id, pas)) {
					cout << "Login Successful :)" << endl;
					while (Q != 6) {
						cout << "Student Funtionalities: " << endl;
						cout << "0-\tRegister course\n1-\tUnregister a course\n2-\tView marksheet of a specific course\n3-\tChange password\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-6) : " << endl;
						cin >> Q;
						if (Q == 0) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d3.addStdCorRegistratioin(id, pas);

						}
						if (Q == 1) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d3.delStdCorRegistratioin(id, pas);

						}

						if (Q == 2) {
							cout << "Enter CourseName: ";
							cin >> pas;
							d3.viewStdGrades(pas);
						}

						if (Q == 3) {
							cout << "Enter Current RollNO(Username):	";
							cin >> id;
							cout << "Enter Current Password:	";
							cin >> pas;
							d3.changeStdPassId(id, pas);
							cout << "New ID and Password: ";
							cout << id << "	" << pas;

						}

					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			break;
		case 3:
			/* identitification + functionalities{*/

			cout << "Your's Identity (0-3): " << endl;
			cout << "0-	HOD" << "\n1-	IT-Manager" << "\n2-	Teacher" << "\n3-	Student" << endl;
			cin >> I;
			cout << endl;
			if (I == 0) {
				cout << "Show HOD ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d4.showHodPassword();
				}

				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d4.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 4) {
						cout << "HOD Funtionalities: " << endl;
						cout << "0-\tAssign courses to teachers\n1-\tRegister a course for a student\n2-\tUnregister a course for a student\n3-\tView grades of a specific course\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-4) : " << endl;
						cin >> Q;
						if (Q == 0) {
							id = 0; pas[0] = '\0';
							d4.printDepTeachers();
							d4.printDeptCourses();
							cout << "Enter Teacher's ID:	";
							cin >> id;
							cout << "Enter CourseName:	";
							cin >> pas;
							d4.assignCourse_Teach(id, pas);
						}
						if (Q == 1) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d4.addRegistratioin(id, pas);
						}
						if (Q == 2) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d4.delRegistration(id, pas);
						}
						if (Q == 3) {
							id = 0; pas[0] = '\0'; char gra;
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gra;
							d4.assignGRade(gra, pas);
							cout << endl;
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 1) {
				cout << "Show ITmanager ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d4.showItPassword();
				}
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d4.authItPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					Q = -1;
					char fn[30], ln[30], g[10], pas[100], d[15];
					long int Id, e;
					int tell, ca, a;
					float gpa;
					while (Q != 5) {
						cout << "IT-Manager Funtionalities: " << endl;
						cout << "0-\tCreate account of Teacher\n1-\tDelete account of Teacher\n2-\tCreate account of students\n3-\tDelete accounts of students\n4-\tMaintain accounts (e.g. change Rollno(UserName), password, etc.)\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (0-5) : " << endl;
						cin >> Q;
						if (Q == 0) {

							cout << "Enter FirstName,LastName,Gender(M/F),Age,ID,Password,Designation(PHD,MPHIL,MS),Tel Extension,Course Allowed: " << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> d >> tell >> c;
							d4.regTeacher(fn, ln, g, a, pas, Id, d, tell, c);
						}
						if (Q == 1) {

							cout << "Enter Employee ID: " << endl;
							cin >> e;
							d4.unRegTeacher(e);

						}
						if (Q == 2) {
							cout << "Enter FirstName,LastName,Gender(M/F),Age,RollNo,Password,CGPA" << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> gpa;
							d4.regStudent(fn, ln, g, a, pas, Id, gpa);
						}
						if (Q == 3) {
							cout << "Enter Roll No: " << endl;
							cin >> e;
							d4.unRegStd(e);

						}
						if (Q == 4) {
							a = -1;
							while (a != 2) {
								cout << "Select Teacher(0)/Student(1)/Exit(2): ";
								cin >> a;
								if (a == 0) {
									cout << "Enter Current EmployeeId(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d4.changePassID(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}
								if (a == 1) {
									cout << "Enter Current RollNO(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d4.changeStdPassId(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}

							}

						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 2) {
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d4.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 5) {
						cout << "Teacher Funtionalities: " << endl;
						cout << "2-\tManage Evaluation of students(e.g. Marks, Weightage)\n3-\tView evaluation report of a specific course displaying all evaluations of all the students of that course\n4-\tAssign grades to students\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (2-5) : " << endl;
						cin >> Q;

						if (Q == 2) {
							int z, x, v;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Total Obtained & Weightage: ";
							cin >> z >> x >> v;
							cout << endl;
							d4.addTest(id, pas, z, x, v);
						}
						if (Q == 3) {
							cout << "Enter Course Name: ";
							cin >> pas;
							d4.viewStdGrades(pas);
							d4.viewMarks();
						}
						if (Q == 4) {
							char gr;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gr;
							d4.assignGRade(gr, pas);
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 3) {
				cout << "Enter ID(Roll NO) & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d4.authStuPassword(id, pas)) {
					cout << "Login Successful :)" << endl;
					while (Q != 6) {
						cout << "Student Funtionalities: " << endl;
						cout << "0-\tRegister course\n1-\tUnregister a course\n2-\tView marksheet of a specific course\n3-\tChange password\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-6) : " << endl;
						cin >> Q;
						if (Q == 0) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d4.addStdCorRegistratioin(id, pas);

						}
						if (Q == 1) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d4.delStdCorRegistratioin(id, pas);

						}

						if (Q == 2) {
							cout << "Enter CourseName: ";
							cin >> pas;
							d4.viewStdGrades(pas);
						}

						if (Q == 3) {
							cout << "Enter Current RollNO(Username):	";
							cin >> id;
							cout << "Enter Current Password:	";
							cin >> pas;
							d4.changeStdPassId(id, pas);
							cout << "New ID and Password: ";
							cout << id << "	" << pas;

						}

					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			break;
		case 4:
			/* identitification + functionalities{*/

			
			cout << "Your's Identity (0-3): " << endl;
			cout << "0-	HOD" << "\n1-	IT-Manager" << "\n2-	Teacher" << "\n3-	Student" << endl;
			cin >> I;
			cout << endl;
			if (I == 0) {
				cout << "Show HOD ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d5.showHodPassword();
				}

				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d5.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 4) {
						cout << "HOD Funtionalities: " << endl;
						cout << "0-\tAssign courses to teachers\n1-\tRegister a course for a student\n2-\tUnregister a course for a student\n3-\tView grades of a specific course\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-4) : " << endl;
						cin >> Q;
						if (Q == 0) {
							id = 0; pas[0] = '\0';
							d5.printDepTeachers();
							d5.printDeptCourses();
							cout << "Enter Teacher's ID:	";
							cin >> id;
							cout << "Enter CourseName:	";
							cin >> pas;
							d5.assignCourse_Teach(id, pas);
						}
						if (Q == 1) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d5.addRegistratioin(id, pas);
						}
						if (Q == 2) {
							id = 0; pas[0] = '\0';
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << endl;
							d5.delRegistration(id, pas);
						}
						if (Q == 3) {
							id = 0; pas[0] = '\0'; char gra;
							cout << "Enter Student (long int)RollNO:\t";
							cin >> id;
							cout << "Enter CourseName(eg.OOP-F)\t";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gra;
							d5.assignGRade(gra, pas);
							cout << endl;
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 1) {
				cout << "Show ITmanager ID & Password (Yes=1,NO=0):\t";
				cin >> G;
				if (G == 1) {
					d5.showItPassword();
				}
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				if (d5.authItPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					Q = -1;
					char fn[30], ln[30], g[10], pas[100], d[15];
					long int Id, e;
					int tell, ca, a;
					float gpa;
					while (Q != 5) {
						cout << "IT-Manager Funtionalities: " << endl;
						cout << "0-\tCreate account of Teacher\n1-\tDelete account of Teacher\n2-\tCreate account of students\n3-\tDelete accounts of students\n4-\tMaintain accounts (e.g. change Rollno(UserName), password, etc.)\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (0-5) : " << endl;
						cin >> Q;
						if (Q == 0) {

							cout << "Enter FirstName,LastName,Gender(M/F),Age,ID,Password,Designation(PHD,MPHIL,MS),Tel Extension,Course Allowed: " << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> d >> tell >> c;
							d5.regTeacher(fn, ln, g, a, pas, Id, d, tell, c);
						}
						if (Q == 1) {

							cout << "Enter Employee ID: " << endl;
							cin >> e;
							d5.unRegTeacher(e);

						}
						if (Q == 2) {
							cout << "Enter FirstName,LastName,Gender(M/F),Age,RollNo,Password,CGPA" << endl;
							cin >> fn >> ln >> g >> a >> Id >> pas >> gpa;
							d5.regStudent(fn, ln, g, a, pas, Id, gpa);
						}
						if (Q == 3) {
							cout << "Enter Roll No: " << endl;
							cin >> e;
							d5.unRegStd(e);

						}
						if (Q == 4) {
							a = -1;
							while (a != 2) {
								cout << "Select Teacher(0)/Student(1)/Exit(2): ";
								cin >> a;
								if (a == 0) {
									cout << "Enter Current EmployeeId(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d5.changePassID(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}
								if (a == 1) {
									cout << "Enter Current RollNO(Username):	";
									cin >> Id;
									cout << "Enter Current Password:	";
									cin >> pas;
									d5.changeStdPassId(Id, pas);
									cout << "New ID and Password: ";
									cout << Id << "	" << pas;

								}

							}

						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 2) {
				cout << "Enter empID & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d5.authTecPassword(id, pas)) {
					cout << "Login Successful :)" << endl << endl;
					while (Q != 5) {
						cout << "Teacher Funtionalities: " << endl;
						cout << "2-\tManage Evaluation of students(e.g. Marks, Weightage)\n3-\tView evaluation report of a specific course displaying all evaluations of all the students of that course\n4-\tAssign grades to students\n5-\tPress 5 for Exit" << endl;
						cout << "Select Operation to perform (2-5) : " << endl;
						cin >> Q;

						if (Q == 2) {
							int z, x, v;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Total Obtained & Weightage: ";
							cin >> z >> x >> v;
							cout << endl;
							d5.addTest(id, pas, z, x, v);
						}
						if (Q == 3) {
							cout << "Enter Course Name: ";
							cin >> pas;
							d5.viewStdGrades(pas);
							d5.viewMarks();
						}
						if (Q == 4) {
							char gr;
							cout << "Enter CourseName: ";
							cin >> pas;
							cout << "Enter Grade: ";
							cin >> gr;
							d5.assignGRade(gr, pas);
						}
					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			if (I == 3) {
				cout << "Enter ID(Roll NO) & Password\t";
				cin >> id;
				cin >> pas;
				Q = -1;
				if (d5.authStuPassword(id, pas)) {
					cout << "Login Successful :)" << endl;
					while (Q != 6) {
						cout << "Student Funtionalities: " << endl;
						cout << "0-\tRegister course\n1-\tUnregister a course\n2-\tView marksheet of a specific course\n3-\tChange password\n4-\tPress 4 for Exit" << endl;
						cout << "Select Operation to perform (0-6) : " << endl;
						cin >> Q;
						if (Q == 0) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d5.addStdCorRegistratioin(id, pas);

						}
						if (Q == 1) {
							cout << "Enter CourseName(eg. OOP-F):\t";
							cin >> pas;
							d5.delStdCorRegistratioin(id, pas);

						}

						if (Q == 2) {
							cout << "Enter CourseName: ";
							cin >> pas;
							d5.viewStdGrades(pas);
						}

						if (Q == 3) {
							cout << "Enter Current RollNO(Username):	";
							cin >> id;
							cout << "Enter Current Password:	";
							cin >> pas;
							d5.changeStdPassId(id, pas);
							cout << "New ID and Password: ";
							cout << id << "	" << pas;

						}

					}
				}
				else
					cout << "Wrong Input :(" << endl;
			}
			break;
		default:
			cout << "Wrong Input :(" << endl;
		}
		

	}

	Department buildDepartment(const char dName[], int maxC_offers, int max_Teachers, int maxStd) {
		if (currentDept == maxDepartments) {
			cout << "Max Departments Reached!! :( Increasing Limit by 1" << endl;
			growList2D(listOfDepartments, maxDepartments);
		}
		else {

			listOfDepartments[currentDept++] = new Department(dName, maxC_offers, max_Teachers, maxStd);
			cout << "Department Successfully built :)" << endl;
			int c = currentDept - 1;
			return listOfDepartments[c]->getobj();


		}
	}

	int getCurrentDept() {
		return currentDept;
	}

	void printUniInfo() {
		cout << "University Name: " << uniName << "\tDepartments: " << maxDepartments << endl;

	}

	void printDepInfo() {
		for (int i = 0; i < currentDept; i++) {
			listOfDepartments[i]->printDeptInfo();
		}
	}

	~University() {
		delete[]uniName;
		
		for (int i = 0; i < currentDept; i++) {
			delete listOfDepartments[i];
		}
		delete[]listOfDepartments;
		cout << "~University() called" << endl;

	}

};

