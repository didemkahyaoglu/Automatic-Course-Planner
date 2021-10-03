#ifndef SCHEDULEWRITER_H
#define SCHEDULEWRITER_H
#include <vector>
#include "Days.h"

using namespace std;
class ScheduleWriter
{
    public:
        ScheduleWriter();
        void writeFile(const vector<Days>);
        virtual ~ScheduleWriter();

    protected:

    private:
};

#endif // SCHEDULEWRITER_H

