#include <iostream>
#include "QuestionBank.h"
using namespace std;
int main()
{
	QuestionBank bank;
	bank.setBankName("三角形几何练习题库");
	cout << "题库名称: " << bank.getBankName() << endl << endl;
	bank.addQuestion(1, 3, 4, 5);
	bank.addQuestion(2, 5, 12, 13);
	bank.addQuestion(3, 8, 15, 17);
	cout << "========题库初始状态========" << endl;
	cout << "题目总数: " << bank.getQuestionCount() << endl;
	bank.showAllQuestions();
	cout << endl;
	bank.answerQuestion(1, 6); 
	bank.answerQuestion(2, 30); 
	bank.answerQuestion(3, 60);
	cout << endl;
	cout << "========题库答题后状态========" << endl;
	cout << "题库满分为: " << bank.getTotalScore() << endl;
	cout << "用户实际得分为: " << bank.getCorrectCount() * 10 << endl;
	cout << "正确率为: " << (double)bank.getCorrectCount() / bank.getQuestionCount() * 100 << "%" << endl;
	cout << endl;
	cout << "========重置答题记录========" << endl;
	bank.setCorrectCount(0);
	cout << "重置后用户得分为: " << bank.getCorrectCount() * 10 << endl;
	cout << "重置后答对题数为: " << bank.getCorrectCount() << endl;
	return 0;
}