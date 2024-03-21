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

    void deleteItem(int data) {
        if(head == NULL)
            return;

        if(head->data == data){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        while(curr != NULL && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        if(curr != NULL) {
            prev->next = curr->next;
            delete curr;
        }
    }
    
    int getSize() {
        int count = 0;
        Node *curr = head;
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }
        return count;
    }

    bool insertItem(int data, int position) {
        Node *newNode = createNode(data);
        if(position == 0) {
            insertToFront(data);
            return true;
        }
        else if(position > getSize())
            return false;
        else if(position == getSize()){
            insertToEnd(data);
            return true;
        }
        Node *curr = head;
        
        for(int i=0; i<(position-1) ; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return true;
    }

    void CallIsMember(int searchTerm)
    {
        
        if(isMember(head, searchTerm))
        {
            cout << searchTerm << " is available in the linked list";
            return;
        }

        cout << searchTerm << " is not available in the linked list";
    }

    bool isMember(Node * head, int searchTerm)
    {
        if(head == NULL)
            return false;
        
        if(head -> data == searchTerm)
            return true;

        if(isMember(head -> next, searchTerm))
            return true;

        return false;

    }

};

void AddToList(LinkedList & list)
{
    int number;
    
    cout << "Fill your linked list: ",
    cin >> number;

    while(number != -1)
    {
        list.insertToFront(number);
        cin >> number;
    }   
    cout << endl;
}

int main()
{
    LinkedList list;
    AddToList(list);

    list.print();

    cout << "Enter search term: ";
    int search;
    cin >> search;

    list.CallIsMember(search);

    return 0;

}