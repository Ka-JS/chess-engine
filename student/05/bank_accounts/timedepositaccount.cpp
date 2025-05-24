#include "timedepositaccount.hh"
#include <iostream>

TimeDepositAccount::TimeDepositAccount(const string& owner) : Account(owner)
{
}

TimeDepositAccount::~TimeDepositAccount()
{
}

bool TimeDepositAccount::take_money(double amount)
{
    if (time_deposit_ > 0) {
        std::cout << "ERROR! Cannot take money: deposit time has not expired" << std::endl;
        return false;
    }

    return  Account::take_money(amount);
}
void TimeDepositAccount::spend_time(int time)
{
    time_deposit_ -= time;
}


void TimeDepositAccount::print() const
{
    Account::print();
    cout << "  ::: Days left : " << time_deposit_ << endl;
}

void TimeDepositAccount::set_times(int timeDeposit)
{
    time_deposit_ = timeDeposit * 365;
}

int TimeDepositAccount::getTimes() const
{
    return time_deposit_;
}
