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

    LinkedList mixLinkedList(LinkedList  rhs)
    {
        Node * currThis = this -> head;
        Node * newList = createNode((this -> retunHead()) -> data);
        LinkedList lastList;

        while(currThis != NULL)
        {   
            /*
            newList -> next = currThis -> next;
            newList = newList -> next;
            currThis = currThis -> next;
            */
           lastList.insertToEnd(currThis -> data);
           currThis = currThis -> next;
        }

        Node * currRhs = rhs.retunHead();
        while(currRhs != NULL)
        {   
            /*
            newList -> next = currRhs;
            newList = newList -> next;
            */
            lastList.insertToEnd(currRhs -> data);
            currRhs = currRhs -> next;
        }
    
        //newList -> next = NULL;

        /*
        Node * currNewList = lastList.retunHead();
        while(currNewList != NULL)
        {
            cout << currNewList -> data << " -> ";
            currNewList = currNewList -> next; 
        }
        cout << endl;
        */
        lastList.sort();
        return lastList;
    }

    void sort()
    {
        Node * curr  = head;
        int temp = 0;
        print();
        int count = 0;
        while(curr -> next != NULL)
        {
            curr = curr ->  next;
            count++;
        }

        curr = head;
        
        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < count; j++)
            {
                if(curr -> data > curr -> next -> data)
                {
                    temp = curr -> next -> data;
                    curr -> next -> data = curr -> data;
                    curr -> data = temp;
                }
                temp = 0;
                curr = curr -> next;                
            }
            curr = head;
        }
        cout << endl;

       print();
    }
    
    
    LinkedList mixAndShort(LinkedList & rhs)
    {
        LinkedList listNew;
        Node * curr = head;
        Node * curr2 = rhs.head;

        while(curr != NULL && curr2 != NULL)
        {
            if(curr -> data < curr2 -> data)
            {
                curr = curr -> next;
            }

            else if(curr -> data > curr2 -> data)
            {
                listNew.insertToEnd(curr -> data);
                curr = curr -> next;
                curr2 = curr -> next;
            }
        }
        listNew.print();
        return listNew;

    }
    

    Node * retunHead()
    {
        return head;
    }
};



int main()
{
    LinkedList list1;
    LinkedList list2;
    
    int count = 0;
    int count2 = 0;

    cout << "Enter Your first List:  ";
    int element;
    cin >> element;

    if(element == -1)
    {
        cout << "Your first  list is empty";
        return 0;
    }

    while(element != -1)
    {   
        list1.insertToEnd(element);
        cin >> element;
    }

    list1.print();

    cout << "Enter Your second List:  ";
    cin >> element;

    if(element == -1)
    {
        cout << "Your second list is empty";
        return 0;
    }

    while(element != -1)
    {   
        list2.insertToEnd(element);
        cin >> element;
    }

    list2.print();

    LinkedList result = list2.mixLinkedList(list1);
    //result.sort();
}