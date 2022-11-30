#include<iostream>
#include<string>
using namespace std;

class CDate
{
private:
    int day;
    int month;
    int year;
public:
    CDate(int,int,int);
    ~CDate();
    void setdate(int d,int m,int y);
    void addDay();
    void display();
};

