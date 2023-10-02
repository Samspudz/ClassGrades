/*
* Adam Marshall
* GAME2303
* September 20, 2023
* Week 3 - Class Grades
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Student
{
private:
    string fName;
    string lName;
    int grade;

public:
    Student(string fName, string lName, int grade)
    {
        this->fName = fName;
        this->lName = lName;
        this->grade = grade;
    }

    string FName()
    {
        return fName;
    }

    string LName()
    {
        return lName;
    }

    int Grade()
    {
        return grade;
    }
};

void SortByGrade(vector<Student>& students)
{

    int i, j;

    for (int i = 0; i < students.size(); i++)
    {
        for (j = i + 1; j < students.size(); ++j)
        {
            if (students[i].Grade() < students[j].Grade())
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main()
{
    string fName;
    string lName;
    string grade;

    ifstream myfile;

    myfile.open("example.txt");

    if (myfile.fail())
    {
        cout << "File failed to open.";
        return 1;
    }

    string currentLine;

    vector<Student> students;

    while (!myfile.eof())
    {
        while (getline(myfile, currentLine))
        {
            stringstream ss(currentLine);
            getline(ss, fName, ' ');
            getline(ss, lName, ' ');
            getline(ss, grade, ' ');

            Student s = Student(fName, lName, stoi(grade)); // stoi converts from string to int

            students.push_back(s);
        }
    }

    SortByGrade(students);

    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].FName() << " " << students[i].LName() << " " << students[i].Grade() << endl;
    }

    return(0);
}

