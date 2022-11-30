#include <iostream>
#include <iomanip>
using namespace std;
#include "Cylinder.h"
#define Pi 3.1415926

Cylinder::Cylinder(double radius=1,double height=1)
{
    setheight(height);
    setradius(radius);
}
void Cylinder::setheight(double height)
{
    cheight=height;
}
void Cylinder::setradius(double radius)
{
    cradius=radius;
}
double Cylinder::getheight()
{
    return cheight;
}
double Cylinder::getradius()
{
    return cradius;
}
void Cylinder::volume()
{
    cvolume=getradius()*getradius()*Pi*getheight();
    cout<<setprecision(3)<<cvolume<<endl;
}
int main()
{
    double radius,height;    //    cout<<"Please input the radius of cylinder:";
    cin>>radius;    //    cout<<"Please input the height of cylinder:";    
    cin>>height;
    Cylinder first(radius,height);    
    first.volume ();    
    cout<<"The volume of Cylinder with default data:"<<endl;    
    Cylinder second;    
    second.volume ();    
    return 0;
}