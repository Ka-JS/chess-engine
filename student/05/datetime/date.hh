#ifndef DATE_HH
#define DATE_HH
#include <string>
using namespace std;

class Date
{
public:
    Date(int year, int month, int day);
    virtual ~Date();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    virtual string toString() const;
private:
    int year_;
    int month_;
    int day_;
    void throwIllegalDate(int day, int month, int year) const;
};

#endif // DATE_HH
