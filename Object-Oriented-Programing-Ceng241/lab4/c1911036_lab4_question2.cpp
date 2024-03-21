#include <iostream>

using namespace std;

int main()
{
	int size;
	
	cout << "How many numbers letters are you going to enter: " <<endl;
	cin >> size;
	
	char *letter = new char[size];
	int *count = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		cout << "Enter letter and how many times it will repeated: " <<endl;
		cin >> letter[i] >> count[i];
	}
	
	for(int i = 0; i < size; i++)
	{
		for(int k = 0; k < count[i]; k++)
		{
			cout<<letter[i];
		}
	}
	
	delete [] letter;
	delete [] count;
}
