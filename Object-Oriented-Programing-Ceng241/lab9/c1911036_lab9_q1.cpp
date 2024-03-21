    #include <iostream>
    #include <string>

    using namespace std;

class calculator
{


	private:
		int lenght;
		float * numbers;
	
	public:

		friend ostream & operator << (ostream & os, const calculator & rhs);

		calculator()
		{
			lenght = 0;
			numbers = new float [10];		
		}
		
		calculator(int l)
		{
			lenght = l;
			numbers = new float[lenght];
		}
		
		
		calculator operator +(const calculator &rhs)const
		{
			float * buff = new float [lenght];
			cout << " + operater func" << endl;
			
			for(int i = 0; i < lenght; i++)
			{
				buff[i] = 0;
				buff[i] = this->numbers[i] + rhs.numbers[i];
			//	cout << buff[i];
			}
			
			calculator thirdSet(lenght);
			
			thirdSet.setNumbers(buff);
			delete [] buff;
			
			return thirdSet;
		}
		
		calculator operator -(const calculator &rhs)const
		{
			cout << "- operator func girdi"<< endl;
			
			float * buff = new float [lenght];
			
			for(int i = 0; i < lenght; i++)
			{
				buff[i] = 0;
				buff[i] = this->numbers[i] - rhs.numbers[i];
				//cout << buff[i];
			}
			
			calculator thirdSet(lenght);
			
			thirdSet.setNumbers(buff);
			
			return thirdSet;
		}
		
		calculator operator *(const calculator &rhs)const
		{
			cout << "* operator func girdi" << endl;
			
			float * buff = new float [lenght];
			
			for(int i = 0; i < lenght; i++)
			{
				buff[i] = 0;
				buff[i] = this->numbers[i] * rhs.numbers[i];
				//cout << buff[i];
			}
			
			calculator thirdSet(lenght);
			
			thirdSet.setNumbers(buff);
			delete [] buff;
			
			return thirdSet;
		}
		
		calculator operator /(const calculator &rhs)const
		{
			cout << "/ operator func girdi" << endl;
			
			float * buff = new float [lenght];
			
			for(int i = 0; i < lenght; i++)
			{
				buff[i] = 0;
				buff[i] = this->numbers[i] / rhs.numbers[i];
				//cout << buff[i];
			}
			
			calculator thirdSet(lenght);
			
			thirdSet.setNumbers(buff);
			delete [] buff;
			
			return thirdSet;
		}


			
		const calculator & operator =(const calculator & rhs)const
		{
			cout << "= operator func girdi" << endl;
			
			calculator thirdSet(lenght);
			thirdSet.lenght = rhs.lenght;
			
			for(int i = 0; i < lenght; i++)
			{
				this->numbers[i] = rhs.numbers[i];	
			}
		
			return *this;
		}
		
		
		int getLenght()
		{
			return lenght;
		}
		
		float getNumbers()
		{
			static int i = -1;
			i++;
			return numbers[i];
		}
		
		void setLenght(float l)
		{
			lenght = l;
		}
		
		void setNumbers(float arr[])
		{
			for(int i = 0; i < lenght; i++)
			{
				numbers[i] = arr[i];
			}
		}
		
		~calculator()
		{
			delete [] numbers;
		}
	
};

ostream & operator << (ostream & os, const calculator & rhs)
{
	//int lenght = rhs.getLenght;

	for(int i = 0; i < rhs.lenght; i++)
	{
		os << rhs.numbers[i] << " ";
	}

	return os;
}


int main()
{
	int lenght;
	
	cout << "Lenght of the first number set: " ;
	cin >> lenght;
	cout << endl;
	calculator firstSet(lenght);
	
	float arr[lenght];
	
	cout << "First set entered: ";
	for(int i = 0; i < lenght; i++)
	{
		cin >> arr[i];
	}
	
	cout << endl;
	firstSet.setNumbers(arr);
	
	
	int lenght2;
	
	cout << "Lenght of the second number set: " ;
	cin >> lenght2;
	cout << endl;
	calculator secondSet(lenght2);
	
	float arr2[lenght2];
	
	cout << "Second set entered: ";
	for(int i = 0; i < lenght2; i++)
	{
		cin >> arr2[i];
	}
	
	secondSet.setNumbers(arr2);
	
	char choose;
	cout << "Choose operation: ";
	cin >> choose;
	
	calculator thirdSet(lenght);
	
	if(choose == '+')
	{
		thirdSet = firstSet + secondSet;	
		cout << endl;
		
		cout << thirdSet << " ";			

	}
	
	else if(choose == '-')
	{
		thirdSet = firstSet - secondSet;	
		cout << endl;

		cout << thirdSet;			
	}
	
	else if(choose == '*')
	{
		thirdSet = firstSet * secondSet;	
		cout << endl;
	
		cout << thirdSet;			
	}
	
	else if(choose == '/')
	{
		thirdSet = firstSet / secondSet;	
		cout << endl;

		cout << thirdSet;			
	}
	
	else if(choose == '=')
	{
		thirdSet = secondSet;	
		cout << endl;
		cout << "copy lenght = " << thirdSet.getLenght() << endl;
		cout << "copy numbers: " << endl;
		
		cout << thirdSet;			
	}
}