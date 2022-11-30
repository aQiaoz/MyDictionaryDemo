#include <iostream>
#include <iomanip>
using namespace std;
#define pi 3.1415926

class Shape
{   
    public:
        Shape ( float num, float a, float b)
        { number=num; ca=a; cb=b; }
        virtual float getArea() { return number*number; }
        virtual float getVolume() { return number*number; }
        friend ostream& operator<<(ostream& out,Shape &p)
        {out<<"Circle with radius "<<p.number<<"; center at (" <<p.ca<<", "<< p.cb<<")"; return out;}
    protected:
        float number;
        float ca;
        float cb;
};
class TwoDimensionalShape : public Shape
{
    public:
       TwoDimensionalShape ( float n1, float a, float b ) : Shape(n1,a,b)
       {}
       float getArea() { return number*number; }
       friend ostream& operator<<(ostream& out,TwoDimensionalShape &p)
       {out<<"Circle with radius "<<p.number<<"; center at (" <<p.ca<<", "<< p.cb<<")"; return out;}
};
class ThreeDimensionalShape : public Shape
{
    public:
        ThreeDimensionalShape ( float n2, float a, float b ) : Shape(n2,a,b)
        {}
        float getArea() { return number*number; }
        float getVolume() { return number*number; }
        friend ostream& operator<<(ostream& out,ThreeDimensionalShape &p)
        {out<<"Circle with radius "<<p.number<<"; center at (" <<p.ca<<", "<< p.cb<<")"; return out;}
};
class Circle : public TwoDimensionalShape
{
    public:
        Circle ( float r=0 , float a=0 , float b=0 ) : TwoDimensionalShape(r,a,b)
        {}
        float getArea() 
        { return pi*number*number; }
        friend ostream& operator<<(ostream& out,Circle &p)
        {out<<"Circle with radius "<<p.number<<"; center at (" <<p.ca<<", "<< p.cb<<")"; return out;}
};

class Square : public TwoDimensionalShape
{
    public:
        Square ( float l=0 , float a=0 , float b=0 ) : TwoDimensionalShape(l,a,b)
        {}
        float getArea() 
        { return number*number; }
        friend ostream& operator<<(ostream& out,Square &p)
        {out<<"Square with side length "<<p.number<<"; center at (" <<p.ca<<", "<< p.cb<<")"; return out;}
};
class Cube : public ThreeDimensionalShape
{
    public:
        Cube ( float l=0 , float a=0 , float b=0 ) : ThreeDimensionalShape(l,a,b)
        {}
        float getArea() 
        { return number*number*6; }
        float getVolume() 
        { return number*number*number; }
        friend ostream& operator<<(ostream& out,Cube &p)
        {out<<"Cube with side length "<<p.number<<"; center at (" <<p.ca<<", "<< p.cb<<")"; return out;}
};
class Sphere : public ThreeDimensionalShape
{
    public:
        Sphere ( float r=0 , float a=0 , float b=0 ) : ThreeDimensionalShape(r,a,b)
        {}
        float getArea() 
        { return 4*pi*number*number; }
        float getVolume() 
        { return (1.3333333)*pi*number*number*number; }
        friend ostream& operator<<(ostream& out,Sphere &p)
        {out<<"Sphere with radius "<<p.number<<"; center at ("<<p.ca<<", "<< p.cb<<")"; return out;}
};

int main()
{   
    Shape * shapes[4];    
    // initialize vector with Shapes    
    shapes[ 0 ] = new Circle( 3.5, 6, 9 );    
    shapes[ 1 ] = new Square( 12, 2, 2 );    
    shapes[ 2 ] = new Sphere( 5, 1.5, 4.5 );    
    shapes[ 3 ] = new Cube( 2.2 );

    // output Shape objects and display area and volume as appropriate    
    for ( int i = 0; i < 4; i++ )    
    {        
        cout << *( shapes[ i ] ) << endl;
        // downcast pointer        
        TwoDimensionalShape *twoDimensionalShapePtr = dynamic_cast < TwoDimensionalShape * > ( shapes[ i ] );        
        // if Shape is a TwoDimensionalShape, dis-play its area        
        if ( twoDimensionalShapePtr != 0 )            
            cout << "Area: " << twoDimensionalShapePtr->getArea() << endl;

        // downcast pointer        
        ThreeDimensionalShape *threeDimensionalShapePtr = dynamic_cast < ThreeDimensionalShape * > ( shapes[ i ] );

        // if Shape is a ThreeDimensionalShape, display its area and volume        
        if ( threeDimensionalShapePtr != 0 )            
            cout << "Area: " << threeDimensionalShapePtr->getArea()
            << "\nVolume: " << threeDimensionalShapePtr->getVolume()            
            << endl;        
            
            cout << endl;    
    } // end for
return 0;
} // end main