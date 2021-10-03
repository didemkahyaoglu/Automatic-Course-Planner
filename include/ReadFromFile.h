#ifndef READFROMFILE_H
#define READFROMFILE_H
#include <vector>
#include <string>
using namespace std;

class ReadFromFile
{
    public:
        ReadFromFile();
        vector<vector<std::string>> read_record(string);
        virtual ~ReadFromFile();

    protected:

    private:
};

#endif // READFROMFILE_H
