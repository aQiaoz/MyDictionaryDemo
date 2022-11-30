#include <iostream>
#include <iomanip>
using namespace std;
class Account
{
    public: Account(int=0,double=0 );// constructor sets attributes构造函数
        double getAvailableBalance()const;// returns available balance获取余额
        int getAccountNumber()const;// returns account number获取账号
        void credit(double);// adds an amount to the Account balance存款
        void debit(double amount );//取款
    private:
        int accountNumber;// account number账号
        double availableBalance;//余额
};
Account::Account(int n,double b )
{
    accountNumber=n;
    availableBalance=b;
}
double Account::getAvailableBalance() const
{
    return availableBalance;
}
int Account::getAccountNumber() const
{
    return accountNumber;
}
void Account::credit(double amount)
{
    availableBalance+=amount;
}
void Account::debit(double amount)
{
    availableBalance-=amount;
}



class BankDatabase
{
    public: BankDatabase(int arraysize);// constructor initializes accounts 
        ~BankDatabase();
        
        double getAvailableBalance(int accountNumber );//根据账号，返回余额
        void credit(int accountNumber,double amount );//向指定账号存入金额
        Account* getAccount(int accountNumber );//根据账号返回指向Account对象的指针，如果找不到账号，返回空指针。
        void debit(int userAccountNumber,double amount );
        void show();//显示所有账户信息
    private:
        Account*  accounts;//存储所有账户的起始地址
        int size; //数据库中账户总数
};// end class BankDatabase
BankDatabase::BankDatabase(int arraysize)
{
    size=arraysize;
    for(int i=0;i<size;i++)
    {
        ;
    }
}
BankDatabase::~BankDatabase()
{
    delete accounts;
    accounts = NULL;
}
double BankDatabase::getAvailableBalance(int accountNumber)
{
    return (getAccount(accountNumber)->getAvailableBalance());
}
void BankDatabase::credit(int accountNumber,double amount )
{
    getAccount(accountNumber)->credit(amount);
}
Account*BankDatabase::getAccount(int accountNumber)
{
    for(int i=0;i<size;i++)
    {
        if(accounts[i].Account::getAccountNumber()==accountNumber)
        {
            return (&accounts[i]);
        }
    }
    return 0;
}


class BalanceInquiry
{
    public: BalanceInquiry(int,BankDatabase& );// constructor
        void execute();// perform the transaction 输出账户的信息
        BankDatabase &getBankDatabase()const;
    private:
        int accountNumber;// indicates account involved要查询的账号
        BankDatabase &bankDatabase;// reference to the account info database数据库引用，注意数据成员为引用时的构造函数定义方式。
};// end class BalanceInquiry
BalanceInquiry::BalanceInquiry(int userAccountNumber, BankDatabase &m_db):bankDatabase(m_db)
{
    accountNumber=userAccountNumber;
}
BankDatabase &BalanceInquiry::getBankDatabase() const
{
    return bankDatabase;
}
void BalanceInquiry::execute()
{
    cout<<"账户信息:"<<endl;
    cout<<" -账号: "<< accountNumber<<endl;
    cout<<" -余额: "<<bankDatabase.getAvailableBalance(accountNumber)<<endl;
}


class Deposit
{
    public: Deposit(int, BankDatabase&);
        void execute();// perform the transaction
        BankDatabase &getBankDatabase()const;
    private:
        double amount;// amount to deposit 存款金额
        int accountNumber;// indicates account involved账号
        BankDatabase &bankDatabase;// reference to the account info database数据库引用
};// end class Deposit
Deposit::Deposit(int m_accountNumber, BankDatabase &m_bd):bankDatabase(m_bd)//存款
{
    accountNumber=m_accountNumber;
}
BankDatabase &Deposit::getBankDatabase() const
{
    return bankDatabase;
}
void Deposit::execute()
{
    cout << "请输入存款金额: ";
    cin >> amount;
    bankDatabase.credit(accountNumber, amount);
}



int main()
{    
    int numberofaccount,currentAccountNumber;//    
    cout<<"请输入账户总数:";    
    cin>>numberofaccount;    
    BankDatabase db(numberofaccount);// 

    cout<<"请输入要查询的账号:";    
    cin>>currentAccountNumber;    

    Deposit d(currentAccountNumber,db);    
    d.execute();  //为账号存钱    

    BalanceInquiry bInquiry(currentAccountNumber,db);    
    bInquiry.execute();  //查询账号余额
}
