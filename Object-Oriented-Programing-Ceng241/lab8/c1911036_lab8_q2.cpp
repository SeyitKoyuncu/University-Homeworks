#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Application
{
	protected:	
		string name;
		string type;
		
		
	public:
		
		Application(string n, string t)
		{
			name = "";
			type = "";
		}
		
		void print()
		{
			cout << "Application print func";
		}
		
		string getName()
		{
			cout << name;
			return name;
		}
		
		string getType()
		{
			return type;
		}
		
		void setName(string n)
		{
			name = n;
		}
		
		void setType(string t)
		{
			type = t;
		}
};


class DesktopApplication : public Application
 {
	private:
	  int size;
	  
	public:
		DesktopApplication(string n , string t, int s) : Application (n,t)
		{
			setName(n);
			setType(t);
			size = s;
		}	
		
		void print()
		{
			cout << "-" << getName() << ", " << getType() << "(" << size << ")" <<endl;
		}
		
		int getSize()
		{
			return size;
		}
		
		void getSize(int s)
		{
			size = s;
		}
 };
 
 
 class WebApplication : public Application
 {
 	private:
		string address;
 		
 	public:
 		
		WebApplication (string n , string t,	string 	a) : Application(n,t)
		{
		 	setName(n);
		 	setType(t);
		 	address = a;
		}	
		
		void print()
		{
			cout << "-" << getName() << ", " << getType() << "." << "Address : " << address <<endl;			
		}
		
		string getAddress()
		{
			return address;
		}
		
		void setAddress(string a)
		{
			address = a;
		}
		
 };

int main()
{
	int choice = 0;
	
	vector <WebApplication> webObj;
	vector <DesktopApplication> desktopObj;
	
	int countDesktop = 0;
	int countWeb = 0 ;
	
	
	do
	{
		cout << "1-New desktop applicaiton: "<< endl;
		cout << "2-New web application: "<< endl;
		cout << "3-Exit " << endl; 
		cin >> choice;
		cout << "Your choice : " << choice << endl;
		
		
		if(choice == 1)
		{
			countDesktop++;
			
			string title;
			cout << "Application title: ";
			getline(cin>>ws,title);
			cout << endl;
			
			string type;
			cout << "Application type: ";
			getline(cin>>ws,type);
			cout << endl;
			
			int size;
			cout << "Application size: ";
			cin >> size;
			cout << endl;
				
			DesktopApplication newObj(title,type,size);
			desktopObj.push_back(newObj);
		}
		
		if(choice == 2)
		{
			countWeb++;
			
			string title;
			cout << "Application title: ";
			getline(cin>>ws,title);
			cout << endl;
			
			string type;
			cout << "Application type: ";
			getline(cin>>ws, type);
			cout << endl;
			
			string address;
			cout << "Web address: ";
			getline(cin>>ws,address);
			
			cout << endl;
			
			WebApplication newObj(title, type, address);
			webObj.push_back(newObj);
		}
		
		if(choice == 3)
		{
			if(countDesktop > 0 && countWeb == 0)
			{
				cout << "Desktop Applications: " << endl;
				
				for(int i = 0; i < countDesktop; i++)
				{
					desktopObj[i].print();					
				}
			}
			
			else if(countDesktop == 0 && countWeb > 0 )
			{
				cout << "Web Applications: " << endl;
				
				for(int i = 0; i < countWeb; i++)
				{
					webObj[i].print();					
				}				
			}
		
			else if(countDesktop > 0 && countWeb > 0)
			{
				cout << "Desktop Applications: " << endl;
				
				for(int i = 0; i < countDesktop; i++)
				{
					desktopObj[i].print();					
				}	
				
				cout << "Web Applications: " << endl;
				
				for(int i = 0; i < countWeb; i++)
				{
					webObj[i].print();					
				}			
			}
			
			else
			{
				cout << "Web Applications and Desktop Applications are empty" << endl;
			}
		}
	}while (choice != 3);
	
	return 0;
}
