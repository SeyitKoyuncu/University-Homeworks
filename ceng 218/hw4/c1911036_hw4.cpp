#include <iostream>
#include <string>

using namespace std;


#define MAX 1000
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

        items[++rear] = data;
        return true;
    }

    bool dequeue(char &data) {
        if(isEmpty())
            return false;
        data = items[front++];
        return true;
    }

    bool peek(char &data) {
        if(isEmpty())
            return false;
        data = items[front];
        return true;
    }
};



int pow(int first, int exponent)
{
    for(int i = 0; i < exponent - 1; i++)
        first = first * 10;

    return first;
}



void menu()
{
    cout << "1. Encrypt Text" << endl;
    cout << "2. Decrypt Text" << endl;
    cout << "3. Exist" << endl;
    cout << "Your Choice: ";
}

int numberOfDigits(int num){
            int count=0;
            while(num != 0)
            {
                count++;
                num = num / 10;
            }
            return count;
}

Queue transferStringToQueue(string str){
    Queue NormalSentence;
    int size = str.size();

    for(int i = 0; i < size; i++)
    {
        NormalSentence.enqueue(str[i]);
    }

    return NormalSentence;
}

Queue intToQueue(int num) {
    Queue numQueue;

}

int main()
{
    int choice;
    string sentence;
    string shifting;
    char alph = ' ';
    int sizeOfShift;

    Queue NormalSentence;
    Queue ShiftedSentence;

    while(1)
    {   
        menu();
        cin >> choice;
        cout << endl;

        if(choice == 1)
        {
            cout << "Phrase: ";
            cin >> sentence;
            cout << endl;

            cout << "Key: ";
            cin >> shifting;
            cout << endl;

            NormalSentence = transferStringToQueue(sentence);

            char alph;
            int control = 0;

            while(!NormalSentence.isEmpty())
            {

                if(control == sizeOfShift)
                    control = 0;

                NormalSentence.dequeue(alph);
                sizeOfShift = shifting.size();
                
                int shiftAmounnt = shifting[control] - '0';
                alph = alph + shiftAmounnt;

                if(alph > 90)
                    alph = alph - 26;
                    
                ShiftedSentence.enqueue(alph);
                control++;            
            }

            while(!ShiftedSentence.isEmpty())
            {
                ShiftedSentence.dequeue(alph);
                cout << alph;
            }
        
            cout << endl;
        }

        else if(choice == 2)
        {
            cout << "Phrase: ";
            cin >> sentence;
            cout << endl;

            cout << "Key: ";
            cin >> shifting;
            cout << endl;

            NormalSentence = transferStringToQueue(sentence);

            char alph;
            int control = 0;
            sizeOfShift = shifting.size();
            while(!NormalSentence.isEmpty())
            {

                if(control == sizeOfShift)
                    control = 0;

                NormalSentence.dequeue(alph);
                
                int shiftAmounnt = shifting[control] - '0';
                alph = alph - shiftAmounnt;

                if(alph < 65)
                    alph = alph + 26;
                    
                ShiftedSentence.enqueue(alph);
                control++;            
            }

            while(!ShiftedSentence.isEmpty())
            {
                ShiftedSentence.dequeue(alph);
                cout << alph;
            }
        
            cout << endl;
        }

        else if(choice == 3)
        {
            cout << "Bye!!";
            return 0;
        }

    }

    return 0;
}