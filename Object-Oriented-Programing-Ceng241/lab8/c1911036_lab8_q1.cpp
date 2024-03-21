#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Song
{
	private:
		string title;
		int min;
		int sec;
	
	public:	
		Song()
		{
			title = "";
			min = 0;
			sec = 0;			
		}
		
		Song(string t)
		{
			title = t;
			min = 0;
			sec = 0;			
		}
		
		Song(string t, int m, int s)
		{
			title = t;
			min = m;
			sec = s;
		}
		
		Song(const Song & obj)
		{
			title = obj.title;
			min = obj.min;
			sec = obj.sec;
		}
		
		//Song(Song && obj)
		//{
			
	//	}
		
		string getTitle()
		{
			return title;
		}
		
		int getMin()
		{
			return min;
		}
		
		int getSec()
		{
			return sec;
		}
		
		void setTitle(string t)
		{
			title = t;
		}
		
		void setMin(int m)
		{
			min = m;
		}
		
		void setSec(int s)
		{
			sec = s;
		}

};

class Playlist : public Song
{
	private:
		vector <Song> songs;
		int totalsec;
		int count = 0;
		
	public:
		Playlist()
		{
			totalsec = 0;
		}
		
		void add(Song & obj)
		{
			count++;
			songs.push_back(obj);
			totalsec = totalsec + obj.getMin() * 60 + obj.getSec();
		}
		
		void search(string s)
		{
			for(int i = 0; i < count; i++)
			{
				string name = songs[i].getTitle();
				int index = name.find(s);
				if(index >= 0 )
				{
					cout << "- " << songs[i].getTitle() << "(" << songs[i].getMin() << ":" << songs[i].getSec() << ")" << endl;	
				}
			}
		}
		
		void print()
		{
			for(int i = 0; i < count; i++)
			{
				cout << "- " << songs[i].getTitle() << "(" << songs[i].getMin() << ":" << songs[i].getSec() << ")" << endl;				
			}
			cout << "Total duration: " << totalsec / 60 << ":" << totalsec % 60 << endl;
		}
		
		int getTotalsec()
		{
			return totalsec;
		}
		
		void setTotalsec(int t)
		{
			totalsec = t;
		}
			
	
	
};


int main()
{
	int choice = 1;
	
	Song songObj;
	Playlist playlistObj;
	
	do
	{
		cout << "1. Add" << endl;
		cout << "2. Display" << endl;
		cout << "3. Search" << endl;
		cout << "4. Exit" << endl;
		
		cin >> choice;
		
		if(choice == 1)
		{
			string title;
			int min;
			int sec;
			
			cout << "Enter song title: ";
			getline(cin >> ws,title);
			cout << endl;
			
			cout << "Enter song duration: ";
			cin >> min;
			cin >> sec;
			
			songObj.setMin(min);
			songObj.setSec(sec);
			songObj.setTitle(title);
			
			playlistObj.add(songObj);
		}
		
		else if (choice == 2)
		{
			cout << "Your playlist: " << endl;
			
			playlistObj.print();			
		}
		
		else if(choice == 3)
		{
			string search;
			
			cout << "Enter part of song title to search: ";
			getline(cin >> ws, search);
			
			playlistObj.search(search);
		}	
		
	}while(choice != 4);
	
	return 0;
}
