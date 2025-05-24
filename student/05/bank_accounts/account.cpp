#include "account.hh"
#include <iostream>

// Initialize the static attribute running_number_
int Account::running_number_ = 0;

Account::Account(const std::string& owner): owner_(owner)
{
    generate_iban();
}

Account::~Account(){}



void Account::save_money(double amount)
{
    balance_ += amount;
}

bool Account::take_money(double amount)
{
    if (balance_ - amount <0) {
        return false;
    }
    balance_ -= amount;
    return true;
}

bool Account::transfer_to(Account *other_account, double amount)
{
    if (other_account == this){
        return true;
    }
    if (!take_money(amount)){
        return false;
    }
    other_account->save_money(amount);
    return true;
}

void Account::print() const
{
    cout << owner_ << " : " << iban_ << " : " << balance_ << " euros" << endl;
}

void Account::print_iban() const
{
    cout << iban_;
}

double Account::get_accountBalance() const {return balance_;}

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
