#include <iostream>
#include <string>
using namespace std;

typedef struct node {
    string data;
    struct node *next;
}Node;

class LinkedList {
private:
    Node *head;

    Node* createNode(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode ->next = NULL;
        return newNode;
    }
public:
    LinkedList():head(NULL) {}

    void print() {
        Node *curr = head;
        while(curr != NULL) {
            cout<<curr->data<<"->";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }

    void insertToFront(int data) {
        Node *newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    void insertToEnd(int data) {
        Node *newNode = createNode(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    bool Search(int searchNumber)
    {
        Node * curr = head;
        int check = 0;
        int count = 0;
        while(curr != NULL)
        {
            if(curr -> data == searchNumber)
            {
                check = 1;
                break;
            }
            curr = curr -> next;
            count++;
        }

        curr = head;
        int i = 0;
        if(check == 1)
        {
            cout << searchNumber << " is found in node " << count + 1 << " Numbers leading to" << searchNumber<<" in the list are: "<< endl;
            while( i < count + 1)
            {
                cout << curr -> data << " -> ";
                curr = curr -> next;
                i++;
            }
            cout << endl;
            return true;
        }

        else
            return false;
    }
};

int main()
{
    cout << "Enter starting number: ";
    int number;
    cin >> number;

    LinkedList list;

    int count= 0;
    while(1)
    {
        list.insertToEnd(number);

        if(number % 2 == 0)
            number = number / 2;

        else
            number = number * 3 + 1;

        count++;

        if(number == 1)
        {
            list.insertToEnd(number);
            count++;
            break;
        }
    }
    cout << "List has been generated (" << count <<" integers )  " <<endl;
    list.print();

    cout << "Enter search term: ";
    int search;
    cin >> search;

    bool check;
    check = list.Search(search);

    if(check == true)
        cout << search << " is in the list" ;

    else
        cout << search << " is not in the list";

    return 0;
}