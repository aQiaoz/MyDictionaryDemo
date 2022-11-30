#include <iostream>
#include <map>
#include <list>
using namespace std;

int main()
{
    int id1, id2;
    int num, n;
    char str[10];
    map< int, list<int> > x;
    cin >> n;
    while(n--)
    {
        cin >> str;
        switch (str[0])
        {
            case 'n':
                cin >> id1;
                x[id1] = list<int>();
                break;
            case 'a':
                cin >> id1 >> num;
                x[id1].push_back(num);
                break;
            case 'u':
                cin >> id1;
                x[id1].sort();
                x[id1].unique();
                break;
            case 'o':
                cin >> id1;
                x[id1].sort();
                for (auto it = x[id1].begin(); it != x[id1].end(); it++)
                {
                    cout << *it <<" ";
                }
                cout << endl;
                break;
            case 'm':
                cin >> id1 >> id2;
                x[id1].merge(x[id2]);
                break;
        }
        
    }
    return 0;
}