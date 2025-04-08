#include "date.hh"
#include "dateexception.hh"
#include <sstream>
#include <iomanip>

void Date::throwIllegalDate(int day, int month, int year) const {
    ostringstream oss;
    oss << "Illegal date " << setfill('0') << setw(2) << day << "."
        << setfill('0') << setw(2) << month << "." << year;
    string message = oss.str();
    const char* c_message = message.c_str();
    throw DateException(c_message);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date::Date(int year, int month, int day) {
    if (year < 1000 || year > 9999) {
        throwIllegalDate(day, month, year);
    }
    if (month < 1 || month > 12) {
        throwIllegalDate(day, month, year);
    }
    if (day < 1 || day > 31) {
        throwIllegalDate(day, month, year);
    }
    if (month == 2) {
        if (isLeapYear(year) && day > 29) {
            throwIllegalDate(day, month, year);
        }
        if (!isLeapYear(year) && day > 28) {
            throwIllegalDate(day, month, year);
        }
    }
}

Date::~Date(){}

int Date::getYear() const
{
    return year_;
}

int Date::getMonth() const
{
    return month_;
}

int Date::getDay() const
{
    return day_;
}

string Date::toString() const
{
    ostringstream oss;
    oss << setfill('0') << setw(2) << day_ << "."
        << setfill('0') << setw(2) << month_ << "." << year_;
    return oss.str();
}
