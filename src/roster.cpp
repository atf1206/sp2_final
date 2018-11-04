
#include <iostream>
#include <string>
#include <vector>

#include "student.h"
#include "roster.h"

using namespace std;

// Takes the hardcoded raw student data and returns a vector
vector<string> getRawStudentData() {
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Andrew,Fritz,afritz8@wgu.edu,35,4,2,5,SOFTWARE"
	};
	vector<string> studentDataV;

	for (string student : studentData) {
		//cout << student << endl;
		studentDataV.push_back(student);
	}

	return studentDataV;
}

// This function breaks a studentData string into parts around commas
// Wish this were more 'functional' -- but perhaps passing by reference 
// ultimately does the same thing under the hood (?)
void parseAndValidateRawStudentData(string *studentData, string *studentID, string *firstName,
		string *lastName, string *emailAddress, int *age,
		int *daysInCourse1, int *daysInCourse2, int *daysInCourse3,
		string *degreeProgram) {

	int commasFound = 0;
	int prevIndex = 0;

	for (int i = 0; i < (*studentData).length(); i++) {
		if ( (*studentData)[i] == ',' ) {
			commasFound += 1;
			switch (commasFound)
			{
				case 1: *studentID = (*studentData).substr(prevIndex,(i-prevIndex));
				break;
				case 2: *firstName = (*studentData).substr(prevIndex,(i-prevIndex));
				break;
				case 3: *lastName = (*studentData).substr(prevIndex,(i-prevIndex));
				break;
				case 4: *emailAddress = (*studentData).substr(prevIndex,(i-prevIndex));
				break;
				case 5: *age = stoi( (*studentData).substr(prevIndex,(i-prevIndex)) );
				break;
				case 6: *daysInCourse1 = stoi( (*studentData).substr(prevIndex,(i-prevIndex)) );
				break;
				case 7: *daysInCourse2 = stoi( (*studentData).substr(prevIndex,(i-prevIndex)) );
				break;
				case 8: 
					*daysInCourse3 = stoi( (*studentData).substr(prevIndex,(i-prevIndex)) );
					*degreeProgram = (*studentData).substr(i+1, (*studentData).length()-1);
				break;
			}
			prevIndex = i+1;
		}
	}
}

void saferPrint(string outString) {
	cout << endl << outString << endl;
}

void saferPrintNoEndl(string outString) {
	cout << endl << outString;
}

int main() {

	saferPrintNoEndl("F.1 Project for Scripting and Programming Applications — C867");
	saferPrint("    Coded in C++ by Andrew Fritz (afritz8@wgu.edu)");

	// init
	Roster classRoster;
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	string degreeProgram;
	
	saferPrint("F.2 Instance of the Roster class called 'classRoster' created");

	saferPrint("F.3 Creating individual student records and adding to roster:");

	// Get vector of all raw student data; 
	// validate & parse to individual student data arrays; and
	// add() each array to the roster
	for (string studentData : getRawStudentData()) {

		try {
			parseAndValidateRawStudentData(&studentData, &studentID, &firstName, &lastName,
				&emailAddress, &age, &daysInCourse1, &daysInCourse2, &daysInCourse3, &degreeProgram);
		} catch (exception& e) {
			cout << "Unable to parse raw student data -- exiting" << endl;
			cout << "Error was: " << e.what() << endl;
			return 1;
		}

		classRoster.add(studentID, firstName, 
				lastName, emailAddress, age, 
				daysInCourse1, daysInCourse2, daysInCourse3, 
				degreeProgram);

	}

	saferPrint("F.4");

	saferPrint("F.4.1 Printing all records with printAll()");
	classRoster.printAll();

	saferPrint("F.4.2 Printing invalid emails with printInvalidEmails()");
	classRoster.printInvalidEmails();

	saferPrint("F.4.3 Printing average days in course for all roster entries");
	for (int i = 0; i<classRoster.getRosterSize(); i++) {
		if (classRoster.classRosterArray[i]) {
			classRoster.printAverageDaysInCourse( string (classRoster.classRosterArray[i]->getStudentID()) );
		}
	} 

	saferPrint("F.4.4 Printing all 'SOFTWARE' students using printByDegreeProgram(SOFTWARE)");
	classRoster.printByDegreeProgram(SOFTWARE);

	saferPrint("F.4.5 Removing student A3 from roster using remove(\"A3\")");
	classRoster.remove("A3");

	saferPrint("F.4.6 Attempting (and failing) to remove student A3 using remove(\"A3\") again");
	classRoster.remove("A3");

	saferPrint("F.5 Destroying the roster");
	classRoster.~Roster();
	
	saferPrint("Done! Exiting now");
}
