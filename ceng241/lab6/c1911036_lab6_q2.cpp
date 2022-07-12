#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class ChessPiece
{
	private:
		string type;
		char xcoord;
		int ycoord;
		
	public:
		ChessPiece()
		{
			srand (time(NULL)); 
			int randomType;
			
			xcoord = 'a' + rand()%8;
			ycoord = rand() % 8 + 1;
			randomType = rand() % 6 + 1;
			
			if(randomType == 1)
				type = "king";
			
			else if(randomType == 2)
				type = "rook";
			
			else if(randomType == 3)
				type = "bishop";
				
			else if(randomType == 4)
				type = "queen";
				
			else if(randomType == 5)
				type = "knight";
				
			else if(randomType == 6)
				type = "pawn";
		}
		
		ChessPiece(string t)
		{
			type = t;
			srand (time(NULL));
			
			xcoord = 'a' + rand()%8;
			ycoord = rand() % 8 + 1;
		}
		
		ChessPiece(string t, char x, int y)
		{
			type = t;
			xcoord = x;
			ycoord = y;
		}
		
		void print()
		{
			cout << type << " is at " << char(xcoord) << ycoord << endl;
		}
};


int main()
{	
	string secondType;
	string thirdType;
	char thirdX;
	int thirdY;
	
	ChessPiece firstPiece; 
	
	cout << "Enter type for second piece: ";
	cin >> secondType;
	
	ChessPiece secondPiece(secondType);
	
	cout << endl << "Enter type and coordinates for third piece: ";
	cin >> thirdType >> thirdX >> thirdY;
	
	ChessPiece thirdPiece(thirdType, thirdX, thirdY);
	
	cout << "First piece: "; 
	firstPiece.print();
	
	cout << "Second piece: ";
	secondPiece.print();
	
	cout << "Third piece: ";
	thirdPiece.print();
}
