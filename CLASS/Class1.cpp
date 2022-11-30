/*类、对象
  设计汽车的工程图纸--类(class)
  工程图中的油门--类的成员函数
  按图纸生产一辆汽车--对象(project)
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 20

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "hello, world!\n"; //如果有using....就可以删除std::
    cout<<endl;
    //cout 输出流对象  <<插入运算符
    printf ("welcome to C++!\n");
    
    srand((unsigned int)time(NULL));
    int *parr=(int*)malloc(N*sizeof(int));//int array[N]
    int *parr=new int[N];
    for(int i=0;i<N;i++)
    {
      parr[i]=rand()%50+1;
      //cout<<setw(4)<<*(parr+i);
      cout<<parr[i]<<"  ";
      if((i+1)%5==0)
        cout<<endl; 
    }
    free(parr);
    delete parr;
    return 0;
}

/*一维数组
int FindMax(int myarr[],int size,int*)
*/
int FindMax(int myarr[],int size,int* p)
{
     int pos=0;
     *p=myarr[0];
     for(int i=1;i<size;i++)
     {
       if(myarr[i]>*p)
       {
          *p=myarr[i];
          pos=i;
       }
     }
     return pos;
}
/*int FindMax(int myarr[],int size,int*)
int max;
int index=FindMax(parr,N,&max);
cout<<"Max is"<<max<<",and the position is"<<index<<endl;

*/

//定义引用
int a=5;
int &ref=a;  //理解上，ref是a的别名


int FindMax(int myarr[],int size,int &ref)
{
     int pos=0;
     ref=myarr[0];
     for(int i=1;i<size;i++)
     {
       if(myarr[i]>ref)
       {
          ref=myarr[i];
          pos=i;
       }
     }
     return pos;
}

//输入流
//cin>>a>>b>>c


