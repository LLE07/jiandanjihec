#pragma once
#include "TriangleItem.h"
class QuestionBank
{
private:
    char m_bankName[50];
    double m_averageScore;
    int m_questionCount;
    int m_correctCount;
    int m_incorrectCount;
    int m_questionNumbers[100];
    int m_questionScores[100];
    int m_totalScore;
    TriangleItem m_triangleItems[100];
public:
    QuestionBank();
    void setBankName(const char* name);
    const char* getBankName() const;
    void setAverageScore(double score);
    double getAverageScore() const;
    void setQuestionCount(int count);
    int getQuestionCount() const;
    void setCorrectCount(int count);
    int getCorrectCount() const;
    void setIncorrectCount(int count);
    int getIncorrectCount() const;
    void setQuestionNumber(int index, int number);
    int getQuestionNumber(int index) const;
    void setQuestionScore(int index, int score);
    int getQuestionScore(int index) const;
    void setTotalScore(int score);
    int getTotalScore() const;
    bool addQuestion(int id, int a, int b, int c);
    bool deleteQuestion(int id);
    void queryQuestion(int id)const;
    void showAllQuestions()const;
    void answerQuestion(int id, int userAns);
    void calculateAverageScore();
    void calculateTotalScore();
};