#ifndef TIMEDEPOSITACCOUNT_HH
#define TIMEDEPOSITACCOUNT_HH
#include "account.hh"

class TimeDepositAccount: public Account
{
public:
    TimeDepositAccount(const string& owner);
    virtual ~TimeDepositAccount();
    virtual bool take_money(double amount) override;
    virtual void print() const override;
    void set_times(int years);
    int get_time_deposit() const;
    int get_days_left() const;
    void spend_time(int days);
private:
    int time_deposit_years_;
    int days_left_;
};

#endif // TIMEDEPOSITACCOUNT_HH
