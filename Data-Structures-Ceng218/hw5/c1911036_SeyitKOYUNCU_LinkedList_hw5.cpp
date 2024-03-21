#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node {
    string data;
    int count;
    string fileNumber;
    struct node *next;
}Node;

class LinkedList {
private:
    Node *head;

    Node* createNode (string file, string word) {
        Node *newNode = new Node;
        newNode->data = word;
        newNode -> fileNumber = file;
        newNode ->next = NULL;
        return newNode;
    }
public:
    LinkedList():head(NULL) {}

    void print(string word) {
        Node *curr = head;
        cout << word << ": ";
        string repeated = "a";

        while(curr != NULL) {
            if(word == curr -> data && repeated != curr -> fileNumber)
            {   
                repeated = curr -> fileNumber;
                cout << curr -> fileNumber << ", "; 
            }
            curr = curr->next; 
        }
        cout<<"NULL"<<endl;
    }


void MaxRepeated()
{
    Node * curr = head;
    Node * search = head;
    int count = 0;
    
    while(curr != NULL)
    {
        while(search != NULL)
        {
            if(curr -> data == search -> data)
                count++;

            search = search -> next;        
        }
        curr -> count = count;
        curr = curr -> next;
        search = head;
        count = 0;
    }

    vector <string> datas;
    vector <int> counts;

    for(int i = 0; i < 10; i++)
    {
        curr = head;
        int max = curr -> count;
        string mostRepeated = curr -> data;
        while(curr != NULL)
        {
            for(int j = 0; j < datas.size();j++)
            {
                if(datas[j] == curr -> data)
                {
                    curr = curr -> next;
                    j = 0;
                }
            }

            if(max <= curr -> count)
            {
                max = curr -> count;
                mostRepeated = curr -> data;
            }
            curr = curr -> next;
        }

        datas.push_back(mostRepeated);
        counts.push_back(max);
    }

    cout << endl;
    for(int i = 0; i < datas.size(); i++)
    {
        cout << i+1 << "- " << datas[i] << " " << counts[i] << endl;
    }
    cout << endl;
}

void MinRepeated()
{
    Node * curr = head;
    Node * search = head;
    int count = 0;
    
    while(curr != NULL)
    {
        while(search != NULL)
        {
            if(curr -> data == search -> data)
                count++;

            search = search -> next;        
        }
        curr -> count = count;
        curr = curr -> next;
        search = head;
        count = 0;
    }

    vector <string> datas;
    vector <int> counts;

    for(int i = 0; i < 10; i++)
    {
        curr = head;
        int min = curr -> count;
        string minRepeat = curr -> data;

        while(curr != NULL)
        {
            for(int j = 0; j < datas.size(); j++)
            {
                if(datas[j] == curr -> data)
                {
                    curr = curr -> next;
                    j = 0;
                }
            }
            
            if(min > curr -> count)
            {
                min = curr -> count;
                minRepeat = curr -> data;
            }
            curr = curr -> next;
        }
        
        datas.push_back(minRepeat);
        counts.push_back(min);
    }
    
    cout << endl;
    for(int i = 0; i < datas.size(); i++)
    {
        cout << i+1 << "- " << datas[i] << " " << counts[i] << endl;
    }
    cout << endl;
}

void insertToEnd(string word, string file) {
        Node *newNode = createNode(file,word);
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

};

// taken from "https://www.techiedelight.com/check-if-a-string-contains-only-letters-in-cpp/"
bool containsOnlyLetters(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
        std::string::npos;
}


LinkedList CreateLinkList()
{
    ifstream file;
    int FileNumber = 1;
    string StringFileNumber = "";
    string StringFileName = "";

    string data;
    LinkedList list;

    for(int i = 0; i < 9598; i++)
    {
        StringFileNumber = to_string(FileNumber);
        StringFileName = StringFileNumber + ".txt";
        file.open(StringFileName);
        
        while(!file.eof())
        {
            file >> data;
            transform(data.begin(), data.end(), data.begin(),[](unsigned char c){ return std::tolower(c); });
            if(containsOnlyLetters(data))
            {
                list.insertToEnd(data,StringFileNumber);
            }
        }
        file.close();
        FileNumber++;
    }

    return list;
}

void menu()
{
    cout << "1- Enter a single keyword to list the document(s)(file names)"  << endl;
    cout << "2- Print the top 10 words that appeared most frequently" << endl;
    cout << "3- Print the top 10 word that appeared least frequently" << endl;
    cout << "4- Exit" << endl;
    cout << "Choice: " << endl;
}

int main()
{

    int choice = -1;
    LinkedList list;
    list = CreateLinkList();

    while(choice != 4)
    {
        menu();
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            list.print(word);
        }

        else if(choice == 2)
        {
            list.MaxRepeated();
        }

        else if(choice == 3)
        {
            list.MinRepeated();
        }

        else if(choice == 4)
            return 0;
    }

    return 0;
}