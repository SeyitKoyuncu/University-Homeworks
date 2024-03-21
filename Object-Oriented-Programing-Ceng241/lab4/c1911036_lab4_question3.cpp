#include <iostream>

using namespace std;

struct numberlist
{
	int value[10];
	string control;	
};

void func_referans(struct numberlist & a)
{
	int sum = 0;
	
	if(a.control == "left-to-right")
	{
		for(int i = 0; i < 10; i++)
		{
			sum = sum + a.value[i];
			a.value[i] = sum;
		}
	}
	
	if(a.control == "right-to-left")
	{
		for(int i = 0; i < 10; i++)
		{
			sum = sum + a.value[i];
		}
		
		int holder[10];
		
		for(int i = 0; i < 10; i++)
		{
			holder[i] = a.value[i];
		}
		 
		for(int i = 0; i < 10; i++)
		{
			a.value[i] = sum;
			sum = sum - holder[i];
		}	
	}
}

void func_pointer(struct numberlist * a)
{
	int sum = 0;
	
	if(a->control == "left-to-right")
	{
		for(int i = 0; i < 10; i++)
		{
			sum = sum + a->value[i];
			a->value[i] = sum;
		}
	}
	
	if(a->control == "right-to-left")
	{
		for(int i = 0; i < 10; i++)
		{
			sum = sum + a->value[i];
		}
		
		int holder[10];
		
		for(int i = 0; i < 10; i++)
		{
			holder[i] = a->value[i];
		}
		 
		for(int i = 0; i < 10; i++)
		{
			a->value[i] = sum;
			sum = sum - holder[i];
		}	
	}
}

int main()
{
	struct numberlist element;
	
	cout <<"Enter 10 integers and order of summation: "<<endl;
	
	for(int i = 0; i < 10; i++)
	{
		cin >> element.value[i];
	}
	
		cin >> element.control;
	
	int holder[10];
	
	for(int i = 0; i < 10; i++)
		holder[i] = element.value[i];
	
	
	func_pointer(&element);
	
	cout << "Result with pointer: ";
	
	for(int i = 0; i < 10; i++)
	{
		cout << element.value[i] << " ";
	}
	
	cout << endl;
	
	for(int i = 0; i < 10; i++)
		element.value[i] = holder[i];
	
	func_referans(element);
	
	cout << "Result with referans: ";
	
	for(int i = 0; i < 10; i++)
	{
		cout << element.value[i] << " ";
	}
}


