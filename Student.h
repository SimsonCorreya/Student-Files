#pragma once
#include <iostream>    // cout / cin
#include <iomanip>     // setw()
#include <string>      // cin >> string

using namespace std;				// std::cin   -> cin 

class Student {						// class declaration.....

	int ID;							// class private member variables..........
	string firstName;
	string lastName;
	string status;
	int mark;
	string grade;
	bool pass;

public:                             // public member functions.........

	Student();						// default constructor

	Student(int tempId, string tempFN, string tempLN, int tempMark);
									// overloaded constructor
	~Student();						// deconstructor 

	void setId(int temp);           // protoytpe of function, defined in .cpp file
	int getId() { return ID; }      // example of an inline function

	void setFirstName(string temp);                // set (mutator) function
	string getFirstName() { return firstName; }    // get (accessor) function

	void setLastName(string temp);
	string getLastName() { return lastName; }

	void setStatus(string temp);
	string getStatus() { return status; }

	void setMark(int temp);
	int getMark() { return mark; }

	void calcGrade();
	string getGrade() { return grade; }

	virtual void calcPassStatus();   // virtual, can be overridden by derived class
	void setPassStatus(bool temp);
	bool getPassStatus() { return pass; }

	void printHeader();

	void printRecord();

};									// end of class declaration

class PostgradStudent : public Student {

protected:
	bool research;

public:
	PostgradStudent();
	PostgradStudent(int tempId, string tempFN, string tempLN, int tempMark);
	~PostgradStudent();
	void calcPassStatus();
};

class UndergradStudent : public Student {

public:
	UndergradStudent();
	UndergradStudent(int tempId, string tempFN, string tempLN, int tempMark);
	~UndergradStudent();

};