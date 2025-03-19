#include "dateperiod.hh"
#include <cmath>

using namespace std;

DatePeriod::DatePeriod(const Date& d1, const Date& d2) : start_(d1), end_(d2) {}

DatePeriod::~DatePeriod() {}


string DatePeriod::getStart() const{
    return start_.toIsoFormat();
}


string DatePeriod::getEnd() const{
    return end_.toIsoFormat();
}


unsigned int DatePeriod::getDiff() const{
    Date temp = start_;
    unsigned int count = 0;

    while (temp<end_){
        if (temp.getDay() < MONTH_SIZES[temp.getMonth()-1] or
           (temp.getMonth() == 2 and temp.isLeapYear() and temp.getDay() < 29)){
            temp = Date(temp.getYear(), temp.getMonth(), temp.getDay()+1);

        }else if(temp.getMonth() < 12){
            temp = Date(temp.getYear(), temp.getMonth() +1, 1);

        }else{
            temp = Date(temp.getYear() +1,1,1);
        }
        count++;
    }
    return count;
}

