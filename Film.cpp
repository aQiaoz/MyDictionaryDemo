#include <iostream>
using namespace std;
class Film
{
    public:
        static int read_input(Film *f[], int n)
        {
            int a;
            for(int i;i<n ;i++)
            {
                cin>>a;
                if(a=1)
                {
                    Film f1;
                    f1.input(*f[i]);
                }
                if(a=2)
                {
                   ForeignFilm f2;
                   f2.input(*f[2]);
                }
                if(a=3)
                {
                    DirectorCut f3;
                    f3.input(*f[3]);
                }
                if(a=4)
                {
                    break;
                }

            }
        }
        virtual void input(Film fs)
        {
            cout<<"Title:";
            cin>>fs.Title;
            cout<<"Director:";
            cin>>fs.Director;
            cout<<"Time:";
            cin>>fs.Time;
            cout<<"Quality";
            cin>>fs.Quality;
        }
        virtual void output()
        {
            cout<<"Title:"<<Title;
            cout<<"Director:"<<Director;
            cout<<"Time:"<<Time;
            cout<<"Quality:"<<Quality;
        }
    protected:
        string Title;
        string Director;
        int Time;
        int Quality;
};

class ForeignFilm : public Film
{
    public:
        void input(Film fs)
        {
            Film::input(fs);
            cout<<"Language:";
            cin>>this->Language;
        }
        void output()
        {
            Film::output();
            cout<<"Language:"<<Language;
        }
    protected:
        string Language;

};
class DirectorCut : public Film
{
    public:
        void input(Film fs)
        {
            Film::input(fs);
            cout<<"Revised_time:";
            cin>>this->Revised_time;
            cout<<"Changes:";
            cin>>this->Changes;
        }
        void output()
        {
            Film::output();
            cout<<"Revised_time:"<<Revised_time;
            cout<<"Changes:"<<Changes;
        }

    protected:
        int Revised_time;
        string Changes;
};
int main()
{    
    const unsigned n=5;    
    Film* films[n];    
    int num= Film::read_input(films, n);    
    cout<<"-------------------\n";    
    for( int i=0;i<num;i++)    
    {        
        films[i]->output();        
        cout<<"-------------------\n";    
    }    
    return 0;
}