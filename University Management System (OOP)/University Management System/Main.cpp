#include"University.h"
#include"Teacher.h"
#include"Course.h"
#include"Department.h"
#include"Student.h"
#include"Registration.h"
//#include"TA.h"
#include"IT Manager.h"

#include<iostream>
using namespace std;

//template<class Type>
//void growList2D(Type**& List, int& cap) {
//	Type** temp = new Type * [cap + 1];
//	for (int i = 0; i < cap; i++) {
//		temp[i] = List[i];
//	}
//	delete[]List;
//	List = temp;
//	temp = NULL;
//}
//

template<class Type>
void growList1D(Type*& List, int& cap) {
	Type* temp = new Type[cap + 1];
	for (int i = 0; i < cap; i++) {
		temp[i] = List[i];
	}
	delete List;
	List = temp;
	temp = NULL;
}

int main() {
	University U1("FAST",5);
	U1.startUP();
	cout << endl;
	system("pause");
	return 0;

	
	//U1.printUniInfo();
	//cout << endl<<endl;
	//
	///*Department D2= U1.buildDepartment("Science & Humanities", 10, 10);*/
	//
	//Department D2("Science & Humanities", 2,2,2);
	///*D2.addHOD(t3);*/
	//
	//D2.regItManager("Rania", "Hussain", "F", 35, "adff3", 20024, "MPHIL", 306);

	////Course c1(1234, "asdf");
	////Registration r1(s1, c1);
	////r1.getCourse();

	//D2.regTeacher(t1);
	//D2.regTeacher(t2);
	//D2.regTeacher(t3);
	//D2.addCourse(1056, "OOP-F");
	//D2.addCourse(1005, "OOP-E");
	//D2.addCourse(1000, "DLD-F");
	//D2.addCourse(1001, "DLD-E");
	//D2.regStudent(s1);
	//D2.regStudent(s2);
	//D2.regStudent(s3);

	//D2.printAllDeptInfo();
	/*D2.unRegCourse(1001, "DLD-E");
	cout << endl;
	D2.unRegStd(s2);
	cout << endl;
	D2.unRegTeacher(t2);
	D2.assignCourse_Teach(t3, "OOP-F");
	D2.printAllDeptInfo();*/
	
	cout << endl;

	
	/*cout << endl;
	cout << *s2.getCgpa()<<endl;
	cout << *s2.getLastName()<<endl;
	cout<< *s2.getAge()<<endl;*/

	//Person p1("p", "n", "F", 33);
	//p1.printInformation();
	//
	//cout<<endl << *p1.getAge()<<endl;

	//cout << endl << *t1.getAge() << "\t" << t1.getDesignation() << endl;


	/*IT_Manager it1("t", "c", "m", 45, 12223, "HOd", 344, 5);
	it1.printInformation();*/

	//Employee e1("e", "c", "m", 33, 4567, "IT", 999);
	//Employee e2("e2", "c", "m", 33, 4566, "IT", 799);
	//e2.printInformation();

	//TA a1("TA", "f", "F", 23, 1987, 4.4, 6, 890);
	//a1.printInformation();
	
}