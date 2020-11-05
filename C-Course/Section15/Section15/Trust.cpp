#include "Trust.hpp"

Trust::Trust(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate}, withdrawal_count(0) {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Trust::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool Trust::withdraw(double amount) {
    if (amount < (0.2*balance) and (withdrawal_count < 3)) {
        withdrawal_count += 1;
        return Account::withdraw(amount);
        }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Trust &account) {
    os << "[Trust: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

