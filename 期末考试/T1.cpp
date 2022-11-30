#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int n[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool run(int a)
{
    if(a%100==0)
    {
        if(a%400==0)
        {
            return true;
        }
    }
    else
    {
        if(a%4==0)
        {
            return true;
        }
    }
    return false;
}
class Date
{
    friend Date operator++ (Date& t1)
    {
        Date s;
        int x;
        if(run(t1.year))
        {
            if(t1.day==n[t1.month] && t1.month==12)
            {
                x=t1.year;
                s.year=x++;
                s.month=1;
                s.day=1;
                return s;
            }
            if(t1.day<n[t1.month])
            {
                x=t1.day;
                s.year=t1.year;
                s.month=t1.month;
                s.day=x++;
                return s;
            }
            if(t1.day==n[t1.month] && t1.month!=12)
            {
                x=t1.month;
                s.year=t1.year;
                s.month=x++;
                s.day=1;
                return s;
            }
        }
        else
        {
            if(t1.day==m[t1.month] && t1.month==12)
            {
                x=t1.year;
                s.year=x++;
                s.month=1;
                s.day=1;
                return s;
            }
            if(t1.day<m[t1.month])
            {
                x=t1.day;
                s.year=t1.year;
                s.month=t1.month;
                s.day=x++;
                return s;
            }
            if(t1.day==m[t1.month] && t1.month!=12)
            {
                x=t1.month;
                s.year=t1.year;
                s.month=x++;
                s.day=1;
                return s;
            }
        }
        
    }
    
    friend Date operator-- (Date& t1)
    {
        Date s;
        int x;
        if(t1.month==1 && t1.day==1)
        {
            x=t1.year;
            s.year=x--;
            s.month=1;
            s.day=1;
            return s;
        }
        if(run(t1.year))
        {
            if(t1.day==1)
            {
                x=t1.month;
                s.year=t1.year;
                s.month=x--;
                s.day=n[x--];
            }
        }
        else
        {
            if(t1.day==1)
            {
                x=t1.month;
                s.year=t1.year;
                s.month=x--;
                s.day=m[x--];
            }
        }
    }
    public:
        Date()
        {}
        friend ostream& operator << (ostream& output,Date &d)
        {
            output<<d.year<<"年"<<d.month<<"月"<<d.day<<"日"<<endl;
            return output;
        }
        friend istream& operator >> (istream& input,Date &d)
        {
            int a,b,c;
            input>>a>>b>>c;
            if(b<1)
            {
                b=1;
            }
            if(b>12)
            {
                b=12;
            }
            if(c<1)
            {
                c=1;
            }
            if ( run(a) && c>n[b] )
            {
                c=n[b];
            }
            if(!run(a) && c>m[b])
            {
                c=m[b];
            }
            d.year=a;
            d.month=b;
            d.day=c;
            return input;
        }

    private:
        int year;
        int month;
        int day;

};
//StudybarCommentBegin
int main()
{
    Date day;
    cin >> day;
    
    cout << "当前日期为：" << day;
    cout << "后一天 = " << ++day ;     // 前置递增
    cout << "当前日期为：" << day;
    cout << "前一天 = " << --day ;    // 前置递减

}
//StudybarCommentEnd