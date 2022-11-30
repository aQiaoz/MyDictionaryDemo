#include <iostream>
using namespace std;
class Film
{
    public:
        Film()
        {
           a=6;
        }
        virtual void print()
        {
            cout<<a<<endl;
        }
    protected:
        int a;
};
class K : public Film
{
    public:
        K()
        {
            b=4;
        }
        void print()
        {
            Film::print();
            cout<<b<<endl;
        }
    protected:
        int b;
};
int main()
{
    K k;
    k.print();
}