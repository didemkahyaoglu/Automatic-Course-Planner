#include "ScheduleWriter.h"
#include "Days.h"
#include <fstream>
#include <iostream>

ScheduleWriter::ScheduleWriter()
{
    //ctor
}
void ScheduleWriter::writeFile(const vector<Days> schedule)
{
        ofstream out;
        out.open("write.txt");

            for (int i=0; i<schedule.size(); i++) {

            if ( schedule[i].morning.bigClass1 == true )
                out << schedule[i].dayName << " Morning bigClass1 " << schedule[i].morning.bigClass1Course.getCourseCode()<<endl;

            if ( schedule[i].morning.bigClass2 == true )
                out<<schedule[i].dayName << " Morning bigClass2 " << schedule[i].morning.bigClass2Course.getCourseCode()<<endl;

            if ( schedule[i].morning.smallClass1 == true )
                out<<schedule[i].dayName << " Morning smallClass1 " << schedule[i].morning.smallClass1Course.getCourseCode()<<endl;

            if ( schedule[i].morning.smallClass2 == true )
                out<<schedule[i].dayName << " Morning smallClass2 " << schedule[i].morning.smallClass2Course.getCourseCode()<<endl;

            if ( schedule[i].afternoon.bigClass1 == true )
                out<<schedule[i].dayName << " Afternoon bigClass1 " << schedule[i].afternoon.bigClass1Course.getCourseCode() <<endl;

            if ( schedule[i].afternoon.bigClass2 == true )
                out<<schedule[i].dayName << " Afternoon bigClass2 " << schedule[i].afternoon.bigClass2Course.getCourseCode()<<endl;

            if ( schedule[i].afternoon.smallClass1 == true )
                out<<schedule[i].dayName << " Afternoon smallClass1 " << schedule[i].afternoon.smallClass1Course.getCourseCode()<<endl;

            if ( schedule[i].afternoon.smallClass2 == true )
                out<<schedule[i].dayName << " Afternoon smallClass2 " << schedule[i].afternoon.smallClass2Course.getCourseCode()<<endl;
        }

}
ScheduleWriter::~ScheduleWriter()
{
    //dtor
}
