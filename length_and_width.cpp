#include <iostream>
#include <iomanip>
using namespace std;


class Rectangle
{
    public:
        Rectangle(){};
        void setLength( double l);
        void setWidth( double w);
        double perimeter();
        double area();

    private:
        double length;
        double width;

};

void Rectangle::setLength(double l)
{
    if(l<=0.0 || l>=20.0)
    {
        length = 1;
    }
    else
    {
        length = l;
    }
}

void Rectangle::setWidth(double w)
{
    if(w<=0.0 || w>=20.0)
    {
        width = 1;
    }
    else
    {
        width = w;
    }
}

double Rectangle::perimeter()
{
    return 2*(length+width);
}
double Rectangle::area()
{
    return length*width;
}
//StudybarCommentBegin
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
    cout<<"the perimeter is:"<<setprecision(2)<<fixed<<r.perimeter()<<endl;
    cout<<"the area is:"<<setprecision(2)<<fixed<<r.area()<<endl;
    return 0;
    
}
//StudybarCommentEnd