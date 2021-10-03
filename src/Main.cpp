#include "Main.h"
#include "ReadFromFile.h"
#include "Courses.h"
#include <iostream>
#include <vector>
#include "Days.h"
#include "ScheduleWriter.h"


using namespace std;

void fillVectorOfCourse(vector<Courses>&);
void fillVectorOfScheduleWithService( vector<Days>&,vector<Courses>&);
int getNumberOfDay(string);
void fillVectorOfScheduleWithDepartment( vector<Days>&, vector<Courses>&, vector<vector<string>>&);
bool isSameTimeSlotMorningForClass(Days& dayValue, Courses& courseValue);
bool isSameTimeSlotAfternoonForClass(Days& dayValue, Courses& courseValue);
bool isBusyOrNotCourseMorning(Courses& courseValue, int dayIndex, vector<vector<string>>& busyTimeSlot);
bool isBusyOrNotCourseAfternoon(Courses& courseValue, int dayIndex, vector<vector<string>>& busyTimeSlot);


int main(){

    vector<Courses> myCourse;
    fillVectorOfCourse(myCourse);
    ReadFromFile r;

    vector<Days> schedule(5);
    schedule[0].dayName = "Monday";
    schedule[1].dayName = "Tuesday";
    schedule[2].dayName = "Wednesday";
    schedule[3].dayName = "Thursday";
    schedule[4].dayName = "Friday";
    vector<vector<string>> busyTimeSlot = r.read_record("busy.csv");
    fillVectorOfScheduleWithService(schedule,myCourse);
    fillVectorOfScheduleWithDepartment(schedule, myCourse, busyTimeSlot);

    ScheduleWriter sch;
    sch.writeFile(schedule);

}

int getNumberOfDay(string dayValue){
    if(dayValue=="Monday") return 0;
    if(dayValue=="Tuesday") return 1;
    if(dayValue=="Wednesday") return 2;
    if(dayValue=="Thursday") return 3;
    if(dayValue=="Friday") return 4;
    else return -1;
}


void fillVectorOfScheduleWithDepartment( vector<Days>& schedule, vector<Courses>& myCourse, vector<vector<string>>& busyTimeSlot){

    for (int dayIndex = 0; dayIndex<5; dayIndex++) {

            for (int i=0; i<myCourse.size(); i++) {
                if(myCourse[i].isAssigned==true){
                continue;
            }

            bool isElective = myCourse[i].getCompulsoryOrElective() == "E" ? true : false;

            bool isSameClassMorningForNow = isSameTimeSlotMorningForClass(schedule[dayIndex], myCourse[i]);
            bool isSameClassAfternoonForNow = isSameTimeSlotAfternoonForClass(schedule[dayIndex], myCourse[i]);

            bool isBusyOrNotCourseMorningNow = isBusyOrNotCourseMorning(myCourse[i], dayIndex, busyTimeSlot);
            bool isBusyOrNotCourseAfternoonNow = isBusyOrNotCourseAfternoon(myCourse[i], dayIndex, busyTimeSlot);

            if ( isSameClassMorningForNow == true && isSameClassAfternoonForNow == true )
                continue;

            if ( isBusyOrNotCourseMorningNow == true && isBusyOrNotCourseAfternoonNow == true )
                continue;

            if ( isSameClassMorningForNow == false && isBusyOrNotCourseMorningNow == false )
            {
                if ( isElective )
                {
                    if(schedule[dayIndex].morning.smallClass1 == false){
                    schedule[dayIndex].morning.smallClass1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.smallClass1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.smallClass2 == false){
                    schedule[dayIndex].morning.smallClass2= true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.smallClass2Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClass1 == false){
                    schedule[dayIndex].morning.bigClass1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClass1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClass2 == false){
                    schedule[dayIndex].morning.bigClass2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClass2Course = myCourse[i];
                    }

                }
                else { //Compulsory
                    if(schedule[dayIndex].morning.bigClass1 == false){
                    schedule[dayIndex].morning.bigClass1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClass1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClass2 == false){
                    schedule[dayIndex].morning.bigClass2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClass2Course = myCourse[i];
                    }
                }
            }
            else if ( isSameClassAfternoonForNow == false && isBusyOrNotCourseAfternoonNow == false  )
            {
                if ( isElective )
                {
                    if(schedule[dayIndex].afternoon.smallClass1 == false){
                    schedule[dayIndex].afternoon.smallClass1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.smallClass1Course = myCourse[i];

                    }
                    else if(schedule[dayIndex].afternoon.smallClass2 == false){
                    schedule[dayIndex].afternoon.smallClass2= true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.smallClass2Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClass1 == false){
                    schedule[dayIndex].afternoon.bigClass1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClass1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClass2 == false){
                    schedule[dayIndex].afternoon.bigClass2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClass2Course = myCourse[i];
                    }

                }
                else { //compulsory
                    if(schedule[dayIndex].afternoon.bigClass1 == false){
                    schedule[dayIndex].afternoon.bigClass1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClass1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClass2 == false){
                    schedule[dayIndex].afternoon.bigClass2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClass2Course = myCourse[i];
                    }
                }
            }

        }

    }
}

