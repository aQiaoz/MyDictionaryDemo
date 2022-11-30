#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ofstream outfile("stock.txt");
    if(!outfile)
    {
        cerr<<"open stock.txt error!"<<endl;
        exit(1);
    }
    char c[100];
    cin.getline(c,100);
    for(int i=0;c[i]!='\0';i++)
    {
        outfile.put(c[i]);
        cout<<c[i];
    }
    outfile.close();

    cout<<"\nEnter request"<<endl
      <<"1-Please enter a stock number"<<endl
      <<"2-Exit program"<<endl;
    
    ifstream infile("stock.txt",ios::in);
    if(!infile)
    {
        cerr<<"open stock.txt error!"<<endl;
        exit(1);
    }
    char *num;
    char name[100];
    string n;
    int request;
    cin>>request;
    switch(request)
    {
        case 1:
            while(infile.getline(name,100))
            {
                cin>>num;
                n=name;
                if(num == "000001" && n.substr(0,5) == "000001")
                {
                    cout<<n.substr(7,n.length());
                }
                if(num == "600104" && n.substr(0,5) == "600104")
                {
                    cout<<n.substr(7,n.length());
                }
                if(num == "000096" && n.substr(0,5) == "000096")
                {
                    cout<<n.substr(7,n.length());
                }
            }
            break;
        case 2:
            cout<<"End of run"<<endl;
            break;
    }

    return 0;
}