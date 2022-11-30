#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include <iterator>
#include <list>
using namespace std;
template<typename T>

class MyQueue
{
    friend ostream& operator << (ostream& output,MyQueue &d)
    {
        List<T> const_iterator it;
        for(it=d.items.begin();it!=d.items.end();++it)
        {
            output<<*it<<endl;
        }
    }
    public:
        MyQueue(int a[],int b[])
        {
            items.insert(items.begin(),a,b)
        }
        int size()
        {
            return items.size()
        }
        void push(int i)
        {
            items.push_back(i);
        }
        bool empty()
        {
            return items.empty()
        }
        void pop()
        {
            
        }


  private:

   list<T>  items;

};
//StudybarCommentBegin
int main()
{
    int arr[]={5,4,3,2,1};
    MyQueue<int> myIntq(arr,arr+5);
    cout << myIntq;
    cout << "Size is : " << myIntq.size() << endl;
    cout<<"Now push a number:";
    int num; cin>>num;
    myIntq.push(num);
    cout<<"Pop All:"<<endl;
    while(!myIntq.empty())
    {
        cout<<myIntq.front()<<"\n";
        myIntq.pop();

    }
    cout<<"After pop:"<<endl;
    cout << myIntq;
    cout << "Size is : " << myIntq.size() << endl;
    
    string arrstring[]={"hello","world","welcome","to"};
    MyQueue<string> myStringq(arrstring,arrstring+4);
    cout << myStringq;
   
    cout<<"Now push a string:";
    string str; cin>>str;
    myStringq.push(str);
    while(!myStringq.empty())
    {
        cout<<myStringq.front()<<"\n";
        myStringq.pop();
        
    }
    cout << myStringq;
    
    
    return 0;
}


//StudybarCommentEnd
