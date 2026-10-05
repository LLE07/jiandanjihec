#include "TriangleItem.h"
#include <cmath>
#include <iostream>
using namespace std;

TriangleItem::TriangleItem() 
{
	m_a = m_b = m_c = 0;
	m_area = m_uarea = 0.0;
	m_perimeter = m_uperimeter = 0;
	m_score = 0;
	m_userAns = 0;
	m_id = 0;
	m_correctAns = 0;
}
TriangleItem::TriangleItem(int a, int b, int c)
{
	m_a = a;
	m_b = b;
	m_c = c;
	calPerimeter();
	calArea();
	m_score = 0;
	m_userAns = 0;
	m_id = 0;
	m_correctAns = 0;
	m_uarea = 0.0;
	m_uperimeter = 0;
}
void TriangleItem::setTriangle(int a, int b, int c)
{
	m_a = a;
	m_b = b;
	m_c = c;
	calPerimeter();
	calArea();
}
void TriangleItem::printTriangle() const
{
	cout << "题目编号: " << m_id << endl;
	cout << "三角形的三边长为: " << m_a << ", " << m_b << ", " << m_c << endl;
	cout << "周长为: " << m_perimeter << endl;
	cout << "面积为: " << m_area << endl;
	cout << "用户答案为: " << m_userAns << endl;
	cout << "正确答案为: " << m_correctAns << endl;
	cout << "得分为: " << m_score << endl;
}
bool TriangleItem::isTriangle() const
{
	if (m_a <= 0 || m_b <= 0 || m_c <= 0)
		return false;
	return (m_a + m_b > m_c) && (m_a + m_c > m_b) && (m_b + m_c > m_a);
}
int TriangleItem::calPerimeter()const
{
	if (!isTriangle())
	{
		return 0;
	}
	return m_a + m_b + m_c;
}
double TriangleItem::calArea()const
{
	if (!isTriangle())
	{
		return 0.0;
	}
	double s = calPerimeter() / 2.0;
	return sqrt(s * (s - m_a) * (s - m_b) * (s - m_c));
}
bool TriangleItem::isRightTriangle() const
{
	if (!isTriangle())
		return false;
	int a2 = m_a * m_a;
	int b2 = m_b * m_b;
	int c2 = m_c * m_c;
	return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
}
void TriangleItem::flow()
{
	cout << "请输入三角形的三边长: ";
	cin >> m_a >> m_b >> m_c;
	calPerimeter();
	calArea();
	cout << "周长为: " << m_perimeter << endl;
	cout << "面积为: " << m_area << endl;
}