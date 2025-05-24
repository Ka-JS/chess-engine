#include "creditaccount.hh"

CreditAccount::CreditAccount(const string& owner): Account(owner)
{

}

CreditAccount::~CreditAccount()
{

}

bool CreditAccount::take_money(double amount)
{
    if (amount <= 0) {
        cout << "ERROR! Cannot take money: invalid amount\n";
        return false;
    }

    double current_balance = get_accountBalance();
    if ((current_balance - amount) < -credit_limit_){
        cout << "ERROR! Cannot take money: credit limit overflow\n";
        return false;
    }

    balance_ -= amount;
    return true;
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
