#include "timedepositaccount.hh"

TimeDepositAccount::TimeDepositAccount(const string& owner): Account(owner)
{

}

TimeDepositAccount::~TimeDepositAccount()
{

}

bool TimeDepositAccount::take_money(double amount)
{
    if (days_left_ > 0){
        cout << "ERROR! Cannot take money: deposit time has not expired" << endl;
        return false;
    }
    if (balance_ >= amount){
        balance_ -= amount;
        return true;
    }
    return false;
}

void TimeDepositAccount::print() const
{
    Account::print();
    cout << "  ::: Days left : " << days_left_ << endl;
}

void TimeDepositAccount::set_times(int years)
{
    time_deposit_years_ = years;
    days_left_ = years*365;
}

int TimeDepositAccount::get_time_deposit() const
{
    return time_deposit_years_;
}

int TimeDepositAccount::get_days_left() const
{
    return days_left_;
}

void TimeDepositAccount::spend_time(int days)
{
    days_left_ -= days;
}
