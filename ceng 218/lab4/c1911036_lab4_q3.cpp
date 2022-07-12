#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 50


class stack
{
    private:
        char items[MAX];
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

    bool push(char data)
    {
        if(isFull())
            return false;

        items[top+1] = data;
        top++;
        return true;
    }

    bool pop(char &data)
    {
        if(IsEmpty())
            return false;

        data = items[top];
        top--;
        return true;    
    }

    bool peek(char & data)
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
            cout << items[i] << " ";
        }
        cout << endl;
    }

    bool balanced()
    {
        if(IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return false;
        }
        
        int countIn = 0;
        int countOut = 0;

        for(int i = 0;  i <= top; i++)
        {
            if(items[i] == '(')
                countIn++;

            else if(items[i] == ')')
                countOut++;
        }

        if(countIn == countOut)
            return true;

        else
            return false;
    }
};



int main()
{
    cout << "Enter your string: " << endl;
    string data;
    cin >> data;

    int size = data.size();
    
    stack Stack;

    for(int i = 0; i < size; i++)
    {
        Stack.push(data[i]);
    }   

    if(Stack.balanced())
        cout << "The string is balanced." << endl;

    else
        cout << "The string is not balanced." << endl;

    return 0;
    
}