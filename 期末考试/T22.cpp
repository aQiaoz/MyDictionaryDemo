#include<iostream>
#include<iomanip>

using namespace std;

class Book
{
    public:
        Book(string n=" ", double p=0):name(n),price(p){}
    
        string name;
        double price;
         

};
class DiscountBook : public Book
{
    public:
        DiscountBook(string n, double p,double r):Book(n,p)
        {discount=r;}
        
        string name;
        double price;
        double discount;
};
class SellBook : public Book
{
    public:
        SellBook(string n, double p,int r):Book(n,p)
        {num=r;}

    
        string name;
        double price;
        int num;
};
//StudybarCommentBegin
int choice()
{
    int n;
    do
    {
        cin >> n;
    }while(n<0 || n>3);
    return n;
}
class BookManager 
{
    BookManager *bo[10];
    public:
        BookManager(){}
        void add(Book *b)
        {
            bo[i]->names[i]=b->name;
            bo[i]->yprices[i]=b->price;
            bo[i]->prices[i]=b->price;
            i++;
        }
        void add(DiscountBook *d)
        {
            bo[i]->names[i]=d->name;
            bo[i]->yprices[i]=d->price;
            bo[i]->prices[i]=d->price*d->discount;
            i++;
        }
        void add(SellBook *s)
        {
            double rate;
            bo[i]->names[i]=s->name;
            bo[i]->yprices[i]=s->price;
            if(s->num<1000)
            {
                rate=0.8;
            }
            if(s->num>=1000 && s->num<=5000)
            {
                rate=0.6;
            }
            if(s->num>5000)
            {
                rate=0.4;
            }
            bo[i]->prices[i]=d->price*rate;
            i++;
        }
        void printAll()
        {
            cout << "\t\t书名\t\t原价\t\t销售价"<<endl;
            for(int j;j<i;j++)
            {
                cout << "\t\t"<<names[j]<<"\t\t"<<yprices[j]<<"\t\t"<<prices[i]<<endl;
            }
        }
    protected:
        Book *b;
        DiscountBook *d;
        SellBook *s;  
        string *names;
        double *yprices;
        double *prices;
        static int i ;
};
int BookManager::i=0;
int main()
{
    BookManager bm; //BookManager类存放指向所有图书的指针
    int n;
    string name;
    double price,discount;
    int total,year,month;
    while ((n = choice())) {
        switch(n)
        {
            case 1:
                cin >> name >>price;
                bm.add(new Book(name,price));
                break;
            case 2:
                cin >> name >> price >> discount;
                bm.add(new DiscountBook(name,price,discount));
                break;
            case 3:
                cin >> name >> price >> total;
                bm.add(new SellBook(name, price, total) );
                break;
        }
    }
    bm.printAll();
}
//StudybarCommentEnd