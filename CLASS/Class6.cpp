////运算符重载
//operator  不能重载的运算符：.     .*    ::     sizeof      ?: 

#include <iostream>
using namespace std;
//1.用类成员函数写
//complex complex::operator+(complex &c1);
//2.用友元函数写
//friend complex operator+(complex &c1,complex &c2);
//类成员
class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h,int m=0);

        Time operator+(const Time &t) const;
        Time operator-(const Time &t) const;
        Time operator*(double mult) const
        {
            Time result;
            long totalminuts=hours*mult*60+minutes*mult;
            result.hours=totalminuts/60;
            result.minutes=totalminuts%60;
            return result;        
        }
};
//友元函数
class Time1
{
    friend Time1 operator+(const Time1 & ti,const Time1 &t2);
    friend Time1 operator-(const Time1 & ti,const Time1 &t2);
    friend Time1 operator*(double mult,const Time1 &t2)
    {
        Time1 result;
        long totalminutes=t2.hours*60+t2.minutes*mult;
        result.hours=totalminutes/60;
        result.minutes=totalminutes%60;
        return result;
    }
    private:
        int hours;
        int minutes;
    public:
        Time1();
        Time1(int h,int m=0);
};
/* 
   运算符重载函数作为成员函数,必须要求运算表达式第一个参数(即
运算符左侧的操作数)是一个类对象，而且与运算符函数的类型相同。
   如果左操作数必须是一个不同类的对象或者是一个基本类型对象，那么
该运算符必须作为全局函数来实现。
*/

////重载流插入运算符和流提取运算符
/*
cin：istream类的对象
cout：ostream类的对象
*/
class Complex
{
    public:
        friend ostream& operator << (ostream&,Complex&);
        friend istream& operator >> (istream&,Complex&);
    private:
        double real,imag;
};
ostream& operator << (ostream& output,Complex& c)
{
    output<<"{"<<c.real<<"+"<<c.imag<<"i)";
    return output;
}
istream& operator >> (istream& input,Complex& c)
{
    input>>c.real>>c.imag;
    return input;
}
int main()
{
    Complex c1,c2;
    cin>>c1>>c2;
    cout<<"c1="<<c1<<endl;
    cout<<"c2="<<c2<<endl;
    return 0;
}





