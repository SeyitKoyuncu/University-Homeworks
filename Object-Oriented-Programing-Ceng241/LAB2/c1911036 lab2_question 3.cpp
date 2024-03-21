#include <iostream>
using namespace std;


struct classroom{
	char name;
	int student_total;
	int student_learned;
};

int main()
{
	struct classroom school[5];
	
	
	for(int i = 0; i < 5; i++)
	{
		cout << "Enter information for " << i+1 << ". class" <<endl;	
		
		cout << "Letter: " << endl;	
		cin >> school[i].name;
		
		cout << "Total number of students :" << endl;
		cin >> school[i].student_total;
		
		cout << "Number of students who learned to read: " << endl;
		cin >> school[i].student_learned;
		
		cout << "-------------------" <<endl;
	}
	
	double percentage;
	
	cout << "Percentage of student who have learned to read: " << endl;
	
	for(int i = 0; i < 5; i++)
	{
		percentage = (100 * school[i].student_learned / school[i].student_total);
		
		cout << "Classroom 1-" << school[i].name << ": %" << percentage << endl;
	}

	return 0;
}
