#include <iostream>
#include <string>

using namespace std;

#define MAX 50
class Stack {
private:
	int items[MAX];
	int top;
public:
	Stack() :
			top(-1) {
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == (MAX-1);
	}

	bool push(int item) {
		if (isFull())
			return false;
        top++;
		items[top] = item;
		return true;
	}

	bool pop(int &item) {
		if (isEmpty())
			return false;
		item = items[top];
        top--;
		return true;
	}

	bool peek(int &item) {
		if (isEmpty())
			return false;
		item = items[top];
		return true;
	}

    void print()
    {
        for(int i = 0; i <= top; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    bool filterOut(string type)
    {
        if(isEmpty())
            return false;

        int number;
        
        if(type == "even")
        {
            pop(number);
            if(number % 2 == 1)
            {
                filterOut(type);
                push(number);
                return true;
            }
            filterOut(type);
            return true;
        }

        else if(type == "odd")
        {
            pop(number);
            if(number % 2 == 0)
            {
                filterOut(type);
                push(number);
                return true;
            }
            filterOut(type);
            return true;
        }

        else
        {
            cout << "Pls write even or odd.." << endl;
            return false;
        }
    }
};

void addItemsToStack(Stack & stk)
{   
    cout << "Fill your stack: ";
    int number;
    cin >> number;

    while(number != -1)
    {
        stk.push(number);
        cin >> number;
    }

    cout << endl;
}

Stack reverseStack(Stack & stk)
{   
    int number;
    Stack temp;
    if(!stk.isEmpty())
    {
        while(!stk.isEmpty())
        {
            stk.pop(number);
            temp.push(number);
        }
    }
    return temp;
}

int main()
{
    Stack stk;
    addItemsToStack(stk);

    cout << "Select 'even' or 'odd' to filter: ";
    string type;
    cin >> type;
    cout << endl;


    if(stk.filterOut(type))
    {
        cout << type << " elements have been removed from stack, the remaining elements are: ";
        stk = reverseStack(stk);
        stk.print();
    }

    else
    {
        cout << "Error detected !!";
    }

    return 0;
    


}