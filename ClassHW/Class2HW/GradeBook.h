#include <string.h>
using namespace std;
class GradeBook
{
    public:
        GradeBook(string name,string teacher);
        void setCourseName(string name);
        string getCourseName();
        void setInstructorName(string teacher);
        string getInstructorName();
        void displayMessage();

    private:
        string courseName,teachername;
};