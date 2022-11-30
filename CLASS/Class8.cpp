#include <iostream>
#include <iomanip>
using namespace std;

/*
多重继承
*/
//弄清顺序
class B1
{
    public:
    B1(int i)    {cout<<"constructing B1 "<<i<<endl;}
    ~B1()        {cout<<"destructing B1 "<<endl;}
};
class B2
{
    public:
    B2(int i)    {cout<<"constructing B2 "<<i<<endl;}
    ~B2()        {cout<<"destructing B2 "<<endl;}
};
class B3
{
    public:
    B3()    {cout<<"constructing B3 *"<<endl;}
    ~B3()        {cout<<"destructing B3"<<endl;}
};
class C:public B2,public B1,public B3
{
    public:
        C(int a,int b,int c,int d):B1(a),memberB2(d),memberB1(c),B2(b){}
    private:
        B1 memberB1;    B2 memberB2;    B3 memberB3;   
};
int main()
{
    //C obj(1,2,3,4);
}


////二义性问题
class N
{
    public:
    int a;
    void display()
    {cout<<"N::a="<<a<<endl;}
};
class A:public N
{
    public:
    int a1;
};
class B:public N
{
    public:
    int a2;
};
class C1 :public A,public B
{
    public:
    int a3;
    void show()
    {cout<<"a3="<<a3<<endl;}
};
//int main()
//{
    //C1 c1;
//}



////虚基类    一个基类可以在生成一个派生类时作为虚基类，而在生成另一个派生类时不作为虚基类。
class Person
{
    public:
        Person(string nam):name(nam){}
        void display()
        {
            cout<<"name: "<<name<<endl;
        }
    protected:
        string name;
};
class Teacher:virtual public Person
{
    public:
    Teacher(string nam,int a,string t):Person(nam)
    {
        age=a;
        title=t;
    }
    void display()
    {
        Person::display();
        cout<<"age: "<<age<<endl;
        cout<<"title: "<<title<<endl;
    }
    protected:
    int age;    string title;
};

class Student:virtual public Person
{
    public:
    Student(string nam,char s,float sco):Person(nam)
    {name=nam;   sex=s;   score=sco;}
    void display()
    {
        Person::display();
        cout<<"sex: "<<sex<<endl;
        cout<<"score: "<<score<<endl;
    }
    protected:
    char sex;    float score;
};
class Graduate:public Teacher,public Student
{
    public:
    Graduate(string nam,int a,char s,string t,float sco,float w):
        Person(nam),Teacher(nam,a,t),Student(nam,s,sco),wage(w){}
    void display()
    {
        Teacher::display;
        Student::display;
        cout<<"wage:"<<wage<<endl;
    }
    private:
    float wage;
};
int main()
{
    Graduate grad1("Wang-Li",24,'f',"assistant",89.5,1234.5);
    grad1.display();
}

//指针
/*
int main()
{
    Student stud1()
    Graduate grad1()
    Student *pt=&stud1;
    pt->display();

    pt=&grad1;
    pt->display
}
*/