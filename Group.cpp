#include "Group.h"
#include <time.h>		// rand()

using namespace std;

Group::Group()
{
}

Group::Group(int size) 
{
	students[size];
	number = 0;
	max_numbers = size;
}

Group::~Group()
{
	cout << "Deleting Group" << endl;
}

void Group::addPostgradRecord() 
{
	cout << "\nOption (1) Add Under Graduate record" << endl;
	/*students[number] = new UndergradStudent();
	number++;*/

	// swap comments for manual input of students

	students[number] = new PostgradStudent(rand() % 9000 + 1000, "ayesha", "pathan", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "joe", "sklar", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "avinash", "subedi", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "dan", "davis", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "barak", "obama", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "joe", "blogs", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "android", "robot", rand() % 70 + 30);
	number++;
	students[number] = new PostgradStudent(rand() % 9000 + 1000, "rohan", "bell", rand() % 70 + 30);
	number++;
}

void Group::addUndergradRecord() 
{
	cout << "\nOption (2) Add Post Graduate record" << endl;
	/*students[number] = new PostgradStudent();
	number++;*/

	// swap comments for manual input of students

	students[number] = new UndergradStudent(rand() % 9000 + 1000, "jordan", "coombes", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "jordan", "blowfield", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "jack", "smith", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "tilly", "pyne", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "lewis", "oonnor", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "spencer", "dougal", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "jamil", "plested", rand() % 50 + 50);
	number++;
	students[number] = new UndergradStudent(rand() % 9000 + 1000, "charles", "grint", rand() % 50 + 50);
	number++;
}

void Group::displayAll() 
{
	cout <<  "Total records in database: " << number << endl;
	cout << setw(10) << "SRN"
		<< setw(15) << "First Name"
		<< setw(15) << "Second Name"
		<< setw(15) << "Status"
		<< setw(10) << "Mark"
		<< setw(10) << "Grade"
		<< setw(10) << "Pass" << endl;

	for (int i = 0; i < number; i++) 
	{
		students[i]->printRecord();
	}
}

void Group::searchGroup() 
{
	bool searchLoop = true;					// while true loop loops
	int searchMenuOption, searchInt;	
	string searchName;
	int matchingStudentsCount = 0;			// count of students that meet search criteria
	int matchingStudentElements[100];		// array holding array indexes of matching students

	while (searchLoop == true) 
	{
		int matchingStudentsCount = 0;		// reset student count
		
		cout << "\nSEARCH/DELETE"
			<< "\n(1) Search by SRN"
			<< "\n(2) Search by first name"
			<< "\n(3) Search by last name"
			<< "\n(4) Back to main menu"
			<< "\nEnter your option to continue : ";
		cin >> searchMenuOption;

		switch (searchMenuOption) 
		{
		case 1:
			cout << "\nOption (1) Search by SRN : ";
			cin >> searchInt;
			cout << "Total records in database: " << number << endl;
			for (int i = 0; i < number; i++)									// loops through all student records
			{	
				if (students[i]->getId() == searchInt)							// if ID of student matches search
				{						
					matchingStudentElements[matchingStudentsCount] = i;			// store index of matching student in array
					matchingStudentsCount++;									// increment count of matching students
				}
			}
			deleteYN(matchingStudentsCount, matchingStudentElements);
			break;

		case 2:
			cout << "\nOption (2) Search by first name : ";
			cin >> searchName;
			cout << "Total records in database: " << number << endl;
			searchName[0] = toupper(searchName[0]);

			for (int i = 0; i < number; i++)									// loops through all student records
			{
				if (students[i]->getFirstName() == searchName)					// if student matches search
				{
					matchingStudentElements[matchingStudentsCount] = i;			// store index of matching student in array
					matchingStudentsCount++;									// increment count of matching students
				}
			}
			deleteYN(matchingStudentsCount, matchingStudentElements);
			break;

		case 3:
			cout << "\nOption (3) Search by last name : ";
			cin >> searchName;
			cout << "Total records in database: " << number << endl;
			searchName[0] = toupper(searchName[0]);

			for (int i = 0; i < number; i++)									// loops through all student records
			{
				if (students[i]->getLastName() == searchName)					// if student matches search
				{
					matchingStudentElements[matchingStudentsCount] = i;			// store index of matching student in array
					matchingStudentsCount++;									// increment count of matching students
				}
			}
			deleteYN(matchingStudentsCount, matchingStudentElements);
			break;

		case 4:
			searchLoop = false;			// break out of loop back to main menu
			break;

		default:
			cout << "\nPlease enter a valid response";
			break;
		}
	}
	return;
}

