#include <iostream>
#include <string>

using namespace std;


class VideoGames{
	
	private:
		string name;
		string type;
		double price;
		bool buy;
		
	public:
		void setName(string n){
			name = n;
		}
		
		string getName()
		{
			return name;
		}
		
		
		void setType(string t){
			type = t;
		}
		
		string getType()
		{
			return type;
		}
		
		
		void setPrice(double p){
			price = p;
		}
		
		double getPrice()
		{
			return price;
		}
		
		
		void setBuy(bool b){
			buy = b;
		}
		
		bool getBuy()
		{
			return buy;
		}
};


int main()
{
	VideoGames games[4];
	
	char name [10];
	char type [10];
	double price;
	bool buy;	
	double discountedPrice[4];
	
	for(int i = 0; i < 4; i++)
	{
		cout << "Enter game type, name and price: ";
		cin >> name;
		cin >> type;
		cin >> price;
		
		cout << endl;
		
		games[i].setName(name);
		games[i].setType(type);
		games[i].setPrice(price);
	
		if(games[i].getName() == "Action" || games[i].getName() == "action")
			discountedPrice[i] = games[i].getPrice() - (games[i].getPrice() * 10 / 100);	

		else if(games[i].getName() == "Strategy" || games[i].getName() == "strategy")
			discountedPrice[i] = games[i].getPrice() - (games[i].getPrice() * 20 / 100);	
			
		else if(games[i].getName() == "Sport" || games[i].getName() == "sport")
			discountedPrice[i] = games[i].getPrice() - (games[i].getPrice() * 30 / 100);
			
		else if(games[i].getName() == "Adventure" || games[i].getName() == "adventure")
			discountedPrice[i] = games[i].getPrice() - (games[i].getPrice() * 25 / 100);
			
		if(discountedPrice[i] > 150)
			games[i].setBuy(0);
		
		else
			games[i].setBuy(1);	
			
	}
	
	
	for(int i = 0; i < 4; i++)
	{
		cout << "Game " << i+1 << ":" << endl;
		
		cout << "Name : " << games[i].getName() << endl;
		
		cout << "Type : " << games[i].getType() << endl;
		
		cout << "Price: " << games[i].getPrice() << " Discounted Price: " << discountedPrice[i] << endl;
		
		cout << "Buy :" << games[i].getBuy() << endl;
	}
}