void fillVectorOfScheduleWithService( vector<Days>& schedule, vector<Courses>& myCourse){

    ReadFromFile readcsv;
    vector<vector<string>> serviceCourse = readcsv.read_record("service.csv");

    for (int i=0; i<serviceCourse.size(); i++) {
         int courseIndex=-1;
        for (int j = 0; j < myCourse.size(); ++j) {
            if (myCourse[j].getCourseCode()== serviceCourse[i][0]) {
            courseIndex=j;
            break;
            }
        }

        int dayIndex = getNumberOfDay(serviceCourse[i][1]);
        bool isElective = myCourse[courseIndex].getCompulsoryOrElective() == "E" ? true : false;

        if( serviceCourse[i][2] == "Afternoon" )
        {
            if ( isElective )
            {
                if(schedule[dayIndex].afternoon.smallClass1 == false){
                schedule[dayIndex].afternoon.smallClass1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.smallClass1Course = myCourse[courseIndex];

                }
                else if(schedule[dayIndex].afternoon.smallClass2 == false){
                schedule[dayIndex].afternoon.smallClass2= true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.smallClass2Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClass1 == false){
                schedule[dayIndex].afternoon.bigClass1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClass1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClass2 == false){
                schedule[dayIndex].afternoon.bigClass2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClass2Course = myCourse[courseIndex];
                }

            }
            else { //compulsory
                if(schedule[dayIndex].afternoon.bigClass1 == false){
                schedule[dayIndex].afternoon.bigClass1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClass1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClass2 == false){
                schedule[dayIndex].afternoon.bigClass2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClass2Course = myCourse[courseIndex];
                }
            }
        }
        else if(serviceCourse[i][2] == "Morning")
        {
            if ( isElective )
            {
                if(schedule[dayIndex].morning.smallClass1 == false){
                schedule[dayIndex].morning.smallClass1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.smallClass1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.smallClass2 == false){
                schedule[dayIndex].morning.smallClass2= true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.smallClass2Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClass1 == false){
                schedule[dayIndex].morning.bigClass1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClass1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClass2 == false){
                schedule[dayIndex].morning.bigClass2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClass2Course = myCourse[courseIndex];
                }

            }
            else { //Compulsory
                if(schedule[dayIndex].morning.bigClass1 == false){
                schedule[dayIndex].morning.bigClass1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClass1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClass2 == false){
                schedule[dayIndex].morning.bigClass2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClass2Course = myCourse[courseIndex];
                }
            }

        }
    }



}

bool isSameTimeSlotMorningForClass(Days& dayValue, Courses& courseValue)
{
    bool returnedValue = false;

    if ( dayValue.morning.bigClass1 == true &&
         dayValue.morning.bigClass1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.bigClass2 == true &&
         dayValue.morning.bigClass2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.smallClass1 == true &&
         dayValue.morning.smallClass1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.smallClass2 == true &&
         dayValue.morning.smallClass2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    return returnedValue;

}

bool isSameTimeSlotAfternoonForClass(Days& dayValue, Courses& courseValue)
{
    bool returnedValue = false;

    if ( dayValue.afternoon.bigClass1 == true &&
         dayValue.afternoon.bigClass1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.bigClass2 == true &&
         dayValue.afternoon.bigClass2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.smallClass1 == true &&
         dayValue.afternoon.smallClass1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.smallClass2 == true &&
         dayValue.afternoon.smallClass2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    return returnedValue;
}

bool isBusyOrNotCourseMorning(Courses& courseValue, int dayIndex, vector<vector<string>>& busyTimeSlot)
{
    bool returnedValue = false;
    for ( int i = 0; i < busyTimeSlot.size() ; ++i )
    {
        int busyTimeSlotDayIndex = getNumberOfDay(busyTimeSlot[i][1]);
        if ( courseValue.getCourseCode() == busyTimeSlot[i][0] && dayIndex == busyTimeSlotDayIndex &&
               busyTimeSlot[i][2] == "Morning" )
        {
            returnedValue = true;
            break;
        }
    }

    return returnedValue;

}

bool isBusyOrNotCourseAfternoon(Courses& courseValue, int dayIndex, vector<vector<string>>& busyTimeSlot)
{
    bool returnedValue = false;
    for ( int i = 0; i < busyTimeSlot.size() ; ++i )
    {
        int busyTimeSlotDayIndex = getNumberOfDay(busyTimeSlot[i][1]);
        if ( courseValue.getCourseCode() == busyTimeSlot[i][0] && dayIndex == busyTimeSlotDayIndex &&
               busyTimeSlot[i][2] == "Afternoon" )
        {
            returnedValue = true;
            break;
        }
    }

    return returnedValue;
}

void fillVectorOfCourse(vector<Courses>& newMyCourse){
      ReadFromFile readcsv;
      vector<vector<string>> course = readcsv.read_record("courses.csv");
      int z=0;
      for (int k=0; k<course.size(); k++) {
          Courses newCourse(course[k][z], course[k][z+1],
                 course[k][z+2], course[k][z+3],
                 course[k][z+4], course[k][z+5],
                  course[k][z+6]);

          newMyCourse.push_back(newCourse);
      }

}

