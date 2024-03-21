#include <iostream>
#include <stdlib.h>    
#include <time.h>

using namespace std;

class D
{
	public:
		int * numbers = new int[3];
		
		D()
		{
			for(int i = 0; i < 3; i++)
			{
				numbers[i] = rand() % 10 + 1;
			}
		}
		
		~D()
		{
			delete [] numbers;
		}
};



class A {
	protected:
		D d;
		
	public:
		
		A()
		{}
		
		void print()
		{
			for(int i = 0; i < 3; i++)
			{
				cout << d.numbers[i] << " ";
			}
			cout << endl;
		}
};


class B : public A{
	public:
		
		B()
		{}
		
		int evens()
		{
			int count = 0;
			
			for(int i = 0; i < 3; i++)
			{
				if(d.numbers[i] % 2 == 0)
				{
					count++;
				}					
			}
			
			return count;
		}
};

class C : public A{
	public:
		
		C()
		{}
		
		int odds()
		{
			int count = 0;
			
			for(int i = 0; i < 3; i++)
			{
				if(d.numbers[i] % 2 == 1)
				{
					count++;
				}					
			}
			
			return count;			
		}
};


int main()
{
	srand (time(NULL));
	
	B b;
	C c;
	A a;
	

	cout << "B array: ";
	b.print();
	
	cout << "B evens: " << b.evens();
	cout << endl;
	
	cout << "C array: ";
	c.print();
	
	cout << "C evens: " << c.odds();
	cout << endl;	
}

