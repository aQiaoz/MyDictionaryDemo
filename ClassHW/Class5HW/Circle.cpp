#include <iostream>
#include <iomanip>
using namespace std;
#define Pi 3.1415926
class Circle
{
private:
    float x;
    float y;
    float radius;
    static int countC;
public:
    Circle(float a=0,float b=0,float r=0);
    static void showCount();
    void display() const;
    float Square() const;
    ~Circle();
};

Circle::Circle(float a,float b,float r)
{
    x=a;
    y=b;
    radius=r;
    countC++;
}
void Circle::display() const
{
    cout<<x<<","<<y<<" "<<"r="<<radius<<endl;
}
void Circle::showCount()
{
    cout<<"The number is"<<setw(2)<<countC<<endl;
}
float Circle::Square() const
{
    return radius*radius*Pi;
}
Circle::~Circle()
{
    x=0;
    y=0;
    radius=0;
}
int Circle ::countC=0;

int main()
{
    Circle::showCount();    
    Circle r1;    
    r1.display ();   

    {        
        Circle r2(3,4,5);        
        r2.display();
        Circle::showCount ();    
    }    
    r1.showCount ();    
    return 0;
}