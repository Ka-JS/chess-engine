#ifndef TIMEDEPOSITACCOUNT_HH
#define TIMEDEPOSITACCOUNT_HH
#include "account.hh"


using namespace std;

class TimeDepositAccount: public Account
{
public:
    TimeDepositAccount(const string& owner);
    virtual ~TimeDepositAccount();
    bool virtual take_money(double amount);
    void virtual print() const;
    void spend_time(int time);
    void set_times(int timeDeposit);
    int getTimes() const;

private:
    int time_deposit_;

};

#endif // TIMEDEPOSITACCOUNT_HH
