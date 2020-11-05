#ifndef CHECKING_ACCOUNT_HPP
#define CHECKING_ACCOUNT_HPP
#include "Account.h"

class Checking_Account: public Account 
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee_rate = 1.50;
protected:
    double fee_rate;

public:
    Checking_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_fee_rate);
    bool withdraw(double amount);

};

#endif // CHECKING_ACCOUNT_HPP
