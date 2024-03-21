#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct course
{
	string code;
	double grade;
};

int main()
{
	vector<course> student;
	
	string class_code;
	double grade = 0.0;
	
	char control = 'y';
	int i = 0;
		
	double sum = 0.0;
	
	while(control == 'y' || control == 'Y')
	{
		cout << "Enter course code and grade: " <<endl;
		cin >> class_code;
		cin >> grade;
		
		student.resize(i);
		
		//student.push_back(course());
		student[i].code = class_code;
		student[i].grade = grade;
		
		cout << "Add new course ? " << endl;
		cin >> control;	
		
		sum = sum + student[i].grade;
		i++;
	}
	
	cout << "List of entered " << i << " courses: "<<endl;
	
	for(int k = 0; k < i; k++)
	{
		cout << "-" << student[k].code << ", Grade: " <<student[k].grade<<endl; 
	}
	
	double cgpa = 0.0;
	
	cout << "CGPA: " << sum / i;
	
	
}
