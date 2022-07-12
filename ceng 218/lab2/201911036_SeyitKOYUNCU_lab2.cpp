#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MAX 81


class Province
{
    private:
        string name;
        int population;

    public:
        Province()
        { 
            name = "";
            population = 0;
        }

        Province(string name, int population)
        {
            this -> name = name;
            this -> population = population;
        }

        void setName(string name){ this -> name = name; }
        void setPopulation(int population) { this -> population = population; }

        string getName(){ return name; }
        int getPopulation(){ return population; }
};

class List {
private:

protected:
	Province items[MAX];
	int size;

public:
	List() {
		size = 0;
	}
	bool isFull() {
		return size == MAX;
	}
	bool isEmpty() {
		return size == 0;
	}

	virtual bool addItem(Province item) {
		if (isFull())
			return false;
        items[size++].setName(item.getName());
        items[size++].setPopulation(item.getPopulation());
		return true;
	}

	void print() {
        for(int i = 0; i < size; i++)
        {
            cout << items[i].getName() << " " << items[i].getPopulation() << endl;
        }
	}
};

class OrderedList: public List {

public:
	OrderedList() : List() {}

	bool addItem(Province item) {
		if (isFull())
			return false;
            
		int i;
		if (size == 0) {
			items[size].setName(item.getName());
            items[size].setPopulation(item.getPopulation());
            size++;
			return true;
		}

		for (i = 0; i < size; i++) {
			if (item.getPopulation() < items[i].getPopulation()) {
				for (int j = size - 1; j >= i; j--) {
					items[j + 1].setName(items[j].getName());
                    items[j + 1].setPopulation(items[j].getPopulation());
				}
				items[i].setName(item.getName());
                items[i].setPopulation(item.getPopulation());
				size++;
				return true;
			}
		}
        items[size].setName(item.getName());
        items[size].setPopulation(item.getPopulation());
        size++;
		return true;
	}
};


int main()
{
    vector <Province> provinces;
    ifstream file;

    file.open("provinces.txt");

    string namePorvince;
    int populationProvince;

    while(!file.eof())
    {
        file >> namePorvince;
        file >> populationProvince;
        
        Province tempProvince(namePorvince, populationProvince);
        provinces.push_back(tempProvince);
    }

    OrderedList ListProvinces;
    int size = provinces.size();
    for(int i = 0;  i < size; i++)
    {
        ListProvinces.addItem(provinces[i]);        
    }

    ListProvinces.print();
}