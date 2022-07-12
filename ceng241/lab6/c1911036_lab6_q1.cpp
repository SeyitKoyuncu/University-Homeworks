#include <iostream>
#include <string>

using namespace std;

class Song
{
	
	public : 
	
		Song()
		{
			min = 0;
			sec = 0;
			title = " ";
			cout << "first constrctuor called" << endl;
		}
		
		Song(string t)
		{
			min = 0;
			sec = 0;
			title = t;
			cout << "second constrctuor called" << endl;
		}
		
		Song(string t, int m, int s)
		{
			title = t;
			min = m;
			sec = s;
			cout << "third constrctuor called" << endl;
		}
		
		void setMin(int m)
		{
			min = m;
		}
		
		void setSec(int s)
		{
			sec = s;
		}
		
		void setTitle(string t)
		{
			title = t;
		}
		
		int getMin()
		{
			return min;
		}
		
		int getSec()
		{
			return sec;
		}
		
		string getTitle()
		{
			return title;
		}
			
	private:
		
		int min;
		int sec;
		string title;
};


int main()
{
	Song song1;
	string song1Name;
	int song1Min;
	int song1Sec;
	
	cout << "Enter title and duration of first song: " ;
	
	getline(cin,song1Name);
	cin >> song1Min;
	cin >> song1Sec;
	
	song1.setSec(song1Sec);
	song1.setTitle(song1Name);
	song1.setMin(song1Min);
	
	
	string song2Name;
	int song2Min;
	int song2Sec;
	
	cout << "Enter title and duration of second song: " ;
	cin.ignore();
	getline(cin,song2Name);
	cin >> song2Min;
	cin >> song2Sec;
	
	Song song2 = Song(song2Name);
	song2.setSec(song2Sec);
	song2.setMin(song2Min);
	
	
	string song3Name;
	int song3Min;
	int song3Sec;
	
	cout << "Enter title and duration of third song: " ;
	cin.ignore();
	getline(cin,song3Name);
	cin >> song3Min;
	cin >> song3Sec;
	
	Song song3 = Song(song3Name, song3Min, song3Sec);
	
	cout << "Your playlist : " << endl;
	cout << "- " << song1.getTitle() << " (" << song1.getMin() <<":" << song1.getSec() << ")"<<endl;
	cout << "- " << song2.getTitle() << " (" << song2.getMin() <<":" << song2.getSec() << ")"<<endl;
	cout << "- " << song3.getTitle() << " (" << song3.getMin() <<":" << song3.getSec() << ")"<<endl;
	
	int totalMin = 0;
	int totalSecond = 0;
	
	totalMin = song1.getMin() + song2.getMin() + song3.getMin();
	totalSecond = song1.getSec() + song2.getSec() + song3.getSec();
	
	for(int i = 0; i < 3; i++)
	{
		if(totalSecond > 60)
		{
			totalMin = totalMin + 1;
			totalSecond = totalSecond - 60;
		}
	}
	
	cout << "Total Duration: " << totalMin << "minutes, " << totalSecond << "seconds";
	
}
