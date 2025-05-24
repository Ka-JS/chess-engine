#include "creditaccount.hh"

CreditAccount::CreditAccount(const string& owner)
              : Account(owner), credit_limit_(0)
{

}

CreditAccount::~CreditAccount()
{

}

bool CreditAccount::take_money(double amount)
{
    if (balance_ >= amount) {
        balance_ -= amount;
        return true;
    } else {
        double extra = amount - balance_;
        if (extra <= credit_limit_) {
            balance_ -= amount;
            return true;
        } else {
            cout << "ERROR! Cannot take money: credit limit overflow" << endl;
            return false;
        }
    }
}


void CreditAccount::print() const
{
    Account::print();
    cout << "  ::: Credit limit : " << credit_limit_ << endl;
}

void CreditAccount::set_credit_limit(double limit)
{
    credit_limit_ = limit;
}

double CreditAccount::get_credit_limit() const
{
    return credit_limit_;
}
