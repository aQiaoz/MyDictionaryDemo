// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     int x;
//     int w;
//     double stack[200];
//     double num;
//     char a,b;

//     while(scanf("%d ",&x) && x!=0)
//     {
//         w=0;
//         stack[++w]=1.0*x;
//         while(scanf("%c %lf%c",&a,&num,&b)!=EOF)
//         {
//             if(a=='+')
//             {
//                 stack[++w]=num;
//             }
//             else if(a=='-')
//             {
//                 stack[++w]=-1*num;
//             }
//             else if(a=='*')
//             {
//                 stack[w]=stack[w]*num;
//             }
//             else if(a=='/')
//             {
//                 stack[w]=stack[w]/num;
//             }
//             if(b!=' ')
//             {
//                 break;
//             }
//         }

//         double c=0;
//         for(int i=1;i<=w;i++)
//         {
//             c +=stack[i];
//         }
//         printf("%.2lf\n",c);
//     }

//     return 0;
// }

#include <iostream>
#include <stack>
using namespace std;
int main()
{
    unsigned int x;
    int sum = 0, flag = 0;
    cin >> x;
    if(x%2!=0) flag==1;
    char str[200000];
    cin >> str;
    if (flag == 1)
    {
        puts("No");
        return 0;
    } 
    for (int i = 0; i < x; i++)
    {
        if (str[i] == '(')
            sum++;
        else
            sum--;
        if (sum < -1)
            flag = 1;
    }
    if(sum!=0) flag=1;
    if (flag == 1) puts("No");
    else puts("Yes");
    return 0;
    // else
    // {
    //     stack<char> s;
    //     for (int i = 0; i < x; i++)
    //     {
    //         cin >> str;
    //         if (str[i] == '(')
    //         {
    //             s.push(str[i]);
    //         }
    //         else if (str[i] == ')' && !s.empty())
    //         {
    //             cout << "No" << endl;
    //             return 0;
    //         }
    //         else
    //         {
    //             s.pop();
    //         }
    //     }
    //     if (s.empty())
    //     {
    //         cout << "Yes" << endl;
    //     }
    //     else
    //     {
    //         cout << "No" << endl;
    //     }
    // }
    // return 0;
}