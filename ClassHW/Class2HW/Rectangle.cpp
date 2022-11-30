#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#include "Rectangle.h"

void Rectangle::setLength(double length)
{
    rlength=length;
}
double Rectangle::getLength()
{
    return rlength;
}
void Rectangle::setWidth(double width)
{
    rwidth=width;
}
double Rectangle::getWidth()
{
    return rwidth;
}
double Rectangle::perimeter()
{
    if(rlength<=0)
    {
        rlength=1;
    }
    if(rwidth<=0)
    {
        rwidth=1;
    }
    return rlength+rwidth;
}
double Rectangle::area()
{
    if(rlength<=0)
    {
        rlength=1;
    }
    if(rwidth<=0)
    {
        rwidth=1;
    }
    return rlength*rwidth;
}

int main()
{    
    Rectangle r;    
    double length,width;
//    cout<<"please input the length of Rectangle:";    
    cin>>length;
//    cout<<"please input the width of Rectangle:";    
    cin>>width;    
    r.setLength(length);    
    r.setWidth(width);    
    cout<<"the perimeter is:"<<
 setprecision(2)<<fixed<<r.perimeter()<<endl;    
    cout<<"the area is:"<<setprecision(2)<<fixed<<r.area()<<endl;    
    return 0;
}