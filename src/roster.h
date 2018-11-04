
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

using namespace std;

// The Roster is built from pointers to instances of the Student class

class Roster {
	private:
		static const int _rosterSize = 10;

	public:
		Student* classRosterArray[_rosterSize];

		// adds a student to the roster
		// student is added by iterating through roster until empty slot is found
		void add(string studentID, string firstName, 
				string lastName, string emailAddress, int age, 
				int daysInCourse1, int daysInCourse2, int daysInCourse3,
				string degree) {

			Student* newStudent = 
				(degree == "SECURITY") ?
				new SecurityStudent(studentID, firstName, 
					lastName, emailAddress, age, 
					daysInCourse1, daysInCourse2, daysInCourse3) :
				(degree == "NETWORK") ?
				new NetworkStudent(studentID, firstName, 
					lastName, emailAddress, age, 
					daysInCourse1, daysInCourse2, daysInCourse3) :
				(degree == "SOFTWARE") ?
				new SoftwareStudent(studentID, firstName, 
					lastName, emailAddress, age, 
					daysInCourse1, daysInCourse2, daysInCourse3) :
				// else
				new Student(studentID, firstName, 
					lastName, emailAddress, age, 
					daysInCourse1, daysInCourse2, daysInCourse3);

			for (int i = 0; i<_rosterSize; i++) {
				if (!classRosterArray[i]) {
					classRosterArray[i] = newStudent;
					cout << "Created new student record in roster slot " << i << ": ";
					newStudent->print();
					break;
				}
				if (i == (_rosterSize-1)) {
					cout << "No room in roster to add additional students" << endl;
				}
			}
		}

		int getRosterSize() {
			return _rosterSize;
		}

		// Removes the first record found that matches a studentID
		void remove(string studentID) {
			bool foundID = 0;
			for (int i = 0; i<_rosterSize; i++) {
				if (classRosterArray[i]) {
					if (classRosterArray[i]->getStudentID() == studentID) {
						classRosterArray[i] = 0;
						cout << "Student with studentID " << studentID << " removed from roster at slot " << i << endl;
						foundID = 1;
						break;
					}
				}
			}
			if (foundID == 0) {
				cout << "Could not remove -- studentID " << studentID << " not found" << endl;
			}
		}

		void printAll() {
			//for (Student* student : classRosterArray) {
			for (int i = 0; i<_rosterSize; i++) {
				if (classRosterArray[i]) { classRosterArray[i]->print(); }
			}
		}

		// Prints average days in courses for a studentID
		void printAverageDaysInCourse(string studentID) {
			bool foundID = 0;
			for (int i = 0; i<_rosterSize; i++) {
				if (classRosterArray[i]) {
					if (classRosterArray[i]->getStudentID() == studentID) {
						float avg = 0.0;
						for (int j = 0; j<3; j++) {
							avg += *( classRosterArray[i]->getDaysInCourseArray() + j );
						}
						cout << "Average days for student id " << studentID << " is: " << avg/3 << endl;
						foundID = 1;
						break;
					}
				}
			}
			if (foundID == 0) {
				cout << "Could not get average -- studentID not found" << endl;
			}
		}

		// Prints emails of students in roster with invalid email format
		void printInvalidEmails() {
			cout << endl << "Checking for invalid email addresses. A valid email should include" << endl;
			cout << "an at sign ('@') and period ('.'), and should not include a space (' ')." << endl << endl;
			bool foundID = 0;
			for (int i = 0; i<_rosterSize; i++) {
				if (classRosterArray[i]) {
					int hasAtSign = 0;
					int hasPeriod = 0;
					int hasSpace = 0;
					string checkString = classRosterArray[i]->getEmailAddress();
					for (int j = 0; j<checkString.length(); j++) {
						if (checkString[j] == '@') {
							hasAtSign = 1;
						}
						if (checkString[j] == '.') {
							hasPeriod = 1;
						}
						if (checkString[j] == ' ') {
							hasSpace = 1;
						}
					}
					if (hasAtSign == 0 || hasPeriod == 0 || hasSpace == 1) {
						if (foundID == 0) {
							cout << "Errors found in the following email addresses:" << endl;
						}
						cout << checkString << endl;
					}
					foundID = 1;
				}
			}
			if (foundID == 0) {
				cout << "No invalid emails found." << endl;
			}
		}

		// Prints out student information for a specified degree program
		void printByDegreeProgram(int degreeProgram) {
			bool foundID = 0;
			for (int i = 0; i<_rosterSize; i++) {
				if (classRosterArray[i]) {
					if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
						classRosterArray[i]->print();
						foundID = 1;
					}
				}
			}
			if (foundID == 0) {
				cout << "Could not remove -- studentID not found" << endl;
			}
		}

		~Roster() {};
};
