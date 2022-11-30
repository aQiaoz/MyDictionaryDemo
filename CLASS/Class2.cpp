/*函数
函数重载：函数名称可以一样，但名字相同时，参数类型或者数量不能相同
函数可以带默认参数double cube(double x=5)
*/

//string--处理字符串的利器
#include <string.h>

//类的定义
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

class Rectangle
{
    public:
        double area()
        {
            return w*h;
        }
        double length();
        void setwidth()
        {
            double w;
            cin>>w;
        }
        void setlength()
        {
            double h;
            cin>>h;
        }
    private:
        double w,h;
};

int main()
{
    Rectangle *p = new Rectangle;
    p->setwidth();
    p->setlength();
    cout<<"area:"<<p->area()<<endl;
    cout<<"length:"<<p->length()<<endl;

    delete p;
    return 0;
}



