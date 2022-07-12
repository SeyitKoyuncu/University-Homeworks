#include <iostream>
#include <string>

using namespace std;

class CTO {
private:
   string name;
public:
    CTO() {
        cout << "CTO()" << endl;
    }
    void work() {
        cout << "CTO is working hard!" << endl;
    }
    void talk() {
        cout << "CTO is talking too much!" << endl;
    }
};

class CEO {
private:
    string name;
public:
    CEO() {
        cout << "CEO()" << endl;
    }
    void work() {
        cout << "CEO is working hard!" << endl;
    }
    void talk() {
        cout << "CEO is talking too much!" << endl;
    }
};

class Engineer: public CEO, public CTO {
private:
    string department;
public:
    Engineer() {
        cout << "Engineer()" << endl;
    }
    void work() {
        cout << "Engineer is working hard!" << endl;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Engineer e;
    e.work();
    //e.talk();
    return 0;
}
