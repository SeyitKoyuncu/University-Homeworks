/*
class Exam
{
    private:
        string type;
        string date;
        string time;
        
    public:
    	Exam()
    	{
    		type = "";
    		date = "";
    		time = "";
		}
		
		Exam(string type, string date, string time)
		{
			this -> type = type;
			this -> date = date;
			this -> time = time;
		}
		
		string getType() { return type; }
		string getDate() { return date; }
		string getTime() { return time; }
		
		void setType(string type) { this -> type = type; }
		void setDate(string date) { this -> date = date; }
		void setTime(string time) { this -> time = time; }
};

class Course
{
    private:
        string code;
        vector <Exam> exams;

    public:
    	
    	Course()
    	{
    		code = "";	
    		Exam tempExam(" "," "," ");
			exams.push_back(tempExam);
		}
		
		Course(string code)
		{
			this -> code = code;
			Exam tempExam;
			exams.push_back(tempExam); 	
		}
		
		Course(string code, Exam TempExams)
		{
			this -> code = code;
			exams.push_back(TempExams);	
		}
		
        void add(Exam Exams)
        {
			exams.push_back(Exams);
        }

        void printExams()
        {
			cout << exams[1].getType() << " " 
			<< exams[1].getDate() << " " 
			<< exams[1].getTime() << endl;
        }
        
        string getCode() { return code; }
        vector <Exam> getExams() { return exams; }
        
        void setCode(string Code) { code = Code; }
        void setExams(vector <Exam> Exams) 
		{
			int size = Exams.size();
			
			for(int i = 0; i < size; i++)
			{
				exams.push_back(Exams[i]);
			}
		}

};


class ExamTable
{
    private:
        vector <Course> courses;

    public:
    	
    	ExamTable()
    	{	
    		cout << "Base constructor";
		}
		
    	ExamTable(Course course)
    	{
    		//courses.push_back(course);
		}
		
        void add(Course Courses)
        {
			courses.push_back(Courses);
			cout << "Add girdi " << endl;
			int size = courses.size();
        }
        
        void print()
        {
			int size = courses.size();
			//Sort();
			write();
			cout << courses[1].getCode() << " ";
        }

        void read()
        {	
        	int sizeCourses = courses.size();
        	string CoursesFile[sizeCourses];
			ifstream ReadFile("exams.txt");
			
			int i = 0;
			while(getline(ReadFile, CoursesFile[i]))
			{
				i++;
			}
			int count = i;
			
			for(i = 0; i < count; i++)
			{
				Course tempCourse(CoursesFile[i]);
				courses.push_back(tempCourse);
			}
			
			ReadFile.close();
			
			Sort();
        }

        void write()
        {	
        	int size = courses.size();
			cout << "Size of courses is = " << size << endl;
			ofstream WriteFile("exams.txt");
			for(int i = 0; i < size; i++)
			{
				WriteFile << courses[i].getCode() << " " 
				<< (courses[i].getExams())[i].getType() << " " 
				<< (courses[i].getExams())[i].getDate() << " " 
				<< (courses[i].getExams())[i].getTime() << endl;			
			}
        }

        void Sort()
        {
			int size = courses.size();
			
			vector <Course> tempVector;
			
			int count = 0;
			int index[size];
			
			for(int i = 0; i < size; i++)
			{	
				string min = courses[i].getCode();
				for(int j = i; j < size; j++)
				{
					if(min < courses[j].getCode())
						index[i] = i;
						
					else
						min = courses[j].getCode();
				}
			}
			
			for(int i = 0; i < size; i++)
			{
				tempVector.push_back(courses[index[i]]);
			}
			
			tempVector.swap(courses);
			cout << "sort patlama testi" << endl;
        }
        
    	
    	vector <Course> getCourses() { return courses; }
    	
    	void setCourses(vector <Course> course)
    	{
    		int size = course.size();
    		
    		for(int i = 0; i < size; i++)
    		{
    			courses.push_back(course[i]);
			}
		}

        
};


void Menu()
{
    cout << "1- Display table" << endl;
    cout << "2- Add new course" << endl;
    cout << "3- Delete existing course" << endl;
    cout << "4- Add exam to existing course" << endl;
    cout << "5- Delete existing course" << endl;
    cout << "6- Exist" << endl;	
}

int main() {
    
    Menu();
	
	int choice;
	cin >> choice;
	
	vector <ExamTable> examTable;
	vector <Course> courses;
	vector <Exam> exams;
	
	int CountIndex = 0;
	
	while(choice != 6)
	{
		if(choice == 1)
		{
			if(CountIndex == 0)
				cout << "Dont have any course or exam" << endl;
				
			else
			{
				int size = examTable.size();
				
				for(int i = 0; i < size; i++)
				{
					cout << i+1 << "- "	;
					examTable[i].print();
					courses[i].printExams();					
				}
			}
		}
		
		else if(choice == 2)
		{
			
			string code;
			
			cout << "Enter course code: ";
			cin >> code;
			cout << endl;
			
			Exam tempExam;
			exams.push_back(tempExam);
			
			Course tempCourse(code);
			courses.push_back(tempCourse);
			courses[CountIndex].add(exams[CountIndex]);
			
			ExamTable tempExamTable;
			examTable.push_back(tempExamTable);
			examTable[CountIndex].add(courses[CountIndex]);
			
			CountIndex++;
			cout << "Course added" << endl;
			
			//((examTable[0].getCourses())[0].getExams())[0].getType();
		}
		
		else if(choice == 3)	
		{	
			
			int size = examTable.size();
			
			for(int i = 0; i <size; i++)
			{
				cout << i+1 << "- " << courses[i].getCode() << endl;
			}
			
			cout << "Which course?: ";
			int deleteIndex;
			cin >> deleteIndex;
			cout << endl;
			
			examTable.erase(examTable.begin() + deleteIndex - 1);
			
			CountIndex--;
			
		}
		
		else if(choice == 4)
		{	
			
			cout << "Available courses: " << endl;
			
			int size = courses.size();
			
			for(int i = 0; i < size; i++)
			{
				cout << i+1 << "- " << courses[i].getCode() << endl;	
			}
			
			int addExamIndex;
			cin >> addExamIndex;
			cout << endl;
			
			cout << "Enter exam type, date and time: ";
			string examType, examDate, examTime;
			cin >> examType >> examDate >> examTime;
			cout << endl;	
			
			exams[addExamIndex - 1].setType(examType);
			exams[addExamIndex - 1].setDate(examDate);
			exams[addExamIndex - 1].setTime(examTime);
			
			courses[addExamIndex - 1].setExams(exams);
			
			examTable[addExamIndex - 1].setCourses(courses);
			
		}
		
		else if(choice == 5)
		{
			
			int size = examTable.size();
			
			vector <Course> tempCourseDelete = examTable[0].getCourses(); 
			
			vector <Exam> tempExamDelete = tempCourseDelete[0].getExams();
			
			 
			for(int i = 0; i <size; i++)
			{
				cout << i+1 << "- " << tempCourseDelete[i].getCode() << " " << tempExamDelete[i].getType() << " " << tempExamDelete[i].getDate() << " " << tempExamDelete[i].getTime() << endl;
			}
			
			cout << "Which course?: ";
			int deleteIndex;
			cin >> deleteIndex;
			cout << endl;
			
			examTable.erase(examTable.begin() + deleteIndex - 1);
			
		}
		
		else if(choice == 6)
		{
			return 0;
		}
		
		cout << "Your choice : ";
		cin >> choice;
		cout << endl;	
	}


    return 0;
}
*/