#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
void bubbleSort(T *a,int num)
{
   int i,j;
   T n;
   for(i=0;i<num-1;i++)
   {
       for(j=i+1;j<num;j++)
       {
           if(a[i]>a[j])
           {
               n=a[i];
               a[i]=a[j];
               a[j]=n;
           }
       }
   }
}

int main()
{    
    const int arraySize = 10;  // size of array   
    int a[ arraySize ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, i;   
    
    // display int array in original order   
    cout << "Integer data items in original order\n";   
    for ( i = 0; i < arraySize; ++i )      
        cout << setw( 6 ) << a[ i ];

    bubbleSort( a, arraySize );          // sort thearray   
   
    // display int array in sorted order   
    cout << "\nInteger data items in ascending order\n";   
    for ( i = 0; i < arraySize; ++i )      
        cout << setw( 6 ) << a[ i ];   
        
    cout << "\n\n";

    // initialize double array   
    double b[ arraySize ] = { 10.1, 9.9, 8.8, 7.7, 6.6, 5.5,                            4.4, 3.3, 2.2, 1.1 };   
    
    // display double array in original order   
    cout << "double point data items in original order\n";   
    
    for ( i = 0; i < arraySize; ++i )      
       cout << setw( 6 ) << b[ i ];   
       
    bubbleSort( b, arraySize );          // sort thearray   
    
    // display sorted double array   
    
    cout << "\ndouble point data items in ascending order\n";
    for ( i = 0; i < arraySize; ++i )      
       cout << setw( 6 ) << b[ i ];   

    cout << endl;

    return 0;
} // end main