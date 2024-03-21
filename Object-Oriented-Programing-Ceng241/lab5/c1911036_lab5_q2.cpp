#include <iostream>
#include <string>

using namespace std;

class Student
{	
	private:
		
		int id;
		string name;
		int year;
		float gpa;
		float exam;
		float total;
	
	public:
		Student()
		{
			cout << "Enter information for student(id name year gpa exam(must be in range 0-5)): " ;
		}
		
		
		void setName(string n)
		{
			name = n;
		}
		
		string getName()
		{
			return name;
		}
		
		
		void setId(int i)
		{
			id = i;
		}
		
		int getId()
		{
			return id;
		}
		

		void setYear(int y)
		{
			year = y;
		}
		
		int getYear()
		{
			return year;
		}
		
		
		void setExam(float e)
		{
			exam = e;
		}
		
		float getExam()
		{
			return exam;
		}
		
		
		void setGpa(float g)
		{
			gpa = g;
		}
		
		float getGpa()
		{
			return gpa;
		}
		
		

		void setTotal(int t)
		{
			total = t;
		}
		
		float getTotal()
		{
			total = (exam * gpa) / 2.0; 
			return total;
		}
};

int main()
{
	Student s1;
	
	int id,year;
	char name[10];
	float exam, gpa;
	
	
	cin >> id;
	cin >> name;
	cin >> year;
	cin >> gpa;
	cin >> exam;
	
	s1.setName(name);
	s1.setId(id);
	s1.setGpa(gpa);
	s1.setYear(year);
	s1.setExam(exam);
	
	
	Student s2;
	
	cin >> id;
	cin >> name;
	cin >> year;
	cin >> gpa;
	cin >> exam;
	
	s2.setName(name);
	s2.setId(id);
	s2.setGpa(gpa);
	s2.setYear(year);
	s2.setExam(exam);
	
	Student s3;
	
	cin >> id;
	cin >> name;
	cin >> year;
	cin >> gpa;
	cin >> exam;
	
	s3.setName(name);
	s3.setId(id);
	s3.setGpa(gpa);
	s3.setYear(year);
	s3.setExam(exam);
	
	
	Student s4;
	
	cin >> id;
	cin >> name;
	cin >> year;
	cin >> gpa;
	cin >> exam;
	
	s4.setName(name);
	s4.setId(id);
	s4.setGpa(gpa);
	s4.setYear(year);
	s4.setExam(exam);
	
	
	cout << "Results: " << s1.getName() << ": " << s1.getTotal() << ", "<< s2.getName() << ": " << s2.getTotal()<< ", "<< s3.getName() << ": " << s3.getTotal() << ", "<< s4.getName() << ": " << s4.getTotal() << ", " << endl;
	
	if(s1.getTotal() > s2.getTotal() &&  s1.getTotal() > s3.getTotal() &&  s1.getTotal() > s4.getTotal() ) 
		cout << s1.getName() << " has just emplyoeed.";
	
	else if(s2.getTotal() > s1.getTotal() &&  s2.getTotal() > s3.getTotal() &&  s2.getTotal() > s4.getTotal() ) 
		cout << s2.getName() << " has just emplyoeed.";
	
	else if(s3.getTotal() > s1.getTotal() &&  s3.getTotal() > s2.getTotal() &&  s3.getTotal() > s4.getTotal() ) 
		cout << s3.getName() << " has just emplyoeed.";
		
	else
		cout << s4.getName() << " has just emplyoeed.";
	
	
	
	
}
