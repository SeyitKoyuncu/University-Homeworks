#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class List {
private:

protected:
	string * items;
	int size;

public:
	List()
    {
		size = 0;
        items = new string[size];
	}

    List(int size)
    {
        items = new string[size];
    }

	void print() {
		for (int i = 0; i < size; i++) {
			cout << items[i] << " " << endl;
		}
	}

    List & operator +=(const vector<string> &rhs)
    {
        delete [] items;
        size = rhs.size();
        items = new string[size];

        for(int i = 0; i < size; i++)
        {
            items[i] = rhs[i];
        }

        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(items[j] < items[i])
                {   
                    string temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
                }
            }
        }
        return * this;
    }

    void setItems(string arr[], int size) 
    {
        delete [] items;
        items = new string [size];

        for(int i = 0; i < size; i++)
        {
            items[i] = arr[i];
        }
    }

    string * getItems() { return items; }

    ~List()
    {
        delete [] items;
    }
};


int main()
{
    cout << "pls enter names: " << endl;
    vector <string> name;
    string tempName;

    cin >> tempName;
    while(tempName != "END")
    {    
        name.push_back(tempName);
        cin >> tempName;
    }

    int size = name.size();

    List list;
    list += name;
    list.print();
}