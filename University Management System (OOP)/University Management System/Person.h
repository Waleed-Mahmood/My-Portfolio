#pragma once
#include<iostream>
using namespace std;

class Person {
protected:
	char* firstName;
	char* lastName;
	char* gender;
	int Age;
	char* password;

public:
	////Person() {
	////	firstName = 0;
	////	lastName = 0;
	////	gender = 0;
	////	Age = 0;
	////	cout << "def"<<endl;
	////}

	Person(const char fname[], const char lname[], const char gen[], int age,const char pass[]) {
		firstName = new char[strlen(fname) + 1];
		strcpy_s(firstName, strlen(fname) + 1, fname);

		lastName = new char[strlen(lname) + 1];
		strcpy_s(lastName, strlen(lname) + 1, lname);

		gender = new char[strlen(gen) + 1];
		strcpy_s(gender, strlen(gen) + 1, gen);
		Age = age;

		password = new char[strlen(pass) + 1];
		strcpy_s(password, strlen(pass) + 1, pass);

		cout << "Person() called" << endl;

	}
	void changeP(const char Pas[]) {
		delete[] password;
		password = new char[strlen(Pas) + 1];
		strcpy_s(password, strlen(Pas) + 1, Pas);
	}

	void printInformation() {
		cout <<"Name: "<< firstName << " " << lastName <<"\tGender: "<<gender <<"\tAge: " << Age;

	}

	char* getFirstName() {
		return firstName;
	}

	char* getLastName() {
		return lastName;
	}

	char* getGender() {
		return gender;
	}

	char* getPassword() {
		return password;
	}

	int getAge() {
		return Age;
	}

	~Person()
	{
		delete[]firstName;
		delete[]lastName;
		delete[]gender;
		cout << "~Person() called\n";
	}

};


