#include "Classroom.h"
#include "BigClassroom.h"
#include "SmallClassroom.h"
#include "ReadFromFile.h"

Classroom::Classroom()
{
    BigClassroom b;
    SmallClassroom s;
    ReadFromFile r;
    vector<vector<std::string>> classNumber;
    classNumber= r.read_record("clasroom.csv");

    for(int i=0; i<classNumber.size(); i++){
            if(classNumber[i][0]=="bigClass")
                b.setNumberOfBig(stoi(classNumber[i][1])) ;
            else if(classNumber[i][0]=="smallClass")
                s.setNumberOfSmall(stoi(classNumber[i][1])) ;
   }
}
Classroom::~Classroom()
{
    //dtor
}
