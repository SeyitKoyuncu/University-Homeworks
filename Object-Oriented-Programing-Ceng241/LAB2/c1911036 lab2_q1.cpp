#include <iostream>
using namespace std;

int main()
{
	char arr[26];
	char letter[26];
	int arr2[26] = {0};
	
	cout << "Enter your letters: " << endl;
	for(int i = 0; i < 26; i++)
		cin >> letter[i];
		
	int a = 0;
	int len = 0;
	int count_0 = 0; 
	int b = 0;
	int j = 0;
	
	/*
	for(int i = 0; i < 26; i++)
	{
		i = count_0;
		letter[i] = arr[b];
		
		for(int k = 0; k < 26; k++)
		{
			if(arr[b] == letter[k])
			{
				//cout << "girdi";
				arr2[a] = arr2[a] + 1;
				count_0++;
				j++;
			}
		}
		a++;
		b++;
	}
	
	*/
	int control = 0;
	
	for(int i = 0; i < 26; i++)
	{
		i = b;
		arr[a] =  letter[i];
			
		while(arr[a] == letter[i])
		{	
			count_0++;	
			i++;
		}
		
			
		if(arr[a] != letter[i])
		{
			//count_0 = 0;
			b = i;
		}
	
		cout << count_0 << " ";
		
		control = count_0 + control;
		
		count_0 = 0;
		
		a++;
		
		if(control == 26)
			break;
		
	}
	
	/*
	for(int i = 0; i < 26; i++)
	{
		cout << arr2[i] << "   ";
	}
	*/
	
	return 0;
}


