#include <iostream>
#include <iomanip>
using namespace std;
class Person
{
    public:
        Person(string nam,int ag,char sex,string i):name(nam),age(ag),gender(sex),id(i){}
        void show()
        {
            cout<<"Name:"<<name<<" Age:"<<age<<" Gender:"<<gender<<" Id:"<<id<<endl;
        }
    protected:
        string name;
        int age;
        char gender;
        string id;
};
class Doctor:virtual public Person
{
    public:
        Doctor(string nam,int ag,char sex,string i,string spe,float fee):Person(nam,ag,sex,i)
        {
            specialty=spe;    visitFee=fee;
        }
        void show()
        {
            cout<<"** Docter:\n";
            Person::show();
            cout<<"Specialty:"<<specialty<<" VisitFee:"<<visitFee<<endl;
        }
        float getvisitFee()
        {
            return visitFee;
        }
    protected:
        string specialty;
        float visitFee;  
};
class Patient: virtual public Person
{
    public:
        Patient(string nam,int ag,char sex,string i,float dfee,Doctor & example):Person(nam,ag,sex,i)
        {
            drugFee=dfee;
            payment=dfee+example.getvisitFee();
        }
        void show()
        {
            cout<<"** Patient:\n";
            Person::show();
        }
        void showpayment()
        {
            cout<<"\nPayment:"<<payment<<endl;
        }
        float getpayment()
        {
            return payment;
        }
        protected:
            float drugFee;
            float payment;
};
class Billing
{
    public:
        Billing(const Patient & pat,const Doctor & doc):patient(pat),doctor(doc)
        { total_income+=patient.getpayment(); }
        void show()
        {
            cout<<"**** Billing information ****"<<endl<<endl;
            patient.show();
            cout<<endl;
            doctor.show();
            cout<<endl;
            patient.showpayment();
            cout<<endl;
        }
        static float getTotalIncome() 
        {
            return total_income;
        }
    private:
        Patient patient;
        Doctor doctor;
        static float total_income;
};
float Billing::total_income=0;
int main()
{    
    Doctor a("Wangli",36,'m',"74869304","pediatrician",100);    
    Doctor b("zhanghai",60,'f',"23457576","obstetrician",50);    
    Patient p1("xiaoming",8,'m',"89437584",298.8,a);    
    Patient p2("sun",9,'f',"34345",78.9,b);    
    Billing bill1(p1,a);
    Billing bill2(p2,b);    
    bill1.show();    
    bill2.show();    
    cout<<fixed<<setprecision(2);    
    cout<<"Total income of Clinic:"
    <<Billing::getTotalIncome()<<endl;    
    return 0;
}