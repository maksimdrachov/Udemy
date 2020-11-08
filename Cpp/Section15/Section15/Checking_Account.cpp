#include "Checking_Account.hpp"

Checking_Account::Checking_Account(std::string name, double balance, double fee_rate)
    : Account {name, balance}, fee_rate{fee_rate} {
}

bool Checking_Account::withdraw(double amount) {
    amount += def_fee_rate;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.def_fee_rate << "%]";
    return os;
}