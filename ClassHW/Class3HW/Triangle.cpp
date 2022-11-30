#include <iostream>
using namespace std;
#include "Triangle.h"

Triangle::Triangle(int side1,int side2,int side3)
{
    setside1(side1);
    setside2(side2);
    setside3(side3);
}

void Triangle::setside1(int side1)
{
    if(side1<0)
    {
        side1=0;
    }
    first=side1;
}
void Triangle::setside2(int side2)
{
    if(side2<0)
    {
        side2=0;
    }
    second=side2;
}
void Triangle::setside3(int side3)
{
    if(side3<0)
    {
        side3=0;
    }
    third=side3;
}
int Triangle::getside1()
{
    return first;
}
int Triangle::getside2()
{
    return second;
}
int Triangle::getside3()
{
    return third;
}

bool Triangle::isRightTriangle()
{
    if(getside1()>getside2())
    {
        if(getside1()>getside3())
        {
            max=getside1();
            a=getside2();
            b=getside3();
        }
        else
        {
            max=getside3();
            a=getside1();
            b=getside2();
        }
    }
    else
    {
        if(getside2()>getside3())
        {
            max=getside2();
            a=getside1();
            b=getside3();
        }
        else
        {
            max=getside3();
            a=getside1();
            b=getside2();
        }
    }

    if((max*max)==(a*a)+(b*b))
        return true;
    else 
        return false;
}
bool Triangle::isEquilateral()
{
    if(getside1()==getside2() ||getside2()==getside3())
        return true;
    else
        return false;
}




int main()
{    
    double first,second,third;
    //    cout<<"Enter side one:";    
    cin>>first;
    //    cout<<"Enter side two:";    
    cin>>second;
    //    cout<<"Enter side three:";    
    cin>>third;    
    Triangle tri(first,second,third);    
    if(tri.isEquilateral())        
        cout<<"You created an equilateral triangle!"<<endl;    
    else if(tri.isRightTriangle())        
        cout<<"You created an right triangle!"<<endl;    
    else        
        cout<<"Neither an equilateral nor a right triangle!"<<endl;    
        return 0; 
        // indicates successful termination
}