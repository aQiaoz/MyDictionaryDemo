#include <iostream>
#include <string.h>
using namespace std;
#include "GradeBook.h"  

GradeBook::GradeBook( string name,string teacher )
{   
    setCourseName( name );
    setInstructorName( teacher );
}
void GradeBook::setCourseName( string name )
{   
    courseName = name;
}
string GradeBook::getCourseName()
{
    return courseName;
}
void GradeBook::setInstructorName( string teacher )
{ 
     teachername=teacher;
}
string GradeBook::getInstructorName()
{
    return teachername;
}
void GradeBook::displayMessage()
{
    cout << "Welcome to the grade book for\n" <<
    getCourseName() << "!" << endl;
    cout<<"This course is presented by:"<<
    getInstructorName()<<endl;
}


int main()
{   // create a GradeBook object; pass a course nameand instructor name   
    GradeBook gradeBook("CS101 Introduction to C++ Programming", "Professor Smith" );   
    // display initial value of instructorName of GradeBook object
        cout << "gradeBook instructor name is: "<<
         gradeBook.getInstructorName() << "\n";
         // modify the instructorName using set function
        gradeBook.setInstructorName( "Assistant Professor Bates" );   
        
        // display new value of instructorName
        cout << "new gradeBook instructor name is: "
             << gradeBook.getInstructorName() << "\n";   
             // display welcome message and instructor's name
        gradeBook.displayMessage();
    return 0; 
    // indicate successful termination} // end main
}

/*    int main()
{
    string nameOfCourse,nameOfteacher;
    GradeBook gradeBook();
    cout << "\nPlease enter the course name:" << endl;
    getline( cin, nameOfCourse );
    cout << "\nPlease enter the teacher name:" << endl;
    getline( cin, nameOfteacher );
   
    gradeBook(nameOfCourse,nameOfteacher);
    cout<<endl;
    gradeBook.displayMessage();

    return 0; 
}
*/

