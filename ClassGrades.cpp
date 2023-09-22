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
	string grade;

public:
	Student(string fName, string lName, string grade)
	{
		this->fName = fName;
		this->lName = lName;
		this->grade = grade;
	}

	void SortByGrade()
	{
		vector<string> students;
		vector<string> grades;

		int i, j, smallestIndex;
		string temp;
		string temp_student;

		students.push_back(fName + " " + lName);
		grades.push_back(grade);

		for (int i = 0; i < students.size(); i++)
		{			
			smallestIndex = i;
			for (j = i + 1; j < students.size() - 1; ++j)
			{
				if (grades.at(j) < grades.at(smallestIndex))
				{
					smallestIndex = j;
				}
			}

			temp = grades.at(i);
			grades.at(i) = grades.at(smallestIndex);
			grades.at(smallestIndex) = temp;

			temp_student = students.at(i);
			students.at(i) = students.at(smallestIndex);
			students.at(smallestIndex) = temp_student;

			cout << students.at(i) << " " << grades.at(i) << endl;
		}

		/*for (int i = 0; i < students.size(); i++)
		{

		}*/
	}

};

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

	while (!myfile.eof())
	{
		while (getline(myfile, currentLine))
		{
			stringstream ss(currentLine);
			getline(ss, fName, ' ');
			getline(ss, lName, ' ');
			getline(ss, grade, ' ');

			Student Student(fName, lName, grade);

			Student.SortByGrade();
		}

	}



	return(0);
}