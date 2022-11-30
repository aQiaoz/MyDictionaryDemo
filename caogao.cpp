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
        return w * h;
    }
    double length();
    void setwidth()
    {
        double w;
        cin >> w;
    }
    void setlength()
    {
        double h;
        cin >> h;
    }

private:
    double w, h;
};

int main()
{
    Rectangle *p = new Rectangle;
    p->setwidth();
    p->setlength();
    cout << "area:" << p->area() << endl;
    cout << "length:" << p->length() << endl;

    delete p;
    return 0;
}
