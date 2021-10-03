#ifndef SMALLCLASSROOM_H
#define SMALLCLASSROOM_H

class SmallClassroom
{
    public:

    SmallClassroom(int);
    SmallClassroom();
    int getNumberOfSmall() const;
    void setNumberOfSmall(const int &value);

    virtual ~SmallClassroom();

    protected:

    private:
        int s_capacity;
        int numberOfSmall;
};

#endif // SMALLCLASSROOM_H
