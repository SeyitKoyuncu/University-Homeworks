#include <iostream>
using namespace std;

int main()
{
	cout << "Enter bar heights:" << endl;
	
	int arr[10][10] = {0};
	int arr_2[10][10] = {0};
	int k = 0;
	
	for(int i = 0; i < 10; i++)
	{
		cin >> arr[0][i];
	}
	
	for(int i = 0; i < 10; i++)
	{
		for(k = 0; k < arr[0][i]; k++)
		{
			arr_2[k][i] = 1;
		}
	}
	
	for(int i = 0; i < 10; i++)
	{
		for( k = 0; k < 10; k++)
		{
			if(arr_2[i][k] != 0)
				cout << "# ";
				
			else
				cout << "  ";
		}
		cout << endl;
	}
	
	return 0;
}
