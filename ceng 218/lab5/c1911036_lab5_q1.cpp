#include <iostream>


using namespace std;

#define MAX 50
class Queue {
private:
    char items[MAX];
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

    bool enqueue(char data) {
        if(isFull())
            return false;

        rear++;
        items[rear] = data;
        return true;
    }

    bool dequeue(char &data) {
        if(isEmpty())
            return false;

        data = items[front];
        front++;
        return true;
    }

    bool peek(char &data) {
        if(isEmpty())
            return false;
        data = items[front];
        return true;
    }

    bool drop()
    {   
        char data = ' ';
        char dataTemp = ' ';

        Queue TempQue;
        Queue FinalQue;

        cout << "Dropped chars: ";

        for(int i = 0; i <= rear ; i++)
        {
            TempQue.dequeue(dataTemp);
            dequeue(data);

            if(dataTemp != data)
            {
                FinalQue.enqueue(data);
                TempQue.enqueue(data);
            }

            else
            {
                cout << data << " ";
            }
        }
        cout << endl;

        int size = FinalQue.size();

        cout << "Final size of queue: " << size << endl;

        cout << "Final Queue: ";

        for(int i = 0; i < size; i++)
        {
            FinalQue.dequeue(data);
            enqueue(data);
            cout << data << " ";
        }
    }
    
    int size(){ return rear+1; }
    
};
typedef struct node {
    int data;
    struct node *next;
}Node;


int main()
{
    cout << "Enter: ";
    
    char letter = ' ';
    Queue que;

    while(1)
    {
        cin >> letter;
        if(letter == '.')
            break;
        
        que.enqueue(letter);
    }

    cout << "Initial size of queue: " << que.size() << endl;
    que.drop();

    return 0;
}