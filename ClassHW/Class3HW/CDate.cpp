#include<iostream>
#include<string>
using namespace std;
#include "CDate.h"

CDate::CDate(int d=1,int m=1,int y=2000)
{
    setdate(d,m,y);
    cout<<"welcome the Date:"<<"\""<<
      year<<"/"<<month<<"/"<<day<<"\""<<endl;
}
void CDate::setdate(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
    while(month>12||month<1)
	{ 
		cout<<"month is an invalid data ,it has been reset to 1";
		month=1;
	}
    while(day>31||day<1)
	{ 
		cout<<"day is an invalid data ,it has been reset to 1";
		day=1;
	}
}
void CDate::display()
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}
void CDate::addDay()
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(day == 31)
            {
                month += 1;
                day = 1;
            }
            else
            {
                day += 1;
            }
            break;
        case 12:
            if(day == 31)
            {
                year += 1;
                month = 1;
                day = 1;
            }
            else
            {
                day += 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day == 30)
            {
                year += 1;
                day = 1;
            }
            else
            {
                day += 1;
            }
            break;
        case 2:          
            if((year % 4== 0 &&year %100 != 0)||(year % 400 == 0))//闰年
            {
                if(day == 29)
                {
                    month += 1;
                    day = 1;
                }
                else
                {
                    day += 1;
                }
            }
            else
            {

                if(day == 28)
                {
                    month += 1;
                    day = 1;
                }
                else
                {
                    day += 1;
                }
            }
            break;
    }
}
CDate::~CDate()
{
    cout<<"you have destructed the date of"<<"\""<<
      year<<"/"<<month<<"/"<<day<<"\""<<endl;
    day=0;
    month=0;
    year=0;
    
}

int main()
{
    int year,month,day;
    
//    cout<<"Please input the year:";
    cin>>year;
//    cout<<"Please input the month:";
    cin>>month;
//    cout<<"Please input the day:";
    cin>>day;
    
    CDate currentDay(day,month,year);
    
    cout<<"Current date:";
    currentDay.display();
    
    currentDay.addDay();
    
    cout<<"Add 1 to current date:";
    currentDay.display();
    
    return 0;
}
