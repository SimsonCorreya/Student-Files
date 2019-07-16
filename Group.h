#pragma once
#include "student.h"

class Group {

	Student *students[100];		// used for dynamically created array
	int number;					// number of students in group, starts at 0
	int max_numbers;			// max possible records in group
	
public:


	Group();
	Group(int size);
	~Group();

	void addUndergradRecord();
	void addPostgradRecord();
	void displayAll();
	void searchGroup();
	void sortRecords();
	void deleteYN(int matchingStudentsCount, int* matchingStudsentElements);

};

