#include "account.hh"
#include <iostream>

// Initialize the static attribute running_number_
int Account::running_number_ = 0;

Account::Account(const std::string& owner) : owner_(owner)
{
    generate_iban();
}

Account::~Account()
{
}

void Account::save_money(double amount)
{
    account_balance += amount;
}

bool Account::take_money(double amount)
{
    if (account_balance - amount <0){
        return false;
    }

    account_balance -= amount;
    return true;
}

bool Account::transfer_to(Account *other_account, double amount)
{
    if (this == other_account) {
        return true;
    }

    if (!take_money(amount)) {
        return false;
    }

    other_account->save_money(amount);
    return true;
}

void Account::print() const
{
    std::cout << owner_ << " : " << iban_ << " : " << account_balance << " euros"<<std::endl;
}

void Account::print_iban() const
{
    std::cout << iban_;
}

double Account::get_accountBalance() const {return account_balance;}

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
