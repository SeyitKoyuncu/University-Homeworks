#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class StudentNode
{
    private:
        int id; //string de olabilir
        string name;
        StudentNode * next;
        StudentNode * head;
        int size;

    public:

        StudentNode()
        {
            head = NULL;
        }

        StudentNode * createStudentNode(string data, int studentID)
        {
            StudentNode * newNode = new StudentNode;
            newNode -> name = data;
            newNode -> id = studentID;
            newNode -> next = NULL;
            return newNode;
        }

        void insertToEnd(string data, int studentId)
        {
            StudentNode * newNode = createStudentNode(data, studentId);
            
            if(head == NULL)
            {
                head = newNode;
                size++;       
                return;       
            }
            StudentNode * curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr -> next = newNode;
            size++;
            
        }

        void printStudent()
        {
            StudentNode * curr = head;
            int i = 1;
            while(curr != NULL)
            {
                cout << i << "- " << curr -> name << curr -> id << endl;
                curr = curr -> next;
                i++;
            }
            cout << endl;
        }
        
        void DeleteAllStudents()
        {
            StudentNode * curr = head;

            while(curr != NULL)
            {
                StudentNode * temp = curr;
                curr = curr -> next;
                delete temp;
            }
        }

        void DeleteStudent(int index)
        {
            if(head == NULL)
            {
                cout << "You dont have any student" << endl;
                return;
            }

            if(index == 1)
            {
                StudentNode * temp = head;
                head = head -> next;
                delete temp;
                return;
            }

            StudentNode * curr = head;
            StudentNode * prev;
            int i = 1;
            while(curr != NULL && i != index)
            {
                prev = curr;
                curr = curr -> next;
                i++;
            }

            if(curr != NULL)
            {
                prev -> next = curr -> next;
                delete curr;
                return;
            }

            cout << "we cant find this student" << endl;

        }

        bool FindStudent(string SearchName)
        {
            if(head == NULL)
            {
                cout << "you dont have any student, pls add student...";
                cout << endl;
                return 0;
            }

            StudentNode * curr = head;

            while(curr != NULL)
            {
                if(curr -> name == SearchName)
                    return 1;

                curr = curr -> next;
            }

            return 0;
        }

        bool SaveToStudents(ofstream & fileWrite)
        {
            if(head == NULL)
            {
                cout << "You dont have any student..." << endl;
                return false;
            }

            StudentNode * curr = head;

            while(curr != NULL)
            {

                fileWrite << curr -> name << " ";
                fileWrite << curr -> id << endl;
                curr = curr -> next;
            }
            fileWrite << "END" << endl;
        }

        string getName() {return name; }
};


class CourseNode
{
    private:
        CourseNode * next;
        StudentNode stHead;
        CourseNode * head;
        int size;

        CourseNode * createCourseNode(string data)
        {
            CourseNode * newNode = new CourseNode;
            newNode -> code = data;
            newNode -> next = NULL;
            return newNode;
        }

    public:
        string code;

        CourseNode(){size = 0; head = NULL;}

        void insertToEnd(string data)
        {
            CourseNode * newNode = createCourseNode(data);
            if(head == NULL)
            {
                head = newNode;
                size++;
                return;                
            }
            CourseNode * curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr -> next = newNode;
            size++;
        }

        void print()
        {
            CourseNode * curr = head;

            int i = 1;
            while(curr != NULL)
            {
                cout << i <<"- " << curr -> code << endl;
                curr = curr -> next;
                i++;
            }
            cout << endl;
        }

        void addStudent(string course, string data, int studentId)
        {  
            CourseNode * curr = head;
            int happ = 0;
            while(curr != NULL)
            {
                if(curr -> code == course)
                {
                    happ = 1;
                    break;
                }
                curr = curr -> next;
            }

            if(happ == 1)
            {  
                curr -> stHead.insertToEnd(data,studentId);
            }

            else 
            {
                cout << "Cant find this course" << endl;
                return;
            }
        }

        void PrintStudents(string course)
        {
            CourseNode * curr = head;
            int happ = 0;
            while(curr != NULL)
            {
                if(curr -> code == course)
                {
                    happ = 1;
                    break;
                }
                curr = curr -> next;
            }

            if(happ == 1)
            {   
                cout << curr -> code << endl;
                curr ->stHead.printStudent();
            }

            else  
                return;
        }

        void DeleteCourse(string course)
        {
            if(head == NULL)
                return;
            
            
            if(head -> code == course)
            {
                CourseNode * temp = head;
                head = head -> next;
                delete temp;
                return;
            }

            CourseNode * curr = head;
            CourseNode * prev;

            while(curr -> code != course && curr != NULL)
            {
                stHead.DeleteAllStudents();
                prev = curr;
                curr = curr -> next;
            }

            if(curr != NULL)
            {
                prev -> next = curr -> next;
                delete curr;
            }

        }

