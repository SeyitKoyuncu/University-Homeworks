#include <iostream>
#include <stdlib.h> 
#include <time.h>  

using namespace std;


class NumberArray
{
	private:
		virtual void generate()
		{
			cout << "normal generate function " << endl;
			for(int i = 0; i < amount; i++)
			{
				numbers[i] = rand() % 1000 + 1;
			}
		}
		
		void print()
		{
			for(int i = 0; i < amount; i++)
			{
				cout << numbers[i] << " ";
			}

			cout << endl;
		}
		
	protected:
		int * numbers;
		int amount;
		
	public:
		NumberArray()
		{
			amount = 0;
			numbers = new int [amount];
		}
		
		NumberArray(int a)
		{
			amount = a;
			numbers = new int[amount];
		}	
		
		void generateAndprint()
		{
			generate();
			print();
		}
		
		virtual ~NumberArray()
		{
			delete [] numbers;
		}	
		
		
};


class primeNumberArray : public NumberArray
{
	public:
		primeNumberArray(int a)
		{
			amount = a;
			numbers = new int [amount];
		}

		virtual ~primeNumberArray()
		{
			delete [] numbers;
		}
		
	private:
		void generate()
		{
			cout << "prime generate function " << endl;
			int temp;
			int count = 0;
			int j = 0;
			while(1)
			{
				temp = rand() % 1000 + 1;

				for(int i = 2; i <= temp; i++)
				{
					if(temp % i == 0)
					{
						count++;
					}
				}

				if(count == 1)
				{
					numbers[j] = temp;
					j++;
				}
				
				count = 0;
				
				if(j == amount)
					break;
			}
		}
};


class EvenNumberArray : public NumberArray
{
	public:	
		EvenNumberArray(int a)
		{
			amount = a;
			numbers = new int [amount];			
		}

		virtual ~EvenNumberArray()
		{
			delete [] numbers;
		}
		
		
	private:
		void generate()
		{
			cout << "even generate function " << endl;
			int temp;
			int i = 0;
			
			while(1)
			{
				temp = rand() % 1000 + 1;
				
				if(temp % 2 == 0)
				{
					numbers[i] = temp;
					i++;
				}
				
				if(i == amount)
					break;		
			}			
		}
};


class OddNumberArray : public NumberArray
{
	public:
		OddNumberArray(int a)
		{
			amount = a;
			numbers = new int [amount];			
		}


		virtual ~OddNumberArray()
		{
			delete [] numbers;
		}
		
	private:
		void generate()
		{
			cout << "odd generate function " << endl;
			int temp;
			int i = 0;
			
			while(1)
			{
				temp = rand() % 1000 + 1;
				
				if(temp % 2 == 1)
				{
					numbers[i] = temp;
					i++;
				}
				
				if(i == amount)
					break;		
			}					
		}
};

int main()
{
	srand (time(NULL));
	
	int lenght, lenght2, lenght3, lenght4;

	cout << "Enter lenght for normal nubmer array: ";
	cin >> lenght;
	cout << endl;

	cout << "Enter lenght for prime number array: ";
	cin >> lenght2;
	cout << endl;

	cout << "Enter lenght for even number array: ";
	cin >> lenght3;
	cout << endl;

	cout << "Enter lenght for odd number array: ";
	cin >> lenght4;
	cout << endl;


	NumberArray * ptrNormal;

	cout << "Normal numbers: ";
	ptrNormal = new NumberArray(lenght); 
	ptrNormal->generateAndprint();
	cout << endl;
	delete ptrNormal;

	cout << "Prime numbers: ";
	ptrNormal = new primeNumberArray(lenght2);
	ptrNormal->generateAndprint();
	cout << endl;
	delete ptrNormal;

	cout << "Even numbers: ";
	ptrNormal = new EvenNumberArray(lenght3);
	ptrNormal->generateAndprint(); 
	cout << endl;
	delete ptrNormal;

	cout << "Odd numbers: ";
	ptrNormal = new OddNumberArray(lenght4);
	ptrNormal->generateAndprint(); 
	cout << endl;
	delete ptrNormal;

	return 0;
	
}
