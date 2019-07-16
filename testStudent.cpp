#pragma once
#include <string>      // cin >> string
#include <iostream>    // cout / cin

#include "Student.h"   // student class header file
#include "Group.h"     // group class header file

using namespace std;					// std::cin   -> cin 

int main() 
{
	srand(time(NULL));						// seed for rand number generator
	std::cout << std::boolalpha;			// bool prints as true / false
	Group *myGroup = new Group(100);		// new object of type Group

	while (0 != 1)							// inf loop
	{                  
		cout << "\nSTUDENT DATABASE"
			<< "\n(1) Add Undergraduate Record"
			<< "\n(2) Add Postgraduate Record"
			<< "\n(3) Show All Records"
			<< "\n(4) Search And Delete Records"
			<< "\n(5) Sort Records"
			<< "\nEnter Your Option To Continue : ";
		int menuOption;
		cin >> menuOption;

		switch (menuOption) 
		{
			case 1: myGroup->addUndergradRecord();	break;
			case 2: myGroup->addPostgradRecord();	break;
			case 3: cout << "\nOption (3) Show all records" << endl; 
					myGroup->displayAll();			break;
			case 4: myGroup->searchGroup();         break;
			case 5: myGroup->sortRecords();         break;
			default: cout << "Please enter a valid response" << endl; break;
		}
	}
	return 0;
}