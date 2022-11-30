#include <iostream>
#include <iomanip>
using namespace std;
class PartFilledArray
{    
    friend ostream& operator<<(ostream& out,PartFilledArray &p);
    public:    
        PartFilledArray(int array_size=0);    
        PartFilledArray( const PartFilledArray & object);    
        ~PartFilledArray( );    
        void addValue(double newentry);

    protected:    
        double *a;    
        int max_number;    
        int number_used;
};
PartFilledArray::PartFilledArray(int array_size)
{
    max_number=(array_size > 0 ? array_size : 10);
    a=new double [max_number];
    for(int i=0;i<max_number;i++)
    {
        a[i]=0;
    }
    number_used=0;
}

PartFilledArray::PartFilledArray(const PartFilledArray & object):max_number(object.max_number)
{
    a=new double[max_number];
    number_used=object.number_used;
    for(int i=0;i<object.number_used;i++)
    {
        a[i]=object.a[i];
    }
}

void PartFilledArray::addValue(double newentry)
{
    a[number_used]=newentry;
    number_used++;
    while(number_used>max_number)
    { 
        cout<<"Adding to a full array."<<endl;
        exit(1);
    }  
}

ostream& operator<<(ostream& output,PartFilledArray &p)
{
    int i;
    for(i=0;i<p.number_used;i++)
    {
        output<<setw(2)<<p.a[i];
    }
    return output;
}
PartFilledArray::~PartFilledArray()
{
    delete [] a;
}


class PartFilledArrayWMax:public PartFilledArray
{    
    friend ostream& operator<<(ostream& out,PartFilledArrayWMax &p);
    public:    
        PartFilledArrayWMax(int array_size);    
        PartFilledArrayWMax(const PartFilledArrayWMax &object);    
        ~PartFilledArrayWMax();    
        void addValue(double newentry);    
        double getMax();
    private:    
        double max_value;
};
PartFilledArrayWMax::PartFilledArrayWMax(int array_size)
{
    max_number=(array_size > 0 ? array_size : 10);
    a=new double [max_number];
    for(int i=0;i<max_number;i++)
    {
        a[i]=0;
    }
    number_used=0;
    max_value=0;
}

PartFilledArrayWMax::PartFilledArrayWMax(const PartFilledArrayWMax & object)
{
    a=new double[max_number];
    number_used=object.number_used;
    for(int i=0;i<object.number_used;i++)
    {
        a[i]=object.a[i];
    }
}

void PartFilledArrayWMax::addValue(double newentry)
{
    a[number_used]=newentry;
    number_used++;
    while(number_used>max_number)
    { 
        cout<<"Adding to a full array."<<endl;
        exit(1);
    }
}

ostream& operator<<(ostream& output,PartFilledArrayWMax &p)
{
    int i;
    for(i=0;i<p.number_used;i++)
    {
        output<<setw(2)<<p.a[i];
    }
    output<<endl;
    return output;
}
double PartFilledArrayWMax::getMax()
{
    max_value=a[0];
    for(int i=1;i<number_used;i++)
    {
        if(a[i]>=max_value)
        {
            max_value=a[i];
        }
    }
    return max_value;
}
PartFilledArrayWMax::~PartFilledArrayWMax()
{
    delete [] a;
}


int main()
{    
    PartFilledArrayWMax a(7);    
    double x;    
    cin>>x;    
    while (x!=0) 
    {        
        a.addValue(x);        
        cin>>x;    
    }    
    cout<<a;    
    cout<<a.getMax()<<endl;    
    PartFilledArrayWMax b(a);    
    cout<<b;    
    cout<<b.getMax()<<endl;
}