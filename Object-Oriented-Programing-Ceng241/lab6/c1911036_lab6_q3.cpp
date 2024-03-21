#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <vector>

using namespace std;

class Collatz{
	private:
		int start;
		int limit;
		vector <int> numbers;
		
	public:
		Collatz()
		{
			srand (time(NULL));
						
			start = rand() % (50 - 10 + 1) + 10;
			limit = 10;
		}
		
		Collatz(int s, int l)
		{
			start = s;
			limit = l;
		}
		
		void generate()
		{
			numbers.push_back(start);
			
			int newNumber;
			
			int i = 0;
			
			while(numbers[i] != 1 && i < limit-1) 
			{
				if(numbers[i] % 2 == 0)
				{
					newNumber = numbers[i] / 2;
					numbers.push_back(newNumber);
				}
				
				else if(numbers[i] % 2 == 1)
				{
					newNumber = numbers[i] * 3 + 1;
					numbers.push_back(newNumber);
				}
				
				i++;
			}
			
			print();
		}
		
		void print()
		{
			cout << "Collatz: ";
			
			int size = numbers.size();
			
			for(int i = 0; i < size; i++)
			{
				cout << numbers[i] << " -> ";
			}
			
			cout << "end";
		}
};

int main()
{
	cout << "1. Default (start: random, limit: 10) " << endl;
	cout << "2. Custom "<<endl;
	
	int choice;
	int number,limit;
	
	
	for(int i = 0; i < 5; i++)
	{
		cout << "Your choice : ";
		cin >> choice;
		if(choice == 1)
		{
			Collatz random;
			random.generate();
		}		
		
		else if(choice == 2)
		{
			cout << "Enter start number and  limit: ";
			cin >> number >> limit;
			
			Collatz manuel(number, limit);
			manuel.generate();	
		}
		
		cout << endl;
	}
}
