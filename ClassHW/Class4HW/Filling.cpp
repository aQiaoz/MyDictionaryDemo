#include <iostream>
using namespace std;
class A 
{
    public:    
        int val;    
        // 在此处补充你的代码
        A(int aval=0)
        {
            val=aval;
        }
        A& GetObj()
        {
            return *this;
        }
    private:
        int  aval;
};

int main()
{    
    A a;
    cout <<a.val << endl;    
    a.GetObj() = 5;    
    cout << a.val << endl;
}
