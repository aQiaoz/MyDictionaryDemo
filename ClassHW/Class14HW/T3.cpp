#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void file_read_dosomething(string filename)
{
    int cnt[1] = {0};
    char str[256];
    fstream outfile(filename,ios::in);
    while(outfile.getline(str,256))
    {
        int tmp = 0;

        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == ' ' || str[i] == '.')
            {
                cnt[1]++;
            }
            if(str[i] >= 'A' && str[i] <= 'z')
            {
                tmp++;
            }
        }

        if(tmp != 0)
        {
            cnt[0]++;
            tmp = 0;
        }
    }

    cout<<"words:"<<cnt[1]<<endl;
    cout<<"lines:"<<cnt[0]<<endl;
    outfile.close();
    system("pause");
}

int main()
{
    file_read_dosomething("data.txt");        
    return 0;
}