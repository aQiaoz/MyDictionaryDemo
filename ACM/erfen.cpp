// #include<iostream>
// using namespace std;
// int array[100000];
// int a2[100000];
// string find(int x,int n)
// {
//     int l=0,r=n-1;
//     while(l<r)
//     {
//         int mid=(r+l)/2;
//         if(array[mid]>=x)
//             r=mid;
//         else 
//             l=mid+1;
//     }
//     if(array[l]==x)
//         return "Yes";
//     if(array[l]!=x)
//         return "No";
// }
// int main()
// {
//     int n,m;
//     unsigned int num1,num2;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cin>>num1;
//         array[i]=num1;
//     }
//     cin>>m;
//     for(int i=0;i<m;i++)
//     {
//         cin>>num2;
//         a2[i]=num2;
//     }
//     for(int i=0;i<m;i++)
//     {
//         cout<<find(a2[i],n)<<endl;
//     }
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int a,b;
//     while(scanf("%d%d",&a,&b),a||b)
//     {    
//         int last=1;
//         for(int i=1;i<=b;i++)
//         {
//             last=last*a%1000;
//         }
//         printf("%d\n",last%1000);
//     }
//     return 0;
// } 

// #include<stdio.h>
// void move(char A, char C, int n)
// {
// 	printf("%d:%c->%c\n", n, A, C);
// }

// void HanoiTower(char A, char B, char C, int n)
// {
// 	if (n == 1)
// 	{
// 		move(A, C, n);
// 	}
// 	else
// 	{
// 		//��n-1��Բ�̴�A��������C���ƶ���B����
// 		HanoiTower(A, C, B, n - 1);
// 		//��A�������һ��Բ���ƶ���C����
// 		move(A, C, n);
// 		//��n-1��Բ�̴�B��������A���ƶ���C����
// 		HanoiTower(B, A, C, n - 1);
// 	}
// }

// int main()
// {
// 	int n = 0;
//     char a,b,c;
// 	scanf("%d ", &n);
//     scanf("%c %c %c",&a,&b,&c);
// 	//��n��Բ�̴�A��������B���ƶ���C����
// 	HanoiTower(a, b, c, n);
// 	return 0;
// }

#include<stdio.h>
int v[10000];
int main()
{
    unsigned int n,m;
    unsigned int num;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        v[i]=num;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    




}