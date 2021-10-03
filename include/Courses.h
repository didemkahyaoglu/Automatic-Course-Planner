#ifndef COURSES_H
#define COURSES_H
#include <string>
using namespace std;

class Courses
{
    public:

    Courses(string, string, string, string,string, string, string);

    string getCourseCode() const;
    string getCourseName() const;
    string getSemesterYear() const;
    string getCredit() const;
    string getCompulsoryOrElective() const;
    string getDepartmentOrService() const;
    string getTeacherName() const;

    void setCourseCode(const string &value);
    void setCourseName(const string &value);
    void setSemesterYear(const string &value);
    void setCredit(const string &value);
    void setCompulsoryOrElective(const string &value);
    void setDepartmentOrService(const string &value);
    void setTeacherName(const string &value);

    bool isAssigned=false;

    Courses();
    virtual ~Courses();

    protected:

    private:

    string courseCode;
    string courseName;
    string semesterYear;
    string credit;
    string compulsoryOrElective;
    string departmentOrService;
    string teacherName;
};

#endif // COURSES_H
