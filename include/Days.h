#ifndef DAYS_H
#define DAYS_H
#include "TimeSlot.h"
#include <string>

class Days
{
    public:
        Days();
        TimeSlot morning;
        TimeSlot afternoon;
        string dayName;

        virtual ~Days();

    protected:

    private:
};

#endif // DAYS_H
