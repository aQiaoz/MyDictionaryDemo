#include <iostream>
#include <string>
using namespace std;
string greet( string form, string lastname, string title, string::size_type pos, int length)
{
    string vec;
    string ti;
    if(title.find("Miss")==pos)
    {
        ti=title.substr(pos,length);
    }
    vec.assign(form.begin(),form.end());
    vec.erase(8,14);
    vec.replace(5,7,ti);
    vec.append(" "+lastname);
    return vec;
}
//StudybarCommentBegin
int main()
{
    string generic1("Dear Ms Daisy:");
    string generic2("MrsMrMissPeople");
    string lastName("Annap");
    string salute = greet(generic1,lastName,generic2,5,4);
    
    cout<<salute;
    
    return 0;
}
//StudybarCommentEnd