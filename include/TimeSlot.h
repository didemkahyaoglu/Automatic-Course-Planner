#ifndef TIMESLOT_H
#define TIMESLOT_H
#include "Courses.h"


class TimeSlot
{
    public:
        TimeSlot();
        Courses bigClass1Course;
        Courses bigClass2Course;
        Courses smallClass1Course;
        Courses smallClass2Course;
        bool bigClass1=false; // Our default variable
        bool bigClass2=false;// Our default variable
        bool smallClass1=false;// Our default variable
        bool smallClass2=false; // Our default variable. An extra small class for part 2 of the project.
        virtual ~TimeSlot();

    protected:

    private:
};

#endif // TIMESLOT_H
