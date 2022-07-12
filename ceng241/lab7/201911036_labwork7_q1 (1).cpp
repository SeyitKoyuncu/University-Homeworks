#include <iostream>
#include <string>


using namespace std;

class Book{
	
private: 
	string title;
	string writer;
	float price;
	
public: 
	Book()
	{
		cout << "default constructor called " << endl;
		
		title = "";
		writer = "";
		price = 0;
	}
	
	Book(string t, string w, float p) 
	{
		cout << "overloaded constructor called " << endl;
		
		title = t;	
		writer = w;
		price = p;
	}
	
	Book(const Book &obj)
	{
		cout << "copy constructor called" << endl;
		
		title= obj.title;
		writer= obj.writer;
		price= obj.price;
		
	}
	string getTitle()
	{
		return title;
	}
	
	string getWriter()
	{
		return writer;
	}
	
	float getPrice()
	{
		return price;
	}
	
	void setTitle(string t)
	{
		title = t;
	}
	
	void setWriter(string w)
	{
		writer = w;
	}
	
	void setPrice(float p)
	{
		price = p;
	}
	
};



int main()
{
	Book * b[2];
	string t, w;
	float p;
	int i;
	
	b[0] = new Book();
	
	for (i=0; i<2; i++)
	{
		if(i == 0)
		{
			cout << "Enter title: ";
			getline(cin, t);
			b[i]->setTitle(t);
			
			cout << "Enter writer: ";
			getline(cin, w);
			b[i]->setWriter(w);
			
			cout << "Enter price: ";
			cin >> p;
			cin.ignore();
			b[i]->setPrice(p);			
		}
		
		
		if(i == 1)
		{
			cout << "Enter title: ";
			getline(cin, t);
			
			cout << "Enter writer: ";
			getline(cin, w);
			
			cout << "Enter price: ";
			cin >> p;
			cin.ignore();	
			
			b[i] = new Book(t,w,p);		
		}
	}
	
	int choice;
	
	cout << "Enter book you want to copy: 1 or 2" << endl;
	cin >> choice;
	
	Book CopyBook = *b[choice-1];
	
	for (i=0; i<2; i++)
	{
		cout << "Book " << i+1 << endl ;
		cout << b[i]->getTitle() << "\t" << b[i]->getWriter() << "\t" << b[i]->getPrice() << endl;	
	}
	
	cout << "copy book : " << endl << CopyBook.getTitle() << "\t" << CopyBook.getWriter() << "\t" << CopyBook.getPrice();
	
	delete b[0];
	delete b[1];
	
	return 0;
}


