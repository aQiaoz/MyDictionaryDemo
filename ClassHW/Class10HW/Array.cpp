#include <iostream>
#include <iomanip>
using namespace std;

template < class elementType, int numberOfElements >
class Array
{
    public:
        Array();
        elementType getSize();
        static elementType getArrayCount()
        {
            return arrayCount;
        }
        friend ostream& operator << (ostream& output,Array< elementType, numberOfElements > &p)
        {
            for( int i=0; i<p.size; i++ )
            {
                output<<p.ptr[i]<<" ";
            }
            cout<<endl;
            return output;
        }
        friend istream& operator >> (istream& input,Array< elementType, numberOfElements > &p)
        {
            for( int i=0; i<p.size; i++ )
            {
                input>>p.ptr[i];
            }
            return input;
        }
    private: 
        elementType ptr[ numberOfElements ]; // ptr指向数组的起始位置 
        int size; // 数组大小，即为numberOfElements 
        static int arrayCount; // 生成的类对象的总数
};

template < class elementType, int numberOfElements >
Array< elementType, numberOfElements >::Array()
{
    Array::size = numberOfElements;
    int i;
    for(i=0;i<size;i++)
        ptr[i]=0;
    arrayCount++;
}

template < class elementType, int numberOfElements >
elementType Array< elementType, numberOfElements >::getSize()
{
    return size;
}



template < class elementType, int numberOfElements >
int Array< elementType, numberOfElements>::arrayCount=0;

int main()
{    
    // create intArray object    
    Array< int, 5 > intArray1;    
    
    // initialize intArray with user input values    
    cin >> intArray1;    
    
    // create intArray object    
    Array< int, 5 > intArray2;    
    
    // initialize intArray with user input values
    cin >> intArray2;    
    
    // create floatArray    
    Array< float, 5 > floatArray;    
    cin >> floatArray;    
    
    // output intArray1    
    cout << "\nIntArray1 contains " << intArray1.getSize() << " Elements.\n";    
    cout << "The values in intArray are:\n";    
    cout << intArray1;    
    
    // output intArray2    
    cout << "\nIntArray2 contains " << intArray2.getSize() << " Elements.\n";    
    cout << "The values in intArray are:\n";    
    cout << intArray2;    
    
    // output floatArray    
    cout << "\nDoubleArray contains " << floatArray.getSize() << " Elements.\n";    
    cout << "The values in the doubleArray are:\n";    
    cout << floatArray;    
    
    cout << "\nThere are " << Array<int,5>::getArrayCount() << " Array<int,5> objects.\n";
    cout << "\nThere are " << Array<float,5>::getArrayCount() << " Array<float,5>objects.\n";    
    return 0;
} // end main