void Group::sortRecords() 
{
	bool sortLoop = true;
	int sortMenuOption;

	while (sortLoop == true)
	{
		bool fixed = false;				// sorted ?
		Student *temp;
		string temp1, temp2;

		cout << "\nSORT"
			<< "\n(1) Sort by SRN"
			<< "\n(2) Sort by First Name"
			<< "\n(3) Sort by Last Name"
			<< "\n(4) Sort by Mark"
			<< "\n(5) Back to Main Menu"
			<< "\nEnter your option to continue : ";
		cin >> sortMenuOption;

		switch (sortMenuOption) 
		{
		case 1:
			cout << "\nOption (1) Sort by SRN" << endl;
			
			while (fixed == false)									// while not sorted
			{								
				fixed = true;

				for (int i = 0; i < number - 1; i++)				// loop through all records
				{				

					temp1 = students[i]->getId();					// temp first name
					temp2 = students[i + 1]->getId();				// temp first name for next record

					if (temp1 < temp2)								// if in wrong order
					{							
						temp = students[i + 1];						// swap records..........
						students[i + 1] = students[i];
						students[i] = temp;
						fixed = false;								// mark array not sorted
					}
				}
			} displayAll(); break;

		case 2:
			cout << "\nOption (2) Sort by First Name" << endl;

			while (fixed == false)									// while not sorted
			{								
				fixed = true;

				for (int i = 0; i < number - 1; i++)				// loop through all records
				{				

					temp1 = students[i]->getFirstName();			// temp first name
					temp2 = students[i + 1]->getFirstName();		// temp first name for next record

					if (temp1 > temp2)								// if in wrong order
					{							
						temp = students[i + 1];						// swap records..........
						students[i + 1] = students[i];
						students[i] = temp;
						fixed = false;								// mark array not sorted
					}
				}
			} displayAll(); break;

		case 3:
			cout << "\nOption (3) Sort by Last Name" << endl;
			
			while (fixed == false)									// while not sorted
			{								
				fixed = true;

				for (int i = 0; i < number - 1; i++)				// loop through all records
				{				

					temp1 = students[i]->getLastName();				// temp first name
					temp2 = students[i + 1]->getLastName();			// temp first name for next record

					if (temp1 > temp2)								// if in wrong order
					{							
						temp = students[i + 1];						// swap records..........
						students[i + 1] = students[i];
						students[i] = temp;
						fixed = false;								// mark array not sorted
					}
				}
			} displayAll(); break;

		case 4:
			cout << "\nOption (4) Sort by Mark" << endl;
			
			while (fixed == false)									// while not sorted
			{								
				fixed = true;

				for (int i = 0; i < number - 1; i++)				// loop through all records
				{				

					temp1 = students[i]->getMark();					// temp first name
					temp2 = students[i + 1]->getMark();				// temp first name for next record

					if (temp1 < temp2)								// if in wrong order
					{							
						temp = students[i + 1];						// swap records..........
						students[i + 1] = students[i];
						students[i] = temp;
						fixed = false;								// mark array not sorted
					}
				}
			} displayAll(); break;

		case 5: 
			sortLoop = false;			// break out of loop back to main menu
			break; 
		default:
			cout << "\nPlease enter a valid response";
			break;
		}	
	}
}

void Group::deleteYN(int matchingStudentsCount, int *matchingStudentElements) {  
	int YNdelete, deleteCount = 0, deletedIndex, deletedShift;

	if (matchingStudentsCount > 0) {							// if any students match search

		students[0]->printHeader();					

		for (int i = 0; i < matchingStudentsCount; i++)
		{
			students[matchingStudentElements[i]]->printRecord();					// print matching records
		}

		cout << "Do you want to delete these records? Yes(1) No(0) : ";
		cin >> YNdelete;

		if (YNdelete == 1)											// if user wants to delete records
		{

			for (int i = 0; i < matchingStudentsCount; i++)			// loops through matching record indexes
			{
				deletedIndex = matchingStudentElements[i];			// original students[] index of record to delete
				deletedShift = deletedIndex - deleteCount;			// new students[] index of record to delete
				delete students[deletedShift];						// deletes matching record
				deleteCount++;										// compensates for shifting student array

				for (deletedShift; deletedShift < number; deletedShift++)	// loops through remaining students
				{
					students[deletedShift] = students[deletedShift + 1];	// shifts students array left
				}
				number--;							// reduce count of student records
			}
		}
	}
	else cout << "No matching records were found" << endl;
}