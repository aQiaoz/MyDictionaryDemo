#include <iostream>
using namespace std;
class Triangle
{
    public:
        Triangle(int,int,int);

        void setside1(int side1);
        void setside2(int side2);
        void setside3(int side3);
        
        int getside1();
        int getside2();
        int getside3();

        bool isRightTriangle();
        bool isEquilateral();

    
    private:
        int first,second,third,max,a,b;
};
