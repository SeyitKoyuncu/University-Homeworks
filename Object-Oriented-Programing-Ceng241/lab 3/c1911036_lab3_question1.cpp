#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	
	ofstream file;
	string file_name;
	
	cout << "Enter file name: " <<endl;
	cin >> file_name;
	
	file.open(file_name.c_str(), ios :: out);
	
	
	int happ = 1;
	char add; 
	string info;
	
	cout << "Enter information to store..." << endl;
	getline(cin >> ws,info);
	
	file << info + "\n";
				
	do{ 
		
		cout << "Want to enter more ? (y/n)" << endl;
		cin >> add;
		
		if(add == 'y')
		{
			getline(cin >> ws ,info);
			file << info + "\n";
			happ = 1;
		}
			
		else if(add == 'n')
			happ = 0;
			
	}while (happ == 1);
	
	file.close();
	
	cout << "This information successfully stored in the file... !!!" << endl;
	
	char see;
	cout << "Want to see ? (y / n)" << endl;
	cin >> see;
	
	ifstream read_data;
	read_data.open(file_name.c_str(), ios :: in );
	
	string read;
	
	if(see == 'y')
	
	{
		cout << "The file contains: " << endl;
		
		while(getline (read_data,read))
		{
			cout << read << endl;
		}		
	}
	
	else
	{
		cout << "bye";
	}
	
	read_data.close();
	
	
	return 0 ;
}
