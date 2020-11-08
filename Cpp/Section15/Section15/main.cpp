// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.hpp"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    // Checking

    vector<Checking_Account> chk_accounts;
    chk_accounts.push_back(Checking_Account {} );
    chk_accounts.push_back(Checking_Account {"Superman"} );
    chk_accounts.push_back(Checking_Account {"Batman", 2000} );
    chk_accounts.push_back(Checking_Account {"Wonderwoman", 5000, 5.0} );

    display(chk_accounts);
    deposit(chk_accounts, 1000);
    withdraw(chk_accounts, 2000);    
    
    // Checking

    vector<Trust> trt_accounts;
    trt_accounts.push_back(Trust {} );
    trt_accounts.push_back(Trust {"Superman"} );
    trt_accounts.push_back(Trust {"Batman", 2000} );
    trt_accounts.push_back(Trust {"Wonderwoman", 5000, 5.0} );

    display(trt_accounts);
    deposit(trt_accounts, 1000);
    withdraw(trt_accounts, 300);
    withdraw(trt_accounts, 300);  
    withdraw(trt_accounts, 300);  
    withdraw(trt_accounts, 300);  

    return 0;
}

