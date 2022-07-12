#include <iostream>

using namespace std;

class Calculator
{
    private:
        int length;
        float *numbers;
    public:
        Calculator()
        {
            length = 0; 
            //No args constructor called
        }

        Calculator(int a)
        {
            numbers = new float(a);         //dynamic 
            length = a;                     //Stores the size of array
            //Overload Constructor called
        }

        void get_numbers()
        {
            //Getting the numbers
            for (int i = 0; i <length; i++)
            {
                cin >> numbers[i] >> endl;
            }
        }

        ~Calculator()
        {
            delete[] numbers; //Destructor
        }

        Calculator operator + (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = numbers[i] + x.numbers[i];
            }

            return storage;
        }

        Calculator operator - (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = numbers[i] - x.numbers[i];
            }

            return storage;
        }

        Calculator operator * (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = number[i] * x.numbers[i];
            }

            return storage;
        }

        Calculator operator / (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = number[i] / x.numbers[i];
            }

            return storage;
        }

        friend ostream& operator << (ostream &os const Calculator &x)
        {
            for (int i = 0; i < x.length; i++)
            {
                cout << x.numbers[i] << " " ;
            }
        }
};

int main()
{
    int len1, len2;

    cout << ""


}