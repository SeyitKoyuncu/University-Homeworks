#include <iostream>
#include <string>

using namespace std;

class SpecialDay
{
	private:
		int year;
		int month;
		int day;
		string title;
		bool repetitive;
		
	public:
		SpecialDay()
		{
			cout << "Default constructor called " << endl;
			year = 0;
			month = 0;
			day = 0;
			title = "";
			repetitive = 0;
		}
		
		SpecialDay(string t, int y, int m, int d)
		{
			repetitive = 0;
			cout << "Overloaded constructor called " << endl;
		}
		
		SpecialDay(const SpecialDay &obj)
		{
			cout << "Copy constructor is called " << endl;
			year = obj.year + 1;
			day = obj.day;
			month = obj.month;
			title = obj.title;
			repetitive = 1;
		}
		
		void setYear(int y)
		{
			year = y;
		}
		
		void setMonth(int m)
		{
			month = m;
		}
		
		void setDay(int d)
		{
			day = d;
		}
		
		void setTtitle(string t)
		{
			title = t;
		}
		
		void setBool(bool b)
		{
			repetitive = b;
		}
		
		int getYear()
		{
			return year;
		}
		
		int getMonth()
		{
			return month;
		}
		
		int getDay()
		{
			return day;
		}
		
		string getTitle()
		{
			return title;
		}
		
		bool getRepetitive()
		{
			return repetitive;
		}
};


int main()
{
	int record;
	
	cout << "Enter number of days to record: ";
	cin >> record;
	cout << endl;
	
	SpecialDay arr[record];
	
	
	
	int day, month, year;
	string title;
	string repetitive;
	bool r;
	
	int count = 0;
	int holder[record];
	
	for(int i = 0; i < record; i++)
	{
		cout << "Enter title, day, month and year respectively: " << endl;
		cin.ignore();
		getline(cin, title);
		cin >> day >> month >> year;
		
		cout << "Is the day repetitive ? " << endl;
		cin >> repetitive;
		//cin.ignore();
		//getline(cin, repetitive);	
		
		if(repetitive == "yes" || repetitive == "Yes" || repetitive == "YES")	
		{
			r = 1;
			holder[count] = i;
			count++;
		}
		
			
		arr[i].setDay(day);
		arr[i].setMonth(month);
		arr[i].setTtitle(title);
		arr[i].setYear(year);
	}
	
	
	cout << "Your Special Occasions: " << endl;
	
	for(int i = 0; i < record; i++)
	{
		cout << arr[i].getTitle() << " " << arr[i].getDay() << "/" << arr[i].getMonth() << "/" << arr[i].getYear() << endl;
	}
	
	cout << "Repetitive Occasions: " << endl;		
	
	SpecialDay * copied[record];
	
	int control;
	
	for(int i = 0; i < count; i++)
	{
		control = holder[i];
		
		copied[i] = new SpecialDay(arr[control]);
		
		cout << copied[i]->getTitle() << " " << copied[i]->getDay() << "/" << copied[i]->getMonth() << "/" << copied[i]->getYear() << endl;
	}
		
	for(int i = 0; i < count; i++)
		delete copied[i];
	
	return 0;
}
