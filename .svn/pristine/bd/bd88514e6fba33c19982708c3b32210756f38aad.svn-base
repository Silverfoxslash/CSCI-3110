#include "Roster.h"
#include <iostream>

using namespace std;

Roster::Roster(std::string className) : m_courseName(className), m_studentNum(0) {};

void Roster::readStudentRecord(std::string file)
{
	string data;
	int score;
	Student readStudent;
	ifstream studentFile;
	studentFile.open(file);
	if (studentFile.is_open())//assert file is open
	{
		getline(studentFile, data);//consumes whole line

		while (studentFile >> data)//should exact id and stop
		{
			readStudent.setID(data);
			studentFile >> score;
			readStudent.changeScore(Student::CLA, score);
			studentFile >> score;
			readStudent.changeScore(Student::OLA, score);
			studentFile >> score;
			readStudent.changeScore(Student::QUIZ, score);
			studentFile >> score;
			readStudent.changeScore(Student::HOMEWORK, score);
			studentFile >> score;
			readStudent.changeScore(Student::EXAM, score);
			studentFile >> score;
			readStudent.changeScore(Student::BONUS, score);
			//reads scores into a student object then puts into next index of array        
			m_students[m_studentNum] = readStudent;
			m_studentNum++;
		}
		studentFile.close();
	}
	else cout << "File no found.\n";
};
void Roster::printClass()
{
	Student currStudent;
	cout << setw(10) << "ID" << setw(4) << "CLA" << setw(6) << "OLA" << setw(6) << "Quiz" << setw(10) << "Homework" << setw(7) << "EXAM" << setw(7) << "BONUS\n\n";
	for(int x=0; x<m_studentNum;x++)
	{
		currStudent = m_students[x];
		cout <<setw(10)<< currStudent.getID();
		cout << setw(4) << currStudent.getScore(currStudent.CLA) << setw(6) << currStudent.getScore(currStudent.OLA) << setw(6) << currStudent.getScore(currStudent.QUIZ) << setw(10) << currStudent.getScore(currStudent.HOMEWORK);
		cout << setw(7) << currStudent.getScore(currStudent.EXAM) << setw(7) << currStudent.getScore(currStudent.BONUS) << endl;
	}
	cout << endl;
}
//Print the record of one student matching the user input
void Roster::searchStudent(std::string input)
{
	Student currStudent;
	int x = NULL;
	for( x=0; x<m_studentNum;x++)
	{
		currStudent = m_students[x];
		if(input== currStudent.getID())
		{
			cout << setw(10) << "ID" << setw(4) << "CLA" << setw(6) << "OLA" << setw(6) << "Quiz" << setw(10) << "Homework" << setw(7) << "EXAM" << setw(7) << "BONUS\n\n";
			cout << setw(10) << currStudent.getID();
			cout << setw(4) << currStudent.getScore(currStudent.CLA) << setw(6) << currStudent.getScore(currStudent.OLA) << setw(6) << currStudent.getScore(currStudent.QUIZ) << setw(10) << currStudent.getScore(currStudent.HOMEWORK);
			cout << setw(7) << currStudent.getScore(currStudent.EXAM) << setw(7) << currStudent.getScore(currStudent.BONUS) << endl<<endl;
			return;
		}


	}


}