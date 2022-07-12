// Overloading operators as member methods
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    Mystring s1{"s1"}; 
    Mystring s2{"s2"};
    
    Mystring s3 = s1;
    s1.display();                                                                      // s1
    s2.display();                                                                      // s2
    
    cout << (s1 == s2) << endl;                                         // false
    cout << (s1 == s3) << endl;                                      // true

    s1.display();                                                                    // s1
    Mystring s12 = -s1;
    s12.display();                                                                    // s1
     
    Mystring s3s = s1 + "s2";                                     // ok with member function
    //Mystring s3s = "s1" + s2;                                 // Compiler error
    
    Mystring two_s3s = s2 + " " + "s1";
    two_s3s.display();      
                                                   // s2 s1
    Mystring three_s3s = s2 + " " + s1 + " " +  " Deneme";
    three_s3s.display();                                                        //  s2 s1 Deneme
    
    return 0;
}

