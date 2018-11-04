
class SoftwareStudent : public Student {
    private:
		Degree _degree;

    public:
		// Constructor
    	SoftwareStudent(string studentID, string firstName, 
				string lastName, string emailAddress, int age, 
				int daysInCourse1, int daysInCourse2, int daysInCourse3) 
				: Student(studentID, firstName, 
				lastName, emailAddress, age, 
				daysInCourse1, daysInCourse2, daysInCourse3)
		{
			_degree = Degree(SOFTWARE);
		}

		Degree getDegreeProgram() {
			return _degree;
		}

		void print() {
			_print();
			cout << parseFromDegree(_degree) << "\t" << endl;
		}

		// Destructor
		~SoftwareStudent() {};
};
