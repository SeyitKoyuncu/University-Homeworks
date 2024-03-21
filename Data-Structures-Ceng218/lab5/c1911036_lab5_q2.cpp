#include <iostream>    
#include <stdlib.h>     
#include <time.h> 
#include <cstdlib>

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
typedef struct node {
    int data;
    struct node *next;
}Node;


int main()
{
    srand (time(NULL));

    Queue que;
    Queue tempQue;
    int randomNumber = 20 + rand() % 50 + 1;

    cout << "I’ve randomly picked a number between 20 and 70." << endl;
    cout << randomNumber;
    int userNumber;
    int data;
    int lives = 5;
    int difference = 0;
    int best = 0;
    int temp = 50;
    
    while(1)
    {
        cout << "Enter your guess: " << endl;
        cin >> userNumber;  

        que.enqueue(userNumber);
        tempQue.enqueue(userNumber);
        tempQue.dequeue(data);

        if(data == randomNumber)
        {
            cout << "You guessed correctly ! " << endl;
            cout << "Your guesses were : ";
            
            while(!que.isEmpty())
            {
                que.dequeue(data);
                cout << data <<  " ";
            }

            cout << endl;
            cout << "Your best guess was: " << userNumber << endl;
            break;
        }     

        else if(data < randomNumber)
        {
            cout << "You guessed lower! Lives left: " << lives << endl;
            difference = randomNumber - data;
            if(difference < temp)
            {
                temp = difference;
                best = data;
            }
        }

        else
        {
            cout << "You guessed higher! Lives left: " << lives << endl;
            difference = data - randomNumber;
            if(difference < temp)
            {
                temp = difference;
                best = data;
            }
        }

        if(lives == 0)
        {
            
            cout << "You have no lives remaining! Game over! The number was " << randomNumber << endl;
            cout << "Your guesses were: ";

            while(!que.isEmpty())
            {
                int temp;
                que.peek(data);
                que.dequeue(temp);
                cout << data <<  " ";
            }

            cout << endl;
            cout << "Your best guess was: " << best << endl;

            break;
        }

        lives--;
    }

    return 0;
}