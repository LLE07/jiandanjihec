#pragma once
class TriangleItem
{
public:
    TriangleItem();
    TriangleItem(int a, int b, int c);
    void setTriangle(int a, int b, int c);
    void printTriangle();
    bool isTriangle();
    int calPerimeter();
    double calArea();
    bool isRightTriangle();
    void flow();
    inline double getArea() { return m_area; }
    inline double getUArea() { return m_uarea; }
    inline double getPerimeter() { return m_perimeter; }
    inline double getUPerimeter() { return m_uperimeter; }
    inline int getScore() { return m_score; }
    inline int getA() { return m_a; }
    inline int getB() { return m_b; }
    inline int getC() { return m_c; }
    inline void setUserAns(int ans) { m_userAns = ans; }
    inline int getUserAns() const { return m_userAns; }
    inline void setId(int id) { m_id = id; }
    inline int getId() const { return m_id; }
    inline void setCorrectAns(int ans) { m_correctAns = ans; }
    inline int getCorrectAns() const { return m_correctAns; }
private :
    double m_area;
    double m_uarea;
    int  m_a;
    int  m_b;
    int  m_c;
    int  m_perimeter;
    int  m_uperimeter;
    int  m_score;
    int m_userAns;
    int m_id;
    int m_correctAns;
};

