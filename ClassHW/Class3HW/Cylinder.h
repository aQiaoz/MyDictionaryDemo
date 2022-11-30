#include <iostream>
using namespace std;
class Cylinder
{
    public:
        Cylinder(double,double);

        void setheight(double height);
        void setradius(double radius);
   
        double getheight();
        double getradius();

        void volume();
    private:
        double cheight,cradius,cvolume;  
};

