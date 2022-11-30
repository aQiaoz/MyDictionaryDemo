#include <iostream>
#include <iomanip>
using namespace std;
class IntegerSet
{
     public:
        IntegerSet();
        IntegerSet(int s[],int k);
        ~IntegerSet();
        void inputSet();
        void insertElement(int i);
        void deleteElement(int i);
        void printSet();
        bool isEqualTo(IntegerSet &x); 
     private:
         bool a[101];
};

IntegerSet::IntegerSet()
{
    for(int i=0;i<101;i++)
        a[i]=false;
}
IntegerSet::IntegerSet(int s[],int k)
{
    for(int i=0;i<101;i++)
       a[i]=0;
    for(int j=0;j<k;j++)
    {
        a[s[j]]=true;
    }
    
}
void IntegerSet::inputSet()
{
    int i;
    cin>>i;
    while(i!=-1)
    {
        if((i<0 || i>100)&&i!=-1)
        {
            cout<<"Invalid Element\n";
        }
        a[i]=true;
        if(i==-1)
        {
            break;
        }
        cin>>i;
    }
}
void IntegerSet::insertElement(int i)
{
    if(i<0 || i>100)
        {
            cout<<"Invalid insert attempted!\n";
        }
    else a[i]=true;
}
void IntegerSet::deleteElement(int i)
{
    a[i]=false;
}
void IntegerSet::printSet()
{   
    int t=0;
    for(int i=0;i<101;i++)
    {
        if(a[i]==true)
        {
            t++;
        }
    }
    if(t==0)
        cout<<"{"<<setw( 4 )<<"---"<<" }"<<endl;
    else
    {
        t=0;
        cout<<"{";
        for(int j=0;j<101;j++)
        {
            if(a[j]==true)
            {
                t++;
                cout<<setw( 4 )<<j;
                if(t%10==0)
                  cout<<endl;
            }
        }    
        cout<<setw( 4 )<<"}"<<endl;
    }
}
bool IntegerSet::isEqualTo(IntegerSet &x)
{
    for(int i=0;i<101;i++)
    {
        if(a[i]!=x.a[i])
        {
            return false;
        }
    }
    return true;
}
IntegerSet::~IntegerSet()
{
    delete[]a;
}

int main()
{    
    IntegerSet a;    
    IntegerSet b;
    //   cout << "Enter set A:\n";    
    a.inputSet();
    //    cout << "\nEnter set B:\n";    
    b.inputSet(); 

    if ( a.isEqualTo( b ) )        
        cout << "Set A is equal to set B\n";    
    else        
        cout << "Set A is not equal to set B\n";
        cout << "\nInserting 77 into set A...\n";   
        a.insertElement( 77 );    
        cout << "Set A is now:\n";    
        a.printSet();   

        cout << "\nDeleting 77 from set A...\n";    
        a.deleteElement( 77 );    
        cout << "Set A is now:\n";    
        a.printSet();    
         
        const int arraySize = 10;    
        int intArray[ arraySize ] = { 25, 67, 2, 9, 99,105, 45, -5, 100, 1 };    
        IntegerSet e( intArray, arraySize );    

        cout << "\nSet E is:\n";    
        e.printSet();    
        cout << endl;    
        return 0;
} // end main