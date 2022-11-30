/*
继承和派生
有了继承，使软件的重用成为可能。
继承是C++和C的最重要的区别之一。
1.有许多基类是被程序的其他部分或其他程序使用的，这些程序要求保留原有的基类不受破坏。
2.用户往往得不到基类的源代码。
3.在类库中，一个基类可能已被指定与用户所需的多种组件建立了某种关系，因此在类库中的基类是不容许修改的。
4.实际中的许多基类并不是从已有的其他程序中选取来的，而是专门作为基类设计的。
5.在面向对象程序设计中，需要设计类的层次结构，从最初的抽象类出发，每一层派生类的建立都逐步地向着目标的具体实现前进。
*/


//公有继承public
/*
•基类的public和protected成员的访问属性在派生类中保持不变，但基类的private成员不可直接访问(仍为基类私有)。
•派生类中的成员函数可以直接访问基类中的public和protected成员，但不能直接访问基类的private成员。
•通过派生类的对象只能访问基类的public成员
*/
#include <iostream>
using namespace std;

class Point  //基类声明
{
    public:
        void InitP(float xx=0,float yy=0)
        {X=xx; Y=yy;}
        void Move (float xoff=0,float yoff=0)
        {X+=xoff; Y+=yoff;}
        float GetX()  {return X;}
        float GetY()  {return Y;}
    private:
        float X,Y;
};
class Rectangle: public Point   //派生类声明
{
    public:    //新增公有函数成员
        void InitR(float x,float y,float w,float h)
        {
            InitP(x,y);    //调用基类公有成员函数
            W=w;H=h;
        }
        float GetW()  {return W;}
        float GetH()  {return H;}
    private:    //新增私有数据成员
        float W,H;
};
int main()
{
    Rectangle rect;
    rect.InitR(2,3,20,10);    //通过派生类对象访问基类共有成员
    rect.Move(3,2);
    cout<<rect.GetX()<<','<<rect.GetY()<<','<<rect.GetH()<<','<<rect.GetW()<<endl;
    return 0;
}



//私有继承
/*
•基类的public和protected成员都以private身份出现在派生类中，但基类的private成员不可直接访问(仍为基类私有)
•通过派生类的对象不能直接访问基类中的任何成员
*/
class Rectangle1: private Point
{
    public:
        void InitR(float x,float y,float w,float h)
        {
            InitP(x,y);
            W=w;H=h;
        }
        void Move (float xoff,float yoff)
        {Point::Move(xoff,yoff);}     //同名覆盖
        float GetX()  {return Point::GetX();}  //同名覆盖
        float GetY()  {return Point::GetY();}  //同名覆盖
        float GetW()  {return W;}
        float GetH()  {return H;}
    private:
        float W,H;
};
//主函数与public继承的相同


//保护继承
/*
•对建立其所在类对象的模块 来说，它与 private 成员的性质相同。
•对于其派生类来说，它与 public 成员的性质相同。
•如果派生类作为新的基类继续派生时，体现出保护和私有继承的区别 ：把保护成员的访问范围扩展到派生类中。
•既实现了数据隐藏 ，又方便继承，实现代码重用。
*/

class Student
{
    public:
        void display();
    protected:
        int num;
        string name;
        char sex;
};
void Student::display()
{
    cout<<"num: "<<num<<"name:"<<name<<"sex: "<<sex<<endl;
}

class GradStudent: protected Student
{
    public:
        void display();
    private:
        int age;
        string addr; 
};
void GradStudent::display()
{
    cout<<"num: "<<num<<"name:"<<name<<"sex: "<<sex<<endl;
    cout<<"age: "<<age<<"address: "<<addr<<endl;
}
//int main()
//{
//    GradStudent stud1;
//    stud1.display();
//    return 0;
//}

/*
子对象
Student(int n,string nam,int n1,string nam1,int a,string ad):
monitor(n1,nam1),People(n,nam),age(a),addr(ad){}
//monitor就是子对象，不管写构造函数声明的声明顺序如何，系统都自动按照下列顺序进行
调用次序：
1．调用基类构造函数，调用顺序按照它们被继承时声明的顺序（从左向右）。
2．调用子对象的构造函数，调用顺序按照它们在类中声明的顺序。
3．派生类的构造函数体中的内容。
*/