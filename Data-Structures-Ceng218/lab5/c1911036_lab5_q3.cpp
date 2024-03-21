#include <iostream>
#include <string>

using namespace std;

#define MAX 50
class Queue {
private:
    int items[MAX];
    int front;
    int rear;

public:
    Queue():front(0),rear(-1) {}

    bool isEmpty() {
        return front>rear;
    }

    bool isFull(){
        return rear == MAX-1;
    }

    bool enqueue(int data) {
        if(isFull())
            return false;

        items[++rear] = data;
        return true;
    }

    bool dequeue(int &data) {
        if(isEmpty())
            return false;
        data = items[front++];
        return true;
    }

    bool peek(int &data) {
        if(isEmpty())
            return false;
        data = items[front];
        return true;
    }
};

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
		items[++top] = item;
		return true;
	}

	bool pop(int &item) {
		if (isEmpty())
			return false;
		item = items[top--];
		return true;
	}

	bool peek(int &item) {
		if (isEmpty())
			return false;
		item = items[top];
		return true;
	}
};


int main() {
    // Write C++ code here
    cout << "Enter your string: ";
    string sentence;
    cin >> sentence;
    cout << endl;
    
    Queue que;
    Stack stk;
    
    int size = sentence.size();
    
    for(int i = 0; i < size; i++)
    {
        que.enqueue(sentence[i]);
        stk.push(sentence[i]);
    }
    
    int count = 0;
    bool palindrome = 0;
    int first;
    int last;
    
    for(int i = 0; i < size; i++)
    {
        que.dequeue(first);
        stk.pop(last);
        
        if(first == last)
            count++;
        
    }
    
    if(count == size)
        palindrome = 1;
    
    if(palindrome == 1)
        cout << sentence << " is palindrom." ;
    
    else
        cout << sentence << " is not palindrom";
    
    
    return 0;
}