        void UnerrollStudent(string course, int index)
        {
            CourseNode * curr = head;
            int happ = 0;
            while(curr != NULL)
            {
                if(curr -> code == course)
                {
                    happ = 1;
                    break;
                }
                curr = curr -> next;
            }

            if(happ == 1)
            {  
                curr -> stHead.DeleteStudent(index);
            }

            else 
            {
                cout << "Cant find this course" << endl;
                return;
            }
        }

        void SearchStudent(string name)
        {
            if(head == NULL)
            {
                cout << "You dont have any course, pls add course...";
                return;
            }

            CourseNode * curr = head;
            bool cond;

            while(curr != NULL)
            {
                cond = curr -> stHead.FindStudent(name);
                if(cond == 1)
                {
                    cout << name << " is enrolled to " << curr -> code << endl;
                    return;
                }
                curr = curr -> next;
            }
            cout << "We can not find his/her in any course" << endl;
            return;
        }

        bool SaveToCourses()
        {
            if(head == NULL)
            {
                cout << "You dont have any course..." << endl;
                return false;
            }

            CourseNode * curr = head;

            ofstream fileWrite;
            fileWrite.open("hw3text.txt");

            while(curr != NULL)
            {
                fileWrite << curr -> code << endl;
                curr -> stHead.SaveToStudents(fileWrite);
                curr = curr -> next;
            }

            fileWrite.close();
        }
};

void menu()
{
    cout << "1. Display student lists for all courses " << endl;
    cout << "2. Add new course " << endl;
    cout << "3. Delete existing course (along with all students enrolled to it)" << endl;
    cout << "4. Enroll a new student to a course " << endl;
    cout << "5. Unenroll student from a course" << endl;
    cout << "6. Search for a student " << endl;
    cout << "7. Save and exit " << endl;
}


int main()
{
    CourseNode Courses;
    ifstream file;

    file.open("hw3text.txt");
    string code;
    string name;
    int number;
    string endString;

    vector <string> codeVec;
    vector <string> nameVec;
    vector <int> numberVec; 

    vector <string> tempCodeVec;

    while(!file.eof())
    {
        file >> code;
        if(code.find("CENG") != string::npos)
        {
            file >> name;
            file >> number;

            codeVec.push_back(code);
            nameVec.push_back(name);
            numberVec.push_back(number);

            tempCodeVec.push_back(code);
        }

        else
        {
            if(code == "END")
            {
                endString == code;   
                code = " ";   

                Courses.insertToEnd(codeVec[0]);

                int size = nameVec.size();
                for(int i = 0; i < size; i++)
                {
                    Courses.addStudent(codeVec[0], nameVec[i], numberVec[i]);
                }       

                nameVec.clear();
                numberVec.clear(); 
                codeVec.clear();
            } 

            else
            {
                name = code;
                file >> number;

                nameVec.push_back(name);
                numberVec.push_back(number);
            }
        }
    }
    file.close();
    menu();
    int choice = 0;

    while(choice != 7)
    {
        cout << "Your Choice: ";
        cin >> choice;
        cout << endl;   


        if(choice == 1)
        {
            for(int i = 0; i < tempCodeVec.size(); i++)
            {
                Courses.PrintStudents(tempCodeVec[i]);
            }
        }   

        else if(choice == 2)
        {
            cout << "Enter course name: ";
            string newCourse;
            cin >> newCourse;
            cout << endl;

            tempCodeVec.push_back(newCourse);
            Courses.insertToEnd(newCourse);
        }  

        else if(choice == 3)
        {
            if(tempCodeVec.size() <= 0)
            {
                cout << "You dont have any course for deleting, plss add course..." << endl;
            } 

            else
            {
                cout << "Available courses: " << endl;
                Courses.print(); 

                cout << "Which course you want to delete : ";
                int index;
                cin >> index;
                Courses.DeleteCourse(tempCodeVec[index - 1]);
                tempCodeVec.erase(tempCodeVec.begin() + index - 1);
            }
        } 

        else if(choice == 4)
        {
            cout << "Enter course code, student id and name: ";
            cin >> code;
            cin >> number;
            cin >> name;
            cout << endl;

            Courses.addStudent(code, name, number);
        } 

        else if(choice == 5)
        {
            if(tempCodeVec.size() <= 0)
            {
                cout << "You dont have any course for deleting, plss add course..." << endl;
            } 

            else
            {
                cout << "Available courses: " << endl;
                Courses.print(); 

                cout << "Which course you want to unerroll student : ";
                int index;
                cin >> index;

                Courses.PrintStudents(tempCodeVec[index - 1]);

                cout << "Whic student you want to unerroll: ";
                int studentIndex;
                cin >> studentIndex;

                Courses.UnerrollStudent(tempCodeVec[index - 1], studentIndex);

            }            
        } 

        else if(choice == 6)
        {
            cout << "Enter student name: ";
            cin >> name;
            cout << endl;

            Courses.SearchStudent(name);
        } 

        else if(choice == 7)
        {
            Courses.SaveToCourses();
            cout << "Saved. Bye!";
            return 0;
        } 

        else 
            cout << "You write wrong number... Pls write again" << endl;
    }

    return 0;
}