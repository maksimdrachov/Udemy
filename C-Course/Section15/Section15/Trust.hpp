#ifndef TRUST_HPP
#define TRUST_HPP
#include "Account.h"

class Trust: public Account
{
friend std::ostream &operator<<(std::ostream &os, const Trust &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int max_withdrawal_count = 3;
    static constexpr int def_withdrawal_count = 0;
protected:
    double int_rate;
    int withdrawal_count;

public:
    Trust(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
    bool withdraw(double amount);
    bool deposit(double amount);
};

#endif // TRUST_HPP
