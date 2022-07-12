#include <string>
#include <iostream>

using namespace std;

int main()
{
	string str;
	
	cout << "Enter a line of string: ";
	getline(cin, str);
	
	int len = str.length();
	int vowel = 0, digits = 0, consonants = 0, spaces = 0;
	
	
	for(int i = 0; i < len; i++ )
	{
		if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' 
		|| str[i] == 'u' ||  str[i] == 'U')
			vowel++;
			
		else if(isdigit(str[i]))
			digits++;
			
		else if(str[i] == ' ')
			spaces++;
		
		else
			consonants++;	
	}
	
	cout << endl;
	
	cout << "Vowels: " << vowel << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White Spaces: " << spaces << endl;
	
}
