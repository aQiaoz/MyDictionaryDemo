#include <iostream>
using namespace std;
//成员函数被调用时存在形参实参相同时使用this指针

//参数初始化表
class Demo
{
public:
    Demo(int w):x(w),y(x),z(x)
    {}
private:
    int x,y,z;
};


//析构函数
class MyStr
{
    public:
        MyStr(char* str);
        void show();

    private:
        int length;
        char* arr;//指针指向空间
};

MyStr::MyStr(char* str)
{
    length=strlen(str);
    arr=new char[length+1];
    strcpy(arr,arr);
}
void MyStr::show()
{
    cout<<"str:"<<arr<<endl;
}
MyStr::~MyStr()
{
    if(length)
    {

    }
}