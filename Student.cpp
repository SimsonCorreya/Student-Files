#pragma once
#include <iostream>		// cout / cin
#include "Student.h"

using namespace std;

Student::Student() 
{
}

Student::Student(int tempId, string tempFN, string tempLN, int tempMark) 
{
	setId(tempId);
	setFirstName(tempFN);
	setLastName(tempLN);
	setMark(tempMark);

	Student::calcGrade();
	Student::calcPassStatus();
}

Student::~Student() 
{
	cout << "The record of student "
		<< firstName
		<< " has been destroyed" << endl;
}

void Student::setId(int temp) 
{
	ID = temp;
}

void Student::setFirstName(string temp) 
{
	temp[0] = toupper(temp[0]);
	firstName = temp;
}

void Student::setLastName(string temp) 
{
	temp[0] = toupper(temp[0]);
	lastName = temp;
}

void Student::setStatus(string temp) 
{
	status = temp;
}

void Student::setMark(int temp)
{
	mark = temp;
}

void Student::calcGrade() 
{
	if (mark >= 70) grade = "A";
	else if (mark >= 60) grade = "B";
	else if (mark >= 50) grade = "C";
	else if (mark >= 40) grade = "D";
	else if (mark >= 30) grade = "E";
	else grade = "F";
}

void Student::calcPassStatus() 
{
	if (mark >= 40) pass = 1;
	else pass = 0;
}

void Student::setPassStatus(bool temp) 
{
	pass = temp;
}

void Student::printHeader() 
{
	cout << setw(10) << "SRN"
		<< setw(15) << "First Name"
		<< setw(15) << "Second Name"
		<< setw(15) << "Status"
		<< setw(10) << "Mark"
		<< setw(10) << "Grade"
		<< setw(10) << "Pass" << endl;
}

void Student::printRecord() 
{
	cout << setw(10) << ID
		<< setw(15) << firstName
		<< setw(15) << lastName
		<< setw(15) << status
		<< setw(10) << mark
		<< setw(10) << grade
		<< setw(10) << pass << endl;
}



PostgradStudent::PostgradStudent() 
{
	int tempId, tempMark;
	string tempFN, tempLN;

	cout << "ID         : ";
	cin >> tempId;
	setId(tempId);

	cout << "First Name : ";
	cin >> tempFN;
	setFirstName(tempFN);

	cout << "Last Name  : ";
	cin >> tempLN;
	setLastName(tempLN);

	cout << "Mark       : ";
	cin >> tempMark;
	setMark(tempMark);

	setStatus("Postgrad");
	calcGrade();
	calcPassStatus();
}

PostgradStudent::PostgradStudent(int tempId, string tempFN, string tempLN, int tempMark) 
{
	setId(tempId);
	setFirstName(tempFN);
	setLastName(tempLN);
	setMark(tempMark);

	setStatus("Postgrad");
	calcGrade();
	calcPassStatus();
}

PostgradStudent::~PostgradStudent()
{
}

void PostgradStudent::calcPassStatus() 
{
	if (getMark() >= 50) setPassStatus(1);
	else setPassStatus(0);
}



UndergradStudent::UndergradStudent() 
{
	int tempId, tempMark;
	string tempFN, tempLN;

	cout << "ID         : ";
	cin >> tempId;
	setId(tempId);

	cout << "First Name : ";
	cin >> tempFN;
	setFirstName(tempFN);

	cout << "Last Name  : ";
	cin >> tempLN;
	setLastName(tempLN);

	cout << "Mark       : ";
	cin >> tempMark;
	setMark(tempMark);

	setStatus("Undergrad");
	calcGrade();
	calcPassStatus();
}

UndergradStudent::UndergradStudent(int tempId, string tempFN, string tempLN, int tempMark) 
{
	setId(tempId);
	setFirstName(tempFN);
	setLastName(tempLN);
	setMark(tempMark);

	setStatus("Undergrad");
	calcGrade();
	calcPassStatus();
}

UndergradStudent::~UndergradStudent() 
{
}