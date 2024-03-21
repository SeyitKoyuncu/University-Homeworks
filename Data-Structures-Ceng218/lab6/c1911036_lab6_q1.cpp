#include <iostream>

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

void invert(Queue Original, Queue & newQue)
{
    int number;
    Original.dequeue(number);
    if(Original.isEmpty())
    {
        newQue.enqueue(number);
        return;
    }
    invert(Original,newQue);
    newQue.enqueue(number);
}

void printQue(Queue que)
{   
    int number;
    while(!que.isEmpty())
    {
        que.dequeue(number);
        cout << number << " "; 
    }
    cout << endl;
}

int main()
{
    int number = 0;

    cout << " Fill your queue: ";
    cin >> number;

    Queue OriginalQue;

    while(number != -1)
    {
        OriginalQue.enqueue(number);
        cin >> number;
    }

    Queue InvertedQue;

    invert(OriginalQue, InvertedQue);

    cout << "Original Queue: ";
    printQue(OriginalQue);
    
    cout << "Inverted Queue: ";
    printQue(InvertedQue);

    return 0;
}