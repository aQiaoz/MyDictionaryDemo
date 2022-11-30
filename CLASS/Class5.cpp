//常对象  const
#include <iostream>
#include <cstring>
using namespace std;

#ifndef DATE_H
#define DATE_H
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Date 
{
    public:
      Date( int = 1, int = 1, int = 1900 ); 
      void print()  const;
      ~Date(); 
    private:
      int month;
      int day; 
      int year; 
      int checkDay( int )  const;
}; 
#endif


class Employee
{
    public:
      Employee( const char * const, const char * const,
         const Date &, const Date & );
      void print() const;
      ~Employee(); 
    private:
      char firstName[ 25 ];
      char lastName[ 25 ];
      const Date birthDate;
    const Date hireDate; 
}; 
#endif


Employee::Employee( const char * const first, const char * const last,
     const Date &dateOfBirth, const Date &dateOfHire )
     : birthDate( dateOfBirth ), // initialize birthDate
       hireDate( dateOfHire ) // initialize hireDate
{
    int length = strlen( first );
    length = ( length < 25 ? length : 24 );
    strncpy( firstName, first, length );
    firstName[ length ] = '\0';
    
    length = strlen( last );
    length = ( length < 25 ? length : 24 );
    strncpy( lastName, last, length );
    lastName[ length ] = '\0';
    cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}
void Employee::print() const
{
    cout << lastName << ", " << firstName << "  Hired: ";
      hireDate.print();
    cout << "  Birthday: ";
    birthDate.print();
    cout << endl;
}
Employee::~Employee()
{
    cout<< "Employee object destructor:" << lastName << ", " << firstName <<
     endl;
}

int main()
{
    Date birth( 7, 24, 1949 );
    Date hire( 3, 12, 1988 );
    Employee manager( "Bob", "Blue", birth, hire );

    cout << endl;
    manager.print();
    
    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff( 14, 35, 1994 ); 
    cout << endl;
    return 0;
}

/*
const int *pi;     const Student *ps;
int *const pi;     Student *const ps;
*/


//静态成员

