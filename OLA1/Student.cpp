#include "Student.h"
#include <string>


Student::Student(void)
{
}

std::string Student::getID(void) const
{
	return m_id;
}

void Student::setID(std::string ID)
{
	m_id = ID;
}


void Student::changeScore(const ScoreType asignment, const int score)
{
	m_score[asignment] = score;
}

int  Student::getScore(const ScoreType assignment) const
{
	return m_score[assignment];
}