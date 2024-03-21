#include <iostream>

using namespace std;

typedef struct node {
    int data;
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

    void printSmallestBWLargest()
    {
        int smallestIndex = 0;
        int biggerIndex = 0;
        int count = 0;
        Node * curr = head;
        int smallVarriable = curr -> next -> data;
        int bigVariable = curr -> next -> data;

        while(curr -> next != NULL)
        {
            if(smallVarriable > curr -> next -> data)
            {
                smallestIndex = count;
                smallVarriable = curr -> next -> data;
            }

            if(bigVariable < curr -> next -> data)
            {
                biggerIndex = count;
                bigVariable = curr -> next -> data;               
            }

            count++;
            curr = curr -> next;
        }

        curr = head;

        if(smallestIndex < biggerIndex)
        {
            for(int i = 0; i < smallestIndex; i++)
                curr = curr -> next;

            for(int i = smallestIndex - 1; i < biggerIndex; i++)
            {
                cout << curr -> next -> data << " -> ";
                curr = curr -> next;
            }
        }

        else if(biggerIndex < smallestIndex)
        {
            for(int i = 0; i < biggerIndex; i++)
                curr = curr -> next;  

            for(int i = biggerIndex - 1; i < smallestIndex; i++)
            {
                cout << curr -> next -> data << " -> ";
                curr = curr -> next;
            }         
        }

        else
            cout << curr -> data;
    }
};

int main()
{
    LinkedList list;
    int count = 0;

    cout << "Enter Your List:  ";
    int element;
    cin >> element;

    if(element == -1)
    {
        cout << "Your list is empty";
        return 0;
    }

    while(element != -1)
    {   
        list.insertToEnd(element);
        cin >> element;
    }
    list.printSmallestBWLargest();
    //list.print();
    return 0;
}
