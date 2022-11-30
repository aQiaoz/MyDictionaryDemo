#include <iostream>
#include <iomanip>
using namespace std;
class First_name
{
    public:
        void setFirstName(string firstname)
        {FirstName=firstname;}
        string getFirstName()
        {return FirstName;}
    private:
        string FirstName;
};
class Last_name
{
    public:
        void setLastName(string lastname)
        {LastName=lastname;}
        string getLastName()
        {return LastName;}
    private:
        string LastName;
};
class Security_Number
{
    public:
        void setSocialSecurityNumber(string socialSecurityNumber)
        {SocialSecurityNumber=socialSecurityNumber;}
        string getSocialSecurityNumber()
        {return SocialSecurityNumber;}
    private:
        string SocialSecurityNumber;
        
};
class Gross_Sales
{
    public:
        void setGrossSales(double grosssales)
        {GrossSales=grosssales;}
        double getGrossSales()
        {return GrossSales;}
    private:
        double GrossSales;
};
class Commission_Rate
{
    public:
        void setCommissionRate(double commissionrate)
        {CommissionRate=commissionrate;}
        double getCommissionRate()
        {return CommissionRate;}
    private:
        double CommissionRate;
};
class Base_Salary
{
    public:
        void setBaseSalary(double basesalary)
        {BaseSalary=basesalary;}
        double getBaseSalary()
        {return BaseSalary;}
    private:
        double BaseSalary;
};
class Earnings
{
    public:
        void setBaseSalary(double earning)
        {Earning=earning;}
        double earnings()
        {return Earning;}
    private:
        double Earning;
};
class BasePlusCommissionEmployee
{
    public:
        BasePlusCommissionEmployee(string First_name,string Last_name,string Security_Number,double GrossSales,double CommissionRate,double BaseSalary)
        { m_First_name.setFirstName(First_name);
          m_Last_Name.setLastName(Last_name);
          m_Security_Number.setSocialSecurityNumber(Security_Number);
          m_Gross_Sales.setGrossSales(GrossSales);
          m_Commission_Rate.setCommissionRate(CommissionRate);
          m_Base_Salary.setBaseSalary(BaseSalary);
        }
        string getFirstName()
        {
            string f;
            f=m_First_name.getFirstName();
            return f;
        }
        string getLastName()
        {
            string l;
            l=m_Last_Name.getLastName();
            return l;
        }
        string getSocialSecurityNumber()
        {
            string s;
            s=m_Security_Number.getSocialSecurityNumber();
            return s;
        }
        double getGrossSales()
        {
            double g;
            g=m_Gross_Sales.getGrossSales();
            return g;
        }
        double getCommissionRate()
        {
            double c;
            c=m_Commission_Rate.getCommissionRate();
            return c;
        }
        double getBaseSalary()
        {
            double b;
            b=m_Base_Salary.getBaseSalary();
            return b;}
        void setBaseSalary(double earning)
        {m_Earnings.setBaseSalary(earning);}
        double earnings()
        {
            double e;
            e=m_Earnings.earnings()+m_Gross_Sales.getGrossSales()*m_Commission_Rate.getCommissionRate();
            return e;
        }
        void print()
        {
            cout<<"\nbase-salaried commission employee: "<<m_First_name.getFirstName()<<" "<<m_Last_Name.getLastName()
            <<"\nsocial security number: "<<m_Security_Number.getSocialSecurityNumber()
            <<"\ngross sales: "<<m_Gross_Sales.getGrossSales()
            <<"\ncommission rate: "<<m_Commission_Rate.getCommissionRate()
            <<"\nbase salary: "<<m_Base_Salary.getBaseSalary()
            << endl;
        }

    private:
        First_name m_First_name;
        Last_name m_Last_Name;
        Security_Number m_Security_Number;
        Gross_Sales m_Gross_Sales;
        Commission_Rate m_Commission_Rate;
        Base_Salary m_Base_Salary;
        Earnings m_Earnings;
};

int main()
{    
    // instantiate BasePlusCommissionEmployee object    
    BasePlusCommissionEmployee employee( "Bob", "Lewis", "333-33-3333", 5000, .04, 300 );

    // set floating-point output formatting    
    cout << fixed << setprecision( 2 );    
     
    // get commission employee data    
    cout << "Employee information obtained by get functions: \n"    
    << "\nFirst name is " << employee.getFirstName()    
    << "\nLast name is " << employee.getLastName()    
    << "\nSocial security number is "    
    << employee.getSocialSecurityNumber()    
    << "\nGross sales is " << employee.getGrossSales()    
    << "\nCommission rate is " << employee.getCommissionRate()    
    << "\nBase salary is " << employee.getBaseSalary() 
    << endl;  

    employee.setBaseSalary( 1000 ); // set base salary    
    cout << "\nUpdated employee information output by print function: \n"    
    << endl;    
    employee.print(); // display the new employee information
    // display the employee's earnings    
    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;    
    return 0;
} // end main