#include "datetime.hh"
#include "dateexception.hh"
#include <sstream>
#include <iomanip>

void DateTime::throwIllegalTime(int hour, int minute, int second) const {
    ostringstream oss;
    oss << "Illegal time "
        << setfill('0') << setw(2) << hour << ":"
        << setfill('0') << setw(2) << minute << ":"
        << setfill('0') << setw(2) << second;
    string message = oss.str();
    const char* c_message = message.c_str();
    throw DateException(c_message);
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
        : Date(year, month, day){

    if (hour < 0 or hour > 23) {
        throwIllegalTime(hour, minute, second);
    }
    if (minute < 0 or minute > 59) {
        throwIllegalTime(hour, minute, second);
    }
    if (second < 0 or second > 59) {
        throwIllegalTime(hour, minute, second);
    }

    hour_ = hour;
    minute_ = minute;
    second_ = second;
}
DateTime::~DateTime() {}

int DateTime::getHour() const
{
    return hour_;
}
int DateTime::getMinute() const {
    return minute_;
}
int DateTime::getSecond() const {
    return second_;
}

string DateTime::toString() const {
    ostringstream oss;
    oss << Date::toString() << " "
        << setfill('0') << setw(2) << hour_ << ":"
        << setfill('0') << setw(2) << minute_ << ":"
        << setfill('0') << setw(2) << second_;
    return oss.str();
}
