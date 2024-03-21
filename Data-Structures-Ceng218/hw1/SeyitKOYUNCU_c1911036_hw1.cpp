#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Exam
{
    private:
        string type;
        string date;
        string time;
        
    public:
    	Exam()
    	{
    		type = " ";
    		date = " ";
    		time = " ";
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
			exams[0].setType(Exams.getType());
			exams[0].setDate(Exams.getDate());
			exams[0].setTime(Exams.getTime());
        }

        void printExams()
        {
			cout << exams[0].getType() << " "
			<< exams[0].getDate() << " "
			<< exams[0].getTime() << endl;
        }
        
        string getCode() { return code; }
        vector <Exam> getExams() { return exams; }
        
        void setCode(string Code) { code = Code; }
        void setExams(Exam Exams) 
		{
			exams[0].setType(Exams.getType());
			exams[0].setDate(Exams.getDate());
			exams[0].setTime(Exams.getTime());
		}

};

class ExamTable
{
    private:
        vector <Course> courses;

    public:
    	
    	ExamTable()
    	{}
		
    	ExamTable(Course course)
    	{}
		
        void add(Course Courses)
        {
			int size = courses.size();
			
			if(size == 0)
				courses.push_back(Courses);

			else
			{
				int happ = 0;
				for(int i = 0; i < size; i++)
				{
					if(Courses.getCode() == courses[i].getCode())
					{	
						happ = 1;
					}	
				}		

				if(happ == 0)
					courses.push_back(Courses);		
			}
        }

		void deleteCourse(int size)
		{   
			courses.erase(courses.begin()+size,courses.begin()+size+1); 
		}
        
        void print()
        {	
			Sort();
			write();
			read();
        }

        void read()
        {	
			ifstream file;

			file.open("exams.txt");

			string code;
			string type;
			string date;
			string time;
			
			int size = courses.size();
			int count = 0;
			while(!file.eof())
			{
				file >> code >> type >> date >> time;

				cout << code << " " << type << " " << date << " " << time << endl;
				count++;

				if(count == size)
					break;
			}	
			
			file.close();
			
        }

        void write()
        {	
        	int size = courses.size();
			
			ofstream WriteFile("exams.txt");
			
			for(int i = 0; i < size; i++)
			{
				vector <Exam> tempExam = courses[i].getExams();

				cout << courses[i].getCode() << " " << 
				tempExam[0].getType() << " " <<
				tempExam[0].getDate() << " " <<
				tempExam[0].getTime() << endl;		
				cout << "size = " << size;	
			}
			WriteFile.close();
        }

        void Sort()
        {
			int size = courses.size();
			if(size != 1)
			{
				for(int i = 0; i < size; i++)
				{
					for(int j = i+1; j < size; j++)
					{
						if(courses[j].getCode() < courses[i].getCode())
						{
							string hold = courses[i].getCode();
							courses[i].setCode(courses[j].getCode());
							courses[j].setCode(hold);

							vector <Exam> examForI = courses[i].getExams();
							vector <Exam> examForJ = courses[j].getExams();

							string tempTypeI = examForI[0].getType();
							string tempDateI = examForI[0].getDate();
							string tempTimeI = examForI[0].getTime();

							courses[i].setExams(examForJ[0]);
							Exam tempExam(tempTypeI,tempDateI,tempTimeI);
							courses[j].setExams(tempExam);
						}
					}
				}				
			}
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
    cout << "5- Delete existing exam" << endl;
    cout << "6- Exist" << endl;	
}


int main()
{
	Menu();
	int choice = 0;
	int count = 0;

	vector <Course> courses;
	ExamTable table;
	string CourseCode;

	while(choice != 6)
	{
		cout << "Your choice: " ;
		cin >> choice;
		cout << endl;

		if(choice == 1)
		{
			int size = courses.size();
			if(size == 0)
			{
				cout << "You dont have any course pls add course" << endl; 
			}
			
			else
			{
				cout << "------Exam Table-------" << endl;
				table.print();
			}
		}

		else if(choice == 2)
		{	
			cout << "Enter course code: ";
			cin >> CourseCode;
			cout << endl;

			Course tempCourse(CourseCode);
			courses.push_back(tempCourse);

			int size = courses.size();

			for(int i = 0; i < size; i++)
			{
				table.add(courses[i]);
			}
			cout << "Course added. " << endl;
			count++;
		}

		else if(choice == 3)
		{
			int size = courses.size();

			cout << "Available coruses: " << endl;

			for(int i = 0; i < size; i++)
			{
				cout << i+1 << "- " << courses[i].getCode() << endl;
			}

			cout << "Which course you want to delete: ";
			int choiceCourse;
			cin >> choiceCourse;
			cout << endl;		
			table.deleteCourse(choiceCourse - 1);
			courses.erase(courses.begin()+choiceCourse - 1,courses.begin()+choiceCourse);    	
			count--;
		}

		else if(choice == 4)
		{
			int size = courses.size();

			cout << "Available coruses: " << endl;

			for(int i = 0; i < size; i++)
			{
				cout << i+1 << "- " << courses[i].getCode() << endl;
			}

			cout << "Which course: ";
			int choiceCourse;
			cin >> choiceCourse;
			cout << endl;

			cout << "Enter exam type, date and time: ";
			string type, date, time;
			cin >> type >> date >> time;
			cout << endl;
			Exam tempExam(type,date,time);

			courses[choiceCourse-1].add(tempExam);
		}

		else if(choice == 5)
		{
			int size = courses.size();

			cout << "Available coruses: " << endl;

			for(int i = 0; i < size; i++)
			{
				cout << i+1 << "- " << courses[i].getCode() << endl;
			}

			cout << "Which exams of course you want to delete: ";
			int choiceCourse;
			cin >> choiceCourse;
			cout << endl;		
			Exam tempExam("unknown", "unknownn", "unknown");
			courses[choiceCourse-1].setExams(tempExam);		
		}

		else if(choice == 6)
		{
			cout << "Bye";
			return 0;
		}

		else	
			cout << "You choice wrong number pls try again..." << endl;
	}

	return 0;

}


