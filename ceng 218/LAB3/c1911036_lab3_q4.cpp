#include <iostream>
#include <fstream>

using namespace std;

typedef struct node {
    string data;
    struct node *next;
}Node;

class LinkedList {
private:
    Node *head;

    Node* createNode(string data) {
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

    void insertToFront(string data) {
        Node *newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    void insertToEnd(string data) {
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

    int getSize() {
        int count = 0;
        Node *curr = head;
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }
        return count;
    }
};

int main()
{
    LinkedList A;
    LinkedList B;
    LinkedList C;
    LinkedList D;
    LinkedList E;
    LinkedList F;
    LinkedList G;
    //LinkedList Ğ;
    LinkedList H;
    LinkedList I;
    //LinkedList İ;
    LinkedList J;
    LinkedList K;
    LinkedList L;
    LinkedList M;
    LinkedList N;
    LinkedList O;
    //LinkedList Ö;
    LinkedList P;
    LinkedList R;
    LinkedList S;
    //LinkedList Ş;
    LinkedList T;
    LinkedList U;
    //LinkedList Ü;
    LinkedList V;
    LinkedList Y;
    LinkedList Z;

    ifstream file;

    file.open("provinces.txt");

    string namePorvince;
    int populationProvince;

    while(!file.eof())
    {
        file >> namePorvince;
        file >> populationProvince;
        
        if(namePorvince[0] == 'A' || namePorvince[0] == 'a')
            A.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'B' || namePorvince[0] == 'b')
            B.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'C' || namePorvince[0] == 'c')
            C.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'D' || namePorvince[0] ==  'd')
            D.insertToEnd(namePorvince);      

        else if(namePorvince[0] == 'E' || namePorvince[0] == 'e')
            E.insertToEnd(namePorvince);     

        else if(namePorvince[0] == 'F' || namePorvince[0] == 'f')
            F.insertToEnd(namePorvince);      
    
        else if(namePorvince[0] == 'G' || namePorvince[0] == 'g')
            G.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'H' || namePorvince[0] == 'h')
            H.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'I' || namePorvince[0] == 'i')
            I.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'j' || namePorvince[0] == 'J')
            J.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'k' || namePorvince[0] == 'K')
            K.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'L' || namePorvince[0] == 'l')
            L.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'M' || namePorvince[0] == 'm')
            M.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'N' || namePorvince[0] == 'n')
            N.insertToEnd(namePorvince); 

        else if(namePorvince[0] == 'O' || namePorvince[0] == 'o')
            O.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'P' || namePorvince[0] == 'p')
            P.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'R' || namePorvince[0] == 'r')
            R.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'S' || namePorvince[0] == 's')
            S.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'T' || namePorvince[0] == 't')
            T.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'U' || namePorvince[0] == 'u')
            U.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'V' || namePorvince[0] == 'v')
            V.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'Y' || namePorvince[0] == 'y')
            Y.insertToEnd(namePorvince);

        else if(namePorvince[0] == 'Z' || namePorvince[0] == 'z')
            Z.insertToEnd(namePorvince);
    }

    int size = A.getSize();
    cout << "Provinces started with A: " << size << endl;
    A.print();
    cout << endl;

    size = B.getSize();
    cout << "Provinces started with B: " << size << endl;
    B.print();
    cout << endl;

    size = C.getSize();
    cout << "Provinces started with C: " << size << endl;
    C.print();
    cout << endl;

    size = D.getSize();
    cout << "Provinces started with D: " << size << endl;
    D.print();
    cout << endl;

    size = E.getSize();
    cout << "Provinces started with E: " << size << endl;
    E.print();
    cout << endl;

    size = F.getSize();
    cout << "Provinces started with F: " << size << endl;
    F.print();
    cout << endl;

    size = G.getSize();
    cout << "Provinces started with G: " << size << endl;
    G.print();
    cout << endl;
    
    size = H.getSize();
    cout << "Provinces started with H: " << size << endl;
    H.print();
    cout << endl;

    size = I.getSize();
    cout << "Provinces started with I: " << size << endl;
    I.print();
    cout << endl;

    size = J.getSize();
    cout << "Provinces started with J: " << size << endl;
    J.print();
    cout << endl;

    size = K.getSize();
    cout << "Provinces started with K: " << size << endl;
    K.print();
    cout << endl;

    size = L.getSize();
    cout << "Provinces started with L: " << size << endl;
    L.print();
    cout << endl;

    size = M.getSize();
    cout << "Provinces started with M: " << size << endl;
    M.print();
    cout << endl;

    size = N.getSize();
    cout << "Provinces started with N: " << size << endl;
    N.print();
    cout << endl;

    size = O.getSize();
    cout << "Provinces started with O: " << size << endl;
    O.print();
    cout << endl;

    size = P.getSize();
    cout << "Provinces started with P: " << size << endl;
    P.print();
    cout << endl;
    

    size = R.getSize();
    cout << "Provinces started with R: " << size << endl;
    R.print();
    cout << endl;

    size = S.getSize();
    cout << "Provinces started with S: " << size << endl;
    S.print();
    cout << endl;    

    size = T.getSize();
    cout << "Provinces started with T: " << size << endl;
    T.print();
    cout << endl;

    size = U.getSize();
    cout << "Provinces started with U: " << size << endl;
    U.print();
    cout << endl;

    size = V.getSize();
    cout << "Provinces started with V: " << size << endl;
    V.print();
    cout << endl;

    size = Y.getSize();
    cout << "Provinces started with Y: " << size << endl;
    Y.print();
    cout << endl;

    size = Z.getSize();
    cout << "Provinces started with Z: " << size << endl;
    Z.print();
    cout << endl;
}