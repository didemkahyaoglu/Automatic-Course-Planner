#include "Courses.h"
#include <string>

Courses::Courses()
{
    //ctor
}
Courses::Courses(string courseCode, string courseName, string semesterYear, string credit,
                 string compulsoryOrElective, string departmentOrService, string teacherName)
{
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->semesterYear = semesterYear;
    this->credit = credit;
    this->compulsoryOrElective = compulsoryOrElective;
    this->departmentOrService = departmentOrService;
    this->teacherName = teacherName;

}

string Courses::getCourseCode() const
{
    return courseCode;
}

void Courses::setCourseCode(const string &value)
{
    courseCode = value;
}

string Courses::getCourseName() const
{
    return courseName;
}

void Courses::setCourseName(const string &value)
{
    courseName = value;
}

string Courses::getSemesterYear() const
{
    return semesterYear;
}

void Courses::setSemesterYear(const string &value)
{
    semesterYear = value;
}

string Courses::getCredit() const
{
    return credit;
}

void Courses::setCredit(const string &value)
{
    credit = value;
}

string Courses::getCompulsoryOrElective() const
{
    return compulsoryOrElective;
}

void Courses::setCompulsoryOrElective(const string &value)
{
    compulsoryOrElective = value;
}

string Courses::getDepartmentOrService() const
{
    return departmentOrService;
}

void Courses::setDepartmentOrService(const string &value)
{
    departmentOrService = value;
}

string Courses::getTeacherName() const
{
    return teacherName;
}

void Courses::setTeacherName(const string &value)
{
    teacherName = value;
}

Courses::~Courses()
{
    //dtor
}
