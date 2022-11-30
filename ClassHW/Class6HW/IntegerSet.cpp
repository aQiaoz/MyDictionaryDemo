#include <iostream>
#include <iomanip>
using namespace std;
class IntegerSet
{
    friend IntegerSet operator+(const IntegerSet& t1,const IntegerSet& t2);

    public:friend IntegerSet operator+(const IntegerSet& t1,const IntegerSet& t2);
        IntegerSet();
        
        friend ostream& operator << (ostream&,IntegerSet&);
        friend istream& operator >> (istream&,IntegerSet&);

    private:
         bool a[101];
         int x;
};

IntegerSet::IntegerSet()
{
    for(int i=0;i<101;i++)
        a[i]=false;
}

IntegerSet operator+(const IntegerSet& t1,const IntegerSet& t2)
{
    IntegerSet sum;
    IntegerSet();
    for(int j=0;j<101;j++)
    {
        if(t1.a[j]==true || t2.a[j]==true)
        {
            sum.a[j]=true;
        }
    }
    return sum;
}

ostream& operator << (ostream& output,IntegerSet& c)
{
    int t=0;
    for(int i=0;i<101;i++)
    {
        if(c.a[i]==true)
        {
            t++;
        }
    }
    if(t==0)
    {
        output<<"null"<<endl;
        return output;
    }
    else
    {
        t=0;
        for(int j=0;j<101;j++)
        {
            if(c.a[j]==true)
            {
                t++;
                output<<setw( 5 )<<j;
                if(t%5==0)
                  output<<endl;
            }
        }    
    }
    return output;
}

istream& operator >> (istream& input,IntegerSet& c)
{
    input>>c.x;
    while(c.x!=-1)
    {
        c.a[c.x]=true;
        if(c.x==-1)
        {
            break;
        }
        input>>c.x;
    }
    return input;
}

int main()
{    
    IntegerSet set1, set2,set3;

    cin>>set1;    
    cin>>set2;    
    cout<<"set1:"<<endl<<set1<<endl;    
    cout<<"set2:"<<endl<<set2<<endl;    
    cout<<"set3:"<<endl<<set3;    
    set3=set1+set2;    
    cout<<"\nafter set1+set2 ,set3:\n"<<set3<<endl;    
    return 0;
}