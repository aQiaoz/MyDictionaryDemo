////多态
//接口一样，实现不同效果
//在派生类中重新定义时，其函数原型，包括返回类型、函数名、参数个数、参数类型以及参数的顺序都必须与基类中的原型完全相同。



////虚函数
//C++提供虚函数，其作用是允许在派生类中重新定义与基类中同名的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数。
#include <iomanip>
#include <iostream>
using namespace std;
class Animal
{
public:
    Animal(string Name){szName=Name;}
    virtual void PrintName(){}
protected:
    string szName;
};
class Dog:public Animal
{
    public:
        Dog(string Name):Animal(Name){}
        void PrintName()  {cout<<"This is dog"<<szName<<endl;}

};
class Cat:public Animal
{
    public:
       Cat (string Name):Animal(Name){}
       void PrintName() {cout<<"This is cat"<<szName<<endl;}
};
class Home
{
    public:
        Home()  {nAnimals=0;}
        void PrintAll ()
        {
            for(int i=0;i<nAnimals;i++)
                pAnimal[i]->PrintName();
        }
        void Add(Animal *Animal)
        {
            pAnimal [nAnimals++]=Animal;
        }
    private:
        int nAnimals;
        Animal *pAnimal[20];
};
bool IsDog(string szName)
{
    if(szName.find("dog")==string::npos)
        return false;
    return true;
}
bool IsCat(string szName)
{
    if(szName.find("cat")==string::npos)
        return false;
    return true;
}

int main()
{
    Home MyHome;
    string szName;
    while (true)
    {
        cin>>szName;
        if(IsDog (szName))
            MyHome.Add(new Dog (szName));
        else if (IsCat(szName))
            MyHome.Add(new Cat (szName));

        MyHome.PrintAll();
    }
}
//增加一个pig类
class Pig: public Animal
{
    public:
        Pig ( string Name ) : Animal(Name){}
        void PrintName()
        { cout<<"this is Pig"<< szName << endl;}
};




////抽象类