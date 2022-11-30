#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
    public:
        MyString(int a)
        { 
            char t;
            if(a>10000000)
            {
                throw t;
            }
            cin>>s;
            ar = new char(a); 
            cout<<"Constructing..."<<endl;
            cout<<"Construction finished"<<endl;
        }
        ~MyString()
        { 
            delete [] ar;
            cout<<"Destruction finished"<<endl;
        }
        void ShowStr()
        {
            cout<<s<<endl;
        }

    private:
       char * ar;
       string s;

};
int main()
{
    long a;
    cin >> a;
    try
    {
        if (a > 0)
        {
            MyString str1(a);   //生成容纳a个字符的字符串
            str1.ShowStr();
        }
        else                  
        {                      
            char *c=(char*)"Array length error.";                     
            throw c;                    //  throw "Array length error.";work in VC not GCC                 
        }
    }
    catch (char* c)
    {
        cout << c << endl;
    }
    catch (char) 
    {        
        cout<<"Constructor abnormal"<<endl;    
    }
    catch (...)
    { 
        cout << "Other failures." << endl; 
    }
    cout << "Main finished." << endl;
    return 0;
}