#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 10

class stack
{
    private:
        int items[MAX];
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

    bool push(int data)
    {
        if(isFull())
            return false;

        items[top+1] = data;
        top++;
        return true;
    }

    bool pop(int &data)
    {
        if(IsEmpty())
            return false;

        data = items[top];
        top--;
        return true;    
    }

    bool peek(int & data)
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

    void convertToBinary(int position)
    {
        if(IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        int data = items[position];
        vector <bool> binary;
        cout <<"binary of " << items[position] << " is = ";
        if(data == 0)
        {
            binary.push_back(0);           
        }

        while(1)
        {
            if(data % 2 == 1)
                binary.push_back(1);

            else   
                binary.push_back(0);

            data = data / 2;

            if(data == 1)
            {
                binary.push_back(1);
                break;
            }

            else if(data == 0)
            {
                binary.push_back(0);
                break;
            }
        }

        int size = binary.size();
        
        reverse(binary.begin(), binary.end());

        for(int i = 0; i < size; i ++)
            cout << binary[i];

        binary.clear();
        cout << endl;
    }

};

int main()
{
    cout << "Pls enter 5 number for add to the stack: " << endl;
    int number;
    stack Stack;

    for(int i = 0; i < 5; i++)
    {
        cin >> number;
        bool addCheck = Stack.push(number);
    }

    Stack.print();
    cout << "Exit for enter -1" << endl;
    cout << "Whic number you want to convert binary (pls write to position)" << endl;
    int position = 0;

    while(1)
    {
        int position = 0;
        cin >> position;
        if(position == -1)
            return 0;
        Stack.convertToBinary(position - 1);
    }

}