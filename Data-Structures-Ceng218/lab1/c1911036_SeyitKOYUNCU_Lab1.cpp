#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


class Student
{
    protected:
        int id;
        string name;

    public:
        Student()
        {
            id = 0;
            name = "";
        }

        Student(int id, string name)
        {
            this -> id = id;
            this -> name = name;
        }

        int getId(){ return id; }
        string getName() { return name; }

        void setId(int id) { this -> id = id; }
        void setName(string name) { this -> name = name; }
};

class GradStudent : public Student
{
    private:
        bool thesis;

    public:
        GradStudent(int id, string name, bool thesis)
        {
            this-> id = id;
            this-> name = name;  
            this-> thesis = thesis;         
        }

        bool getThesis() { return thesis; }

        void setThesis(bool thesis) { this -> thesis = thesis; }
};

class Course
{
    protected:
        string code;

    public:

        Course()
        {
            code = "";
        }

        Course(string code)
        {
            this -> code = code;
        }

        string getCode() { return code; }
        void setCode(string code) { this -> code = code; }
};

class GradCourse : public Course
{
    private:
        vector <GradStudent> students;

    public:
        GradCourse()
        {
            code = "";
        }

        GradCourse(string code)
        {
            this -> code = code;
        }

        void enroll(GradStudent student)
        {
            students.push_back(student);
        }

        void listStudents()
        {
            int size = students.size();
            
            for(int i = 0; i < size; i++)
            {   
                if(students[i].getThesis() == true)
                    cout << i+1 << " " << students[i].getId() << " - " << students[i].getName() << " (with thesis)" << endl; 

                else
                    cout << i+1 << " " << students[i].getId() << " - " << students[i].getName()  << endl; 
            }
        }
};

class UndergradCourse : public Course
{
    private:
        vector <Student> students;

    public:

        UndergradCourse()
        {
            code = "";
        }

        UndergradCourse(string code)
        {
            this -> code = code;
        }

        void enroll(Student student)
        {
            students.push_back(student);
        }

        void listStudents()
        {
            int size = students.size();

            for(int i = 0; i < size; i++)
            {
                cout << i+1 << " " << students[i].getId() << " - " << students[i].getName() << endl;                     
            }
        }
};

void Menu()
{
    cout << "Welcome to registration system !" << endl;
    cout << "1. Register new undergraduate student" << endl;
    cout << "2. Register new graduate student"<< endl;
    cout << "3. Display student lists" << endl;
    cout << "4. Exit" << endl;
    cout << "Your choice: " << endl;
}


int main()
{
    Menu();
    int choice;
    cin >> choice;

    vector <Student> students;
    vector <GradStudent> GradStudents;
    UndergradCourse underGradCourse;
    GradCourse gradCourse;
    
    
    int underCount = 0;

    while(choice != 4)
    {
        if(choice == 1)
        {   
            int ID;
            string name;

            cout << "Enter student ID and name: " ;
            cin >> ID >> name;

            Student tempStudent(ID,name);
            underGradCourse.enroll(tempStudent);
        }

        if (choice == 2)
        {
            int ID;
            string name;
            bool thesis;

            cout << "Enter student ID and name: " ;
            cin >> ID >> name;          
            cout << endl;

            cout << "Enroll " << name << " to thesis ? ";
            string thesisChoice;
            cin >> thesisChoice;
            //sadece kucuk harflerle girilecegini kabul ettim
            if(thesisChoice == "no")
                thesis = false;
            else
                thesis = true;

            GradStudent tempGradStudent(ID, name, thesis);    
            gradCourse.enroll(tempGradStudent);          

        }

        else if(choice == 3)
        {
            underGradCourse.setCode("CENG 105");

            cout << underGradCourse.getCode() << endl;
            underGradCourse.listStudents();

            underGradCourse.setCode("CENG 111");
            cout << underGradCourse.getCode() << endl;
            underGradCourse.listStudents();


            gradCourse.setCode("CENG 501");

            cout << gradCourse.getCode() << endl;
            gradCourse.listStudents();

            gradCourse.setCode("CENG 502");
            cout << gradCourse.getCode() << endl;
            gradCourse.listStudents();

        }

        else if(choice == 4)
        {
            cout << "Bye !";
            return 0;
        }

        else
        {
            cout << "Your choice is wronng pls try again..." << endl;
        }

        Menu();
        cin >> choice;
    }
}