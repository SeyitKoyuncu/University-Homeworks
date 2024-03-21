#include <iostream>
#include <string>
#include <string>


using namespace std;

int main ()
{
	string first;
	
	cout << "Enter any string first: ";
	getline(cin , first);
	cout << endl;
	
	string sub;
	
	cout << "Enter substring you want to search: ";
	getline(cin, sub);
	cout << endl;
	
	int sub_len = sub.length();
	int first_len = first.length();
	
	int count = 0;
	
	for(int i = 0; i < first_len+1; i++ )
	{
		if(count != sub_len)
		{
			if (first[i] == sub[count])
			{
				count ++;
			}			
		}
		
		else
		{
			cout << "The substring [" << sub << "]  is present in given string at position [" << i - count + 1 << "]";
			break;	
		}

	}
	
	
	
	
	return 0;
}
