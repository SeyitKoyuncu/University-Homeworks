#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class Car
{
	private:
		
		string model;
		int max_speed;
		int * speed_traps;
		int * pit_stops;
		int numberOfSpeedTraps;
		int numberOfPitStops;
		
	public:
	
		Car()
		{
			model = "";
			max_speed = 100;
			speed_traps = new int[5];
			pit_stops = new int[2];
			numberOfSpeedTraps = 0;
			numberOfPitStops = 0;
		}
		
		Car(string m, int ms )
		{
			model = m;
			max_speed = ms;
			speed_traps = new int[5];
			pit_stops = new int[2];
			numberOfSpeedTraps = 0;
			numberOfPitStops = 0;
		}
		
		Car(const Car &obj)
		{
			model = "car2";
			max_speed = 100;
			speed_traps = new int[5];
			pit_stops = new int[2];
			numberOfSpeedTraps = 0;
			numberOfPitStops = 0;
		}
		
		void Race()
		{
			speed_traps[numberOfSpeedTraps] = (rand() % max_speed) + 10;
			pit_stops[numberOfPitStops] = (rand() % 10) + 1; 
			
			numberOfSpeedTraps++;
			numberOfPitStops++;
		}
		
		int getMaxSpeed()
		{
			return max_speed;
		}
		
		int getNumberOfSpeedTraps()
		{
			return numberOfSpeedTraps;
		}
		
		int getNumberOfPitStops()
		{
			return numberOfPitStops;
		}
		
		string getModel()
		{
			return model;
		}
		
		int * getSpeed_Traps()
		{
			return  speed_traps;
		}
		
		int * getPit_Stops()
		{
			return pit_stops;
		}
		
		void setSpeed_Traps(int arr[5])
		{
			for(int i = 0; i < 5; i++)
			{
				speed_traps[i] = arr[i];
			}
		}
		
		void setPit_Stops(int arr[5])
		{
			for(int i = 0; i < 5; i++)
			{
				pit_stops[i] = arr[i];
			}
		}
		
		void setMaxSpeed(int ms)
		{
			max_speed = ms;
		}
		
		void setNumberOfSpeedTraps(int nst)
		{
			numberOfSpeedTraps = nst;
		}
		
		void setNumberOfPitStops(int nps)
		{
			numberOfPitStops = nps;
		}
		
		void setModel(string m)
		{
			model = m;
		}
							
		~Car()
		{
			delete [] speed_traps;
			delete [] pit_stops;
		}	
	
};


int main()
{
	srand (time(NULL));

	Car car1("car1", 140);
	
	cout << car1.getModel() << ":" << endl;
	cout << "speed trap: " << endl;
	
	for(int i = 0; i < 5; i++)
	{
		car1.Race();
	}
	
	int * hiz = car1.getSpeed_Traps();
	double avg = 0;
	
	for(int i = 0; i < 5; i++)
	{
		cout << i+1 << ": " << hiz[i] << endl;
		avg = hiz[i] + avg;
	}	
	
	int * pit = car1.getPit_Stops();
	
	for(int i = 0; i < 2; i++)
	{
		cout << i+1 << ". pit stop: " << pit[i] <<endl;
	}
	
	avg = avg / 5;
	cout << "Avg Speed : " << avg << endl;	
	
	double totalTime = ((60 * 50) / avg) + pit[0] + pit[1];
	
	int a = totalTime;
	cout << "Total time : " << a << ":" << totalTime - a << endl ;


	Car car2 = car1;

	cout << "\n\n" << car2.getModel() << ":" << endl;
	cout << "speed trap: " << endl;
	
	for(int i = 0; i < 5; i++)
	{
		car2.Race();
	}
	
	int * hiz2 = car2.getSpeed_Traps();
	double avg2 = 0;
	
	for(int i = 0; i < 5; i++)
	{
		cout << i+1 << ": " << hiz2[i] << endl;
		avg2 = hiz2[i] + avg2;
	}	
	
	int * pit2 = car2.getPit_Stops();
	
	for(int i = 0; i < 2; i++)
	{
		cout << i+1 << ". pit stop: " << pit2[i] <<endl;
	}
	
	avg2 = avg2 / 5;
	cout << "Avg Speed : " << avg2 << endl;	
	
	double totalTime2 = ((60 * 50) / avg2) + pit2[0] + pit2[1];
	
	int a2 = totalTime2;
	cout << "Total time : " << a2 << ":" << totalTime2 - a2 << endl;
	
	if(totalTime > totalTime2)
		cout << "\n\nWinner is Car 1" << endl; 
		
	else if(totalTime2 > totalTime)
		cout << "\n\nWinner is Car 2"; 
		
	else
		cout << "\n\nBoth of them win";
		
		
	return 0;
}
