#include <string.h>
using namespace std;
class Rectangle
{
    public:
        void setLength(double length);
        double getLength();
        void setWidth(double width);
        double getWidth();
        double perimeter();
        double area();
        
    private:
        double rlength,rwidth;
};