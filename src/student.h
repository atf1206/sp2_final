
#include "degree.h"

using namespace std;

class Student {

	private:
		string _studentID;
		string _firstName;
		string _lastName;
		string _emailAddress;
		int _age;
		int _daysInCourse1;
		int _daysInCourse2;
		int _daysInCourse3;
		int daysInCourseArray[3];
		Degree _degree;

	public:
		// Constructor
		Student(string studentID, string firstName, 
				string lastName, string emailAddress, int age, 
				int daysInCourse1, int daysInCourse2, int daysInCourse3) 
				: _studentID(studentID), _firstName(firstName), 
				_lastName(lastName), _emailAddress(emailAddress), _age(age), 
				_daysInCourse1(daysInCourse1), _daysInCourse2(daysInCourse2), _daysInCourse3(daysInCourse3)
		{
			daysInCourseArray[0] = _daysInCourse1;
			daysInCourseArray[1] = _daysInCourse2;
			daysInCourseArray[2] = _daysInCourse3;
		}

		// Getters and Setters
		string getStudentID() { return _studentID; }
		void setStudentID(string studentID) { _studentID = studentID; }

		string getFirstName() { return _firstName; }
		void setFirstName(string firstName) { _firstName = firstName; }

		string getLastName() { return _lastName; }
		void setLastName(string lastName) { _lastName = lastName; }

		string getEmailAddress() { return _emailAddress; }
		void setEmailAddress(string emailAddress) { _emailAddress = emailAddress; }

		int getAge() { return _age; }
		void setAge(int age) { _age = age; }

		int* getDaysInCourseArray() { return daysInCourseArray; }

		Degree virtual getDegreeProgram() {
			return Degree(NONE);
		}
		// This function is strange as subclasses contain their own _degree
		// Included here (but not used) because instructions require it
		void setDegreeProgram(Degree degree) {
			_degree = degree;
		}

		void _print() {
			cout << _studentID << "\t";
			cout << _firstName << "\t";
			cout << _lastName << "\t";
			cout << _emailAddress << "\t";
			cout << _age << "\t";
			cout << _daysInCourse1 << "\t";
			cout << _daysInCourse2 << "\t";
			cout << _daysInCourse3 << "\t";
		}

		// Prints single student's data to stdout
		void virtual print() {
			_print();
			cout << "NONE" << "\t" << endl;
		}

		// Destructor
		~Student() {};
};
