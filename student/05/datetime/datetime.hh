#ifndef DATETIME_HH
#define DATETIME_HH
#include "date.hh"

class DateTime : public Date
{
public:
    DateTime(int year, int month, int day, int hour, int minute, int second);
    virtual ~DateTime();

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    virtual string toString() const;

private:
    int hour_;
    int minute_;
    int second_;
    void throwIllegalTime(int hour, int minute, int second) const;
};

#endif // DATETIME_HH
