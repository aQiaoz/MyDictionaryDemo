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
    
    public:
        Date()
        {}
        bool operator >(const Date &t) const
        {
            if(year>t.year)
            {
                return true;
            }
            if(year<t.year)
            {
                return false;
            }
            if(year==t.year)
            {
                if(month>t.month)
                {
                    return true;
                }
                if(month<t.month)
                {
                    return false;
                }
                if(month==t.month)
                {
                    if(day>t.day)
                    {
                        return true;
                    }
                    if(day<t.day)
                    {
                        return false;
                    }
                }
            }
        }
        bool operator >=(const Date &t) const
        {
            if(year>t.year)
            {
                return true;
            }
            if(year<t.year)
            {
                return false;
            }
            if(year==t.year)
            {
                if(month>t.month)
                {
                    return true;
                }
                if(month<t.month)
                {
                    return false;
                }
                if(month==t.month)
                {
                    if(day>t.day)
                    {
                        return true;
                    }
                    if(day<t.day)
                    {
                        return false;
                    }
                    if(day==t.day)
                    {
                        return true;
                    }
                }
            }
        }
        bool operator <(const Date &t) const
        {
            if(year<t.year)
            {
                return true;
            }
            if(year>t.year)
            {
                return false;
            }
            if(year==t.year)
            {
                if(month<t.month)
                {
                    return true;
                }
                if(month>t.month)
                {
                    return false;
                }
                if(month==t.month)
                {
                    if(day<t.day)
                    {
                        return true;
                    }
                    if(day>t.day)
                    {
                        return false;
                    }
                    if(day==t.day)
                    {
                        return true;
                    }
                }
            }
        }
        bool operator <=(const Date &t) const
        {
            if(year<t.year)
            {
                return true;
            }
            if(year>t.year)
            {
                return false;
            }
            if(year==t.year)
            {
                if(month<t.month)
                {
                    return true;
                }
                if(month>t.month)
                {
                    return false;
                }
                if(month==t.month)
                {
                    if(day<t.day)
                    {
                        return true;
                    }
                    if(day>t.day)
                    {
                        return false;
                    }
                }
            }
        }
        bool operator ==(const Date &t)
        {
            if(day==t.day && month==t.month &&year==t.year)
            {
                return true;
            }
            return false;
        }
        bool operator !=(const Date &t) const
        {
             if(day==t.day && month==t.month &&year==t.year)
            {
                return false;
            }
            return true;
        }
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
    //cout << "请输入比较对象的日期day2:";
    Date day2;    // 比较对象的日期
    cin >> day2;

    cout << boolalpha;
    cout << "day  = " << day  ;
    cout << "day2 = " << day2 ;
    cout << "day  == day2  = " << (day  == day2) << '\n';
    cout << "day  != day2  = " << (day  != day2) << '\n';
    cout << "day  >  day2  = " << (day  >  day2) << '\n';
    cout << "day  >= day2  = " << (day  >= day2) << '\n';
    cout << "day  <  day2  = " << (day  <  day2) << '\n';
    cout << "day  <= day2  = " << (day  <= day2) << '\n';

}
//StudybarCommentEnd