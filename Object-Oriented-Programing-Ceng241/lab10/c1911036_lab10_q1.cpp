#include <iostream>
#include <string>


using namespace std;


class DistanceUnit
{
    protected:
        float value;

    public:
        DistanceUnit()
        {
            value = 0;
        }

        DistanceUnit operator ++(int lhs)
        {
            value++;
        }

        DistanceUnit operator --(int lhs)
        {
            value--;
        }

        DistanceUnit operator -=(int lhs)
        {
            value = value +-lhs;
        }
               
        DistanceUnit operator +=(int lhs)
        {
            value = value + lhs;
        }

        float getValue() { return value; }
        void setValue(float v) { value = v; }

};

class Foot : public DistanceUnit
{
    public:
        float toMeters()
        {
           return value * 0.3048;
        }
};

class Meter : public DistanceUnit
{
    public:
        float toFeet()
        {
            return value / 0.3048;
        }
};

int main()
{
    int choice;

    cout << "1. Set distance to feet " << endl;
    cout << "2. Set distance to meter "<< endl;
    cout << "choice : ";
    cin >> choice;

    int n;

    if(choice == 1)
    {
        Foot objFoot;

        cout << "Distance : " << objFoot.getValue() << endl;

        while(1)
        {
            int choiceFoot;

            cout << "1. Move 1 foot forwards" << endl;
            cout << "2. Move 1 foot backwards" << endl;
            cout << "3. Move n foot forwards" << endl;
            cout << "4. Move n foot backwards" << endl;
            cout << "5. Convert to meter " << endl;
            cout << "6. Exit" << endl;
            cout << "your choice : ";
            cin >> choiceFoot;
            cout << endl;

            if(choiceFoot == 1)
            {
                objFoot++;
            }

            else if(choiceFoot == 2)
            {
                objFoot--;
            }

            else if(choiceFoot == 3)
            {
                cout << "Enter N: ";
                cin >> n;
                cout << endl;

                objFoot += n;
            }

            else if(choiceFoot == 4)
            {
                cout << "Enter N: ";
                cin >> n;
                cout << endl;

                objFoot -= n;
            }   

            else if(choiceFoot == 5)
            {
                cout << objFoot.getValue() << " feet : " << objFoot.toMeters() << " meters " << endl;
            }   
    
            else if(choiceFoot == 6)
            {
                cout << "Bye !!";
                break;
            }
        }
    }       

    else if(choice == 2)
    {
        Foot objMeter;

        cout << "Distance : " << objMeter.getValue() << endl;

        while(1)
        {
            int choiceMeter;

            cout << "1. Move 1 meter forwards" << endl;
            cout << "2. Move 1 meter backwards" << endl;
            cout << "3. Move n meter forwards" << endl;
            cout << "4. Move n meter backwards" << endl;
            cout << "5. Convert to foot " << endl;
            cout << "6. Exit" << endl;
            cout << "your choice : ";
            cin >> choiceMeter;
            cout << endl;

            if(choiceMeter == 1)
            {
                objMeter++;
            }

            else if(choiceMeter == 2)
            {
                objMeter--;
            }

            else if(choiceMeter == 3)
            {
                cout << "Enter N: ";
                cin >> n;
                cout << endl;

                objMeter += n;
            }

            else if(choiceMeter == 4)
            {
                cout << "Enter N: ";
                cin >> n;
                cout << endl;

                objMeter -= n;
            }   

            else if(choiceMeter == 5)
            {
                cout << objMeter.getValue() << " meter : " << objMeter.toMeters() << " feets " << endl;
            }   
    
            else if(choiceMeter == 6)
            {
                cout << "Bye !!";
                break;
            }
        }        
    }
}