#include <iostream>
#include<iomanip>
using namespace std;
class Rational
{

    public:
        Rational(int nu=1,int de=2);

        Rational operator+(const Rational &t) const;
        Rational operator-(const Rational &t) const;
        Rational operator*(const Rational &t) const;
        Rational operator/(const Rational &t) const;

        bool operator >(const Rational &t) const;
        bool operator >=(const Rational &t) const;
        bool operator <(const Rational &t) const;
        bool operator <=(const Rational &t) const;
        bool operator ==(const Rational &t) const;
        bool operator !=(const Rational &t) const;

        void Show1() const;
        void Show2() const;

        friend ostream& operator << (ostream&,Rational&);

    private:
        int numerator; //分子
        int denominator; //分母
};

Rational::Rational(int nu,int de)
{
    if(de==0)
    {
        de=1;
    }
    if(de<0)
    {
        de=-de;
        nu=-nu;
    }
    numerator=nu;
    denominator=de;
    for(int i=(abs(denominator)>=abs(numerator) ? abs(denominator):abs(numerator));i>0;i--)
    {
        if((abs(denominator)%i==0) && (abs(numerator)%i==0))
        {
            numerator=numerator/i;
            denominator=denominator/i;
            break;
        }
    }
}

Rational Rational::operator+(const Rational &t) const
{
    Rational sum;
    sum.numerator=(numerator*t.denominator)+(denominator*t.numerator);
    sum.denominator=denominator*t.denominator;
    for(int i=(abs(sum.denominator)>=abs(sum.numerator) ? abs(sum.denominator):abs(sum.numerator));i>0;i--)
    {
        if((abs(sum.denominator)%i==0) && (abs(sum.numerator)%i==0))
        {
            sum.numerator/=i;
            sum.denominator/=i;
            break;
        }
    }
    return sum;

}

Rational Rational::operator-(const Rational &t) const
{
    Rational diff;
    diff.numerator=(numerator*t.denominator)-(denominator*t.numerator);
    diff.denominator=denominator*t.denominator;
    for(int i=(abs(diff.denominator)>=abs(diff.numerator) ? abs(diff.denominator):abs(diff.numerator));i>0;i--)
    {
        if((abs(diff.denominator)%i==0) && (abs(diff.numerator)%i==0))
        {
            diff.numerator/=i;
            diff.denominator/=i;
            break;
        }
    }
    return diff;
}

Rational Rational::operator*(const Rational &t) const
{
    Rational result;
    result.numerator=numerator*t.numerator;
    result.denominator=denominator*t.denominator;
    for(int i=(abs(result.denominator)>=abs(result.numerator) ? abs(result.denominator):abs(result.numerator));i>0;i--)
    {
        if((abs(result.denominator)%i==0) && (abs(result.numerator)%i==0))
        {
            result.numerator/=i;
            result.denominator/=i;
            break;
        }
    }
    return result;
}

Rational Rational::operator/(const Rational &t) const
{
    Rational result1;
    result1.numerator=numerator*t.denominator;
    result1.denominator=denominator*t.numerator;
    for(int i=(abs(result1.denominator)>=abs(result1.numerator) ? abs(result1.denominator):abs(result1.numerator));i>0;i--)
    {
        if((abs(result1.denominator)%i==0) && (abs(result1.numerator)%i==0))
        {
            result1.numerator/=i;
            result1.denominator/=i;
            break;
        }
    }
    return result1;
}

void Rational::Show1() const
{
    cout<<numerator<<"/"<<denominator<<endl;
}

void Rational::Show2() const
{
    cout<<setprecision(4)<<numerator/denominator<<endl;
}

bool Rational::operator >(const Rational &t) const
{
    if((numerator/denominator)>(t.numerator/t.denominator))
    {
        return true;
    }
    else  return false;
}

bool Rational::operator >=(const Rational &t) const
{
    if((numerator/denominator)>=(t.numerator/t.denominator))
    {
        return true;
    }
    else  return false;
}

bool Rational::operator <(const Rational &t) const
{
    if((numerator/denominator)<(t.numerator/t.denominator))
    {
        return true;
    }
    else  return false;
}

bool Rational::operator <=(const Rational &t) const
{
    if((numerator/denominator)<=(t.numerator/t.denominator))
    {
        return true;
    }
    else  return false;
}

bool Rational::operator ==(const Rational &t) const
{
    if((numerator/denominator)==(t.numerator/t.denominator))
    {
        return true;
    }
    else  return false;
}

bool Rational::operator !=(const Rational &t) const
{
    if((numerator/denominator)!=(t.numerator/t.denominator))
    {
        return true;
    }
    else  return false;
}

ostream& operator << (ostream& output,Rational& c)
{
    if(c.denominator==1)
    {
        output<<c.numerator;
        return output;
    }
    output<<c.numerator<<"/"<<c.denominator;
    return output;
}


int main()
{        
    int firstN,firstD,secondN,secondD;  

    cin>>firstN;        
    cin>>firstD;         
    cin>>secondN;         
    cin>>secondD;

    Rational c(firstN,firstD),d(secondN,secondD),x;    
    cout<<c;    
    cout << " + " ;    
    cout<<d;    
    cout << " = ";    
    x = c + d; // test overloaded operators + and =    
    cout<<x;   

    cout << '\n';    
    cout<<c;    
    cout << " - " ;    
    cout<<d;    
    cout << " = ";    
    x = c - d; // test overloaded operators - and =    
    cout<<x;    

    cout << '\n';    
    cout<<c;    
    cout << " * " ;    
    cout<<d;    
    cout << " = ";    
    x = c * d; // test overloaded operators * and =    
    cout<<x;    

    cout << '\n';    
    cout<<c;    
    cout << " / " ;    
    cout<<d;    
    cout << " = ";    
    x = c / d; // test overloaded operators / and =    
    cout<<x;

    cout << '\n';    
    cout<<c;    
    cout << " is:\n";    
    
    // test overloaded greater than operator    
    cout << ( ( c > d ) ? "  > " : "  <= " );    
    cout<<d;    
    cout << " according to the overloaded > operator\n";  

    // test overloaded less than operator    
    cout << ( ( c < d ) ? "  < " : "  >= " );    
    cout<<d;    
    cout << " according to the overloaded < operator\n"; 

    // test overloaded greater than or equal to opera-tor    
    cout << ( ( c >= d ) ? "  >= " : "  < " );    
    cout<<d;    
    cout << " according to the overloaded >= operator\n";  

    // test overloaded less than or equal to operator    
    cout << ( ( c <= d ) ? "  <= " : "  > " );    
    cout<<d;    
    cout << " according to the overloaded <= operator\n";    

    // test overloaded equality operator    
    cout << ( ( c == d ) ? "  == " : "  != " );    
    cout<<d;
    cout << " according to the overloaded == operator\n";    

    // test overloaded inequality operator    
    cout << ( ( c != d ) ? "  != " : "  == " );    
    cout<<d;    
    cout << " according to the overloaded != operator" << endl;    
    return 0;
    } // end main