#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Flight
{
    private:
        string flightNo;
        int maximumNumberOfSeats = 25;
        int NumberOfPassengers;
        vector <string> listOfPassengers;

    public:

        Flight()
        {
            flightNo = "FLIGHT102";
            NumberOfPassengers = 0;
        }

        bool reserveSeat(string nameOfPassenger)
        {
            if(NumberOfPassengers == maximumNumberOfSeats)
            {
                cout << "we cant reserve because all seats are full" << endl;
                return false;
            }

            cout << "succesfully reserved..." << endl;

            NumberOfPassengers++;
            listOfPassengers.push_back(nameOfPassenger);

        }

        bool cancelReservation(string nameOfPassenger)
        {
            for(int i = 0; i < NumberOfPassengers; i++)
            {
                if(listOfPassengers[i] == nameOfPassenger)
                {
                    listOfPassengers.erase(listOfPassengers.begin()+i);  
                    NumberOfPassengers--;
                    cout << "Succesfully canceling..." << endl;
                    return true;
                }
            }
            cout << "We cant find this passenger..." << endl;
            return false;
        }

        int numberOfPassengers()
        {
            return NumberOfPassengers;
        }

        bool searchUser(string name)
        {
            for(int i = 0; i < NumberOfPassengers - 1; i++)
            {
                if(listOfPassengers[i] == name)
                    return true;
            }

            return false;
        }

        void printPassengers()
        {
            int size = listOfPassengers.size();
            for(int i = 0; i < size; i++)
            {
                cout << i+1 << ". seat = " << listOfPassengers[i] << endl;
            }
        }

        void setFlightNo(string setFlightNo) { this -> flightNo = flightNo; }
        void setMaximumNumberOfSeats( int maximumNumberOfSeats) { this -> maximumNumberOfSeats = maximumNumberOfSeats; }
        void setNumberOfPassengers(int NumberOfPassengers) { this -> NumberOfPassengers = NumberOfPassengers; }
        void setListOfPassengers(string listOfPassengers[], int size)
        {
            for(int i = 0; i < size; i++)
            {
                this -> listOfPassengers.push_back(listOfPassengers[i]);
            }
        }

        string getFlightNo() { return flightNo; }
        int getMaximumNumberOfSeats() { return maximumNumberOfSeats; }
        int getNumberOfPassengers() { return NumberOfPassengers; }
        vector <string> getListOfPassengers() { return listOfPassengers; }

        ~Flight() {}

};    


void menu()
{
    cout << "1- Reserve a ticket" << endl;
    cout << "2- Cancel a reservation" << endl;
    cout << "3- Check whether a ticket is reserved for a particular person" << endl;
    cout << "4- display the passengers." << endl;
    cout << "5- Exit" << endl;
}

int main()
{
    int choice;
    Flight passengers;
    int count = 0;

    string name;
    bool happen;
    menu();

    do
    {   
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        if(choice == 1)
        {
            cout << "Write name which you want to reserve: ";
            cin >> name;
            passengers.reserveSeat(name);
        }

        else if(choice == 2)
        {
            cout << "Write name which you want to cancel reserve: ";
            cin >> name;
            passengers.cancelReservation(name);
        }

        else if(choice == 3)
        {
            cout << "Write name which you want to check: ";
            cin >> name;
            happen = passengers.searchUser(name);
            cout << endl;

            if(happen == true)
                cout << "He/she has a ticket. " << endl;

            else if(happen == false)
                cout << "He/she don't have a ticket." << endl;
        }

        else if(choice == 4)
        {
            cout << "---" << passengers.getFlightNo() << "----" << endl;
            cout << "Flight have " << passengers.numberOfPassengers() << " passengers. " << endl;
            passengers.printPassengers();
        }

        else if(choice == 5)
        {
            cout << "Good bye !!" ;
            return 0;
        }

        else
            cout << "You choice wrong number, pls try again..." << endl;
    }while(1);

    return 0;
}