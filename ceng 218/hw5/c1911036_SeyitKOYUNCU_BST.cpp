#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct TNode {
    string data;
    int count;
    string fileNumber;
    struct TNode *left;
    struct TNode *right;
}TNODE;

string maxRepeated;
int maxCount;

class BST {
private:
    TNODE *root;
    TNODE * createNode(string word, string file){
        TNODE *newNode = new TNODE;
        newNode->data = word;
        newNode -> fileNumber = file;
        newNode -> count = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    TNODE* insert(TNODE *root, string word, string file){
        if(root == NULL) {
            return createNode(word,file);
        }

        else if(root->data > word){
            root->left = insert(root->left, word,file);
        }
        else{
            root->right = insert(root->right, word, file);
        }
        return root;
    }
    
    TNODE* search(TNODE *root, string data, string repeated) {
        if(root == NULL)
            return NULL;
        
        if(root -> data == data)
        {   
            if(repeated != root -> fileNumber)
            {
                cout << root -> fileNumber << " ";
                repeated = root -> fileNumber;
            }
            return search(root -> right, data,repeated);
        }

        else if(root->data > data)
            return search(root->left, data,repeated);
        
        else
            return search(root->right, data,repeated);
    }

    void inorder(TNODE *root) {
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout<<root->count<<" ";
        inorder(root->right);
    }
    
public:
    BST() {
        root = NULL;
    }

    void insert(string word, string file) {
        root = insert(root,word, file);
    }

    bool search(string data){
        return (search(root, data,"repeatData") == NULL ? false: true);
    }

    void inorder(){
        inorder(root);
        cout << endl;
    }

};

// taken from "https://www.techiedelight.com/check-if-a-string-contains-only-letters-in-cpp/"
bool containsOnlyLetters(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
        std::string::npos;
}

BST CreateBST()
{
    ifstream file;
    int FileNumber = 1;
    string StringFileNumber = "";
    string StringFileName = "";

    string data;
    BST tree;

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
                tree.insert(data,StringFileNumber);
            }
        }
        file.close();
        FileNumber++;
    }

    return tree;
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
    BST tree;
    tree = CreateBST();

    while(choice != 4)
    {
        menu();
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            cout << word << ": ";
            tree.search(word);
            cout << endl;
        }

        else if(choice == 2)
        {
            //tree.CalculateCount();
            cout << "Yapamadım" << endl;
        }

        else if(choice == 3)
        {
            tree.inorder();
        }

        else if(choice == 4)
            return 0;
    }

    return 0;
}