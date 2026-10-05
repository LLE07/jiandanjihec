#include "QuestionBank.h"
#include <iostream>
#include <cstring>
using namespace std;
QuestionBank::QuestionBank()
{
	strcpy(m_bankName, "Default Bank");
	m_averageScore = 0.0;
	m_questionCount = 0;
	m_correctCount = 0;
	m_incorrectCount = 0;
	m_totalScore = 0;
	for (int i = 0; i < 100; ++i)
	{
		m_questionNumbers[i] = 0;
		m_questionScores[i] = 0;
	}
}
void QuestionBank::setBankName(const char* name)
{
	strcpy(m_bankName, name);
}
const char* QuestionBank::getBankName() const
{
	return m_bankName;
}
void QuestionBank::setAverageScore(double score)
{
	m_averageScore = score;
}
double QuestionBank::getAverageScore() const
{
	return m_averageScore;
}
void QuestionBank::setQuestionCount(int count)
{
	m_questionCount = count;
}
int QuestionBank::getQuestionCount() const
{
	return m_questionCount;
}
void QuestionBank::setCorrectCount(int count)
{
	m_correctCount = count;
}
int QuestionBank::getCorrectCount() const
{
	return m_correctCount;
}
void QuestionBank::setIncorrectCount(int count)
{
	m_incorrectCount = count;
}
int QuestionBank::getIncorrectCount() const
{
	return m_incorrectCount;
}
void QuestionBank::setQuestionNumber(int index, int number)
{
	if (index >= 0 && index < 100)
		m_questionNumbers[index] = number;
}
int QuestionBank::getQuestionNumber(int index) const
{
	if (index >= 0 && index < 100)
		return m_questionNumbers[index];
	return -1;
}
void QuestionBank::setQuestionScore(int index, int score)
{
	if (index >= 0 && index < 100)
		m_questionScores[index] = score;
}
int QuestionBank::getQuestionScore(int index) const
{
	if (index >= 0 && index < 100)
		return m_questionScores[index];
	return -1;
}
void QuestionBank::setTotalScore(int score)
{
	m_totalScore = score;
}
int QuestionBank::getTotalScore() const
{
	return m_totalScore;
}
bool QuestionBank::addQuestion(int id, int a, int b, int c)
{
	if (m_questionCount >= 100)
		return false;
	m_triangleItems[m_questionCount].setTriangle(a, b, c);
	m_triangleItems[m_questionCount].setId(id);
	m_questionNumbers[m_questionCount] = id;
	m_questionScores[m_questionCount] = 10;
	++m_questionCount;
	calculateAverageScore();
	calculateTotalScore();
	return true;
}
bool QuestionBank::deleteQuestion(int id)
{
	for (int i = 0; i < m_questionCount; ++i)
	{
		if (m_triangleItems[i].getId() == id)
		{
			for (int j = i; j < m_questionCount - 1; ++j)
			{
				m_triangleItems[j] = m_triangleItems[j + 1];
				m_questionNumbers[j] = m_questionNumbers[j + 1];
				m_questionScores[j] = m_questionScores[j + 1];
			}
			--m_questionCount;
			calculateAverageScore();
			calculateTotalScore();
			return true;
		}
	}
	return false;
}
void QuestionBank::queryQuestion(int id) const
{
	for (int i = 0; i < m_questionCount; ++i)
	{
		if (m_triangleItems[i].getId() == id)
		{
			cout << "题目编号 " << id << " 的详细信息如下：" << endl;
			m_triangleItems[i].printTriangle();
			return;
		}
	}
	cout << "题目编号 " << id << " 不存在。" << endl;
}
void QuestionBank::showAllQuestions() const
{
	cout << "题库名称: " << m_bankName << endl;
	cout << "题目总数: " << m_questionCount << endl;
	cout << "平均得分: " << m_averageScore << endl;
	cout << "总得分: " << m_totalScore << endl;
	for (int i = 0; i < m_questionCount; ++i)
	{
		cout << "题目编号: " << m_triangleItems[i].getId() << endl;
		m_triangleItems[i].printTriangle();
	}
}
void QuestionBank::answerQuestion(int id, int userAns)
{
	for (int i = 0; i < m_questionCount; ++i)
	{
		if (m_triangleItems[i].getId() == id)
		{
			m_triangleItems[i].setUserAns(userAns);
			if (userAns == m_triangleItems[i].getCorrectAns())
			{
				++m_correctCount;
				cout << "题目编号 " << id << " 回答正确，得分为 " << m_questionScores[i] << " 分。" << endl;
			}
			else
			{
				++m_incorrectCount;
				cout << "题目编号 " << id << " 回答错误，正确答案为 " << m_triangleItems[i].getCorrectAns() << "，得分为 0 分。" << endl;
			}
			calculateAverageScore();
			calculateTotalScore();
			return;
		}
	}
	cout << "题目编号 " << id << " 不存在。" << endl;
}
void QuestionBank::calculateAverageScore()
{
	if (m_questionCount == 0)
	{
		m_averageScore = 0.0;
		return;
	}
	int totalScore = 0;
	for (int i = 0; i < m_questionCount; ++i)
	{
		totalScore += m_triangleItems[i].getScore();
	}
	m_averageScore = static_cast<double>(totalScore) / m_questionCount;
}
void QuestionBank::calculateTotalScore()
{
	int totalScore = 0;
	for (int i = 0; i < m_questionCount; ++i)
	{
		totalScore += m_triangleItems[i].getScore();
	}
	m_totalScore = totalScore;
}	