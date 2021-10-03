#ifndef BIGCLASSROOM_H
#define BIGCLASSROOM_H

class BigClassroom
{
    public:

    BigClassroom(int);
    BigClassroom();
    int getNumberOfBig() const;
    void setNumberOfBig(const int &value);

    virtual ~BigClassroom();

    protected:

    private:
        int b_capacity;
        int numberOfBig;

};
#endif // BIGCLASSROOM_H
