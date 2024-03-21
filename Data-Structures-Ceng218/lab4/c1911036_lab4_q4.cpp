#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

#define MAX 50

class stack
{
    private:
        int items[MAX];
        int top;
        int maxStep;

    public:
    stack() 
    {
        top = -1;
        maxStep = 20 + (rand() % 50);
        //cout << maxStep;
    }

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

    bool pop()
    {
        if(IsEmpty())
            return false;
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
            cout << items[i] << " ";
        }
        cout << endl;
    }

    bool findSwitch()
    {
        if(isFull())
        {
            cout << "Stack is full..." << endl;
            return false;
        }

        if(items[top] == maxStep)
            return true;
        
        else if(items[top] < maxStep)
        {
            cout << "The voice tells the light switch is still ahead..." << endl;
            return false;
        }

        else
        {
            cout << "The voice tells you have missed the light switch and go backwards..." << endl;
            return false;
        }
    }

};


int main()
{
    srand((unsigned) time(0));
    stack Stack;

    cout << "You find yourself in a dark corridor. You can not see anything."
    "Suddenly you hear a voice telling you to move forwards and find"
    "a light switch in order to find the exit..." << endl;

    string direction;
    int stepCurr = 0;
    int stepOld = 0;
    do
    {
        cin >> direction;

        if(direction == "forwards")
        {   
            cin >> stepOld;
            stepCurr = stepCurr + stepOld;
            Stack.push(stepCurr);
        }

        else if(direction == "backwards")
        {
            Stack.pop();
            stepCurr = stepCurr - stepOld;
        }

        Stack.print();
    }while(!Stack.findSwitch());

    cout << "You found the light switch! Congratulations!"; 
    return 0;
}