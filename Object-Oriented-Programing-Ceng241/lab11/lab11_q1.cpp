#include <iostream>

using namespace std;


class Shape
{
	public:
        virtual void printArea() = 0;
        virtual void printCircumference() = 0;
};

class Triangele : public Shape
{
    private:
        int height;
        int base;
        int hypo;

    public:
        virtual void printArea();
        virtual void printCircumference();

};

class Circle: public Shape
{
    private:
        int radius;

    public:
        virtual void printArea();
        virtual void printCircumference();
};

class Rectangle: public Shape
{
    public:
        int breadth;
        int lenght;

    public:
        Rectangle(int b, int l)
        {
            breadth = b;
            lenght = l;
        }

        virtual void printArea();
        virtual void printCircumference();       
};


int CalculateTotalArea (Shape **shapes)
{
    int total = breadth + shapes.lenght;
    return total;
}

int main()
{ 

    cout << "Enter how many rectangles you want to create: " ;
    int rectengle;
    cin >> rectengle;
    cout <<endl;

    for(int i = 0; i < rectengle; i++)
    {
        cout << "Enter breadth and length respectively: ";
        int breadth;
        int length;
        Rectangle rectObj(breadth,length);
        Shape * tempShape = &rectObj;
        int total = CalculateTotalArea(&tempShape);
        cout << total;
    }

    cout << "Enter how many triangle you want to create: " ;
    int triangle;
    cin >> triangle;
    cout <<endl;

    cout << "Enter how many circle you want to create: " ;
    int circle;
    cin >> circle;
    cout <<endl;

    int total = circle + rectengle + triangle;


}