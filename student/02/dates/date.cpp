#include "date.hh"
#include <iomanip>
#include <sstream>
#include <tuple>
//TODO: Implement other functions here
// Obvious getter methods
using namespace std;
// Constructor taking three ints as parameters.
Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

// Destructor
Date::~Date(){}

int Date::getYear() const{
    return year_;
}
int Date::getMonth() const{
    return month_;
}
int Date::getDay() const{
    return day_;
}

// Returns the date in the format dd.mm.yyyy
string Date::toString() const{
    ostringstream oss;
    oss << day_ << "." << month_ << "." << year_;
    return oss.str();
}

// Returns the date in the format yyyy-mm-dd
string Date::toIsoFormat() const{
    ostringstream oss;
    oss << setw(4) << setfill('0')<< year_<< "-"
        << setw(2) << setfill('0')<< month_<< "-"
        << setw(2) << setfill('0')<< day_;
    return oss.str();
}

// Comparison methods
bool Date::operator<(const Date& other) const{
    return tie(year_,month_,day_) < tie(other.year_,other.month_,other.day_);
}
bool Date::operator==(const Date& other) const{
    return year_ == other.year_ and month_ == other.month_ and day_ == other.day_;
}


// Checks the legality of the date.
// The year must be in the interval [FIRST_YEAR..LAST_YEAR], the month must
// be in the interval [1..12], the day must be greater or equal to 1 and
// less or equal to the elements in the MONTH_SIZES array, and also leap
// years are taken into account.
bool Date::isLegal() const {
    if (year_ < FIRST_YEAR or year_ > LAST_YEAR or month_ < 1 or month_ > 12)
        return false;

    int max_days = MONTH_SIZES[month_ - 1];
    if (month_ == 2 and isLeapYear())
        max_days = 29;

    return day_ >= 1 and day_ <= max_days;
}



bool Date::isLeapYear() const
{
    return (year_ % 4 == 0) and ((year_ % 100 != 0) or (year_ % 400 == 0));
}

