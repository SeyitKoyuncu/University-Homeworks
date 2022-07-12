#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#define MAX 10

class stack
{
    private:
        string items[MAX];
        int decimalItems[MAX];
        int top;

    public:
    stack() : top(-1) {}

    bool IsEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    bool push(string data)
    {
        if(isFull())
            return false;

        items[top+1] = data;
        top++;
        return true;
    }

    bool pop(string &data)
    {
        if(IsEmpty())
            return false;

        data = items[top];
        top--;
        return true;    
    }

    bool peek(string & data)
    {
        if(IsEmpty())
            return false;

        data = items[top];
        return true;
    }

    void print()
    {
        if(IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        for(int i = 0; i <=top ; i++)
        {
            cout << i+1 << "- " << items[i] << " ";
        }
        cout << endl;
    }

    void convertToDecimal(int position)
    {
        if(IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        
        string data = items[position];

        int size = items[position].size();
        int decimal = 0;
        for(int i = 0; i < size; i++)
        {
            if(items[position][size - i - 1] == '1')
            {
                cout << "girdi"<< endl;
                decimal = decimal + pow(2,i);
            }
        }

        decimalItems[position] = decimal;

        cout << items[position] << "'s decimal = " << decimalItems[position] << endl;
    }
};


int main()
{
    cout << "Pls enter 5 binary number for add to the stack: " << endl;
    string number;
    stack Stack;

    for(int i = 0; i < 5; i++)
    {
        cin >> number;
        bool addCheck = Stack.push(number);
    }

    Stack.print();
    cout << "Exit for enter -1" << endl;
    cout << "Whic number you want to convert decimal (pls write to position)" << endl;
    int position = 0;

    while(true)
    {
        int position = 0;
        cin >> position;
        if(position == -1)
            return 0;
        Stack.convertToDecimal(position - 1);
    }

    return 0;
}
