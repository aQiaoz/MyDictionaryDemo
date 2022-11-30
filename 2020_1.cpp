#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using std::cout;
using std::endl;
using namespace std;

int main()
{
    vector<string> words;
    char c;
    string word;
    vector<string>::const_iterator it;
    cout<<"Enter your choice(q/a/d/f/s/p):";
    cin>>c;
    while(1)
    {
        switch(c)
        {
            case 'a':
                cout<<"Enter a word:";
                cin>>word;
                words.push_back(word);
                cout<<word<<" added."<<endl;
                break;
            case 'p':
                for(it=words.begin();it!=words.end();++it)
                {
                    cout<<*it<<" ";
                }
                cout<<"\nprint end!"<<endl;
                break;
            case 's':
                sort(words.begin(),words.end ());
                cout<<"sort end!"<<endl;
                break;
            case 'd':
                cout<<"word:";
                cin>>word;
                for(vector<string>::const_iterator it=words.begin();it!=words.end();++it)
                {
                    if(*it==word)
                    {
                        it = words.erase(it);
                    }
                }
                cout<<word<<" deleted"<<endl;
                break;
            case 'f':
                cout<<"word:";
                cin>>word;
                it = find(words.begin(),words.end(),word);
                if(it==words.end())
                {
                    cout<<word<<" not finded."<<endl;
                }
                else
                {
                    cout<<word<<" finded."<<endl;
                }
                break;
            case 'q':
                cout<<"bye"<<endl;
                return 0;
                break;
        }
        cout<<"Enter your choice(q/a/d/f/s/p):";
        cin>>c;   
    }
}