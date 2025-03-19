#ifndef DATEPERIOD_HH
#define DATEPERIOD_HH
#include "date.hh"
#include <string>

using namespace std;

class DatePeriod
{
public:
    DatePeriod(const Date& d1, const Date& d2);

    virtual ~DatePeriod();

    string getStart() const;
    string getEnd() const;
    unsigned int getDiff() const;

private:
    Date start_;
    Date end_;
};

#endif // DATEPERIOD_HH
